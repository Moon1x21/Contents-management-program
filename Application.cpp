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

//���ã�� ����Ʈ �޴� ����
void Application::open_fcList()
{
	FcMenu fc;
	fc.setModal(true);
	fc.applyApp(this);
	fc.exec();
}

//������ ����(����, ����, ����) �޴� ����
void Application::contents_menu()
{
	ContentsMenu menu;
	menu.setModal(true);
	menu.applyApp(this);
	menu.exec();
}

//������ ã�� �޴� ����
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
	file_path.Add(data);	//FilePath List�� ����
}

//Delete the file path type in the filePath list
void Application::DeleteFilePath(string _cname)
{
	FileType data(_cname);
	file_path.Delete(data);	//FilePath List���� �ش��ϴ� ���� Ÿ�� ����
}

//Replace the file path in the filepath list
void Application::ReplaceFilePath(string _cname, string _filepath)
{
	FileType data(_cname, _filepath);
	file_path.Replace(data);	//FilePath List�� �ش��ϴ� ���� ��� ����
}

//	Add new Fc record into list
void Application::AddFcList(string type, string data)
{
	Key_List Fitem(type);
	if (FcList.Add(Fitem)) {
		FcList.Find(Fitem)->info.SetDes(type + " Ÿ���� ���ã�� ����Ʈ");
	}

	FcList.Find(Fitem)->info.GetList()->Add(data);	//�ش��ϴ� Key_List�� ����
}


//	Add new event record into list
void Application::AddEventlist(string _ename, string data)
{
	Key_List item(_ename);
	if (EList.Add(item)) {
		EList.Find(item)->info.SetDes(_ename);
	}
	EList.Find(item)->info.GetList()->Add(data);	//�ش��ϴ� Key_List�� ����
}

//	Add new people record into list
void Application::AddPeopleList(string _pname, string data)
{
	Key_List pitem(_pname);
	if (PeList.Add(pitem)) {
		PeList.Find(pitem)->info.SetDes(_pname + " �� ���Ե� ������ ����Ʈ");
	}
	PeList.Find(pitem)->info.GetList()->Add(data);	//�ش��ϴ� Key_List�� ����
}

//	Add new place record into list
void Application::AddPlaceList(string _plname, string data)
{
	Key_List plitem(_plname);
	if (PlList.Add(plitem)) {
		PlList.Find(plitem)->info.SetDes(_plname + " ��Ұ� ���Ե� ������ ����Ʈ");
	}
	PlList.Find(plitem)->info.GetList()->Add(data);	//�ش��ϴ� Key_List�� ����
}


