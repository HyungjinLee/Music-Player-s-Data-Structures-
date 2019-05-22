#pragma once

#ifndef _GenreType_H
#define _GenreType_H

#include <iostream>
#include <string>
#include "SimpleMusicType.h"
#include "BinarySearchTree.h"
#include "CircularQueueType.h"

using namespace std;


/**
*	������ Ŭ����
*/
class GenreType
{
public:
	/**
	*	�⺻ ������
	*/
	GenreType()
	{
		m_genre = ""; //  �ʱ�ȭ
	}

	/**
	*	destructor.
	*/
	~GenreType() {
	}

	/**
	*	@brief	�� �帣�� ������
	*	@pre	�� �帣�� �������־�� ��
	*	@post	�� �帣�� ��ȯ
	*
	*/
	string GetGenre()
	{
		return m_genre;
	}


	/**
	*	@brief	�� �帣�� ������
	*	@pre
	*	@post	�� �帣�� ����
	*
	*/
	void SetGenre(string genre)
	{
		m_genre = genre;
	}

	/**
	*	@brief	�帣 ����Ʈ�� �������� �߰���
	*	@pre
	*	@post	SimpleMusicType�� �������� �߰���
	*
	*/
	int Add(SimpleMusicType& item);


	 // SMList�� ������
	void ResetSMList();

	 // �帣 Ÿ�� SMList���� �� ����
	 int Delete(int num);

	 // ������ �����ε�
	 bool operator==(const GenreType &obj)
	 {
		 return (this->m_genre == obj.m_genre);
	 }
	 bool operator>(const GenreType &obj)
	 {
		 return (this->m_genre > obj.m_genre);
	 }
	 bool operator<(const GenreType &obj)
	 {
		 return (this->m_genre < obj.m_genre);
	 }

	 // ����Ʈ�� ���� ������ ����
	 void GetNextItem(SimpleMusicType& item, bool& finished);

	 // ����Ʈ�� ����� ����
	 int GetSMListSize()
	 {
		 return SMList.GetLength();
	 }

protected:
	string m_genre;		// ���� �帣 - ��ġ�� �ʰ�
	BinarySearchTree<SimpleMusicType> SMList; // ������ �� ���� ����Ʈ - �� ��ȣ
};

#endif	// _GenreType_H