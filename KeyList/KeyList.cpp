#include "pch.h"
#include "KeyList.h"

//	Add new master contents into event list
int Key_List::AddKeyList(string data)
{
	if (keylist->IsFull()) {
		return 0;
	}

	if (keylist->Add(data)) {
		return 1;
	}

	return 0;
}

//	Find the data and delete the data record in the list
int Key_List::DeleteKeyList(string& data)
{
	int pre = keylist->GetLength();//이전 item개수를 받아온다.

	keylist->Delete(data);

	if (pre > keylist->GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
		return 1;

	return 0;
}

//	Find the item int the list
int Key_List::RetrieveKeyList(string& data)
{
	if (keylist->Get(data)) {
		return 1;
	}
	return 0;
}

//	Copy the item.
bool Key_List::operator==(const Key_List& _item) {
	if (keyname == _item.GetKeyname())
		return true;
	else
		return false;
}

//	Compare two item types by item e_name.
bool Key_List::operator>(const Key_List& _item) {
	if (keyname > _item.GetKeyname())
		return true;
	else
		return false;
}

//	Compare two item types by item e_name.
bool Key_List::operator<(const Key_List& _item) {
	if (keyname < _item.GetKeyname())
		return true;
	else
		return false;
}

//	Copy the item types
void Key_List::operator =(Key_List& _item) {
	this->keyname = _item.keyname;
	this->key_description = _item.key_description;
	keylist = _item.GetList();
}



