#pragma once

#ifndef _AlbumType_H
#define _AlbumType_H

#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"
#include "SimpleMusicType.h"

using namespace std;

/**
*	������ Ŭ����
*/
class AlbumType
{
public:
	/**
	*	�⺻ ������
	*/
	AlbumType()
	{
		m_name = ""; // �ٹ� ��
		m_company = ""; // ���ڵ� ��
		m_singer = ""; // ���� ��
		
	}

	/**
	*	destructor.
	*/
	~AlbumType() {}

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
	*	@brief	���ڵ� �縦 ������
	*	@pre	���ڵ� �簡 �������־�� ��
	*	@post	���ڵ� �縦 ��ȯ
	*
	*/
	string GetCompany()
	{
		return m_company;
	}

	/**
	*	@brief	�������� ������
	*	@pre	�������� �������־�� ��
	*	@post	�������� ��ȯ
	*
	*/
	string GetSinger()
	{
		return m_singer;
	}

	/**
	*	@brief	�ٹ����� ������
	*	@pre
	*	@post	�ٹ����� ����
	*
	*/
	void SetName(string name)
	{
		m_name = name;
	}

	/**
	*	@brief	���ڵ� �縦 ������
	*	@pre
	*	@post	���ڵ� �縦 ����
	*
	*/
	void SetCompany(string company)
	{
		m_company = company;
	}

	/**
	*	@brief	�������� ������
	*	@pre
	*	@post	�������� ����
	*
	*/
	void SetSinger(string singer)
	{
		m_singer = singer;
	}

	/**
	*	@brief	�ٹ� �߸����� ������
	*	@pre
	*	@post	�߸����� ����
	*
	*/
	string GetDate() {
		return m_date; 
	}
	
	/**
	*	@brief	�ٹ� �߸����� ������
	*	@pre
	*	@post	�߸����� ����
	*
	*/
	void SetDate(string date) 
	{ 
		m_date = date;
	}

	/**
	*	@brief	�ٹ� ���ڵ带 ����
	*	@pre
	*	@post	�ٹ� ���ڵ尡 ������
	*	@param	m_name		�ٹ� ����.
	*	@param	m_company	���ڵ� ��.
	*	@param	m_singer	���� ��.
	*/

	void SetRecord(string name, string company, string singer)
	{
		SetName(name);
		SetCompany(company);
		SetSinger(singer);		
	}

	/**
	*	@brief	��ũ���� �ٹ� ������ ������
	*	@pre	
	*	@post	�ٹ� ���� ���
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tAlbum name : " << m_name << endl;
	};

	/**
	*	@brief	��ũ���� ���ڵ� �縦 ������
	*	@pre	
	*	@post	���ڵ� �縦 ���
	*/
	void DisplayCompanyOnScreen()
	{
		cout << "\tCompany   : " << m_company << endl;
	};

	/**
	*	@brief	��ũ���� ���� �̸��� ������
	*	@pre	���� �̸��� �����Ǿ�� ��
	*	@post	���� �̸��� ���
	*/
	void DisplaySingerOnScreen()
	{
		cout << "\tSinger : " << m_singer << endl;
	};

	/**
	*	@brief	��ũ���� �߸����� ������
	*	@pre	�߸����� �����Ǿ�� ��
	*	@post	�߸����� ���
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tRelease Date : " << m_date << endl;
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
		DisplayCompanyOnScreen();
		DisplaySingerOnScreen();
		DisplayDateOnScreen();
		cout << "--------------------------" << endl;
	};
	/**
	*	@brief	Ű���忡�� �ֿ� Ű(�ٹ���, ������)�� �Է¹���
	*	@pre
	*	@post	�ֿ� Ű�� �����ۿ� �Էµ�
	*/
	void EnterKeyFromKB()
	{
		SetNameFromKB();
		SetSingerFromKB();
	}

	/**
	*	@brief	Ű���忡�� �ٹ� ������ �Է¹���
	*	@pre
	*	@post	�ٹ� ������ ������
	*/
	void SetNameFromKB()
	{
		cout << "\tAlbum Name : ";
		cin >> m_name;

	}

	/**
	*	@brief	Ű���忡�� ���ڵ� �縦 �Է¹���
	*	@pre
	*	@post	�������� ������
	*/
	void SetCompanyFromKB()
	{
		cout << "\tCompany : ";
		cin >> m_company;
	}

	/**
	*	@brief	Ű���忡�� �������� �Է¹���
	*	@pre
	*	@post	�������� ������
	*/
	void SetSingerFromKB()
	{
		cout << "\tSinger : ";
		cin >> m_singer;
	}

	/**
	*	@brief	Ű���忡�� �߸����� �Է¹���
	*	@pre
	*	@post	�߸����� ������
	*/
	void SetDateFromKB()
	{
		cout << "\tRelase Date : ";
		cin >> m_date;
	}


	/**
	*	@brief	Ű����� ���� ���ڵ带 �Է¹���
	*	@pre
	*	@post	���ڵ尡 ������
	*/
	void SetRecordFromKB()
	{
		SetNameFromKB();
		SetCompanyFromKB();
		SetSingerFromKB();
		SetDateFromKB();
	}

	/**
	*	@brief	�ٹ� ����Ʈ�� �������� �߰���
	*	@pre
	*	@post	SimpleMusicType�� �������� �߰���
	*
	*/
	int Add(SimpleMusicType item);

	// SMList�� ����� ����
	int GetSMListSize();

	// �帣 Ÿ�� SMList���� �� ����
	int Delete(int num);

	/**
	*	@brief	���Ϸκ��� ���ڵ带 �о��
	*	@pre	Ÿ�� ������ �����־����
	*	@post	���� ���ڵ尡 ������
	*	@param	fin	file descriptor.
	*	@return	������ 1, ���н� 0 ����
	*/
	int ReadDataFromFile(ifstream& fin);

	bool operator==(const AlbumType &obj)
	{
		return (this->m_name == obj.m_name && this->m_singer == obj.m_singer); // �ٹ��̸� + �������� ���� ��� �ߺ��ٹ�
	}
	bool operator!=(const AlbumType &obj)
	{
		return (this->m_name != obj.m_name || this->m_singer != obj.m_singer); // �ٹ��̸� + �������� ���� ��� �ߺ��ٹ�
	}
	bool operator>(const AlbumType &obj)
	{
		return (this->m_name > obj.m_name);
	}
	bool operator<(const AlbumType &obj)
	{
		return (this->m_name < obj.m_name);
	}
	
	void SetPrimaryKey() {
		m_primarykey = m_name + m_singer + m_date;	
	}

	// ����Ʈ�� ���� ������ ����
	void GetNextItem(SimpleMusicType& item, bool& finished);
	
	// ����Ʈ�� ������
	void ResetSMList()
	{
		SMList.ResetTree();
	}
protected:
	string m_primarykey;	// �ٹ� �̸� + ���� �� + �߸� ��
	string m_name;			// �ٹ� �̸�
	string m_company;		// ���ڵ� ��
	string m_singer;		// ���� ��
	string m_date;			// �߸���

private:
	BinarySearchTree<SimpleMusicType> SMList; // ������ �� ���� ����Ʈ - �� ��ȣ
};

#endif	// _MusicType_H
