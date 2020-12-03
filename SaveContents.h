#pragma once
#include "pch.h"
#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include <qfiledialog.h>
#include "ui_SaveContents.h"

namespace Ui {
	class SaveContents;
}
class SaveContents :public QDialog
{
	friend class ContentsMenu;
	Q_OBJECT

public:
	/**
	*	default constructor
	*/
	SaveContents(QWidget* parent = 0);

	/**
	*	destructor
	*/
	~SaveContents();

	/**
   *	@brief	ContentsMenu를 동기화함
   *	@pre	none
   *	@post	ContentsMenu가 동기화됨
   */
	void applyMenu(ContentsMenu* menu) { this->menu = menu; }


private slots:
	/**
   *	@brief	컨텐츠 저장이 됨
   *	@pre	click
   *	@post	각각의 컨텐츠 기록이 저장됨.
   */
	void open_window();

	/**
   *	@brief	사진을 load
   *	@pre	click
   *	@post	사진을 로드하는 창이 뜨고, 사진 load. type에 사진으로 저장
   */
	void load_pic();

	/**
   *	@brief	동영상을 load
   *	@pre	click
   *	@post	동영상을 로드하는 창이 뜨고, 동영상 load. type에 동영상으로 저장
   */
	void load_video();

	/**
   *	@brief	파노라마 load
   *	@pre	click
   *	@post	파노라마를 로드하는 창이 뜨고, 파노라마 load. type에 파노라마로 저장
   */
	void load_panorama();

private:

	Ui::SaveContents* ui;
	ContentsMenu* menu;
	string cfilepath;		//contents path
	string cname; 	//Contents nbame
	string cdate; //Contents date
	string cevent;	//Event nbame
	string cpeople;	//People name
	string cplace;	// place name
	string ccontent;	//Content
	string ctype;		//contents type
	bool cfc;		//fc list 포함 여부
};