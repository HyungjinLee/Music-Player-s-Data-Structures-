#pragma once

#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include "DoublySortedLinkedList.h"
#include "BinarySearchTree.h"
#include "GenreType.h"
#include "CircularQueueType.h"
#include "AlbumType.h"
#include "SingerType.h"
#include "ArrayListForInt.h"

#define FILENAMESIZE 1024

using namespace std;
/**
*	프로그램 관리를 편하게 하기 위한 Application 클래스
*/

class Application 
{
public:
	/**
	*	기본 생성자
	*/
	Application()
	{
		m_Command = 0; 
		temp.IsEmpty();  
		temp_p.IsEmpty();
		ReadInfo(); // 앨범, 가수 정보 읽어옴

	}
	
	/**
	*	소멸자
	*/
	~Application()	{}

	/**
	*	@brief	프로그램 드라이버
	*	@pre	프로그램이 실행
	*	@post	프로그램 종료
	*/
	void Run();

	/**
	*	@brief	키보드로부터 명령을 읽어와서 실행시킴
	*	@pre	
	*	@post	
	*	@return	사용자 명령
	*/
	int GetCommand();

	/**
	*	@brief	리스트에 새로운 레코드 추가
	*	@pre	리스트가 초기화 되어야 함
	*	@post	새로운 레코드가 리스트에 추가됨
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int AddMusic();

	/**
	*	@brief	음악 리스트의 마지막 곡 번호 리턴
	*	@pre	음악 리스트에 적어도 하나의 아이템이 있어야 함
	*	@post	마지막 곡 번호가 반환됨
	*	@return	마지막 곡 번호 리턴
	*/
	int GetLastMusicNum();

	/**
	*	@brief	음악 아이템에 새로운 곡 번호 생성
	*	@pre	음악 리스트에 적어도 하나의 아이템이 있어야 함
	*	@post	새로운 곡 번호가 음악 아이템에 생성됨
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int CreateMusicNum(MusicType& music);

	/**
	*	@brief  곡 명이 포함되는 음악을 찾음
	*	@pre	음악 리스트에 적어도 하나의 아이템이 있어야 함
	*	@post	곡 명이 포함되는 음악을 찾을 시에 1을 리턴
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int GetByTitle(MusicType&);


	/**
	*	@brief	앨범명이 포함되는 음악을 찾음
	*	@pre	음악 리스트에 적어도 하나의 아이템이 있어야 함
	*	@post	앨범명이 포함되는 음악을 찾을 시에 1을 리턴
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int GetByAlbum(MusicType&);

	/**
	*	@brief	가수명이 포함되는 음악을 찾음
	*	@pre	음악 리스트에 적어도 하나의 아이템이 있어야 함
	*	@post	가수명이 포함되는 음악을 찾을 시에 1을 리턴
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int GetByArtist(MusicType&);


	/**
	*	@brief	장르가 포함되는 음악을 찾음 
	*	@pre	음악 리스트에 적어도 하나의 아이템이 있어야 함
	*	@post	장르가 포함되는 음악을 찾을 시에 1을 리턴
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int GetByGenre(MusicType&);

	/**
	*	@brief	리스트에 새로운 레코드 추가
	*	@pre	리스트가 초기화 되어야 함
	*	@post	새로운 레코드가 리스트에 추가됨
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int AddAlbum();

	/**
	*	@brief	리스트에 새로운 레코드 추가
	*	@pre	리스트가 초기화 되어야 함
	*	@post	새로운 레코드가 리스트에 추가됨
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int AddArtist();


	/**
	*	@brief	모든 레코드를 출력
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();


	/**
	*	@brief	모든 레코드를 출력
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllSinger();

	/**
	*	@brief	앨범명으로 음악 리스트의 정보를 업데이트함
	*	@pre	none.
	*	@post	앨범 리스트에서 변경된 정보가 음악 리스트에도 적용됨
	*/
	int UpdateMLByAlbum(AlbumType& album,AlbumType& newalbum);

	/**
	*	@brief	가수명으로 음악 리스트의 정보를 업데이트함
	*	@pre	none.
	*	@post	가수 리스트에서 변경된 정보가 음악 리스트에도 적용됨
	*/
	int UpdateMLBySinger(SingerType& singer,SingerType& newsinger);



