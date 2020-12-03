#include"Application.h"


//default constructor
Application::Application(QWidget* parent)
	: QDialog(parent),
	ui(new Ui::app)
{
	setWindowFlags(Qt::Window);
	ui->setupUi(this);
	ui->file_input_W->hide();
}

//destructor
Application::~Application()
{
	delete ui;
}

//즐겨찾기 리스트 메뉴 띄우기
void Application::open_fcList()
{
	FcMenu fc;
	fc.setModal(true);
	fc.applyApp(this);
	fc.exec();
}

//컨텐츠 관리(저장, 수정, 삭제) 메뉴 띄우기
void Application::contents_menu()
{
	ContentsMenu menu;
	menu.setModal(true);
	menu.applyApp(this);
	menu.exec();
}

//컨텐츠 찾기 메뉴 띄우기
void Application::find_contents()
{
	FindMenu find;
	find.setModal(true);
	find.applyApp(this);
	find.exec();
}

//Add new file path record into list
void Application::AddFilePath(string _cname, string _filepath)
{
	FileType data(_cname, _filepath);
	file_path.Add(data);	//FilePath List에 저장
}

//Delete the file path type in the filePath list
void Application::DeleteFilePath(string _cname)
{
	FileType data(_cname);
	file_path.Delete(data);	//FilePath List에서 해당하는 파일 타입 삭제
}

//Replace the file path in the filepath list
void Application::ReplaceFilePath(string _cname, string _filepath)
{
	FileType data(_cname, _filepath);
	file_path.Replace(data);	//FilePath List에 해당하는 파일 경로 변경
}

//	Add new Fc record into list
void Application::AddFcList(string type, string data)
{
	Key_List Fitem(type);
	if (FcList.Add(Fitem)) {
		FcList.Find(Fitem)->info.SetDes(type + " 타입의 즐겨찾기 리스트");
	}

	FcList.Find(Fitem)->info.GetList()->Add(data);	//해당하는 Key_List에 저장
}


//	Add new event record into list
void Application::AddEventlist(string _ename, string data)
{
	Key_List item(_ename);
	if (EList.Add(item)) {
		EList.Find(item)->info.SetDes(_ename);
	}
	EList.Find(item)->info.GetList()->Add(data);	//해당하는 Key_List에 저장
}

//	Add new people record into list
void Application::AddPeopleList(string _pname, string data)
{
	Key_List pitem(_pname);
	if (PeList.Add(pitem)) {
		PeList.Find(pitem)->info.SetDes(_pname + " 이 포함된 컨텐츠 리스트");
	}
	PeList.Find(pitem)->info.GetList()->Add(data);	//해당하는 Key_List에 저장
}

//	Add new place record into list
void Application::AddPlaceList(string _plname, string data)
{
	Key_List plitem(_plname);
	if (PlList.Add(plitem)) {
		PlList.Find(plitem)->info.SetDes(_plname + " 장소가 포함된 컨텐츠 리스트");
	}
	PlList.Find(plitem)->info.GetList()->Add(data);	//해당하는 Key_List에 저장
}


//	Delete the item in the Event list
int Application::DeleteEventType(string _ename, string data)
{
	Key_List eitem(_ename);
	DoubleNode<Key_List>* temp = EList.Find(eitem);	//Event의 Node pointer
	if (temp != nullptr) {
		temp->info.GetList()->Delete(data);	//데이터 삭제
		if (temp->info.GetList()->GetLength() == 0) {	//만약 EventList타입 안에 있는 list 길이가 0이면 Event삭제
			EList.Delete(eitem);
		}
		return 1;
	}
	return 0;
}

//	Delete the item in the people list
int Application::DeletePeopleType(string _pname, string data)
{
	Key_List pitem(_pname);
	DoubleNode<Key_List>* plist = PeList.Find(pitem);	//People의 Node pointer
	if (plist != nullptr) {
		plist->info.GetList()->Delete(data);	//데이터 삭제
		if (plist->info.GetList()->GetLength() == 0) {	//만약 안에 있는 list 길이가 0이면 삭제
			PeList.Delete(pitem);
		}
		return 1;
	}
	return 0;
}

//	Delete the item in the place list
int Application::DeletePlaceType(string _pname, string data)
{
	Key_List plitem(_pname);
	DoubleNode<Key_List>* plist = PlList.Find(plitem);	//Place의 Node pointer
	if (plist != nullptr) {
		plist->info.GetList()->Delete(data);	//데이터 삭제
		if (plist->info.GetList()->GetLength() == 0) {	//만약 안에 있는 list 길이가 0이면 삭제
			PlList.Delete(plitem);
		}
		return 1;
	}
	return 0;
}

