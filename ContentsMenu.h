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
   *	@brief	Application�� ����ȭ��
   *	@pre	none
   *	@post	Application�� ����ȭ��
   */
	void applyApp(Application* app) { this->app = app; }
public slots:

	/**
   *	@brief	������ �����ϱ�
   *	@pre	click
   *	@post	������ ����ȭ���� �������, ������ ����.
   */
	void add_contents();

	/**
   *	@brief	������ �����ϱ�
   *	@pre	click
   *	@post	������ �̸��� ���� ȭ���� �������, �ش��ϴ� ������ ����.
   *	@return	�����Ǹ� 1, �ƴϸ� 0
   */
	int delete_contents();

	/**
   *	@brief	������ �����ϱ�
   *	@pre	click
   *	@post	������ �̸��� ���� ȭ���� �������, �ش��ϴ� ������ ����.
   *	@return	�����Ǹ� 1, �ƴϸ� 0
   */
	int replace_contents();

private:
	Ui::ContentsMenu* ui;
	Application* app;	//Application
};
