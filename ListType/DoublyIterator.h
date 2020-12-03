#pragma once
#include "pch.h"
template<typename T>
class DoublyIterator {
	friend class DoubleLinkedList<T>;
private:
	const DoubleLinkedList<T>& m_list;			///< 사용할 리스트의 참조 변수
	DoubleNode<T>* m_CurPointer;			///< Node pointer for pointing current node to use iteration.
public:

	/**
	*	Initialize m_List and m_pCurPointer. (constructor overloading)
	*/
	DoublyIterator(const DoubleLinkedList<T>& list) :m_list(list), m_CurPointer(list.m_pFirst) {}

	/**
	*	@brief	Get next data of the current pointer.
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to the next node.
	*	@return	Return next data of the list.
	*/
	T Next();
	/**
	*	@brief	Get back data of the current pointer.
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to the back node.
	*	@return	Return back data of the list.
	*/
	T Back();
	/**
	*	@brief	Get first data of the list.
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to the first node.
	*	@return	Return first data of the list.
	*/
	T first();

	/**
	*	@brief	현재 노드 포인터의 다음 노드가 null인지 아닌지 판단하는 메서드.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool NextNotNull();

	/**
	*	@brief	현재 노드를 가리키는 포인터가 null인지 아닌지 판단하는 메서드.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool NotNull();

	/**
	*	@brief	현재 노드 포인터의 전 노드가 null인지 아닌지 판단하는 메서드.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool BackNotNull();

	/**
	*	@brief	Get current data of the list and go to the next node. 현재 노드. 객체반환은 return by value
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to next node.
	*	@return	Return current data pointer of the list.
	*/
	DoubleNode<T>* GetCurNode();

	/**
	*	@brief	Copy the im_CurPointer
	*	@pre	two item types should be initialized.
	*	@param	data	target item for copy the m_CurPointer
	*/
	void operator = (const DoublyIterator<T>& data);
};

//Get next data of the current pointer.
template<typename T>
T DoublyIterator<T>::Next() {
	T output = m_CurPointer->info;
	m_CurPointer = m_CurPointer->next;
	return output;
}

//Get back data of the current pointer.
template<typename T>
T DoublyIterator<T>::Back() {
	T output = m_CurPointer->info;
	m_CurPointer = m_CurPointer->back;
	return output;
}


//Get first data of the list.
template<typename T>
T DoublyIterator<T>::first() {
	if (m_list.m_length != 0) {
		m_CurPointer = m_list.m_pFirst;
		return m_CurPointer->info;
	}
}

//현재 노드 포인터의 다음 노드가 null인지 아닌지 판단하는 메서드.
template<typename T>
bool DoublyIterator<T>::NextNotNull() {
	if (m_CurPointer->next == nullptr)
		return false;
	else
		return true;
}

//현재 노드 포인터의 전 노드가 null인지 아닌지 판단하는 메서드.
template<typename T>
bool DoublyIterator<T>::BackNotNull() {
	if (m_CurPointer->back == nullptr)
		return false;
	else
		return true;
}

//Get current data of the list and go to the next node. 현재 노드.
template<typename T>
DoubleNode<T>* DoublyIterator<T>::GetCurNode() {
	return m_CurPointer;
}

//Copy the im_CurPointer
template<typename T>
void DoublyIterator<T>::operator = (const DoublyIterator<T>& data) {
	m_CurPointer = data.m_CurPointer();
}

// 현재 원소가 null인지 검사
template <typename T>
bool DoublyIterator<T>::NotNull() {
	if (m_CurPointer == nullptr) {
		return false;
	}
	else return true;
}
