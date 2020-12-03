#include "ContentsMenu.h"

//default constructor
ContentsMenu::ContentsMenu(QWidget* parent):
	QDialog(parent),
	ui(new Ui::ContentsMenu)
{
	ui->setupUi(this);
}

//destructor
ContentsMenu::~ContentsMenu()
{
	delete ui;
}

//Application�� ����ȭ��
void ContentsMenu::add_contents()
{
	this->close();
	SaveContents save;
	save.setModal(true);
	save.applyMenu(this);
	save.exec();
	if (app->m_List.IsFull()) {
		QMessageBox::information(this, "ERROR", "List is Full");
		return;
	}
	else {
		if (save.cname != "") {
			ItemType newItem;
			string cname = save.cname;	//������ �̸�
			string cdate = save.cdate;		//������ �ð�
			string cevent = save.cevent;			//������ �̺�Ʈ
			string cpeople = save.cpeople;		//������ ���Ե� ���
			string cplace = save.cplace;			//������ ���
			string ctype = save.ctype;			//������ Ÿ��
			string ccontent = save.ccontent;		//������ ����
			string cfile = save.cfilepath;		//������ ���
			bool cfc = save.cfc;		//���ã�� ����Ʈ ���� ����
			newItem.SetRecord(cname, cdate, cpeople, ctype, cevent, ccontent, cplace, cfc, cfile, 0);
			if (app->m_List.Add(newItem)) {
				//EventType ����
				app->AddEventlist(cevent, cname);

				//PeopleType ����
				app->AddPeopleList(cpeople, cname);

				//PlaceType ����
				app->AddPlaceList(cplace, cname);

				//filepath list�� ����
				app->AddFilePath(cname, cfile);

				//���ã�� ���Կ� üũ�Ǹ� �����ϱ�
				if (cfc) {
					app->AddFcList(ctype, cname);
				}

				QMessageBox::information(this, "SUCCESS", "ADD SUCCESS!");
				app->add_table(cname);
			}
			else {
				QMessageBox::information(this, "ERROR", "ADD FAIL!");
			}
		}
	}
}

//������ �����ϱ�
int ContentsMenu::delete_contents()
{
	this->close();
	InputWindow name;
	name.setModal(true);
	name.applyMenu(this);
	name.exec();
	string cname = name.find_show();
	if (cname != "") {
		ItemType input;
		input.SetName(cname);
		if (app->m_List.Delete(input)) {		//if delete the item in the list, return 1
			app->DeleteEventType(input.GetEvent(), input.GetName());	//EventType���� ����
			app->DeletePeopleType(input.GetPeople(), input.GetName());	//PeopleType���� ����
			app->DeletePlaceType(input.GetPlace(), input.GetName());	//PlaceType���� ����
			app->DeleteFcType(input.GetType(), input.GetName());	//FcType���� ����
			app->DeleteFilePath(input.GetName());	//filepath list ���� ����
			app->delete_table();
			QMessageBox::information(this, "SUCCESS", "DELETE SUCCESS!");
			return 1;
		}

		//if fail to delete item record, return 0
		QMessageBox::information(this, "ERROR", "DELETE FAIL!");
		return 0;
	}
	

}

//������ �����ϱ�
int ContentsMenu::replace_contents()
{
	this->close();
	InputWindow name;
	name.setModal(true);
	name.applyMenu(this);
	name.exec();
	string cname = name.find_show();
	if (cname != "") {
		ItemType input;	//�ٲ� ����������, �ٲ�� �� ������ record�� ���� itemType
		input.SetName(cname);		//������ �̸�
		if (!app->m_List.Get(input))
		{
			QMessageBox::information(this, "ERROR", "CONTENTS NOT EXIST!");
			return 0;
		}
		SaveContents save;
		save.setModal(true);
		save.applyMenu(this);
		save.ui->cname->text() = QString::fromStdString(cname);
		save.exec();
		ItemType newItem;
		string cdate = save.cdate;		//������ �ð�
		string cevent = save.cevent;			//������ �̺�Ʈ
		string cpeople = save.cpeople;		//������ ���Ե� ���
		string cplace = save.cplace;			//������ ���
		string ctype = save.ctype;			//������ Ÿ��
		string ccontent = save.ccontent;		//������ ����
		string cfile = save.cfilepath;		//������ ���
		bool cfc = save.cfc;		//���ã�� ����Ʈ ���� ����
		newItem.SetRecord(cname, cdate, cpeople, ctype, cevent, ccontent, cplace, cfc, cfile, input.GetView());
		app->m_List.Replace(newItem);

		//EventLIst���� �ٲ� data����
		if (newItem.GetEvent() != input.GetEvent()) {
			app->DeleteEventType(input.GetEvent(), input.GetName());	//���� ������ ����
			app->AddEventlist(newItem.GetEvent(), newItem.GetName());	//�ٲ� ������ ����
		}
		//PeopleList���� �ٲ� data ����
		if (newItem.GetPeople() != input.GetPeople()) {
			app->DeletePeopleType(input.GetPeople(), input.GetName());	//���� ������ ����
			app->AddPeopleList(newItem.GetPeople(), newItem.GetName());	//�ٲ� ������ ����
		}
		//PlaceList���� �ٲ� data ����
		if (newItem.GetPlace() != input.GetPlace()) {
			app->DeletePlaceType(input.GetPlace(), input.GetName());	//���� ������ ����
			app->AddPeopleList(newItem.GetPlace(), newItem.GetName());		//�ٲ� ������ ����
		}

		if (newItem.GetFile() != input.GetFile()) {			//������ �ٲ�� filepath list���� ���ϰ�� �ٲٱ�
			app->ReplaceFilePath(newItem.GetName(), newItem.GetFile());
		}

		if (newItem.GetFc() != input.GetFc())	//���ã�� �߰��� �ٲ�����
		{
			if (newItem.GetFc() && !input.GetFc())		//������ ���ã�� �׸� ���ٰ� �߰��ϴ� ���
			{
				app->m_List.Find(newItem)->info.changeFc();
				app->AddFcList(ctype, cname);
			}
			else {			//������ ���ã�� �׸� �ִٰ� ���ã���׸񿡼� ������ ���
				app->m_List.Find(newItem)->info.changeFc();
				app->DeleteFcType(ctype, cname);
			}
		}

		QMessageBox::information(this, "SUCCESS", "REPLACE SUCCESS!");
		return 1;
	}
}