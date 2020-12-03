#pragma once
#include "pch.h"
#include <QDialog>
#include "ui_FcMenu.h"

namespace Ui {
	class FcMenu;
}

class FcMenu :public QDialog
{
	friend class Application;
	Q_OBJECT

public:
	/**
	*	default constructor
	*/
	FcMenu(QWidget* parent = 0);

	/**
	*	destructor
	*/
	~FcMenu();

	 /**
	*	@brief	Application를 동기화함
	*	@pre	none
    *	@post	Application가 동기화됨
    */
	void applyApp(Application* app) { this->app = app; }

public slots:

	/**
   *	@brief	즐겨찾기 리스트에 저장할 컨텐츠 이름을 입력받고, 저장
   *	@pre	none
   *	@post	즐겨찾기 리스트에 저장할 컨텐츠 이름을 입력받고, 즐겨찾기 리스트에 저장
   */
	void add_fc();

	/**
   *	@brief	즐겨찾기 리스트에서 삭제할 컨텐츠 이름을 입력받고, 저장
   *	@pre	none
   *	@post	즐겨찾기 리스트에서 삭제할 컨텐츠 이름을 입력받고, 즐겨찾기 리스트에 저장
   */
	void delete_fc();

	/**
   *	@brief	즐겨찾기 리스트에서 타입별 컨텐츠 간단정보 보기
   *	@pre	none
   *	@post	타입을 선택하고, 해당 타입 리스트에 있는 컨텐츠들의 간단한 정보를 화면에 띄움
   */
	void view_fc();

	/**
   *	@brief	즐겨찾기 리스트에서 타입별 컨텐츠 상세정보 보기
   *	@pre	none
   *	@post	타입을 선택하고, 해당 타입 리스트에 있는 컨텐츠들의 상세한 정보를 화면에 띄움
   */
	void view_fc_mc();


private:
	Ui::FcMenu* ui;
	Application* app;	//application
	int num;	//타입 종류
};
