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
   *	@brief	FcMenu를 동기화함
   *	@pre	none
   *	@post	FcMenu가 동기화됨
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
   *	@brief	type을 사진으로 저장
   *	@pre	click
   *	@post	타입이 사진으로 저장됨
   */
	void find_pic();

	/**
   *	@brief	type을 동영상으로 저장
   *	@pre	click
   *	@post	타입이 동영상으로 저장됨
   */
	void find_video();

	/**
   *	@brief	type을 파노라마으로 저장
   *	@pre	click
   *	@post	타입이 파노라마으로 저장됨
   */
	void find_panorama();

private:
	Ui::InputFcType* ui;
	FcMenu* fc;		///fcmenu 
	string type;			///type
};