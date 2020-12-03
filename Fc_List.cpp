#include "pch.h"
#include "Fc_List.h"


//	Add new contents into key list
int Fc_list::AddPlist(FileType inData)
{
	if (Flist->IsFull())
	{
		//cout << "\t List is FULL" << endl;
		return 0;
	}

	Flist->Add(inData);
	return 1;
}

//	Find the data and delete the data record in the list
int Fc_list::DeletePlist(FileType& data)
{
	int pre = Flist->GetLength();//���� item������ �޾ƿ´�.

	Flist->Delete(data);

	if (pre > Flist->GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		return 1;
	}
	return 0;
}

//	Compare two item types by item Pname
bool Fc_list::operator==(const Fc_list& _item) {
	if (Fcname == _item.Getname())
		return true;
	return false;
}

//	Compare two item types by item Pname
bool Fc_list::operator>(const Fc_list& _item) {
	if (Fcname > _item.Getname())
		return true;
	return false;
}

//	Compare two item types by item Pname
bool Fc_list::operator<(const Fc_list& _item) {
	if (Fcname < _item.Getname())
		return true;
	return false;
}

//	Copy the item types
void Fc_list::operator =(Fc_list& _item) {
	this->Fcname = _item.Fcname;
	this->Flist = _item.GetList();
	this->Description = _item.Description;
}