//	Delete the item in the Event list
int Application::DeleteEventType(string _ename, string data)
{
	Key_List eitem(_ename);
	DoubleNode<Key_List>* temp = EList.Find(eitem);	//Event�� Node pointer
	if (temp != nullptr) {
		temp->info.GetList()->Delete(data);	//������ ����
		if (temp->info.GetList()->GetLength() == 0) {	//���� EventListŸ�� �ȿ� �ִ� list ���̰� 0�̸� Event����
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
	DoubleNode<Key_List>* plist = PeList.Find(pitem);	//People�� Node pointer
	if (plist != nullptr) {
		plist->info.GetList()->Delete(data);	//������ ����
		if (plist->info.GetList()->GetLength() == 0) {	//���� �ȿ� �ִ� list ���̰� 0�̸� ����
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
	DoubleNode<Key_List>* plist = PlList.Find(plitem);	//Place�� Node pointer
	if (plist != nullptr) {
		plist->info.GetList()->Delete(data);	//������ ����
		if (plist->info.GetList()->GetLength() == 0) {	//���� �ȿ� �ִ� list ���̰� 0�̸� ����
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
	DoubleNode<Key_List>* Flist = FcList.Find(data);	//Fc�� Node pointer
	if (Flist != nullptr) {
		Flist->info.GetList()->Delete(name);		//������ ����
		if (Flist->info.GetList()->GetLength() == 0) {		//���� �ȿ� �ִ� list ���̰� 0�̸� ����
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
	bool found = false;		//������ ã�Ҵ��� �˷���
	while (iter.NotNull()) {
		node = iter.GetCurNode();
		if (node->info.GetName() == name||found) {	//ó�� ������ �̸��� ������, �������� ã�� �Ŀ��� found�� ���ؼ� if�� ������ ��.
			found = true;	//������ ã���� true��
			node->info.PlusView();
			ShowDetail show;	//������ ������ �����ִ� ȭ��
			show.setModal(true);
			show.applyApp(this);	//application ����ȭ
			show.set(node->info);	//showȭ�鿡 ������ ���� �����ϱ�
			show.exec();
			if (node->info.GetView() > 20 && !node->info.GetFc()) {	//���� viewpoint�� 20�� �Ѱ�, ���� fcList�� ���ԵǾ����� ������ fclist�� ����.
				node->info.changeFc();	//fclist ���� ���� true�� �ٲ���.
				AddFcList(node->info.GetType(), node->info.GetName());	// Add Fc List
			}
			switch (show.Getnum())
			{
			case 0:	//�޴��� ���ư��� ��ư�� ������ ���� 
				return true;
				break;
			case 1:	//���� ��ư�� ������ BACK NOT NULL�϶��� ���� ���� iterator ������
				if (iter.BackNotNull())
					iter.Back();
				else
					QMessageBox::information(this, "ERROR", "FIRST CONTENTS!!");	//BACK NULL�̸� ���â �����
				break;
			case 2:	//���� ��ư�� ������ NEXT NOT NULL�� �� ���� ����  iterator ������
				if (iter.NextNotNull())
					iter.Next();
				else
					QMessageBox::information(this, "ERROR", "LAST CONTENTS!!");	//NEXT NULL�̸� ���â �����
				break;
			default:
				break;
			}
		}
		else
			iter.Next();
	}
	//���� �������� ã�� ���ϸ� false �����ϱ�
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
			ShowDetail show;	//������ ������ �����ִ� ȭ��
			show.setModal(true);
			show.applyApp(this);	//application ����ȭ
			show.set(node->info);	//showȭ�鿡 ������ ���� �����ϱ�
			show.exec();
			if (node->info.GetView() > 20 && !node->info.GetFc()) {	//���� viewpoint�� 20�� �Ѱ�, ���� fcList�� ���ԵǾ����� ������ fclist�� ����.
				node->info.changeFc();	//fclist ���� ���� true�� �ٲ���.
				AddFcList(node->info.GetType(), node->info.GetName());	// Add Fc List
			}
			switch (show.Getnum())
			{
			case 0:	//�޴��� ���ư��� ��ư�� ������ ���� 
				return 0;
				break;
			case 1:	//���� ��ư�� ������ BACK NOT NULL�϶��� ���� ���� iterator ������
				if (iter2.BackNotNull())
					iter2.Back();
				else
					QMessageBox::information(this, "ERROR", "FIRST CONTENTS!!");	//BACK NULL�̸� ���â �����
				return 1;
				break;
			case 2:	//���� ��ư�� ������ NEXT NOT NULL�� �� ���� ����  iterator ������.
				if (iter2.NextNotNull())
					iter2.Next();
				else
					QMessageBox::information(this, "ERROR", "LAST CONTENTS!!");	//NEXT NULL�̸� ���â �����
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

// ������ �ҷ��� ������ ���� �Լ�
int Application::OpenInFile(char* fileName)
{
	m_InFile.open(fileName);	// �ҷ����� ���� ���� ����

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// ������ ������ ������ ���� �Լ�
int Application::OpenOutFile(char* fileName)
{
	m_OutFile.open(fileName);	// �����ϱ� ���� ���� ����

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}

// �б� ���� ������ ���� ���Ͽ� �ִ� ��� �����͸� �ҷ����� �����͵�� ����Ʈ�� �����.
int Application::ReadDataFromFile()
{
	ItemType data;	// �б�� �ӽ� ����
	QMessageBox::information(this, "ERROR", ui->file_name->text());
	string file = ui->file_name->text().toStdString();
	ui->file_name->setText("");
	char filename[FILENAMESIZE];
	strcpy(filename, file.c_str());
	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
	{
		QMessageBox::information(this, "ERROR", "FAIL TO OPEN FILE");
		return 0;
	}
		

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
		FileType input(data.GetName(), data.GetFile());
		file_path.Add(input);
	}

	m_InFile.close();	// ������ �ݴ´�.
	QMessageBox::information(this, "SUCCESS", "READ FILE");

	return 1;
}


// ���� ���� ������ ���� ����Ʈ�� ��� �������� �����Ѵ�.
int Application::WriteDataToFile()
{
	ItemType data;	// ����� �ӽ� ����
	string file = ui->file_name->text().toStdString();
	char filename[FILENAMESIZE];
	ui->file_name->setText("");
	strcpy(filename, file.c_str());
	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename)) {
		QMessageBox::information(this, "ERROR", "FAIL TO MAKE FILE");
		return 0;
	}

	if (m_List.GetLength() == 0) {
		QMessageBox::information(this, "ERROR", "LIST IS EMPTY");
		return 0;
	}
	// list�� ��� �����͸� ���Ͽ� ����
	DoublyIterator<ItemType> itor(m_List);
	while (itor.NotNull())
	{
		itor.GetCurNode()->info.WriteDataToFile(m_OutFile);
		itor.Next();
	}

	m_OutFile.close();	// ������ �ݴ´�.
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
	ShowDetail show;	//������ ������ �����ִ� ȭ��
	show.setModal(true);
	show.applyApp(this);	//application ����ȭ
	show.set(node->info);	//showȭ�鿡 ������ ���� �����ϱ�
	show.hide_button();
	show.exec();
	file = QString::fromStdString(node->info.GetFile());
	if (node->info.GetView() > 20 && !node->info.GetFc()) {	//���� viewpoint�� 20�� �Ѱ�, ���� fcList�� ���ԵǾ����� ������ fclist�� ����.
		node->info.changeFc();	//fclist ���� ���� true�� �ٲ���.
		AddFcList(node->info.GetType(), node->info.GetName());	// Add Fc List
	}
	QPixmap img;
	img.load(file);
	ui->label->setPixmap(img);
	ui->label->setScaledContents(true);
}