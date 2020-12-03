#include "FcMenu.h"

//default constructor
FcMenu::FcMenu(QWidget* parent)
	: QDialog(parent),
	ui(new Ui::FcMenu)
{
	ui->setupUi(this);
	ui->widget->hide();
	num = -1;
}

//destructor
FcMenu::~FcMenu()
{
	delete ui;
}

//���ã�� ����Ʈ�� ������ ������ �̸��� �Է¹ް�, ����
void FcMenu::add_fc()
{
	this->close();
	InputWindow input;
	input.setModal(true);
	input.applyFc(this);	//fcmenu�� ����ȭ
	input.exec();
	string fcname = input.find_show();	//������ ������ �̸�
	if (fcname != "") {	//â�� ���� ���� ���
		ItemType temp;
		temp.SetName(fcname);
		if (app->m_List.Find(temp) == nullptr) {
			QMessageBox::information(this, "ERROR", "FAIL TO ADD!");
			return;
		}
		if (app->m_List.Find(temp)->info.GetFc()) {	//�̹� Fclilst�� �����ϸ� return 0
			QMessageBox::information(this, "ERROR", "ALREADY EXIST!");
			return;
		}
		app->m_List.Find(temp)->info.changeFc();	//Fclist ���翩�� true�� �ٲ��ֱ�
		app->AddFcList(temp.GetType(), temp.GetName());
		QMessageBox::information(this, "SUCCESS", "ADD SUCCESS!!");
	}
}

//���ã�� ����Ʈ���� ������ ������ �̸��� �Է¹ް�, ����
void FcMenu::delete_fc()
{
	this->close();
	InputWindow input;
	input.setModal(true);
	input.applyFc(this);	//fcmenu�� ����ȭ
	input.exec();
	string fcname = input.find_show();	//������ ������ �̸�
	if (fcname != "") {	//â�� ���� ���� ���
		ItemType item;
		item.SetName(fcname);
		if (app->m_List.Find(item) != nullptr) {
			string Type = item.GetType();
			if (app->DeleteFcType(Type, item.GetName())) {
				app->m_List.Find(item)->info.changeFc();	//Fclist ���翩�� false�� �ٲ��ֱ�
				QMessageBox::information(this, "SUCCESS", "DELETE SUCCESS!!");
				return;
			}
		}
		QMessageBox::information(this, "ERROR", "FAIL TO DELETE!");
		return;
	}
	
	
}

//���ã�� ����Ʈ���� Ÿ�Ժ� ������ �������� ����
void FcMenu::view_fc()
{
	this->close();
	InputFcType input;
	input.setModal(true);
	input.applyFc(this);
	input.exec();
	string name = input.GetType();		//Ÿ�� �̸�
	if (name != "") {	//â�� ���� ���� ���
		Key_List Fitem(name);
		if (app->FcList.Find(Fitem) != nullptr) {
			DoublyIterator<string> iter(*app->FcList.Find(Fitem)->info.GetList());		//Ÿ�� ����Ʈ iterator
			while (iter.NotNull()) {
				this->close();
				string name = iter.GetCurNode()->info;
				FileType data(name);
				app->file_path.Find(data);	//filePath list���� �ش��ϴ� �����̸��� ��� �޾ƿ���
				ShowDetail show;
				show.setModal(this);
				show.applyFc(this);
				show.setfc(data);	//Fc_type�� ���ؼ� �̸��� ������ �����ϰ� �����ϱ�
				show.exec();
				switch (show.Getnum())
				{
				case 0:	//�޴��� ���ư��� ��ư�� ������ ���� 
					return;
					break;
				case 1:	//���� ��ư�� ������ BACK NOT NULL�϶��� ���� ���� iterator ������
					if (iter.BackNotNull())
						iter.Back();
					else
						QMessageBox::information(this, "ERROR", "FIRST CONTENTS!!");	//BACK NULL�̸� ���â �����
					break;
				case 2:	//���� ��ư�� ������ NEXT NOT NULL�� �� ���� ����  iterator ������
					if (iter.NextNotNull())
						iter.Next();
					else
						QMessageBox::information(this, "ERROR", "LAST CONTENTS!!");	//NEXT NULL�̸� ���â �����
					break;
				default:
					break;
				}
			}
			return;
		}
		//���� Ÿ�Կ� �ش��ϴ� ����Ʈ�� �������� ������ ���â ����
		QMessageBox::information(this, "ERROR", "THE LIST IS Empty!");
	}
	
}

//Ÿ�Ժ� ���ã�� ����Ʈ�� ���Ե� ������ ������ ����
void FcMenu::view_fc_mc()
{
	this->close();
	InputFcType input;
	input.setModal(true);
	input.applyFc(this);
	input.exec();
	string name = input.GetType();	 //Ÿ�� �Է¹ޱ�
	if (name != "") {	//â�� ���� ���� ���
		Key_List Fitem(name);
		if (app->FcList.Find(Fitem) != nullptr) {
			DoubleLinkedList<string>* list = app->FcList.Find(Fitem)->info.GetList();		//���ã�� Ÿ�Ժ� ����Ʈ�� ����Ǿ��ִ� list������
			DoublyIterator<string> iter(*list);
			DoubleNode<string>* node = iter.GetCurNode();
			while (iter.NotNull()) {
				node = iter.GetCurNode();
				int num = app->SearchByCnameAndDisplay(node->info, iter);	//�ش��ϴ� �������� �ڼ��� ���� ȭ�鿡 ���
				if (num == 0 || num == -1)	//�޴��� ���ư��� ��ư�� �����ų�, ������ ã�� ������ ��
					return;
			}
			return;
		}
		//���� Ÿ�Կ� �ش��ϴ� ����Ʈ�� �������� ������ ���â ����
		QMessageBox::information(this, "ERROR", "THE LIST IS Empty!");
	}
}

