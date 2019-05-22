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
*	아이템 클래스
*/
class SingerType
{
public:
	/**
	*	기본 생성자
	*/
	SingerType()
	{
		m_name = ""; // 가수 이름
		m_startdate = ""; // 데뷔년도 or 생일
		m_genre = ""; // 활동장르

	}

	/**
	*	destructor.
	*/
	~SingerType() {}

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
	*	@brief	데뷔 날짜를 리턴함
	*	@pre	데뷔 날짜가 정해져있어야 함
	*	@post	데뷔 날짜를 반환
	*
	*/
	string GetDate()
	{
		return m_startdate;
	}

	/**
	*	@brief	장르를 리턴함
	*	@pre	장르가 정해져있어야 함
	*	@post	장르를 반환
	*
	*/
	string GetGenre()
	{
		return m_genre;
	}

	/**
	*	@brief	가수명을 설정함
	*	@pre
	*	@post	가수명을 설정
	*
	*/
	void SetName(string name)
	{
		m_name = name;
	}

	/**
	*	@brief	출생/데뷔일 설정함
	*	@pre
	*	@post	출생/데뷔일 설정
	*
	*/
	void SetDate(string date)
	{
		m_startdate = date;
	}

	/**
	*	@brief	장르 설정함
	*	@pre
	*	@post	장르를 설정
	*
	*/
	void SetGenre(string genre)
	{
		m_genre = genre;
	}


	/**
	*	@brief	스크린에 가수명을 보여줌
	*	@pre
	*	@post	가수 명을 출력
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tSinger name : " << m_name << endl;
	};

	/**
	*	@brief	스크린에 날짜를 보여줌
	*	@pre
	*	@post	날짜를 출력
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tBirth / Debut Date : " << m_startdate << endl;
	};

	/**
	*	@brief	스크린에 장르를 보여줌
	*	@pre	장르가 설정되어야 함
	*	@post	장르를 출력
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre : " << m_genre << endl;
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
		DisplayDateOnScreen();
		DisplayGenreOnScreen();
		cout << "--------------------------" << endl;
	};

	/**
	*	@brief	키보드에서 가수명을 입력받음
	*	@pre
	*	@post	가수명이 설정됨
	*/
	void SetNameFromKB()
	{
		cout << "\tSinger Name : ";
		cin >> m_name;

	}

	/**
	*	@brief	키보드에서 출생일/데뷔일을 입력받음
	*	@pre
	*	@post	날짜가 설정됨
	*/
	void SetDateFromKB()
	{
		cout << "\tBirth / Debut date : ";
		cin >> m_startdate;
	}

	/**
	*	@brief	키보드에서 장르를 입력받음
	*	@pre
	*	@post	장르가 설정됨
	*/
	void SetGenreFromKB()
	{
		cout << "\tGenre : ";
		cin >> m_genre;
	}

	/**
	*	@brief	키보드로 부터 리코드를 입력받음
	*	@pre
	*	@post	리코드가 설정됨
	*/
	void SetRecordFromKB()
	{
		SetNameFromKB();
		SetDateFromKB();
		SetGenreFromKB();
	}

	/**
	*	@brief	앨범 리스트에 아이템을 추가함
	*	@pre
	*	@post	SimpleMusicType의 아이템이 추가됨
	*
	*/
	int Add(SimpleAlbumType& item);


	// SA리스트 안에 해당 앨범이 있는지 검사
	int Get(SimpleAlbumType album);

	// SMList의 사이즈를 얻어옴
	int GetSMListSize();

	// 장르 타입 SAList에서 앨범 삭제
	int Delete(string name, string singer);

	/**
	*	@brief	파일로부터 레코드를 읽어옴
	*	@pre	타겟 파일이 열려있어야함
	*	@post	음악 레코드가 설정됨
	*	@param	fin	file descriptor.
	*	@return	성공시 1, 실패시 0 리턴
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

	// 다음 아이템 값을 얻음
	void GetNextItem(SimpleAlbumType& item, bool& finished);
	
	// 리스트를 리셋
	void ResetSAList()
	{
		SAList.ResetTree();
	}
protected:
	string m_name;			// 가수 이름
	string m_startdate;		// 출생/데뷔일
	string m_genre;			// 장르		
	BinarySearchTree<SimpleAlbumType> SAList; // 간단한 앨범 정보 리스트 - 앨범 명, 가수 명
};

#endif	// _MusicType_H
