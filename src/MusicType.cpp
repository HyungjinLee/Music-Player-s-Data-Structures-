#include "MusicType.h"
#include "Screens.h"
#include "sfml_progress.h"

int MusicType::PlayMusic()
{

	m_playnum++; // 재생 횟수 증가

	std::vector<cScreen*> Screens;
	sf::Music music;
	int screen = 0;

	// window creation
	sf::RenderWindow App(sf::VideoMode(640, 480, 32), "Music Player");
	
	//Mouse cursor no more visible
	App.setMouseCursorVisible(false);



	//Screens preparations
	screen_0 s0;
	Screens.push_back(&s0);
	
	if (!music.openFromFile("audio/" + std::to_string(GetPrimaryKey()) + ".wav"))
		return -1; // error

	// Play music
	music.setVolume(50);
	music.play();

	//Main loop
	while (screen >= 0)
	{	
		screen = Screens[screen]->Run(App,music);
	}

	return EXIT_SUCCESS;

}
// 키보드에서 곡 번호를 입력받음
void MusicType::EnterNumFromKB()
{
	cout << "\tMusic Number : ";
	cin >> m_num;
}


// 키보드로부터 노래 제목을 입력
void MusicType::SetTitleFromKB()
{
	cout << "\tTitle : ";
	cin >> m_title;
}


// 키보드로부터 가수명을 입력
void MusicType::SetSingerFromKB()
{
	cout << "\tSinger : ";
	cin >> m_singer;
}


// 키보드로부터 앨범명을 입력
void MusicType::SetAlbumFromKB()
{
	cout << "\tAlbum : ";
	cin >> m_album;
}

// 키보드로부터 장르를 입력
void MusicType::SetGenreFromKB()
{
	cout << "\tGenre : ";
	cin >> m_genre;
}

// 키보드로부터 가사를 입력
void MusicType::SetLyricFromKB()
{
	cout << "\tLyric : ";
	cin.ignore();
	getline(cin, m_lyric);
}


// 키보드로부터 레코드를 입력
void MusicType::SetRecordFromKB()
{
	SetTitleFromKB();
	SetSingerFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetLyricFromKB();
}


// Read a record from file.
int MusicType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_title;
	fin >> m_singer;
	fin >> m_album;
	fin >> m_genre;
	fin >> m_playnum;
	getline(fin,m_lyric);

	return 1;
};


// Write a record into file.
int MusicType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_title << " ";
	fout << m_singer << " ";
	fout << m_album << " ";
	fout << m_genre << " ";
	fout << m_playnum << " ";
	fout << m_lyric;

	return 1;
}
