#pragma once
#include "pch.h"
#include "ui_ContentsMenu.h"
#include <QDialog>

namespace Ui {
	class ContentsMenu;
}

class ContentsMenu :public QDialog
{
	friend class Application;
	Q_OBJECT

public:
	/**
	*	default constructor
	*/
	ContentsMenu(QWidget* parent = 0);
	/**
	*	destructor
	*/
	~ContentsMenu();
	/**
   *	@brief	Application를 동기화함
   *	@pre	none
   *	@post	Application가 동기화됨
   */
	void applyApp(Application* app) { this->app = app; }
public slots:

	/**
   *	@brief	컨텐츠 저장하기
   *	@pre	click
   *	@post	컨텐츠 저장화면이 띄워지고, 컨텐츠 저장.
   */
	void add_contents();

	/**
   *	@brief	컨텐츠 삭제하기
   *	@pre	click
   *	@post	컨텐츠 이름을 적는 화면이 띄워지고, 해당하는 컨텐츠 삭제.
   *	@return	삭제되면 1, 아니면 0
   */
	int delete_contents();

	/**
   *	@brief	컨텐츠 수정하기
   *	@pre	click
   *	@post	컨텐츠 이름을 적는 화면이 띄워지고, 해당하는 컨텐츠 수정.
   *	@return	수정되면 1, 아니면 0
   */
	int replace_contents();

private:
	Ui::ContentsMenu* ui;
	Application* app;	//Application
};
