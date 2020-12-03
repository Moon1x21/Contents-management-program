#pragma once
#include "pch.h"
#include <QDialog>
#include "ui_InputWindow.h"

namespace Ui {
	class InputWindow;
}

class InputWindow :public QDialog
{
	friend class FindMenu;
	friend class ContentsMenu;
	friend class FcMenu;
	Q_OBJECT

public:
	/**
	*	default constructor
	*/
	InputWindow(QWidget* parent = 0);

	/**
	*	destructor
	*/
	~InputWindow();

	 /**
	*	@brief	findmenu를 동기화함
	*	@pre	none
    *	@post	FindMenu가 동기화됨
    */
	void applyFind(FindMenu* show) { this->show = show; }
	/**
   *	@brief	ContentsMenu를 동기화함
   *	@pre	none
   *	@post	ContentsMenu가 동기화됨
   */
	void applyMenu(ContentsMenu* menu) { this->menu = menu; }

	/**
   *	@brief	FcMenu를 동기화함
   *	@pre	none
   *	@post	FcMenu가 동기화됨
   */
	void applyFc(FcMenu* fc) { this->fc = fc; }
public slots:

	/**
   *	@brief	컨텐츠의 키워드를 입력받음
   *	@pre	none
   *	@post	컨텐츠의 키워드를 입력받고 창이 닫힘
   *	@return	입력한 컨텐츠 키워드
   */
	string find_show();
private:
	Ui::InputWindow* ui;
	FindMenu* show;	//findmenu
	ContentsMenu* menu;	//contents menu
	FcMenu* fc;	//fcmenu 
};
