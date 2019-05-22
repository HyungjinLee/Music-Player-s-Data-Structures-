#pragma once
#ifndef _DOUBLYSORTEDLINKEDLIST_H
#define _DOUBLYSORTEDLINKEDLIST_H

#include "DoublyIterator.h"
#include "SimpleAlbumType.h"
#include "SimpleMusicType.h"

template<typename T>
class DoublyIterator;

/**
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template <typename T>
struct DoublyNodeType
{
	T data; // �� ����� ������
	DoublyNodeType *prev; // ����� ���� ����Ű�� ������
	DoublyNodeType *next; // ����� ������ ����Ű�� ������
};

/**
*	���ĵ� �����Ḯ��Ʈ Ŭ����
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; //DoublyIterator�� ģ�� Ŭ����
public:
	/**
	*	����Ʈ ������.
	*/
	DoublySortedLinkedList();

	/**
	*	�Ҹ���.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	����Ʈ�� ������� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	������� �ƴ����� �˷��ش�.
	*	@return	��������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsEmpty();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	m_header�� m_trailer�� ������ ��� �����͸� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����Ʈ�� ���̸� ��ȯ.
	*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
	*/
	int GetLength() const;

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�������� ����Ʈ�� �߰��Ѵ�.
	*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
	*/
	int Add(T item);

	/**
	*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
	*/
	void Delete(T item);

	/**
	*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	���ο� ������ ��ü�ȴ�.
	*/
	void Replace(T& item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	int Get(T &item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� ������ �����͸� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	������ ������ ��ȯ
	*	@return	��ġ�ϴ� �����͸� ã���� ������ ��ȯ, �׷��� ������ NULL�� ��ȯ.
	*/
	T* GetPointer(T &item);

private:
	DoublyNodeType<T>* m_header; // ����Ʈ�� �� ó��
	DoublyNodeType<T>* m_trailer; // ����Ʈ�� �� ��
	int m_nLength; // ����Ʈ�� ����
};

// ����Ʈ�� �� ó���� ���� ���θ� ����Ű�� �����ϰ� ����Ʈ�� ���̸� 0���� �ʱ�ȭ���ѳ��´�.
template <typename T>
DoublySortedLinkedList<T> :: DoublySortedLinkedList()
{
	m_header = new DoublyNodeType<T>;
	m_trailer = new DoublyNodeType<T>;
	
	m_header->next = m_trailer; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.
	m_header->prev = NULL; // ó��.

	m_trailer->next = NULL; // ��.
	m_trailer->prev = m_header; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.

	m_nLength = 0; // ���̴� 0.
}

// �Ҹ���.
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	if (typeid(T) != typeid(SimpleMusicType) && typeid(T) != typeid(SimpleAlbumType))
	{
		delete m_header;
		delete m_trailer;
	}
}

// ����Ʈ�� ������� �˻��Ѵ�.
template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty()
{
	if(m_nLength == 0)
		return true;
	else
		return false;
}

// ����Ʈ�� ����.
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T> *pItem;
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while(itor.NextNotNull())
	{
		pItem = itor.m_pCurPointer;
		itor.Next(); // ���� �����͸� �������� �̵�.
		delete pItem; 
		m_nLength--;
	}

	m_header->next = m_trailer;
	m_header->prev = NULL;
	m_trailer->prev = m_header;
	m_trailer->next = NULL;

	return;
}

// ����Ʈ�� ���̸� ��ȯ�Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}

// �������� �Է¹޾� ����Ʈ�� �´� �ڸ��� ã�� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::Add(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	if(IsEmpty()) // ó�� ������ ��
	{
		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_header->next = pItem;
		pItem->prev = m_header;
		pItem->next = m_trailer;
		m_trailer->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}
	else // ó���� �ƴ� ��
	{
		while(1)
		{
			if(item < itor.m_pCurPointer->data || itor.m_pCurPointer == m_trailer) // �´� �ڸ��� ã�´�.
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = itor.m_pCurPointer->prev;
				pItem->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem; // �������� ����.
				m_nLength++;
				return 1;
			}
			else if(item == itor.m_pCurPointer->data) // ���� ������ �������� ������
				return 0; // 0�� ��ȯ.
			else
				itor.Next(); // �������� �̵�.
		}
	}
}

// �Է¹��� �������� �����Ϳ��� ã�Ƴ��� �����Ѵ�.
template <typename T>
void DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while(itor.m_pCurPointer != m_trailer)
	{
		if(itor.m_pCurPointer->data == item) // ��ġ�ϴ� �����͸� ã�´�.
		{
			DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
			pItem = itor.m_pCurPointer;
			itor.Next();
			pItem->prev->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev = pItem->prev; // �����ϴ� ����� �հ� �ڸ� ���� �̾��ش�.
			delete pItem; // ����.
			break;
		}
		else
			itor.Next();
	}
	m_nLength--; // ���� ����.
	return;
}

// �Է¹��� �������� ������ ��ü�Ѵ�.
template <typename T>
void DoublySortedLinkedList<T>::Replace(T& item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.
	 
	while(itor.m_pCurPointer != m_trailer)
	{
		if(itor.m_pCurPointer->data == item)
		{
			item.SetRecordFromKB(); // ���ο� ���� �Է¹���
			itor.m_pCurPointer->data = item; // ������ ��ü.
			return;
		}
		else
			itor.Next();
	}

	return;
}

// �Է¹��� �����۰� ��ġ�ϴ� �������� ����Ʈ���� ã�� �����´�.
template <typename T>
int DoublySortedLinkedList<T>::Get(T &item)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_trailer)
	{
		if (itor.m_pCurPointer->data == item)
		{
			item = itor.m_pCurPointer->data;
			return 1; // ��ġ�ϸ� ���� �������� ��ȯ.
		}
		else
			itor.Next(); // �������� �̵�.
	}

	return 0; // ��ġ���� ������ 0�� ��ȯ.
}

// �Է¹��� �����۰� ��ġ�ϴ� �������� ����Ʈ���� ã�� �����´�.
template <typename T>
T* DoublySortedLinkedList<T>::GetPointer(T &item)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	while(itor.m_pCurPointer != m_trailer)
	{
		if(itor.m_pCurPointer->data == item)
		{
			item = itor.m_pCurPointer->data;
			return itor.Current(); // ��ġ�ϸ� ���� �������� ��ȯ.
		}
		else
			itor.Next(); // �������� �̵�.
	}

	return NULL; // ��ġ���� ������ NULL�� ��ȯ.
}

#endif _DOUBLYSORTEDLINKEDLIST_H