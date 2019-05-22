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
*	아이템 클래스
*/
class GenreType
{
public:
	/**
	*	기본 생성자
	*/
	GenreType()
	{
		m_genre = ""; //  초기화
	}

	/**
	*	destructor.
	*/
	~GenreType() {
	}

	/**
	*	@brief	곡 장르를 리턴함
	*	@pre	곡 장르가 정해져있어야 함
	*	@post	곡 장르를 반환
	*
	*/
	string GetGenre()
	{
		return m_genre;
	}


	/**
	*	@brief	곡 장르를 설정함
	*	@pre
	*	@post	곡 장르를 설정
	*
	*/
	void SetGenre(string genre)
	{
		m_genre = genre;
	}

	/**
	*	@brief	장르 리스트에 아이템을 추가함
	*	@pre
	*	@post	SimpleMusicType의 아이템이 추가됨
	*
	*/
	int Add(SimpleMusicType& item);


	 // SMList를 리셋함
	void ResetSMList();

	 // 장르 타입 SMList에서 곡 삭제
	 int Delete(int num);

	 // 연산자 오버로딩
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

	 // 리스트의 다음 아이템 얻음
	 void GetNextItem(SimpleMusicType& item, bool& finished);

	 // 리스트의 사이즈를 얻음
	 int GetSMListSize()
	 {
		 return SMList.GetLength();
	 }

protected:
	string m_genre;		// 음악 장르 - 겹치지 않게
	BinarySearchTree<SimpleMusicType> SMList; // 간단한 곡 정보 리스트 - 곡 번호
};

#endif	// _GenreType_H