	/**
	*	@brief	모든 레코드를 출력
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllAlbum();


	/**
	*	@brief	입력 파일을 읽어옴
	*	@pre	읽을 파일이 존재
	*	@post	읽기 전용 파일을 읽음
	*	@param	fileName	읽고자 하는 파일 이름
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	파일을 여는 함수
	*	@pre	리스트는 초기화 되어야 함
	*	@post	파일을 쓰기 전용으로 연다
	*	@param	fileName	쓰기 전용으로 열고자 하는 파일 명
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	파일을 읽기 전용으로 읽고, 파일 속 데이터를 자료구조에 입력
	*	@pre	파일이 아직 열리지 않은 상태
	*	@post	리스트는 파일로부터 모든 레코드를 유지
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int ReadDataFromFile();

	/**
	*	@brief 앨범, 가수 DB를 읽어옴
	*	@pre   파일이 아직 열리지 않은 상태
	*	@post  데이터를 읽어옴
	*	@return 성공시 1, 실패시 0 리턴
	*/

	int ReadInfo();

	/**
	*	@brief	파일을 읽기 전용으로 읽음
	*	@pre	파일이 아직 열리지 않은 상태
	*	@post	리스트 속 데이터는 결과 파일에 저장됨 
	*	@return	성공시 1, 실패시 0 리턴
	*/
	int WriteDataToFile();

	/**
	*	@brief	리스트에서 해당 노래 제목을 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchByName();
	
	/**
	*	@brief	리스트에서 해당 가수명을 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchByArtist();

	/**
	*	@brief	리스트에서 해당 앨범명을 가진 item을 찾아 출력한다.
	*	@pre	없음.
	*	@post	찾은 item이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchByAlbum();
	
	/**
	*	@brief	리스트에서 해당 장르명을 가진 item을 찾아 출력한다.
	*	@pre	없음.
	*	@post	찾은 item이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchByGenre();

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 제거한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 해당 item을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DeleteMusic();
	
	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 제거한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 해당 item을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DeleteAlbum();

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 제거한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 해당 item을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DeleteArtist();

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 변경한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 item이 변경된다.
	*/
	int ReplaceMusic();

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 변경한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 item이 변경된다.
	*/
	int ReplaceAlbum();

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 변경한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 item이 변경된다.
	*/
	int ReplaceArtist();


	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 재생한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 item이 재생된다.
	*/
	int PlayMusic();

	/**
	*	@brief	최근에 추가된 30곡의 자세한 정보를 화면에 출력.
	*	@pre	
	*	@post	최근 30곡의 정보가 출력
	*/ 
	void DisplayNewMusic();

	/**
	*	@brief	최근에 재생된 30곡의 자세한 정보를 화면에 출력.
	*	@pre
	*	@post	최근 30곡의 정보가 출력
	*/
	void DisplayMyPlayList();

	/**
	*	@brief	장르별로 출력
	*	@pre
	*	@post	장르별로 화면에 음악 출력
	*/
	void DisplayMusicByGenre();
	
	/**
	*	@brief	앨범별로 출력
	*	@pre
	*	@post	앨범별로 화면에 음악 출력
	*/
	int DisplayMusicByAlbum();

	// 음악 리스트 인터페이스
	void MusicListMenu();

	// 앨범 리스트 인터페이스
	void AlbumListMenu();

	// 가수 리스트 인터페이스
	void ArtistListMenu();

	// 장르 리스트 인터페이스
	void GenreListMenu();

	int DisplayArtistAlbum();

private:
	ifstream m_InFile;		// 입력 파일 DESCRIPTOR
	ofstream m_OutFile;		// 출력 파일 DESCRIPTOR
	
	//DoublySortedLinkedList<MusicType> MusicList;		// 모든 음악 정보가 저장된 리스트
	
	BinarySearchTree<MusicType> MusicList; // 모든 음악 정보가 저장될 리스트
	DoublySortedLinkedList<GenreType> my_GenreList; // 장르별로 음악을 관리하기 위한 리스트
	DoublySortedLinkedList<AlbumType> my_AlbumList; // 앨범별로 음악을 관리하기 위한 리스트									//LinkedList<
	DoublySortedLinkedList<SingerType> my_SingerList; // 가수별로 음악을 관리하기 위한 리스트

	CircularQueueType<SimpleMusicType> AddRecentlyMusicList; // 최근 추가한 곡들을 저장할 리스트
	CircularQueueType<SimpleMusicType> temp; // ARL 백업 큐
	
	CircularQueueType<SimpleMusicType> PlayedRecentlyMusicList; // 최근 플레이한 곡들을 저장할 리스트 (내 재생목록)
	CircularQueueType<SimpleMusicType> temp_p; // PRL 백업 큐

	ArrayListForInt deleted_num; // 지운 음악 번호를 저장하는 리스트

	int m_Command;			// 현재 명령어 번호

};

#endif	// _APPLICATION_H