#pragma once

#ifndef _SimpleMusicType_H
#define _SimpleMusicType_H

#include <iostream>
#include <string>
#include "MusicType.h"

using namespace std;

/**
*	������ Ŭ����
*/
class SimpleMusicType
{
public:
	/**
	*	�⺻ ������
	*/
	SimpleMusicType()
	{
		m_num = 0; // ��ȣ �ʱ�ȭ
		m_title = "";
	}

	/**
	*   ���� ���縦 ���� Ŭ���� �ȿ� �ִ� ��Ʈ����Ʈ ������ ����
	*/
	SimpleMusicType(const SimpleMusicType& simple)
	{
		m_num = simple.m_num;
		m_title = simple.m_title;
	}

	/**
	*	destructor.
	*/
	~SimpleMusicType() {}

	/**
	*	@brief	�� ��ȣ�� ������
	*	@pre	�� ��ȣ�� �������־�� ��
	*	@post	�� ��ȣ�� ��ȯ
	*
	*/
	int GetNum()
	{
		return m_num;
	}

	/**
	*	@brief	�� ������ ������
	*	@pre	�� ������ �������־�� ��
	*	@post	�� ������ ��ȯ
	*
	*/
	string GetTitle()
	{
		return m_title;
	}


	/**
	*	@brief	�� ������ ������
	*	@pre
	*	@post	�� ������ ����
	*
	*/
	void SetNum(int num)
	{
		m_num = num;
	}

	/**
	*	@brief	�� ������ ������
	*	@pre
	*	@post	�� ������ ����
	*
	*/

	void SetTitle(string title)
	{
		m_title = title;
	}

	bool operator==(const SimpleMusicType &obj)
	{
		return (m_num == obj.m_num);
	}
	bool operator>(const SimpleMusicType &obj)
	{
		return (m_num > obj.m_num);
	}
	bool operator<(const SimpleMusicType &obj)
	{
		return (m_num < obj.m_num);
	}

protected:
	int m_num;			///< Music Number : Primary key
	string m_title;		///< Music Title.
};

#endif	// _SimpleMusicType_H