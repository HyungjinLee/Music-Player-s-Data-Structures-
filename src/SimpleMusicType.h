#pragma once

#ifndef _SimpleMusicType_H
#define _SimpleMusicType_H

#include <iostream>
#include <string>
#include "MusicType.h"

using namespace std;

/**
*	아이템 클래스
*/
class SimpleMusicType
{
public:
	/**
	*	기본 생성자
	*/
	SimpleMusicType()
	{
		m_num = 0; // 번호 초기화
		m_title = "";
	}

	/**
	*   깊은 복사를 통해 클래스 안에 있는 에트리뷰트 값까지 복사
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
	*	@brief	곡 번호을 리턴함
	*	@pre	곡 번호이 정해져있어야 함
	*	@post	곡 번호를 반환
	*
	*/
	int GetNum()
	{
		return m_num;
	}

	/**
	*	@brief	곡 제목을 리턴함
	*	@pre	곡 제목이 정해져있어야 함
	*	@post	곡 제목을 반환
	*
	*/
	string GetTitle()
	{
		return m_title;
	}


	/**
	*	@brief	곡 제목을 설정함
	*	@pre
	*	@post	곡 제목을 설정
	*
	*/
	void SetNum(int num)
	{
		m_num = num;
	}

	/**
	*	@brief	곡 제목을 설정함
	*	@pre
	*	@post	곡 제목을 설정
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