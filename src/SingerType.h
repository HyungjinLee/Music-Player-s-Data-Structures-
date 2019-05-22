#pragma once

#ifndef _SingerType_H
#define _SingerType_H

#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"
#include "SimpleAlbumType.h"


using namespace std;

/**
*	������ Ŭ����
*/
class SingerType
{
public:
	/**
	*	�⺻ ������
	*/
	SingerType()
	{
		m_name = ""; // ���� �̸�
		m_startdate = ""; // ���߳⵵ or ����
		m_genre = ""; // Ȱ���帣

	}

	/**
	*	destructor.
	*/
	~SingerType() {}

	/**
	*	@brief	�ٹ� �̸��� ������
	*	@pre	�ٹ� �̸��� �������־�� ��
	*	@post	�ٹ� �̸��� ��ȯ
	*
	*/
	string GetName()
	{
		return m_name;
	}

	/**
	*	@brief	���� ��¥�� ������
	*	@pre	���� ��¥�� �������־�� ��
	*	@post	���� ��¥�� ��ȯ
	*
	*/
	string GetDate()
	{
		return m_startdate;
	}

	/**
	*	@brief	�帣�� ������
	*	@pre	�帣�� �������־�� ��
	*	@post	�帣�� ��ȯ
	*
	*/
	string GetGenre()
	{
		return m_genre;
	}

	/**
	*	@brief	�������� ������
	*	@pre
	*	@post	�������� ����
	*
	*/
	void SetName(string name)
	{
		m_name = name;
	}

	/**
	*	@brief	���/������ ������
	*	@pre
	*	@post	���/������ ����
	*
	*/
	void SetDate(string date)
	{
		m_startdate = date;
	}

	/**
	*	@brief	�帣 ������
	*	@pre
	*	@post	�帣�� ����
	*
	*/
	void SetGenre(string genre)
	{
		m_genre = genre;
	}


	/**
	*	@brief	��ũ���� �������� ������
	*	@pre
	*	@post	���� ���� ���
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tSinger name : " << m_name << endl;
	};

	/**
	*	@brief	��ũ���� ��¥�� ������
	*	@pre
	*	@post	��¥�� ���
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tBirth / Debut Date : " << m_startdate << endl;
	};

	/**
	*	@brief	��ũ���� �帣�� ������
	*	@pre	�帣�� �����Ǿ�� ��
	*	@post	�帣�� ���
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre : " << m_genre << endl;
	};

	/**

	*	@brief	�ٹ� ���ڵ带 ȭ�鿡 ���
	*	@pre	�ٹ� ���ڵ尡 �����Ǿ�� ��
	*	@post	�ٹ� ���ڵ尡 ��µ�
	*/
	void DisplayRecordOnScreen()
	{
		cout << "--------------------------" << endl;
		DisplayNameOnScreen();
		DisplayDateOnScreen();
		DisplayGenreOnScreen();
		cout << "--------------------------" << endl;
	};

	/**
	*	@brief	Ű���忡�� �������� �Է¹���
	*	@pre
	*	@post	�������� ������
	*/
	void SetNameFromKB()
	{
		cout << "\tSinger Name : ";
		cin >> m_name;

	}

	/**
	*	@brief	Ű���忡�� �����/�������� �Է¹���
	*	@pre
	*	@post	��¥�� ������
	*/
	void SetDateFromKB()
	{
		cout << "\tBirth / Debut date : ";
		cin >> m_startdate;
	}

	/**
	*	@brief	Ű���忡�� �帣�� �Է¹���
	*	@pre
	*	@post	�帣�� ������
	*/
	void SetGenreFromKB()
	{
		cout << "\tGenre : ";
		cin >> m_genre;
	}

	/**
	*	@brief	Ű����� ���� ���ڵ带 �Է¹���
	*	@pre
	*	@post	���ڵ尡 ������
	*/
	void SetRecordFromKB()
	{
		SetNameFromKB();
		SetDateFromKB();
		SetGenreFromKB();
	}

	/**
	*	@brief	�ٹ� ����Ʈ�� �������� �߰���
	*	@pre
	*	@post	SimpleMusicType�� �������� �߰���
	*
	*/
	int Add(SimpleAlbumType& item);


	// SA����Ʈ �ȿ� �ش� �ٹ��� �ִ��� �˻�
	int Get(SimpleAlbumType album);

	// SMList�� ����� ����
	int GetSMListSize();

	// �帣 Ÿ�� SAList���� �ٹ� ����
	int Delete(string name, string singer);

	/**
	*	@brief	���Ϸκ��� ���ڵ带 �о��
	*	@pre	Ÿ�� ������ �����־����
	*	@post	���� ���ڵ尡 ������
	*	@param	fin	file descriptor.
	*	@return	������ 1, ���н� 0 ����
	*/
	int ReadDataFromFile(ifstream& fin);

	bool operator==(const SingerType &obj)
	{
		return (this->m_name == obj.m_name);
	}
	bool operator!=(const SingerType & obj)
	{
		return (this->m_name != obj.m_name);
	}
	bool operator>(const SingerType &obj)
	{
		return (this->m_name > obj.m_name);
	}
	bool operator<(const SingerType &obj)
	{
		return (this->m_name < obj.m_name);
	}

	// ���� ������ ���� ����
	void GetNextItem(SimpleAlbumType& item, bool& finished);
	
	// ����Ʈ�� ����
	void ResetSAList()
	{
		SAList.ResetTree();
	}
protected:
	string m_name;			// ���� �̸�
	string m_startdate;		// ���/������
	string m_genre;			// �帣		
	BinarySearchTree<SimpleAlbumType> SAList; // ������ �ٹ� ���� ����Ʈ - �ٹ� ��, ���� ��
};

#endif	// _MusicType_H
