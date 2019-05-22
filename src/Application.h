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
*	���α׷� ������ ���ϰ� �ϱ� ���� Application Ŭ����
*/

class Application 
{
public:
	/**
	*	�⺻ ������
	*/
	Application()
	{
		m_Command = 0; 
		temp.IsEmpty();  
		temp_p.IsEmpty();
		ReadInfo(); // �ٹ�, ���� ���� �о��

	}
	
	/**
	*	�Ҹ���
	*/
	~Application()	{}

	/**
	*	@brief	���α׷� ����̹�
	*	@pre	���α׷��� ����
	*	@post	���α׷� ����
	*/
	void Run();

	/**
	*	@brief	Ű����κ��� ����� �о�ͼ� �����Ŵ
	*	@pre	
	*	@post	
	*	@return	����� ���
	*/
	int GetCommand();

	/**
	*	@brief	����Ʈ�� ���ο� ���ڵ� �߰�
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ�� ��
	*	@post	���ο� ���ڵ尡 ����Ʈ�� �߰���
	*	@return	������ 1, ���н� 0 ����
	*/
	int AddMusic();

	/**
	*	@brief	���� ����Ʈ�� ������ �� ��ȣ ����
	*	@pre	���� ����Ʈ�� ��� �ϳ��� �������� �־�� ��
	*	@post	������ �� ��ȣ�� ��ȯ��
	*	@return	������ �� ��ȣ ����
	*/
	int GetLastMusicNum();

	/**
	*	@brief	���� �����ۿ� ���ο� �� ��ȣ ����
	*	@pre	���� ����Ʈ�� ��� �ϳ��� �������� �־�� ��
	*	@post	���ο� �� ��ȣ�� ���� �����ۿ� ������
	*	@return	������ 1, ���н� 0 ����
	*/
	int CreateMusicNum(MusicType& music);

	/**
	*	@brief  �� ���� ���ԵǴ� ������ ã��
	*	@pre	���� ����Ʈ�� ��� �ϳ��� �������� �־�� ��
	*	@post	�� ���� ���ԵǴ� ������ ã�� �ÿ� 1�� ����
	*	@return	������ 1, ���н� 0 ����
	*/
	int GetByTitle(MusicType&);


	/**
	*	@brief	�ٹ����� ���ԵǴ� ������ ã��
	*	@pre	���� ����Ʈ�� ��� �ϳ��� �������� �־�� ��
	*	@post	�ٹ����� ���ԵǴ� ������ ã�� �ÿ� 1�� ����
	*	@return	������ 1, ���н� 0 ����
	*/
	int GetByAlbum(MusicType&);

	/**
	*	@brief	�������� ���ԵǴ� ������ ã��
	*	@pre	���� ����Ʈ�� ��� �ϳ��� �������� �־�� ��
	*	@post	�������� ���ԵǴ� ������ ã�� �ÿ� 1�� ����
	*	@return	������ 1, ���н� 0 ����
	*/
	int GetByArtist(MusicType&);


	/**
	*	@brief	�帣�� ���ԵǴ� ������ ã�� 
	*	@pre	���� ����Ʈ�� ��� �ϳ��� �������� �־�� ��
	*	@post	�帣�� ���ԵǴ� ������ ã�� �ÿ� 1�� ����
	*	@return	������ 1, ���н� 0 ����
	*/
	int GetByGenre(MusicType&);

	/**
	*	@brief	����Ʈ�� ���ο� ���ڵ� �߰�
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ�� ��
	*	@post	���ο� ���ڵ尡 ����Ʈ�� �߰���
	*	@return	������ 1, ���н� 0 ����
	*/
	int AddAlbum();

	/**
	*	@brief	����Ʈ�� ���ο� ���ڵ� �߰�
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ�� ��
	*	@post	���ο� ���ڵ尡 ����Ʈ�� �߰���
	*	@return	������ 1, ���н� 0 ����
	*/
	int AddArtist();


	/**
	*	@brief	��� ���ڵ带 ���
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();


	/**
	*	@brief	��� ���ڵ带 ���
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllSinger();

	/**
	*	@brief	�ٹ������� ���� ����Ʈ�� ������ ������Ʈ��
	*	@pre	none.
	*	@post	�ٹ� ����Ʈ���� ����� ������ ���� ����Ʈ���� �����
	*/
	int UpdateMLByAlbum(AlbumType& album,AlbumType& newalbum);

	/**
	*	@brief	���������� ���� ����Ʈ�� ������ ������Ʈ��
	*	@pre	none.
	*	@post	���� ����Ʈ���� ����� ������ ���� ����Ʈ���� �����
	*/
	int UpdateMLBySinger(SingerType& singer,SingerType& newsinger);



