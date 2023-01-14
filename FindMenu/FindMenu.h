#pragma once
#include "pch.h"
#include <QDialog>
#include "ui_FindMenu.h"
#include <QMessageBox>

namespace Ui {
	class FindMenu;
}

class FindMenu:public QDialog
{
	friend class SaveContents;
	friend class Application;
	friend class ShowDetail;
	friend class InputWindow;

	Q_OBJECT
public:
	/**
   *	default constructor
   */
	FindMenu(QWidget* parent = 0);

	/**
	*	destructor
	*/
	~FindMenu();

	/**
   *	@brief	Application을 동기화함
   *	@pre	none
   *	@post	Application가 동기화됨
   */
	void applyApp(Application* app) { this->app = app; }


private slots:

	/**
   *	@brief	컨텐츠의 이름을 통해 컨텐츠 상세정보 보기
   *	@pre	버튼 클릭
   *	@post	컨텐츠 이름 입력받는 화면을 띄우고, 해당 이름을 가진 컨텐츠의 상세 기록을 화면에 띄움
   */
	void Find_contents();

	/**
   *	@brief	컨텐츠에 포함된 사람을 통해 컨텐츠 상세정보 보기
   *	@pre	버튼 클릭
   *	@post	컨텐츠 사람을 입력받는 화면을 띄우고, 해당하는 리스트의 컨텐츠들의 상세 기록을 화면에 띄움
   */
	void Find_People();

	/**
   *	@brief	컨텐츠에 포함된 장소를 통해 컨텐츠 상세정보 보기
   *	@pre	버튼 클릭
   *	@post	컨텐츠 장소를 입력받는 화면을 띄우고, 해당하는 리스트의 컨텐츠들의 상세 기록을 화면에 띄움
   */
	void Find_Place();

	/**
   *	@brief	컨텐츠 키워드를 통해서 해당하는 컨텐츠들 상세정보 보기
   *	@pre	버튼 클릭
   *	@post	컨텐츠 키워드들을 입력받는 화면을 띄우고, 해당하는 리스트의 컨텐츠들의 상세 기록을 화면에 띄움
   */
	void Find_KeyWord();

	/**
   *	@brief	컨텐츠의 이벤트를 통해 컨텐츠 상세정보 보기
   *	@pre	버튼 클릭
   *	@post	컨텐츠 이벤트를 입력받는 화면을 띄우고, 해당하는 리스트의 컨텐츠들의 상세 기록을 화면에 띄움
   */
	void Find_Event();

	void find_Key();
private:
	Ui::FindMenu* ui;
	ShowDetail* show;		//상세정보 띄우기
	Application* app;	//application
	InputWindow* input;	//컨텐츠 이름 입력

};