//	Delete the item in the Fc list
int Application::DeleteFcType(string type, string name)
{
	Key_List data(type);
	DoubleNode<Key_List>* Flist = FcList.Find(data);	//Fc의 Node pointer
	if (Flist != nullptr) {
		Flist->info.GetList()->Delete(name);		//데이터 삭제
		if (Flist->info.GetList()->GetLength() == 0) {		//만약 안에 있는 list 길이가 0이면 삭제
			FcList.Delete(data);
		}
		return 1;
	}
	return 0;
}


// Find ItemType by contents name and display the record on the screen
bool Application::SearchByname(string name) {
	DoublyIterator<ItemType> iter(m_List);
	DoubleNode<ItemType>* node;
	bool found = false;		//컨텐츠 찾았는지 알려줌
	while (iter.NotNull()) {
		node = iter.GetCurNode();
		if (node->info.GetName() == name||found) {	//처음 돌때는 이름이 같을때, 컨텐츠를 찾은 후에는 found를 통해서 if문 안으로 들어감.
			found = true;	//컨텐츠 찾으면 true값
			node->info.PlusView();
			ShowDetail show;	//컨텐츠 디테일 보여주는 화면
			show.setModal(true);
			show.applyApp(this);	//application 동기화
			show.set(node->info);	//show화면에 컨텐츠 정보 세팅하기
			show.exec();
			if (node->info.GetView() > 20 && !node->info.GetFc()) {	//만약 viewpoint가 20이 넘고, 아직 fcList에 포함되어있지 않으면 fclist에 저장.
				node->info.changeFc();	//fclist 포함 유무 true로 바꿔줌.
				AddFcList(node->info.GetType(), node->info.GetName());	// Add Fc List
			}
			switch (show.Getnum())
			{
			case 0:	//메뉴로 돌아가기 버튼을 누르면 종류 
				return true;
				break;
			case 1:	//이전 버튼을 누르면 BACK NOT NULL일때만 이전 노드로 iterator 움직임
				if (iter.BackNotNull())
					iter.Back();
				else
					QMessageBox::information(this, "ERROR", "FIRST CONTENTS!!");	//BACK NULL이면 경고창 띄워줌
				break;
			case 2:	//다음 버튼을 누르면 NEXT NOT NULL일 때 다음 노드로  iterator 움직임
				if (iter.NextNotNull())
					iter.Next();
				else
					QMessageBox::information(this, "ERROR", "LAST CONTENTS!!");	//NEXT NULL이면 경고창 띄워줌
				break;
			default:
				break;
			}
		}
		else
			iter.Next();
	}
	//만약 컨텐츠를 찾기 못하면 false 리턴하기
	return false;
}

int Application::SearchByCnameAndDisplay(string name, DoublyIterator<string>& iter2)
{
	DoublyIterator<ItemType> iter(m_List);
	DoubleNode<ItemType>* node;
	while (iter.NotNull()) {
		node = iter.GetCurNode();
		if (node->info.GetName() == name) {
			node->info.PlusView();
			ShowDetail show;	//컨텐츠 디테일 보여주는 화면
			show.setModal(true);
			show.applyApp(this);	//application 동기화
			show.set(node->info);	//show화면에 컨텐츠 정보 세팅하기
			show.exec();
			if (node->info.GetView() > 20 && !node->info.GetFc()) {	//만약 viewpoint가 20이 넘고, 아직 fcList에 포함되어있지 않으면 fclist에 저장.
				node->info.changeFc();	//fclist 포함 유무 true로 바꿔줌.
				AddFcList(node->info.GetType(), node->info.GetName());	// Add Fc List
			}
			switch (show.Getnum())
			{
			case 0:	//메뉴로 돌아가기 버튼을 누르면 종류 
				return 0;
				break;
			case 1:	//이전 버튼을 누르면 BACK NOT NULL일때만 이전 노드로 iterator 움직임
				if (iter2.BackNotNull())
					iter2.Back();
				else
					QMessageBox::information(this, "ERROR", "FIRST CONTENTS!!");	//BACK NULL이면 경고창 띄워줌
				return 1;
				break;
			case 2:	//다음 버튼을 누르면 NEXT NOT NULL일 때 다음 노드로  iterator 움직임.
				if (iter2.NextNotNull())
					iter2.Next();
				else
					QMessageBox::information(this, "ERROR", "LAST CONTENTS!!");	//NEXT NULL이면 경고창 띄워줌
				return 1;
				break;
			default:
				break;
			}
		}
		else
			iter.Next();
	}
	return -1;
}

