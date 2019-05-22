#pragma once

#ifndef _SimpleAlbumType_H
#define _SimpleAlbumType_H

#include <iostream>
#include <string>
#include "MusicType.h"

using namespace std;

/**
*	아이템 클래스
*/
class SimpleAlbumType
{
public:
	/**
	*	기본 생성자
	*/
	SimpleAlbumType()
	{
		m_name = ""; // 이름 초기화
		m_singer = "";
	}

	/**
	*   깊은 복사를 통해 클래스 안에 있는 에트리뷰트 값까지 복사
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
	*	@brief	앨범명을 리턴함
	*	@pre	앨범명이 정해져있어야 함
	*	@post	앨범명을 반환
	*
	*/
	string GetName()
	{
		return m_name;
	}

	/**
	*	@brief	가수명을 리턴함
	*	@pre	가수명이 정해져있어야 함
	*	@post	가수명을 반환
	*
	*/
	string GetSinger()
	{
		return m_singer;
	}

	/**
	*	@brief  앨범명을 설정함
	*	@pre
	*	@post	앨범명을 설정
	*
	*/
	void SetName(string name)
	{
		m_name = name;
	}

	/**
	*	@brief  가수명을 설정함
	*	@pre
	*	@post	가수명을 설정
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
	string m_name;			// 앨범 이름
	string m_singer;       // 가수 이름
};

#endif	// _SimpleAlbumType_H