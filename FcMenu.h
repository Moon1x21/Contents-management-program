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
	*	@brief	Application�� ����ȭ��
	*	@pre	none
    *	@post	Application�� ����ȭ��
    */
	void applyApp(Application* app) { this->app = app; }

public slots:

	/**
   *	@brief	���ã�� ����Ʈ�� ������ ������ �̸��� �Է¹ް�, ����
   *	@pre	none
   *	@post	���ã�� ����Ʈ�� ������ ������ �̸��� �Է¹ް�, ���ã�� ����Ʈ�� ����
   */
	void add_fc();

	/**
   *	@brief	���ã�� ����Ʈ���� ������ ������ �̸��� �Է¹ް�, ����
   *	@pre	none
   *	@post	���ã�� ����Ʈ���� ������ ������ �̸��� �Է¹ް�, ���ã�� ����Ʈ�� ����
   */
	void delete_fc();

	/**
   *	@brief	���ã�� ����Ʈ���� Ÿ�Ժ� ������ �������� ����
   *	@pre	none
   *	@post	Ÿ���� �����ϰ�, �ش� Ÿ�� ����Ʈ�� �ִ� ���������� ������ ������ ȭ�鿡 ���
   */
	void view_fc();

	/**
   *	@brief	���ã�� ����Ʈ���� Ÿ�Ժ� ������ ������ ����
   *	@pre	none
   *	@post	Ÿ���� �����ϰ�, �ش� Ÿ�� ����Ʈ�� �ִ� ���������� ���� ������ ȭ�鿡 ���
   */
	void view_fc_mc();


private:
	Ui::FcMenu* ui;
	Application* app;	//application
	int num;	//Ÿ�� ����
};
