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

//컨텐츠의 이름을 통해 컨텐츠 상세정보 보기
void FindMenu::Find_contents()
{
	InputWindow input;
	input.setModal(true);
	input.applyFind(this);
	input.exec();
	this->close();
	string cname = input.find_show();	//컨텐츠 이름 입력받기
	if (cname != "") {	//창을 그냥 끄지 않을 경우

		if (app->SearchByname(cname))	//MasterList에서 찾아서 자세한 record Display on Screen
			return;
		else
			QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
	}
}

//컨텐츠에 포함된 사람을 통해 컨텐츠 상세정보 보기
void FindMenu::Find_People()
{
	this->close();
	InputWindow input;
	input.setModal(true);
	input.applyFind(this);
	input.exec();
	bool found = false;
	string cpeople = input.find_show();	//사람 키워드 입력받기
	if (cpeople != "") {	//창을 그냥 끄지 않을 경우
		Key_List data(cpeople);
		if (app->PeList.Get(data)) {
			found = true;
			DoubleLinkedList<string>* pelist = app->PeList.Find(data)->info.GetList();	//People에 저장되어있는 list포인터
			DoublyIterator<string> iter(*pelist);
			DoubleNode<string>* node = iter.GetCurNode();
			while (iter.NotNull()) {
				node = iter.GetCurNode();
				int num = app->SearchByCnameAndDisplay(node->info, iter);	//해당하는 컨텐츠의 자세한 정보 화면에 출력
				if (num == 0 || num == -1)		//메뉴로 돌아가기 버튼을 눌렀거나, 컨텐츠 찾지 못했을 때
					return;
			}
			return;
		}
		if (!found)	//만약 키워드에 해당하는 리스트가 존재하지 않으면 경고창 띄우기
			QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
	}
	
}

//컨텐츠에 포함된 장소를 통해 컨텐츠 상세정보 보기
void FindMenu::Find_Place()
{
	this->close();
	InputWindow input;
	input.setModal(true);
	input.applyFind(this);
	input.exec();
	bool found = false;
	string cplace = input.find_show();	//장소 키워드 입력받기
	if (cplace != "") {	//창을 그냥 끄지 않을 경우
		Key_List data(cplace);
		if (app->PlList.Get(data)) {
			found = true;
			DoubleLinkedList<string>* pllist = app->PlList.Find(data)->info.GetList();	//Place에 저장되어있는 list포인터
			DoublyIterator<string> iter(*pllist);
			DoubleNode<string>* node = iter.GetCurNode();
			while (iter.NotNull()) {
				node = iter.GetCurNode();
				int num = app->SearchByCnameAndDisplay(node->info, iter);		//해당하는 컨텐츠의 자세한 정보 화면에 출력
				if (num == 0 || num == -1)		//메뉴로 돌아가기 버튼을 눌렀거나, 컨텐츠 찾지 못했을 때
					return;
			}
			return;
		}
		if (!found)	//만약 키워드에 해당하는 리스트가 존재하지 않으면 경고창 띄우기
			QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
	}
}

//컨텐츠 키워드를 통해서 해당하는 컨텐츠들 상세정보 보기
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
	if (app->EList.Get(Ename)) {		//이벤트 리스트 찾음
		if (app->PeList.Get(Pname)) {	//사람 리스트 찾음
			if (app->PlList.Get(Plname)) {		//장소 리스트 찾음
				DoublyIterator<string> iter(*app->EList.Find(Ename)->info.GetList());	///이벤트 리스트에 저장된 컨텐츠 이름들을 사람리스트와 장소 리스트에서 찾아서 있으면 list안에 집어넣음	
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
						int num = app->SearchByCnameAndDisplay(iter2.GetCurNode()->info, iter2);	//컨텐츠 이름을 통해서 상세정보 보여주기
						if (num == 0 || num == -1)		//메뉴로 돌아가기 버튼을 눌렀거나, 컨텐츠 찾지 못했을 때
							return;
					}
				}
				else {		//공통된 컨텐츠 없으면 실패
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

//컨텐츠의 이벤트를 통해 컨텐츠 상세정보 보기
void FindMenu::Find_Event()
{
	InputWindow input;
	input.setModal(true);
	input.applyFind(this);
	input.exec();
	bool found = false;
	string cevent = input.find_show();	//이벤트 키워드 입력받기
	Key_List data(cevent);
	if (app->EList.Get(data)) {
		found = true;
		DoubleLinkedList<string>* E_list = app->EList.Find(data)->info.GetList();		//Event에 저장되어있는 list포인터
		DoublyIterator<string> iter(*E_list);
		DoubleNode<string>* node = iter.GetCurNode();
		while (iter.NotNull()) {
			node = iter.GetCurNode();
			int num = app->SearchByCnameAndDisplay(node->info,iter);		//해당하는 컨텐츠의 자세한 정보 화면에 출력
			if (num == 0 || num == -1)		//메뉴로 돌아가기 버튼을 눌렀거나, 컨텐츠 찾지 못했을 때
				return;
		}
		return;
	}
	if (!found)	//만약 키워드에 해당하는 리스트가 존재하지 않으면 경고창 띄우기
		QMessageBox::information(this, "ERROR", "FAIL TO FIND!");
}



