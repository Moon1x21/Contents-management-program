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
   *	@brief	ContentsMenu�� ����ȭ��
   *	@pre	none
   *	@post	ContentsMenu�� ����ȭ��
   */
	void applyMenu(ContentsMenu* menu) { this->menu = menu; }


private slots:
	/**
   *	@brief	������ ������ ��
   *	@pre	click
   *	@post	������ ������ ����� �����.
   */
	void open_window();

	/**
   *	@brief	������ load
   *	@pre	click
   *	@post	������ �ε��ϴ� â�� �߰�, ���� load. type�� �������� ����
   */
	void load_pic();

	/**
   *	@brief	�������� load
   *	@pre	click
   *	@post	�������� �ε��ϴ� â�� �߰�, ������ load. type�� ���������� ����
   */
	void load_video();

	/**
   *	@brief	�ĳ�� load
   *	@pre	click
   *	@post	�ĳ�󸶸� �ε��ϴ� â�� �߰�, �ĳ�� load. type�� �ĳ�󸶷� ����
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
	bool cfc;		//fc list ���� ����
};