	/**
	*	@brief	��� ���ڵ带 ���
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllAlbum();


	/**
	*	@brief	�Է� ������ �о��
	*	@pre	���� ������ ����
	*	@post	�б� ���� ������ ����
	*	@param	fileName	�а��� �ϴ� ���� �̸�
	*	@return	������ 1, ���н� 0 ����
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	������ ���� �Լ�
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ�� ��
	*	@post	������ ���� �������� ����
	*	@param	fileName	���� �������� ������ �ϴ� ���� ��
	*	@return	������ 1, ���н� 0 ����
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	������ �б� �������� �а�, ���� �� �����͸� �ڷᱸ���� �Է�
	*	@pre	������ ���� ������ ���� ����
	*	@post	����Ʈ�� ���Ϸκ��� ��� ���ڵ带 ����
	*	@return	������ 1, ���н� 0 ����
	*/
	int ReadDataFromFile();

	/**
	*	@brief �ٹ�, ���� DB�� �о��
	*	@pre   ������ ���� ������ ���� ����
	*	@post  �����͸� �о��
	*	@return ������ 1, ���н� 0 ����
	*/

	int ReadInfo();

	/**
	*	@brief	������ �б� �������� ����
	*	@pre	������ ���� ������ ���� ����
	*	@post	����Ʈ �� �����ʹ� ��� ���Ͽ� ����� 
	*	@return	������ 1, ���н� 0 ����
	*/
	int WriteDataToFile();

	/**
	*	@brief	����Ʈ���� �ش� �뷡 ������ ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchByName();
	
	/**
	*	@brief	����Ʈ���� �ش� �������� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchByArtist();

	/**
	*	@brief	����Ʈ���� �ش� �ٹ����� ���� item�� ã�� ����Ѵ�.
	*	@pre	����.
	*	@post	ã�� item�� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchByAlbum();
	
	/**
	*	@brief	����Ʈ���� �ش� �帣���� ���� item�� ã�� ����Ѵ�.
	*	@pre	����.
	*	@post	ã�� item�� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchByGenre();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� item�� �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DeleteMusic();
	
	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� item�� �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DeleteAlbum();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� item�� �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DeleteArtist();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� item�� ����ȴ�.
	*/
	int ReplaceMusic();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� item�� ����ȴ�.
	*/
	int ReplaceAlbum();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� item�� ����ȴ�.
	*/
	int ReplaceArtist();


	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� ����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� item�� ����ȴ�.
	*/
	int PlayMusic();

	/**
	*	@brief	�ֱٿ� �߰��� 30���� �ڼ��� ������ ȭ�鿡 ���.
	*	@pre	
	*	@post	�ֱ� 30���� ������ ���
	*/ 
	void DisplayNewMusic();

	/**
	*	@brief	�ֱٿ� ����� 30���� �ڼ��� ������ ȭ�鿡 ���.
	*	@pre
	*	@post	�ֱ� 30���� ������ ���
	*/
	void DisplayMyPlayList();

	/**
	*	@brief	�帣���� ���
	*	@pre
	*	@post	�帣���� ȭ�鿡 ���� ���
	*/
	void DisplayMusicByGenre();
	
	/**
	*	@brief	�ٹ����� ���
	*	@pre
	*	@post	�ٹ����� ȭ�鿡 ���� ���
	*/
	int DisplayMusicByAlbum();

	// ���� ����Ʈ �������̽�
	void MusicListMenu();

	// �ٹ� ����Ʈ �������̽�
	void AlbumListMenu();

	// ���� ����Ʈ �������̽�
	void ArtistListMenu();

	// �帣 ����Ʈ �������̽�
	void GenreListMenu();

	int DisplayArtistAlbum();

private:
	ifstream m_InFile;		// �Է� ���� DESCRIPTOR
	ofstream m_OutFile;		// ��� ���� DESCRIPTOR
	
	//DoublySortedLinkedList<MusicType> MusicList;		// ��� ���� ������ ����� ����Ʈ
	
	BinarySearchTree<MusicType> MusicList; // ��� ���� ������ ����� ����Ʈ
	DoublySortedLinkedList<GenreType> my_GenreList; // �帣���� ������ �����ϱ� ���� ����Ʈ
	DoublySortedLinkedList<AlbumType> my_AlbumList; // �ٹ����� ������ �����ϱ� ���� ����Ʈ									//LinkedList<
	DoublySortedLinkedList<SingerType> my_SingerList; // �������� ������ �����ϱ� ���� ����Ʈ

	CircularQueueType<SimpleMusicType> AddRecentlyMusicList; // �ֱ� �߰��� ����� ������ ����Ʈ
	CircularQueueType<SimpleMusicType> temp; // ARL ��� ť
	
	CircularQueueType<SimpleMusicType> PlayedRecentlyMusicList; // �ֱ� �÷����� ����� ������ ����Ʈ (�� ������)
	CircularQueueType<SimpleMusicType> temp_p; // PRL ��� ť

	ArrayListForInt deleted_num; // ���� ���� ��ȣ�� �����ϴ� ����Ʈ

	int m_Command;			// ���� ��ɾ� ��ȣ

};

#endif	// _APPLICATION_H