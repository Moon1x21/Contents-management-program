#include "FindMenu.h"

//default constructor
FindMenu::FindMenu(QWidget* parent):
	QDialog(parent),
	ui(new Ui::FindMenu)
{
	ui->setupUi(this);
	ui->widget->hide();
	ui->widget_2->hide();
	ui->widget_3->hide();
}

//destructor
FindMenu::~FindMenu()
{
	delete ui;
}

//�������� �̸��� ���� ������ ������ ����
void FindMenu::Find_contents()
{
	InputWindow input;
	input.setModal(true);
	input.applyFind(this);
	input.exec();
	this->close();
	string cname = input.find_show();	//������ �̸� �Է¹ޱ�
	if (cname != "") {	//â�� �׳� ���� ���� ���

		if (app->SearchByname(cname))	//MasterList���� ã�Ƽ� �ڼ��� record Display on Screen
			return;
		else
			QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
	}
}

//�������� ���Ե� ����� ���� ������ ������ ����
void FindMenu::Find_People()
{
	this->close();
	InputWindow input;
	input.setModal(true);
	input.applyFind(this);
	input.exec();
	bool found = false;
	string cpeople = input.find_show();	//��� Ű���� �Է¹ޱ�
	if (cpeople != "") {	//â�� �׳� ���� ���� ���
		Key_List data(cpeople);
		if (app->PeList.Get(data)) {
			found = true;
			DoubleLinkedList<string>* pelist = app->PeList.Find(data)->info.GetList();	//People�� ����Ǿ��ִ� list������
			DoublyIterator<string> iter(*pelist);
			DoubleNode<string>* node = iter.GetCurNode();
			while (iter.NotNull()) {
				node = iter.GetCurNode();
				int num = app->SearchByCnameAndDisplay(node->info, iter);	//�ش��ϴ� �������� �ڼ��� ���� ȭ�鿡 ���
				if (num == 0 || num == -1)		//�޴��� ���ư��� ��ư�� �����ų�, ������ ã�� ������ ��
					return;
			}
			return;
		}
		if (!found)	//���� Ű���忡 �ش��ϴ� ����Ʈ�� �������� ������ ���â ����
			QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
	}
	
}

//�������� ���Ե� ��Ҹ� ���� ������ ������ ����
void FindMenu::Find_Place()
{
	this->close();
	InputWindow input;
	input.setModal(true);
	input.applyFind(this);
	input.exec();
	bool found = false;
	string cplace = input.find_show();	//��� Ű���� �Է¹ޱ�
	if (cplace != "") {	//â�� �׳� ���� ���� ���
		Key_List data(cplace);
		if (app->PlList.Get(data)) {
			found = true;
			DoubleLinkedList<string>* pllist = app->PlList.Find(data)->info.GetList();	//Place�� ����Ǿ��ִ� list������
			DoublyIterator<string> iter(*pllist);
			DoubleNode<string>* node = iter.GetCurNode();
			while (iter.NotNull()) {
				node = iter.GetCurNode();
				int num = app->SearchByCnameAndDisplay(node->info, iter);		//�ش��ϴ� �������� �ڼ��� ���� ȭ�鿡 ���
				if (num == 0 || num == -1)		//�޴��� ���ư��� ��ư�� �����ų�, ������ ã�� ������ ��
					return;
			}
			return;
		}
		if (!found)	//���� Ű���忡 �ش��ϴ� ����Ʈ�� �������� ������ ���â ����
			QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
	}
}

//������ Ű���带 ���ؼ� �ش��ϴ� �������� ������ ����
void FindMenu::Find_KeyWord()
{
	ui->widget->show();
	ui->widget_2->show();
	ui->widget_3->show();
}

void FindMenu::find_Key()
{
	this->close();
	ui->widget->hide();
	string _cevent, _cpeople, _cplace;
	_cevent = ui->lineEdit->text().toStdString();
	_cpeople = ui->lineEdit_2->text().toStdString();
	_cplace = ui->lineEdit_3->text().toStdString();
	ui->lineEdit->clear();
	ui->lineEdit_2->clear();
	ui->lineEdit_3->clear();
	Key_List Ename(_cevent);
	Key_List Pname(_cpeople);
	Key_List Plname(_cplace);
	if (app->EList.Get(Ename)) {		//�̺�Ʈ ����Ʈ ã��
		if (app->PeList.Get(Pname)) {	//��� ����Ʈ ã��
			if (app->PlList.Get(Plname)) {		//��� ����Ʈ ã��
				DoublyIterator<string> iter(*app->EList.Find(Ename)->info.GetList());	///�̺�Ʈ ����Ʈ�� ����� ������ �̸����� �������Ʈ�� ��� ����Ʈ���� ã�Ƽ� ������ list�ȿ� �������	
				DoubleLinkedList<string> list;
				string cname;
				while (iter.NotNull()) {
					cname = iter.GetCurNode()->info;
					if (app->PeList.Find(Pname)->info.GetList()->Get(cname) && app->PlList.Find(Plname)->info.GetList()->Get(cname)) {
						list.Add(cname);
					}
					iter.Next();
				}
				if (list.GetLength() != 0) {
					DoublyIterator<string> iter2(list);
					while (iter2.NotNull()) {
						int num = app->SearchByCnameAndDisplay(iter2.GetCurNode()->info, iter2);	//������ �̸��� ���ؼ� ������ �����ֱ�
						if (num == 0 || num == -1)		//�޴��� ���ư��� ��ư�� �����ų�, ������ ã�� ������ ��
							return;
					}
				}
				else {		//����� ������ ������ ����
					QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
					return;
				}
			}
			else {
				QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
				return;
			}
		}
		else {
			QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
			return;
		}
	}
	else {
		QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
		return;
	}
}

//�������� �̺�Ʈ�� ���� ������ ������ ����
void FindMenu::Find_Event()
{
	InputWindow input;
	input.setModal(true);
	input.applyFind(this);
	input.exec();
	bool found = false;
	string cevent = input.find_show();	//�̺�Ʈ Ű���� �Է¹ޱ�
	Key_List data(cevent);
	if (app->EList.Get(data)) {
		found = true;
		DoubleLinkedList<string>* E_list = app->EList.Find(data)->info.GetList();		//Event�� ����Ǿ��ִ� list������
		DoublyIterator<string> iter(*E_list);
		DoubleNode<string>* node = iter.GetCurNode();
		while (iter.NotNull()) {
			node = iter.GetCurNode();
			int num = app->SearchByCnameAndDisplay(node->info,iter);		//�ش��ϴ� �������� �ڼ��� ���� ȭ�鿡 ���
			if (num == 0 || num == -1)		//�޴��� ���ư��� ��ư�� �����ų�, ������ ã�� ������ ��
				return;
		}
		return;
	}
	if (!found)	//���� Ű���忡 �ش��ϴ� ����Ʈ�� �������� ������ ���â ����
		QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
}



