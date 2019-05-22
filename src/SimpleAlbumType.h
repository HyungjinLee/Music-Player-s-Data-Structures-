#pragma once

#ifndef _SimpleAlbumType_H
#define _SimpleAlbumType_H

#include <iostream>
#include <string>
#include "MusicType.h"

using namespace std;

/**
*	������ Ŭ����
*/
class SimpleAlbumType
{
public:
	/**
	*	�⺻ ������
	*/
	SimpleAlbumType()
	{
		m_name = ""; // �̸� �ʱ�ȭ
		m_singer = "";
	}

	/**
	*   ���� ���縦 ���� Ŭ���� �ȿ� �ִ� ��Ʈ����Ʈ ������ ����
	*/

	SimpleAlbumType(const SimpleAlbumType& simple)
	{
		m_name = simple.m_name;
		m_singer = simple.m_singer;
	}

	/**
	*	destructor.
	*/
	~SimpleAlbumType() {}

	/**
	*	@brief	�ٹ����� ������
	*	@pre	�ٹ����� �������־�� ��
	*	@post	�ٹ����� ��ȯ
	*
	*/
	string GetName()
	{
		return m_name;
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
	*	@brief  �ٹ����� ������
	*	@pre
	*	@post	�ٹ����� ����
	*
	*/
	void SetName(string name)
	{
		m_name = name;
	}

	/**
	*	@brief  �������� ������
	*	@pre
	*	@post	�������� ����
	*
	*/

	void SetSinger(string singer)
	{
		m_singer = singer;
	}

	bool operator==(const SimpleAlbumType &obj)
	{
		return (this->m_name == obj.m_name && this->m_singer == obj.m_singer);
	}
	bool operator>(const SimpleAlbumType &obj)
	{
		return (this->m_name > obj.m_name);
	}
	bool operator<(const SimpleAlbumType &obj)
	{
		return (this->m_name < obj.m_name);
	}


protected:
	string m_name;			// �ٹ� �̸�
	string m_singer;       // ���� �̸�
};

#endif	// _SimpleAlbumType_H