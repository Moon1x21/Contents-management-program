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
	*	@brief	findmenu�� ����ȭ��
	*	@pre	none
    *	@post	FindMenu�� ����ȭ��
    */
	void applyFind(FindMenu* show) { this->show = show; }
	/**
   *	@brief	ContentsMenu�� ����ȭ��
   *	@pre	none
   *	@post	ContentsMenu�� ����ȭ��
   */
	void applyMenu(ContentsMenu* menu) { this->menu = menu; }

	/**
   *	@brief	FcMenu�� ����ȭ��
   *	@pre	none
   *	@post	FcMenu�� ����ȭ��
   */
	void applyFc(FcMenu* fc) { this->fc = fc; }
public slots:

	/**
   *	@brief	�������� Ű���带 �Է¹���
   *	@pre	none
   *	@post	�������� Ű���带 �Է¹ް� â�� ����
   *	@return	�Է��� ������ Ű����
   */
	string find_show();
private:
	Ui::InputWindow* ui;
	FindMenu* show;	//findmenu
	ContentsMenu* menu;	//contents menu
	FcMenu* fc;	//fcmenu 
};
