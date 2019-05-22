#include "MusicType.h"
#include "Screens.h"
#include "sfml_progress.h"

int MusicType::PlayMusic()
{

	m_playnum++; // ��� Ƚ�� ����

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
// Ű���忡�� �� ��ȣ�� �Է¹���
void MusicType::EnterNumFromKB()
{
	cout << "\tMusic Number : ";
	cin >> m_num;
}


// Ű����κ��� �뷡 ������ �Է�
void MusicType::SetTitleFromKB()
{
	cout << "\tTitle : ";
	cin >> m_title;
}


// Ű����κ��� �������� �Է�
void MusicType::SetSingerFromKB()
{
	cout << "\tSinger : ";
	cin >> m_singer;
}


// Ű����κ��� �ٹ����� �Է�
void MusicType::SetAlbumFromKB()
{
	cout << "\tAlbum : ";
	cin >> m_album;
}

// Ű����κ��� �帣�� �Է�
void MusicType::SetGenreFromKB()
{
	cout << "\tGenre : ";
	cin >> m_genre;
}

// Ű����κ��� ���縦 �Է�
void MusicType::SetLyricFromKB()
{
	cout << "\tLyric : ";
	cin.ignore();
	getline(cin, m_lyric);
}


// Ű����κ��� ���ڵ带 �Է�
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
