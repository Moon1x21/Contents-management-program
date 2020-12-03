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

//Application를 동기화함
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
			string cname = save.cname;	//컨텐츠 이름
			string cdate = save.cdate;		//컨텐츠 시간
			string cevent = save.cevent;			//컨텐츠 이벤트
			string cpeople = save.cpeople;		//컨텐츠 포함된 사람
			string cplace = save.cplace;			//컨텐츠 장소
			string ctype = save.ctype;			//컨텐츠 타입
			string ccontent = save.ccontent;		//컨텐츠 내용
			string cfile = save.cfilepath;		//컨텐츠 경로
			bool cfc = save.cfc;		//즐겨찾기 리스트 포함 유무
			newItem.SetRecord(cname, cdate, cpeople, ctype, cevent, ccontent, cplace, cfc, cfile, 0);
			if (app->m_List.Add(newItem)) {
				//EventType 저장
				app->AddEventlist(cevent, cname);

				//PeopleType 저장
				app->AddPeopleList(cpeople, cname);

				//PlaceType 저장
				app->AddPlaceList(cplace, cname);

				//filepath list에 저장
				app->AddFilePath(cname, cfile);

				//즐겨찾기 포함에 체크되면 포함하기
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

//컨텐츠 삭제하기
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
			app->DeleteEventType(input.GetEvent(), input.GetName());	//EventType에서 삭제
			app->DeletePeopleType(input.GetPeople(), input.GetName());	//PeopleType에서 삭제
			app->DeletePlaceType(input.GetPlace(), input.GetName());	//PlaceType에서 삭제
			app->DeleteFcType(input.GetType(), input.GetName());	//FcType에서 삭제
			app->DeleteFilePath(input.GetName());	//filepath list 에서 삭제
			app->delete_table();
			QMessageBox::information(this, "SUCCESS", "DELETE SUCCESS!");
			return 1;
		}

		//if fail to delete item record, return 0
		QMessageBox::information(this, "ERROR", "DELETE FAIL!");
		return 0;
	}
	

}

//컨텐츠 수정하기
int ContentsMenu::replace_contents()
{
	this->close();
	InputWindow name;
	name.setModal(true);
	name.applyMenu(this);
	name.exec();
	string cname = name.find_show();
	if (cname != "") {
		ItemType input;	//바꿀 컨텐츠이자, 바뀌기 전 아이템 record를 가질 itemType
		input.SetName(cname);		//컨텐츠 이름
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
		string cdate = save.cdate;		//컨텐츠 시간
		string cevent = save.cevent;			//컨텐츠 이벤트
		string cpeople = save.cpeople;		//컨텐츠 포함된 사람
		string cplace = save.cplace;			//컨텐츠 장소
		string ctype = save.ctype;			//컨텐츠 타입
		string ccontent = save.ccontent;		//컨텐츠 내용
		string cfile = save.cfilepath;		//컨텐츠 경로
		bool cfc = save.cfc;		//즐겨찾기 리스트 포함 유무
		newItem.SetRecord(cname, cdate, cpeople, ctype, cevent, ccontent, cplace, cfc, cfile, input.GetView());
		app->m_List.Replace(newItem);

		//EventLIst에서 바뀐 data삭제
		if (newItem.GetEvent() != input.GetEvent()) {
			app->DeleteEventType(input.GetEvent(), input.GetName());	//원래 데이터 삭제
			app->AddEventlist(newItem.GetEvent(), newItem.GetName());	//바뀐 데이터 저장
		}
		//PeopleList에서 바뀐 data 삭제
		if (newItem.GetPeople() != input.GetPeople()) {
			app->DeletePeopleType(input.GetPeople(), input.GetName());	//원래 데이터 삭제
			app->AddPeopleList(newItem.GetPeople(), newItem.GetName());	//바뀐 데이터 저장
		}
		//PlaceList에서 바뀐 data 삭제
		if (newItem.GetPlace() != input.GetPlace()) {
			app->DeletePlaceType(input.GetPlace(), input.GetName());	//원래 데이터 삭제
			app->AddPeopleList(newItem.GetPlace(), newItem.GetName());		//바뀐 데이터 저장
		}

		if (newItem.GetFile() != input.GetFile()) {			//사진이 바뀌면 filepath list에서 파일경로 바꾸기
			app->ReplaceFilePath(newItem.GetName(), newItem.GetFile());
		}

		if (newItem.GetFc() != input.GetFc())	//즐겨찾기 추가가 바꼈으면
		{
			if (newItem.GetFc() && !input.GetFc())		//원래는 즐겨찾기 항목에 없다가 추가하는 경우
			{
				app->m_List.Find(newItem)->info.changeFc();
				app->AddFcList(ctype, cname);
			}
			else {			//원래는 즐겨찾기 항목에 있다가 즐겨찾기항목에서 제외한 경우
				app->m_List.Find(newItem)->info.changeFc();
				app->DeleteFcType(ctype, cname);
			}
		}

		QMessageBox::information(this, "SUCCESS", "REPLACE SUCCESS!");
		return 1;
	}
}