// 정보를 불러올 파일을 여는 함수
int Application::OpenInFile(char* fileName)
{
	m_InFile.open(fileName);	// 불러오기 위한 파일 열기

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// 정보를 저장할 파일을 여는 함수
int Application::OpenOutFile(char* fileName)
{
	m_OutFile.open(fileName);	// 저장하기 위한 파일 열기

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}

// 읽기 위한 파일을 열어 파일에 있는 모든 데이터를 불러오고 데이터들로 리스트를 만든다.
int Application::ReadDataFromFile()
{
	ItemType data;	// 읽기용 임시 변수
	QMessageBox::information(this, "ERROR", ui->file_name->text());
	string file = ui->file_name->text().toStdString();
	ui->file_name->setText("");
	char filename[FILENAMESIZE];
	strcpy(filename, file.c_str());
	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
	{
		QMessageBox::information(this, "ERROR", "FAIL TO OPEN FILE");
		return 0;
	}
		

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
		FileType input(data.GetName(), data.GetFile());
		file_path.Add(input);
	}

	m_InFile.close();	// 파일을 닫는다.
	QMessageBox::information(this, "SUCCESS", "READ FILE");

	return 1;
}


// 쓰기 위한 파일을 열어 리스트의 모든 정보들을 저장한다.
int Application::WriteDataToFile()
{
	ItemType data;	// 쓰기용 임시 변수
	string file = ui->file_name->text().toStdString();
	char filename[FILENAMESIZE];
	ui->file_name->setText("");
	strcpy(filename, file.c_str());
	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename)) {
		QMessageBox::information(this, "ERROR", "FAIL TO MAKE FILE");
		return 0;
	}

	if (m_List.GetLength() == 0) {
		QMessageBox::information(this, "ERROR", "LIST IS EMPTY");
		return 0;
	}
	// list의 모든 데이터를 파일에 쓰기
	DoublyIterator<ItemType> itor(m_List);
	while (itor.NotNull())
	{
		itor.GetCurNode()->info.WriteDataToFile(m_OutFile);
		itor.Next();
	}

	m_OutFile.close();	// 파일을 닫는다.
	QMessageBox::information(this, "SUCCESS", "MAKE FILE");
	return 1;
}


void Application::save_files()
{
	ui->file_input_W->show();
	write = true;
}

void Application::open_files()
{
	ui->file_input_W->show();
	write = false;
}

void Application::save_file_input()
{
	ui->file_input_W->hide();
	if (write)
		WriteDataToFile();
	else
		ReadDataFromFile();
}

void Application::delete_table()
{
	ui->tableWidget->clearContents();
	int row = ui->tableWidget->rowCount();
	while (row != 0) {
		row--;
		ui->tableWidget->removeRow(row);
	}
	DoublyIterator<FileType> iter(file_path);
	DoubleNode<FileType>* node = iter.GetCurNode();
	int num = 1;
	while (iter.NotNull()) {
		node = iter.GetCurNode();
		QString name = QString::fromStdString(node->info.GetName());
		ui->tableWidget->setRowCount(num);
		ui->tableWidget->setItem(num - 1, 0, new QTableWidgetItem(name));
		num++;
	}
}


void Application::add_table(string _cname) {
	QString name = QString::fromStdString(_cname);
	int num = m_List.GetLength();
	ui->tableWidget->setRowCount(num);
	ui->tableWidget->setItem(num-1,0,new QTableWidgetItem(name));
}

void Application::display_file()
{
	QString item = ui->tableWidget->currentItem()->text();
	string _cname = item.toStdString();
	DoublyIterator<FileType> iter(file_path);
	DoubleNode<FileType>* node = iter.GetCurNode();
	QString file;
	while (iter.NotNull()) {
		node = iter.GetCurNode();
		if (node->info.GetName() == _cname)
		{
			file = QString::fromStdString(node->info.GetFilePath());
			break;
		}
		else
			iter.Next();
	}
	QPixmap img;
	img.load(file);
	ui->label->setPixmap(img);
	ui->label->setScaledContents(true);
}

void  Application::display_record()
{
	QString item = ui->tableWidget->currentItem()->text();
	string _cname = item.toStdString();
	DoubleNode<ItemType>* node;
	QString file;
	ItemType contents(_cname);
	node = m_List.Find(contents);
	ShowDetail show;	//컨텐츠 디테일 보여주는 화면
	show.setModal(true);
	show.applyApp(this);	//application 동기화
	show.set(node->info);	//show화면에 컨텐츠 정보 세팅하기
	show.hide_button();
	show.exec();
	file = QString::fromStdString(node->info.GetFile());
	if (node->info.GetView() > 20 && !node->info.GetFc()) {	//만약 viewpoint가 20이 넘고, 아직 fcList에 포함되어있지 않으면 fclist에 저장.
		node->info.changeFc();	//fclist 포함 유무 true로 바꿔줌.
		AddFcList(node->info.GetType(), node->info.GetName());	// Add Fc List
	}
	QPixmap img;
	img.load(file);
	ui->label->setPixmap(img);
	ui->label->setScaledContents(true);
}
