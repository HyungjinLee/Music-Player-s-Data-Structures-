#pragma once
#ifndef _MusicType_H
#define _MusicType_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
*	������ Ŭ����
*/
class MusicType
{
public:
	/**
	*	�⺻ ������
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
	*	@brief	�� ��ȣ�� ������
	*	@pre	�� ��ȣ�� �������־�� ��
	*	@post	�� ��ȣ�� ��ȯ
	*
	*/
	int GetPrimaryKey()
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
	*	@brief	�ٹ����� ������
	*	@pre	�ٹ����� �������־�� ��
	*	@post	�ٹ����� ��ȯ
	*
	*/
	string GetAlbum()
	{
		return m_album;
	}

	/**
	*	@brief	�帣�� ������
	*	@pre	�帣�� �������־�� ��
	*	@post	�帣�� ��ȯ
	*
	*/
	string GetGenre()
	{
		return m_genre;
	}
	
	/**
	*	@brief	���縦 ������
	*	@pre	���簡 �������־�� ��
	*	@post	���縦 ��ȯ
	*
	*/
	string GetLyric()
	{
		return m_lyric;
	}

	/**
	*	@brief	��� Ƚ���� ������
	*	@pre	��� Ƚ���� �������־�� ��
	*	@post	��� Ƚ���� ��ȯ
	*
	*/
	int GetplayNum()
	{
		return m_playnum;
	}

	/**
	*	@brief	�� ��ȣ�� ������
	*	@pre
	*	@post	�� ��ȣ�� ����
	*
	*/

	void SetPrimaryKey(int num)
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

	/**
	*	@brief	�������� ������
	*	@pre	
	*	@post	�������� ����
	*
	*/
	void SetSinger(string singer)
	{
		m_singer=singer;
	}

	/**
	*	@brief	�ٹ����� ������
	*	@pre
	*	@post	�ٹ����� ����
	*
	*/
	void SetAlbum(string album)
	{
		m_album=album;
	}

	/**
	*	@brief	�帣�� ������
	*	@pre	
	*	@post	�帣�� ����
	*
	*/
	void SetGenre(string genre)
	{
		m_genre=genre;
	}

	/**
	*	@brief	���縦 ������
	*	@pre
	*	@post	���縦 ����
	*
	*/
	void SetLyric(string lyric)
	{
		m_lyric = lyric;
	}
	/**
	*	@brief	��� Ƚ���� ������
	*	@pre
	*	@post	���Ƚ���� ����
	*
	*/
	void SetplayNum(int num)
	{
		m_playnum = num;
	}
	
	/**
	*	@brief	�뷡 ���ڵ带 ����
	*	@pre	
	*	@post	�뷡 ���ڵ尡 ������
	*	@param	m_title		���� ����.
	*	@param	m_singer	���� �̸�.
	*	@param	m_album		�ٹ� �̸�.
	*	@param  m_genre		���� �帣.
	*   @param  m_lyric		���� ����.
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
	*	@brief	��ũ���� �� ������ ������
	*	@pre	���̵� �����Ǿ�� ��
	*	@post	�뷡 ������ ���
	*/
	void DisplayNumOnScreen()
	{
		cout << "\tNum   : " << m_num << endl;
	};

	/**
	*	@brief	��ũ���� ���Ƚ���� ������
	*	@pre    ���̵� �����Ǿ�� ��
	*	@post	�뷡 ������ ���
	*/
	void DisplayPlaynumOnScreen()
	{
		cout << "\tPlayNum   : " << m_playnum << endl;
	};

	/**
	*	@brief	��ũ���� �뷡 ������ ������
	*	@pre	���̵� �����Ǿ�� ��
	*	@post	�뷡 ������ ���
	*/
	void DisplayTitleOnScreen() 
	{
		cout << "\tTitle   : " << m_title << endl; 
	};

	/**
	*	@brief	��ũ���� ���� �̸��� ������
	*	@pre	���� �̸��� �����Ǿ�� ��
	*	@post	���� �̸��� ���
	*/
	void DisplaySingerOnScreen() 
	{
		cout << "\tSinger : " << m_singer << endl; 
	};

	/**
	*	@brief	�ٹ� ������ ������
	*	@pre	�ٹ��� �����Ǿ�� ��
	*	@post	�ٹ� ������ ���
	*/
	void DisplayAlbumOnScreen() 
	{
		cout << "\tAlbum : " << m_album << endl; 
	};

	/**
	*	@brief	�帣�� ������
	*	@pre	�帣�� �����Ǿ�� ��
	*	@post	�帣�� ���
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre : " << m_genre << endl;
	};

	/**
	*	@brief	���縦 ������
	*	@pre	���簡 �����Ǿ�� ��
	*	@post	���縦 ���
	*/
	void DisplayLyricOnScreen()
	{
		cout << "\tLyric : " << m_lyric << endl;
	};


	/**
	*	@brief	�뷡 ���ڵ带 ȭ�鿡 ���
	*	@pre	�뷡 ���ڵ尡 �����Ǿ�� ��
	*	@post	�뷡 ���ڵ尡 ��µ�
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
	*	@brief	Ű���忡�� �� ��ȣ�� �Է¹��� - ���ϴ� �� ����
 	*	@pre
	*	@post	�뷡 �� ��ȣ�� ������
	*/	
	void EnterNumFromKB();

	/**
	*	@brief	Ű���忡�� �뷡 ������ �Է¹���
	*	@pre	
	*	@post	�뷡 ������ ������
	*/
	void SetTitleFromKB();

	/**
	*	@brief	Ű���忡�� �������� �Է¹���
	*	@pre
	*	@post	�������� ������
	*/
	void SetSingerFromKB();

	/**
	*	@brief	Ű���忡�� �ٹ����� �Է¹���
	*	@pre
	*	@post	�ٹ����� ������
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	Ű���忡�� �帣�� �Է¹���
	*	@pre
	*	@post	�帣�� ������
	*/
	void SetGenreFromKB();

	/**
	*	@brief	Ű���忡�� ���縦 �Է¹���
	*	@pre
	*	@post	���簡 ������
	*/
	void SetLyricFromKB();

	/**
	*	@brief	Ű����� ���� ���ڵ带 �Է¹���
	*	@pre
	*	@post	���ڵ尡 ������
	*/
	void SetRecordFromKB();


	/**
	*	@brief	���Ϸκ��� ���ڵ带 �о��
	*	@pre	Ÿ�� ������ �����־����
	*	@post	���� ���ڵ尡 ������
	*	@param	fin	file descriptor.
	*	@return	������ 1, ���н� 0 ����
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	���ڵ带 ���Ͽ� ��
	*	@pre	Ÿ�� ������ �����ְ�, ����Ʈ�� �ʱ�ȭ�Ǿ�� ��
	*	@post	Ÿ�� ���Ͽ� ���ο� ���� ���ڵ尡 �����
	*	@param	fout	file descriptor.
	*	@return	������ 1, ���н� 0 ����
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

	 // ������ ����Ѵ�.
	int PlayMusic();
	
	MusicType& GetNextItem()
	{
		return *this;
	}

protected:
	int m_num;			// Primary Key - ��ġ�� �ʰ�
	string m_title;		///< Music Title.
	string m_singer;	///< Singer Name.
	string m_album;		///< Album Name.
	string m_genre;		///< Genre.
	string m_lyric;		///< Lyrics Including space.
	int m_playnum;		// ���Ƚ��
};

#endif	// _MusicType_H
