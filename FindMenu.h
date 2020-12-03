#pragma once
#include "pch.h"
#include <QDialog>
#include "ui_FindMenu.h"
#include <QMessageBox>

namespace Ui {
	class FindMenu;
}

class FindMenu:public QDialog
{
	friend class SaveContents;
	friend class Application;
	friend class ShowDetail;
	friend class InputWindow;

	Q_OBJECT
public:
	/**
   *	default constructor
   */
	FindMenu(QWidget* parent = 0);

	/**
	*	destructor
	*/
	~FindMenu();

	/**
   *	@brief	Application�� ����ȭ��
   *	@pre	none
   *	@post	Application�� ����ȭ��
   */
	void applyApp(Application* app) { this->app = app; }


private slots:

	/**
   *	@brief	�������� �̸��� ���� ������ ������ ����
   *	@pre	��ư Ŭ��
   *	@post	������ �̸� �Է¹޴� ȭ���� ����, �ش� �̸��� ���� �������� �� ����� ȭ�鿡 ���
   */
	void Find_contents();

	/**
   *	@brief	�������� ���Ե� ����� ���� ������ ������ ����
   *	@pre	��ư Ŭ��
   *	@post	������ ����� �Է¹޴� ȭ���� ����, �ش��ϴ� ����Ʈ�� ���������� �� ����� ȭ�鿡 ���
   */
	void Find_People();

	/**
   *	@brief	�������� ���Ե� ��Ҹ� ���� ������ ������ ����
   *	@pre	��ư Ŭ��
   *	@post	������ ��Ҹ� �Է¹޴� ȭ���� ����, �ش��ϴ� ����Ʈ�� ���������� �� ����� ȭ�鿡 ���
   */
	void Find_Place();

	/**
   *	@brief	������ Ű���带 ���ؼ� �ش��ϴ� �������� ������ ����
   *	@pre	��ư Ŭ��
   *	@post	������ Ű������� �Է¹޴� ȭ���� ����, �ش��ϴ� ����Ʈ�� ���������� �� ����� ȭ�鿡 ���
   */
	void Find_KeyWord();

	/**
   *	@brief	�������� �̺�Ʈ�� ���� ������ ������ ����
   *	@pre	��ư Ŭ��
   *	@post	������ �̺�Ʈ�� �Է¹޴� ȭ���� ����, �ش��ϴ� ����Ʈ�� ���������� �� ����� ȭ�鿡 ���
   */
	void Find_Event();

	void find_Key();
private:
	Ui::FindMenu* ui;
	ShowDetail* show;		//������ ����
	Application* app;	//application
	InputWindow* input;	//������ �̸� �Է�

};
