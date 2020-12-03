#pragma once
#include <QDialog>
#include "pch.h"
#include "ui_Application.h"

using namespace std;

namespace Ui {
	class app;
}

class Application : public QDialog
{
	friend class ShowDetail;
	friend class ContentsMenu;
	friend class FindMenu;
	friend class FcMenu;
	friend class MyfileMenu;

	Q_OBJECT

public:
	/**
	*	default constructor
	*/
	Application(QWidget* parent = 0);
	/**
	*	destructor
	*/
	~Application();

	void applyDetail(ShowDetail* show) { this->show = show; }

	/**
	*	@brief	Add new file path record into list
	*	@pre	list should be initialized
	*	@post	new Fc record is added into the list
	*	@param	num	contents Type for add
	*	@param	_cname	contents name
	*	@param	_filepath	contents file path
	*/
	void AddFilePath(string _cname, string _filepath);

	/**
	*	@brief	Delete the file path type in the filePath list
	*	@pre	the  file path is in the  file path list
	*	@post	delete the  file path in the  file path list
	*	@param	_cname	contents name  for delete
	*/
	void DeleteFilePath(string _cname);

	/**
	*	@brief	Replace the file path in the filepath list
	*	@pre	the  file path is in the Event list
	*	@post	Replace the file path in the Event list
	*	@param	_cname	contents name for delete
	*	@param	_filepath	file path name  for delete
	*/
	void ReplaceFilePath(string _cname, string _filepath);

	/**
	*	@brief	Add new Fc record into list
	*	@pre	list should be initialized
	*	@post	new Fc record is added into the list
	*	@param	type	contents Type for add
	*	@param	data	contents name
	*/
	void AddFcList(string type, string data);
	/**
	*	@brief	Add new event record into list
	*	@pre	list should be initialized
	*	@post	new event record is added into the list
	*	@param	_ename	event name for add
	*	@param	data	contents name
	*/
	void AddEventlist(string _ename, string data);

	/**
	*	@brief	Add new people record into list
	*	@pre	list should be initialized
	*	@post	new people record is added into the list
	*	@param	_pname	people name for add
	*	@param	data	contents name
	*/
	void AddPeopleList(string _pname, string data);

	/**
	*	@brief	Add new place record into list
	*	@pre	list should be initialized
	*	@post	new place record is added into the list
	*	@param	_plname	place name for add
	*	@param	data	contents name
	*/
	void AddPlaceList(string _plname, string data);


	/**
	*	@brief	Add new file record into list
	*	@pre	list should be initialized
	*	@post	new file record is added into the list
	*	@param	_fname	file name for add
	*	@param	data	contents name
	*/
	void AddMyList(string _fname, string data);

	/**
	*	@brief	Delete the item in the Event list
	*	@pre	the item is in the Event list
	*	@post	delete the item in the Event list
	*	@param	_ename	event name for delete
	*	@param	data	contents name  for delete
	*	@return	return 1 if this function is works well, otherwise return 0
	*/
	int DeleteEventType(string _ename, string data);

	/**
	*	@brief	Delete the item in the people list
	*	@pre	the item is in the people list
	*	@post	delete the item in the people list
	*	@param	_pname	people name  for delete
	*	@param	data	contents name  for delete
	*	@return	return 1 if this function is works well, otherwise return 0
	*/
	int DeletePeopleType(string _pname, string data);

	/**
	*	@brief	Delete the item in the place list
	*	@pre	the item is in the place list
	*	@post	delete the item in the place list
	*	@param	_pname	place name  for delete
	*	@param	data	contents name  for delete
	*	@return	return 1 if this function is works well, otherwise return 0
	*/
	int DeletePlaceType(string _pname, string data);

	/**
	*	@brief	Delete the item in the MyFile list
	*	@pre	the item is in the MyFile list
	*	@post	delete the item in the MyFile list
	*	@param	_filename	MyFile name for delete
	*	@param	_cname	contents name  for delete
	*	@return	return 1 if this function is works well, otherwise return 0
	*/
	int DeleteMyFileType(string _filename, string name);

	/**
	*	@brief	Delete the item in the list
	*	@pre	the item is in the list
	*	@post	delete the item in the list
	*	@param	type	type name  for delete
	*	@param	name	contents name  for delete
	*	@return	return 1 if this function is works well, otherwise return 0
	*/
	int DeleteFcType(string type, string name);

