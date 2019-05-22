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
*	아이템 클래스
*/
class AlbumType
{
public:
	/**
	*	기본 생성자
	*/
	AlbumType()
	{
		m_name = ""; // 앨범 명
		m_company = ""; // 레코드 사
		m_singer = ""; // 가수 명
		
	}

	/**
	*	destructor.
	*/
	~AlbumType() {}

	/**
	*	@brief	앨범 이름을 리턴함
	*	@pre	앨범 이름이 정해져있어야 함
	*	@post	앨범 이름을 반환
	*
	*/
	string GetName()
	{
		return m_name;
	}

	/**
	*	@brief	레코드 사를 리턴함
	*	@pre	레코드 사가 정해져있어야 함
	*	@post	레코드 사를 반환
	*
	*/
	string GetCompany()
	{
		return m_company;
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
	*	@brief	앨범명을 설정함
	*	@pre
	*	@post	앨범명을 설정
	*
	*/
	void SetName(string name)
	{
		m_name = name;
	}

	/**
	*	@brief	레코드 사를 설정함
	*	@pre
	*	@post	레코드 사를 설정
	*
	*/
	void SetCompany(string company)
	{
		m_company = company;
	}

	/**
	*	@brief	가수명을 설정함
	*	@pre
	*	@post	가수명을 설정
	*
	*/
	void SetSinger(string singer)
	{
		m_singer = singer;
	}

	/**
	*	@brief	앨범 발매일을 리턴함
	*	@pre
	*	@post	발매일을 리턴
	*
	*/
	string GetDate() {
		return m_date; 
	}
	
	/**
	*	@brief	앨범 발매일을 설정함
	*	@pre
	*	@post	발매일을 설정
	*
	*/
	void SetDate(string date) 
	{ 
		m_date = date;
	}

	/**
	*	@brief	앨범 레코드를 설정
	*	@pre
	*	@post	앨범 레코드가 설정됨
	*	@param	m_name		앨범 제목.
	*	@param	m_company	레코드 사.
	*	@param	m_singer	가수 명.
	*/

	void SetRecord(string name, string company, string singer)
	{
		SetName(name);
		SetCompany(company);
		SetSinger(singer);		
	}

	/**
	*	@brief	스크린에 앨범 제목을 보여줌
	*	@pre	
	*	@post	앨범 명을 출력
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tAlbum name : " << m_name << endl;
	};

	/**
	*	@brief	스크린에 레코드 사를 보여줌
	*	@pre	
	*	@post	레코드 사를 출력
	*/
	void DisplayCompanyOnScreen()
	{
		cout << "\tCompany   : " << m_company << endl;
	};

	/**
	*	@brief	스크린에 가수 이름을 보여줌
	*	@pre	가수 이름이 설정되어야 함
	*	@post	갸수 이름을 출력
	*/
	void DisplaySingerOnScreen()
	{
		cout << "\tSinger : " << m_singer << endl;
	};

	/**
	*	@brief	스크린에 발매일을 보여줌
	*	@pre	발매일이 설정되어야 함
	*	@post	발매일을 출력
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tRelease Date : " << m_date << endl;
	};


	/**
	*	@brief	앨범 레코드를 화면에 출력
	*	@pre	앨범 레코드가 설정되어야 함
	*	@post	앨범 레코드가 출력됨
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
	*	@brief	키보드에서 주요 키(앨범명, 가수명)을 입력받음
	*	@pre
	*	@post	주요 키가 아이템에 입력됨
	*/
	void EnterKeyFromKB()
	{
		SetNameFromKB();
		SetSingerFromKB();
	}

	/**
	*	@brief	키보드에서 앨범 제목을 입력받음
	*	@pre
	*	@post	앨범 제목이 설정됨
	*/
	void SetNameFromKB()
	{
		cout << "\tAlbum Name : ";
		cin >> m_name;

	}

	/**
	*	@brief	키보드에서 레코드 사를 입력받음
	*	@pre
	*	@post	가수명이 설정됨
	*/
	void SetCompanyFromKB()
	{
		cout << "\tCompany : ";
		cin >> m_company;
	}

	/**
	*	@brief	키보드에서 가수명을 입력받음
	*	@pre
	*	@post	가수명이 설정됨
	*/
	void SetSingerFromKB()
	{
		cout << "\tSinger : ";
		cin >> m_singer;
	}

	/**
	*	@brief	키보드에서 발매일을 입력받음
	*	@pre
	*	@post	발매일이 설정됨
	*/
	void SetDateFromKB()
	{
		cout << "\tRelase Date : ";
		cin >> m_date;
	}


	/**
	*	@brief	키보드로 부터 리코드를 입력받음
	*	@pre
	*	@post	리코드가 설정됨
	*/
	void SetRecordFromKB()
	{
		SetNameFromKB();
		SetCompanyFromKB();
		SetSingerFromKB();
		SetDateFromKB();
	}

	/**
	*	@brief	앨범 리스트에 아이템을 추가함
	*	@pre
	*	@post	SimpleMusicType의 아이템이 추가됨
	*
	*/
	int Add(SimpleMusicType item);

	// SMList의 사이즈를 얻어옴
	int GetSMListSize();

	// 장르 타입 SMList에서 곡 삭제
	int Delete(int num);

	/**
	*	@brief	파일로부터 레코드를 읽어옴
	*	@pre	타겟 파일이 열려있어야함
	*	@post	음악 레코드가 설정됨
	*	@param	fin	file descriptor.
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int ReadDataFromFile(ifstream& fin);

	bool operator==(const AlbumType &obj)
	{
		return (this->m_name == obj.m_name && this->m_singer == obj.m_singer); // 앨범이름 + 가수명이 같은 경우 중복앨범
	}
	bool operator!=(const AlbumType &obj)
	{
		return (this->m_name != obj.m_name || this->m_singer != obj.m_singer); // 앨범이름 + 가수명이 같은 경우 중복앨범
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

	// 리스트의 다음 아이템 얻음
	void GetNextItem(SimpleMusicType& item, bool& finished);
	
	// 리스트를 리셋함
	void ResetSMList()
	{
		SMList.ResetTree();
	}
protected:
	string m_primarykey;	// 앨범 이름 + 가수 명 + 발매 일
	string m_name;			// 앨범 이름
	string m_company;		// 레코드 사
	string m_singer;		// 가수 명
	string m_date;			// 발매일

private:
	BinarySearchTree<SimpleMusicType> SMList; // 간단한 곡 정보 리스트 - 곡 번호
};

#endif	// _MusicType_H
