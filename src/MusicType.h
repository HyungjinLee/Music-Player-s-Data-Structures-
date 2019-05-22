#pragma once
#ifndef _MusicType_H
#define _MusicType_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
*	아이템 클래스
*/
class MusicType
{
public:
	/**
	*	기본 생성자
	*/
	MusicType()
	{
		m_title = "";
		m_singer = "";
		m_album = "";
		m_genre = "";
		m_lyric = "";
		m_playnum = 0;	
	}

	/**
	*	destructor.
	*/
	~MusicType()	{}

	/**
	*	@brief	곡 번호를 리턴함
	*	@pre	곡 번호가 정해져있어야 함
	*	@post	곡 번호를 반환
	*
	*/
	int GetPrimaryKey()
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
	*	@brief	앨범명을 리턴함
	*	@pre	앨범명이 정해져있어야 함
	*	@post	앨범명을 반환
	*
	*/
	string GetAlbum()
	{
		return m_album;
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
	*	@brief	가사를 리턴함
	*	@pre	가사가 정해져있어야 함
	*	@post	가사를 반환
	*
	*/
	string GetLyric()
	{
		return m_lyric;
	}

	/**
	*	@brief	재생 횟수를 리턴함
	*	@pre	재생 횟수가 정해져있어야 함
	*	@post	재생 횟수를 반환
	*
	*/
	int GetplayNum()
	{
		return m_playnum;
	}

	/**
	*	@brief	곡 번호를 설정함
	*	@pre
	*	@post	곡 번호를 설정
	*
	*/

	void SetPrimaryKey(int num)
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

	/**
	*	@brief	가수명을 설정함
	*	@pre	
	*	@post	가수명을 설정
	*
	*/
	void SetSinger(string singer)
	{
		m_singer=singer;
	}

	/**
	*	@brief	앨범명을 설정함
	*	@pre
	*	@post	앨범명을 설정
	*
	*/
	void SetAlbum(string album)
	{
		m_album=album;
	}

	/**
	*	@brief	장르를 설정함
	*	@pre	
	*	@post	장르를 설정
	*
	*/
	void SetGenre(string genre)
	{
		m_genre=genre;
	}

	/**
	*	@brief	가사를 설정함
	*	@pre
	*	@post	가사를 설정
	*
	*/
	void SetLyric(string lyric)
	{
		m_lyric = lyric;
	}
	/**
	*	@brief	재생 횟수를 설정함
	*	@pre
	*	@post	재생횟수를 설정
	*
	*/
	void SetplayNum(int num)
	{
		m_playnum = num;
	}
	
	/**
	*	@brief	노래 레코드를 설정
	*	@pre	
	*	@post	노래 레코드가 설정됨
	*	@param	m_title		음악 제목.
	*	@param	m_singer	가수 이름.
	*	@param	m_album		앨범 이름.
	*	@param  m_genre		음악 장르.
	*   @param  m_lyric		음악 가사.
	*/
	void SetRecord(string title, string singer, string album, string genre, int num, string lyric)
	{
		SetTitle(title);
		SetSinger(singer);
		SetAlbum(album);
		SetGenre(genre);
		SetplayNum(num);
		SetLyric(lyric);
	}

	/**
	*	@brief	스크린에 곡 제목을 보여줌
	*	@pre	아이디가 설정되어야 함
	*	@post	노래 제목을 출력
	*/
	void DisplayNumOnScreen()
	{
		cout << "\tNum   : " << m_num << endl;
	};

	/**
	*	@brief	스크린에 재생횟수를 보여줌
	*	@pre    아이디가 설정되어야 함
	*	@post	노래 제목을 출력
	*/
	void DisplayPlaynumOnScreen()
	{
		cout << "\tPlayNum   : " << m_playnum << endl;
	};

	/**
	*	@brief	스크린에 노래 제목을 보여줌
	*	@pre	아이디가 설정되어야 함
	*	@post	노래 제목을 출력
	*/
	void DisplayTitleOnScreen() 
	{
		cout << "\tTitle   : " << m_title << endl; 
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
	*	@brief	앨범 제목을 보여줌
	*	@pre	앨범이 설정되어야 함
	*	@post	앨범 제목을 출력
	*/
	void DisplayAlbumOnScreen() 
	{
		cout << "\tAlbum : " << m_album << endl; 
	};

	/**
	*	@brief	장르를 보여줌
	*	@pre	장르가 설정되어야 함
	*	@post	장르가 출력
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre : " << m_genre << endl;
	};

	/**
	*	@brief	가사를 보여줌
	*	@pre	가사가 설정되어야 함
	*	@post	가사를 출력
	*/
	void DisplayLyricOnScreen()
	{
		cout << "\tLyric : " << m_lyric << endl;
	};


	/**
	*	@brief	노래 레코드를 화면에 출력
	*	@pre	노래 레코드가 설정되어야 함
	*	@post	노래 레코드가 출력됨
	*/
	void DisplayRecordOnScreen()
	{
		cout << "--------------------------" << endl;
		DisplayNumOnScreen();
		DisplayTitleOnScreen();
		DisplaySingerOnScreen();
		DisplayAlbumOnScreen();
		DisplayGenreOnScreen();
		DisplayPlaynumOnScreen();
		DisplayLyricOnScreen();
		cout << "--------------------------" << endl;
	};
	
	/**
	*	@brief	키보드에서 곡 번호를 입력받음 - 원하는 곡 선택
 	*	@pre
	*	@post	노래 곡 번호가 설정됨
	*/	
	void EnterNumFromKB();

	/**
	*	@brief	키보드에서 노래 제목을 입력받음
	*	@pre	
	*	@post	노래 제목이 설정됨
	*/
	void SetTitleFromKB();

	/**
	*	@brief	키보드에서 가수명을 입력받음
	*	@pre
	*	@post	가수명이 설정됨
	*/
	void SetSingerFromKB();

	/**
	*	@brief	키보드에서 앨범명을 입력받음
	*	@pre
	*	@post	앨범명이 설정됨
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	키보드에서 장르를 입력받음
	*	@pre
	*	@post	장르가 설정됨
	*/
	void SetGenreFromKB();

	/**
	*	@brief	키보드에서 가사를 입력받음
	*	@pre
	*	@post	가사가 설정됨
	*/
	void SetLyricFromKB();

	/**
	*	@brief	키보드로 부터 리코드를 입력받음
	*	@pre
	*	@post	리코드가 설정됨
	*/
	void SetRecordFromKB();


	/**
	*	@brief	파일로부터 레코드를 읽어옴
	*	@pre	타겟 파일이 열려있어야함
	*	@post	음악 레코드가 설정됨
	*	@param	fin	file descriptor.
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	레코드를 파일에 씀
	*	@pre	타겟 파일이 열려있고, 리스트가 초기화되어야 함
	*	@post	타겟 파일에 새로운 음악 레코드가 저장됨
	*	@param	fout	file descriptor.
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int WriteDataToFile(ofstream& fout);
	
	bool operator==(const MusicType &obj)
	{
		return (this->m_num == obj.m_num);
	}
	bool operator>(const MusicType &obj)
	{
		return (this->m_num > obj.m_num);
	}
	bool operator<(const MusicType &obj)
	{
		return (this->m_num < obj.m_num);
	}

	 // 음악을 재생한다.
	int PlayMusic();
	
	MusicType& GetNextItem()
	{
		return *this;
	}

protected:
	int m_num;			// Primary Key - 겹치지 않게
	string m_title;		///< Music Title.
	string m_singer;	///< Singer Name.
	string m_album;		///< Album Name.
	string m_genre;		///< Genre.
	string m_lyric;		///< Lyrics Including space.
	int m_playnum;		// 재생횟수
};

#endif	// _MusicType_H
