#pragma once
#include"pch.h"


template<typename T>
struct DoubleNode;

template<typename T>
class DoublyIterator;

template<typename T>
class DoubleLinkedList {
	friend class DoublyIterator<T>;
public:
	/**
	*	default constructor.
	*/
	DoubleLinkedList();

	/**
	*	destructor.
	*/
	~DoubleLinkedList() {
		MakeEmpty();
	}

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T& item);

	/**
	*	@brief	Delete item into this list by the keys
	*	@pre	List has been initialized.
	*	@post	Item is deleted in this list..
	*	@param	data	primary key가 반드시 포함되어 있는 ItemType 객체.
	*	@return 삭제할 일치하는 데이터가 있으면 삭제 후 1, 없으면 0을 리턴.
	*/
	int Delete(T& item);

	/**
	*	@brief	Replace item into this list by the keys
	*	@pre	List has been initialized.
	*	@post	Item is replaced in this list.
	*	@param	data	primary key가 반드시 포함되어 있는 ItemType 객체.
	*/
	int Replace(T& item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Determines whether the list is full.
	*	@pre	List has been initialized.
	*	@post	None.
	*	@return	If there is not memory left, throws bad_alloc exception and return true, otherwise false.
	*/
	bool IsFull();

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	Double node type.
	*/
	DoubleNode<T>* Find(T& data);
private:
	int m_length;
	DoubleNode<T>* m_pFirst;
	DoubleNode<T>* m_pLast;

};


template<typename T>
struct DoubleNode {
	T info;
	DoubleNode<T>* next;
	DoubleNode<T>* back;
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_length = 0;
	m_pFirst = nullptr;
	m_pLast = nullptr;
}

//Determines whether the list is full.
template<typename T>
bool DoubleLinkedList<T>::IsFull() {
	try {
		DoubleNode<T>* temp = nullptr;	// if there is not memory left, temp would not be initialized as NULL and
		delete temp;					// deleting temp(pointer) could not be executed.
		return false;
	}
	catch (bad_alloc& e_ba) {
		//cerr << "bad_alloc exception caught : " << e_ba.what() << endl;
		return true;
	}
}

//Initialize list to empty state.
template<typename T>
void DoubleLinkedList<T>::MakeEmpty() {
	DoublyIterator<T> itor(*this);
	DoubleNode<T>* temp;

	while (itor.NotNull()) {
		temp = itor.m_CurPointer;
		itor.Next();
		delete temp;
	}
	m_length = 0;
}

//Get number of elements in the list.
template<typename T>
int DoubleLinkedList<T>::GetLength() const
{
	return m_length;
}

//Add item into this list.
template<typename T>
int DoubleLinkedList<T>::Add(T& item)
{
	if (!IsFull()) {

		DoubleNode<T>* data;
		data = new DoubleNode<T>;
		DoublyIterator<T> iter(*this);

		data->info = item;
		data->next = nullptr;
		data->back = nullptr;

		if (m_length == 0) {
			m_pFirst = data;
			m_pLast = m_pFirst;
		}
		else {
			DoubleNode<T>* temp;
			while (iter.NotNull())
			{
				temp = iter.m_CurPointer;

				if (data->info < temp->info) {
					data->next = temp;
					if (temp->back ==nullptr) {
						m_pFirst = data;
					}
					else {
						data->back = temp->back;
						temp->back->next = data;
					}
					temp->back = data;
					break;
				}
				else if (data->info == temp->info) {
					return 0;
				}
				else {
					if (!iter.NextNotNull()) { //맨뒤
						temp->next = data;
						data->back = temp;
						m_pLast = data;
						break;
					}
					else {
						iter.Next();
					}
				}
			}
		}
		m_length++;
		return 1;
	}
	else
		return 0;
}

//Delete item into this list by the keys
template<typename T>
int DoubleLinkedList<T>::Delete(T& item)
{
	DoublyIterator<T> itor(*this);
	DoubleNode<T>* temp;
	while (itor.NotNull()) {
		temp = itor.GetCurNode();
		if (itor.GetCurNode()->info == item) {
			if (temp->next != nullptr) {
				temp->next->back = temp->back;
			}
			else m_pLast = temp->back;
			if (temp->back != nullptr) {
				temp->back->next = temp->next;
			}
			else m_pFirst = temp->next;
			delete temp;
			m_length--;
			return 1;
		}
		else {
			itor.Next();
		}
	}
	return 0;
}

//Replace item into this list by the keys
template<typename T>
int DoubleLinkedList<T>::Replace(T& item)
{
	DoublyIterator<T> itor(*this);

	while (itor.NotNull()) {
		if (item == itor.m_CurPointer->info) {
			itor.m_CurPointer->info = item;
			return 1;
		}
		else if (item < itor.GetCurNode()->info) {
			return 0;
		}
		else {
			itor.Next();
		}
	}
	return 0;
}

template<typename T>
int DoubleLinkedList<T>::Get(T& item)
{
	DoublyIterator<T> itor(*this);
	int count = 0;
	bool found = false;
	while (itor.NotNull()) {
		count++;
		if (item == itor.m_CurPointer->info) {
			item = itor.m_CurPointer->info;
			found = true;
			break;
		}
		else {
			itor.Next();
		}
	}
	if (found) {
		return count;
	}
	else return 0;
}


//Retrieve list element whose key matches item's key (if present).
template<typename T>
DoubleNode<T>* DoubleLinkedList<T>::Find(T& data) {
	DoublyIterator<T> itor(*this);
	while (itor.NotNull()) {
		if (data == itor.m_CurPointer->info) {
			data = itor.m_CurPointer->info;
			return itor.m_CurPointer;
		}
		else {
			itor.Next();
		}
	}
	return nullptr;
}