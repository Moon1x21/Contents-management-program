#include "pch.h"
#include "ItemType.h"


bool ItemType::operator==(const ItemType& _item) {
	if (c_name == _item.c_name)
		return true;
	else
		return false;

}

// Compare two item types by item c_Dtime.
bool ItemType::operator>(const ItemType& _item) {
	if (c_Dtime > _item.GetDtime())
		return true;
	return false;
}

//	Compare two item types by item c_Dtime.
bool ItemType::operator<(const ItemType& _item) {
	if (c_Dtime < _item.GetDtime())
		return true;
	return false;
}

// Copy the item.
void ItemType::operator=(const ItemType& _item) {
	c_name = _item.c_name;
	c_Dtime = _item.c_Dtime;
	c_type = _item.c_type;
	c_people = _item.c_people;
	c_event = _item.c_event;
	c_place = _item.c_place;
	c_con = _item.c_con;
	view_point = _item.view_point;
	filepath = _item.filepath;
	fc = _item.fc;
}

// ���Ͽ��� �������� ID, �̸�, �����ڸ� �����´�.
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> c_name;
	fin >> c_Dtime;
	fin >> c_type;
	fin >> c_people;
	fin >> c_event;
	fin >> c_place;
	fin >> c_con;
	fin >> view_point;
	fin >> filepath;
	fin >> fc;

	return 1;
};

// ���Ͽ� �������� ID, �̸�, �����ڸ� �Է��Ѵ�.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << c_name << " ";
	fout << c_Dtime << " ";
	fout << c_type << " ";
	fout << c_people << " ";
	fout << c_event << " ";
	fout << c_place << " ";
	fout << c_con << " ";
	fout << view_point << " ";
	fout << filepath << " ";
	fout << fc << " ";

	return 1;
}



