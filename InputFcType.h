#pragma once
#include "pch.h"
#include <QDialog>
#include "ui_InputFcType.h"

namespace Ui {
	class InputFcType;
}

class InputFcType :public QDialog
{
	Q_OBJECT

public:
	/**
	*	default constructor
	*/
	InputFcType(QWidget* parent = 0);

	/**
	*	destructor
	*/
	~InputFcType();

	/**
   *	@brief	FcMenu�� ����ȭ��
   *	@pre	none
   *	@post	FcMenu�� ����ȭ��
   */
	void applyFc(FcMenu* fc) { this->fc = fc; }

	/**
	*	@brief	Get contents type
	*	@pre	Contents type is set
	*	@post	none
	*	@return	Contents type
	*/
	string GetType() { return type; }
public slots:

	/**
   *	@brief	type�� �������� ����
   *	@pre	click
   *	@post	Ÿ���� �������� �����
   */
	void find_pic();

	/**
   *	@brief	type�� ���������� ����
   *	@pre	click
   *	@post	Ÿ���� ���������� �����
   */
	void find_video();

	/**
   *	@brief	type�� �ĳ������ ����
   *	@pre	click
   *	@post	Ÿ���� �ĳ������ �����
   */
	void find_panorama();

private:
	Ui::InputFcType* ui;
	FcMenu* fc;		///fcmenu 
	string type;			///type
};