	/**
	*	@brief	Search the contents and display
	*	@pre	none
	*	@post	serach master contents and display the record
	*	@param	cname	contents name  for delete
	*	@return	return true if this function is works well, otherwise return false
	*/
	bool SearchByname(string cname);

	/**
	*	@brief	Search the contents and display
	*	@pre	none
	*	@post	serach master contents and display the record
	*	@param	cname	contents name  search
	*	@param	iter2	keylist iterator
	*	@return	return 1 if this function is works well, otherwise return 0
	*/
	int SearchByCnameAndDisplay(string cname,DoublyIterator<string>& iter2);

	/**
	*	@brief	정보를 불러올 파일을 파일 디스크립트를 이용해 연다.
	*	@pre	정보를 불러올 파일이 존재해야한다.
	*	@post	읽기 위한 파일을 연다.
	*	@param	fileName	정보를 불러오기 위해 여는 파일의 이름.
	*	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int OpenInFile(char* fileName);

	/**
	*	@brief	정보를 저장할 파일을 파일 디스크립트를 이용해 연다.
	*	@pre	리스트가 초기화되어있어야 한다.
	*	@post	쓰기 위한 파일을 연다.
	*	@param	fileName	정보를 쓰기 위해 여는 파일의 이름.
	*	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int OpenOutFile(char* fileName);

	/**
	*	@brief	읽기 위한 파일을 열어 파일에 있는 모든 데이터를 불러오고 데이터들로 리스트를 만든다.
	*	@pre	파일이 열려있지 않다.
	*	@post	리스트에 파일의 모든 아이템 정보들을 넣는다.
	*	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	O쓰기 위한 파일을 열어 리스트의 모든 정보들을 저장한다.
	*	@pre	파일이 열려있지 않다.
	*	@post	저장하는 파일에 리스트가 저장된다.
	*	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int WriteDataToFile();


private slots:
	/**
	*	@brief	즐겨찾기 리스트 메뉴 띄우기
	*	@pre	버튼 클릭하기
	*	@post	즐겨찾기 리스트 메뉴가 화면에 띄워짐
	*/
	void open_fcList();

	/**
	*	@brief	컨텐츠 관리(저장, 수정, 삭제) 메뉴 띄우기
	*	@pre	버튼 클릭하기
	*	@post	컨텐츠 관리 메뉴가 화면에 띄워짐
	*/
	void contents_menu();

	/**
	*	@brief	컨텐츠 찾기 메뉴 띄우기
	*	@pre	버튼 클릭하기
	*	@post	컨텐츠 찾기 메뉴가 화면에 띄워짐
	*/
	void find_contents();

	/**
	*	@brief	컨텐츠 리스트 정보들 파일로 저장하기
	*	@pre	버튼 클릭하기
	*	@post	컨텐츠 리스트 정보들 파일로 저장됨
	*/
	void save_files();

	/**
	*	@brief	컨텐츠 리스트 파일에서 리스트 저장하기
	*	@pre	버튼 클릭하기
	*	@post	컨텐츠 리스트 파일에서 불러온 정보들이 리스트에 저장됨
	*/
	void open_files();

	/**
	*	@brief	파일이름 받기
	*	@pre	버튼 클릭하기
	*	@post	저장 혹은 불러올 파일 이름 받아옴
	*	@return	파일 이름
	*/
	void save_file_input();

	void delete_table();

	void add_table(string _cname);

	void display_file();

	void display_record();
private:

	Ui::app* ui;
	ShowDetail* show;
	ContentsMenu* menu;
	QLabel* label;
	DoubleLinkedList<ItemType> m_List;			///< master Contents list
	DoubleLinkedList<Key_List>EList;		///< eventtype List
	DoubleLinkedList<Key_List>PeList;			///< PeopleType List
	DoubleLinkedList<Key_List>PlList;			///<PlaceType List
	DoubleLinkedList<Key_List>FcList;			///<FcType List
	DoubleLinkedList<FileType>file_path;		///<FilePath List 
	ifstream m_InFile;		///< 입력 파일 디스크립터.
	ofstream m_OutFile;		///< 출력 파일 디스크립터.
	bool write;
};
