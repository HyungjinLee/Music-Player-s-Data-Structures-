#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	����Ʈ ������.
	*/
	DoublyIterator(const DoublySortedLinkedList<T> &list) : m_List(list), m_pCurPointer(list.m_header)
	{};  // DoublySortedLinkedList�� ģ�� Ŭ����.

	bool NotNull();
	bool NextNotNull();
	
	T First();
	T* Next();
	T Last();
	T* Current();

	DoublyNodeType<T> GetCurrentNode();
private:
	const DoublySortedLinkedList<T> &m_List;
	DoublyNodeType<T>* m_pCurPointer;
};

template <typename T>
bool DoublyIterator<T> :: NotNull()
{
	if(m_pCurPointer == NULL)
		return false;
	else
		return true;
}

template <typename T>
bool DoublyIterator<T> :: NextNotNull()
{
	if(m_pCurPointer->next == NULL)
		return false;
	else
		return true;
}

template <typename T>
T DoublyIterator<T> :: First()
{
	return m_List.m_header->data;
}

template <typename T>
T DoublyIterator<T> ::Last()
{
	return m_List.m_trailer->prev->data;
}

template <typename T>
T* DoublyIterator<T> :: Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return &m_pCurPointer->data;
}

template <typename T>
T* DoublyIterator<T> ::Current()
{
	return &m_pCurPointer->data;
}

template <typename T>
DoublyNodeType<T> DoublyIterator<T> :: GetCurrentNode()
{
	return *m_pCurPointer;
}

#endif _DOUBLYITERATOR_H