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

//즐겨찾기 리스트에 저장할 컨텐츠 이름을 입력받고, 저장
void FcMenu::add_fc()
{
	this->close();
	InputWindow input;
	input.setModal(true);
	input.applyFc(this);	//fcmenu와 동기화
	input.exec();
	string fcname = input.find_show();	//저장할 컨텐츠 이름
	if (fcname != "") {	//창을 끄지 않을 경우
		ItemType temp;
		temp.SetName(fcname);
		if (app->m_List.Find(temp) == nullptr) {
			QMessageBox::information(this, "ERROR", "FAIL TO ADD!");
			return;
		}
		if (app->m_List.Find(temp)->info.GetFc()) {	//이미 Fclilst에 존재하면 return 0
			QMessageBox::information(this, "ERROR", "ALREADY EXIST!");
			return;
		}
		app->m_List.Find(temp)->info.changeFc();	//Fclist 존재여부 true로 바꿔주기
		app->AddFcList(temp.GetType(), temp.GetName());
		QMessageBox::information(this, "SUCCESS", "ADD SUCCESS!!");
	}
}

//즐겨찾기 리스트에서 삭제할 컨텐츠 이름을 입력받고, 저장
void FcMenu::delete_fc()
{
	this->close();
	InputWindow input;
	input.setModal(true);
	input.applyFc(this);	//fcmenu와 동기화
	input.exec();
	string fcname = input.find_show();	//삭제할 컨텐츠 이름
	if (fcname != "") {	//창을 끄지 않을 경우
		ItemType item;
		item.SetName(fcname);
		if (app->m_List.Find(item) != nullptr) {
			string Type = item.GetType();
			if (app->DeleteFcType(Type, item.GetName())) {
				app->m_List.Find(item)->info.changeFc();	//Fclist 존재여부 false로 바꿔주기
				QMessageBox::information(this, "SUCCESS", "DELETE SUCCESS!!");
				return;
			}
		}
		QMessageBox::information(this, "ERROR", "FAIL TO DELETE!");
		return;
	}
	
	
}

//즐겨찾기 리스트에서 타입별 컨텐츠 간단정보 보기
void FcMenu::view_fc()
{
	this->close();
	InputFcType input;
	input.setModal(true);
	input.applyFc(this);
	input.exec();
	string name = input.GetType();		//타입 이름
	if (name != "") {	//창을 끄지 않을 경우
		Key_List Fitem(name);
		if (app->FcList.Find(Fitem) != nullptr) {
			DoublyIterator<string> iter(*app->FcList.Find(Fitem)->info.GetList());		//타입 리스트 iterator
			while (iter.NotNull()) {
				this->close();
				string name = iter.GetCurNode()->info;
				FileType data(name);
				app->file_path.Find(data);	//filePath list에서 해당하는 파일이름의 경로 받아오기
				ShowDetail show;
				show.setModal(this);
				show.applyFc(this);
				show.setfc(data);	//Fc_type을 통해서 이름과 사진만 간단하게 세팅하기
				show.exec();
				switch (show.Getnum())
				{
				case 0:	//메뉴로 돌아가기 버튼을 누르면 종류 
					return;
					break;
				case 1:	//이전 버튼을 누르면 BACK NOT NULL일때만 이전 노드로 iterator 움직임
					if (iter.BackNotNull())
						iter.Back();
					else
						QMessageBox::information(this, "ERROR", "FIRST CONTENTS!!");	//BACK NULL이면 경고창 띄워줌
					break;
				case 2:	//다음 버튼을 누르면 NEXT NOT NULL일 때 다음 노드로  iterator 움직임
					if (iter.NextNotNull())
						iter.Next();
					else
						QMessageBox::information(this, "ERROR", "LAST CONTENTS!!");	//NEXT NULL이면 경고창 띄워줌
					break;
				default:
					break;
				}
			}
			return;
		}
		//만약 타입에 해당하는 리스트가 존재하지 않으면 경고창 띄우기
		QMessageBox::information(this, "ERROR", "THE LIST IS Empty!");
	}
	
}

//타입별 즐겨찾기 리스트에 포함된 컨텐츠 상세정보 보기
void FcMenu::view_fc_mc()
{
	this->close();
	InputFcType input;
	input.setModal(true);
	input.applyFc(this);
	input.exec();
	string name = input.GetType();	 //타입 입력받기
	if (name != "") {	//창을 끄지 않을 경우
		Key_List Fitem(name);
		if (app->FcList.Find(Fitem) != nullptr) {
			DoubleLinkedList<string>* list = app->FcList.Find(Fitem)->info.GetList();		//즐겨찾기 타입별 리스트에 저장되어있는 list포인터
			DoublyIterator<string> iter(*list);
			DoubleNode<string>* node = iter.GetCurNode();
			while (iter.NotNull()) {
				node = iter.GetCurNode();
				int num = app->SearchByCnameAndDisplay(node->info, iter);	//해당하는 컨텐츠의 자세한 정보 화면에 출력
				if (num == 0 || num == -1)	//메뉴로 돌아가기 버튼을 눌렀거나, 컨텐츠 찾지 못했을 때
					return;
			}
			return;
		}
		//만약 타입에 해당하는 리스트가 존재하지 않으면 경고창 띄우기
		QMessageBox::information(this, "ERROR", "THE LIST IS Empty!");
	}
}

