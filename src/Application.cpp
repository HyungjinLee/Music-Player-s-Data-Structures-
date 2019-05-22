#include "Application.h"
#include <Windows.h>

// 콘솔 상에서 커서를 이동
void gotoxy(int x, int y)
{
	COORD pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Application::Run()
{
	while (1)
	{
		system("cls");

		m_Command = GetCommand();
		
		switch (m_Command)
		{
		case 1:	// 음악 리스트 메뉴
			MusicListMenu();
			break;
		case 2:	// 앨범 리스트 메뉴
			AlbumListMenu();
			break;
		case 3:	// 가수 리스트 메뉴
			ArtistListMenu();
			break;
		case 4:	// 장르 리스트 메뉴
			GenreListMenu();
			break;
		case 5: // txt 파일에서 음악정보를 읽어온다
			if (ReadDataFromFile()) // 로드 성공하면
			{
				cout << "Loading Success!" << endl;
				system("Pause");
			}
			
			break;
		case 6:	// txt 파일에 음악정보를 쓴다
			WriteDataToFile();
			break;	
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// 뮤직 리스트 메뉴

void Application::MusicListMenu()
{
	int com;

	while (1)
	{
		system("cls");
		cout << " MusicList" << endl;
		cout << endl << "________________________ " << endl;
		cout << "1. Add Music " << endl;
		cout << "2. Delete Music " << endl;
		cout << "3. Replace Music" << endl;
		cout << "4. Play Music" << endl;
		cout << "5. Recently Added List (30)" << endl;
		cout << "6. My PlayList (30)" << endl;
		cout << "7. Go Previous" << endl;



		cout << "command -> ";

		cin >> com;

		if (cin.fail())
		{
			// 버퍼를 제거해 주어 무한루프 방지
			cin.clear();
			cin.ignore();
		}

		string id;
		string pass;

		switch (com)
		{
		case 1: // 음악 리스트 추가
			AddMusic();
			system("Pause");
			break;
		case 2: // 음악 리스트 삭제
			DeleteMusic();
			system("Pause");
			break;
		case 3: // 음악 리스트 갱신
			ReplaceMusic();
			system("Pause");
			break;

		case 4: // 음악 재생
			system("cls");
			DisplayAllMusic(); // 일단 음악 리스트를 모두 출력한 후
			PlayMusic(); // 음악을 골라서 하나씩 플레이
			break;

		case 5: // 최근 추가 목록 30곡
			system("cls");
			DisplayNewMusic(); // 새 30곡을 출력
			system("Pause");
			break;

		case 6: // 최근 재생 목록 30곡
			system("cls");
			DisplayMyPlayList(); // 내 재생목록 30곡 출력
			system("Pause");
			break;

		case 7: // 이전 메뉴
			system("cls");
			Run();
			return ;

		default: // 예외 처리
			cout << "Wrong Input!!";
		}

	}
	system("Pause");

}
// 앨범 리스트 메뉴
void Application::AlbumListMenu()
{
	int com;

	while (1)
	{
		system("cls");
		cout << " AlbumList" << endl;
		cout << endl << "________________________ " << endl;
		cout << "1. Add Album " << endl;
		cout << "2. Delete Album " << endl;
		cout << "3. Replace Album" << endl;
		cout << "4. Display All Albums" << endl;
		cout << "5. Display Music in Album" << endl;
		cout << "6. Go Previous" << endl;

		cout << "command -> ";

		cin >> com;

		if (cin.fail())
		{
			// 버퍼를 제거해 주어 무한루프 방지
			cin.clear();
			cin.ignore();
		}

		switch (com)
		{
		case 1: // 앨범 추가
			system("cls");
			AddAlbum();
			system("Pause");
			break;
		case 2: // 앨범 삭제
			system("cls");
			DeleteAlbum();
			system("Pause");
			break;
		case 3: // 앨범 갱신
			system("cls");
			ReplaceAlbum();
			system("Pause");
			break;

		case 4: // 모든 앨범 출력
			system("cls");
			DisplayAllAlbum();
			system("Pause");
			break;

		case 5: // 앨범 별 음악 출력
			system("cls");
			DisplayMusicByAlbum();
			system("Pause");
			break;
		case 6: // 이전 메뉴
			system("cls");
			Run();
			return ;

		default: // 예외 처리
			cout << "Wrong Input!!";
		}

	}
	
}

// 앨범 추가
int Application::AddAlbum()
{
	// 입력받은 레코드를 리스트에 추가

	AlbumType item;
	item.SetRecordFromKB();

	if (my_AlbumList.Get(item))// 중복 검사
	{
		cout << "Duplication in Album!!" << endl;
		return 0; // 실패
	}

	// 새 앨범을 앨범리스트에 추가
	my_AlbumList.Add(item);

	return 1;
}

// 앨범 삭제
int Application::DeleteAlbum()
{
	AlbumType item;
	item.EnterKeyFromKB(); // 앨범명, 가수명을 입력받음

	if (!my_AlbumList.Get(item))
	{
		cout << "<========DELETE FAIL !=======>" << endl; // 찾지 못한 경우
		this->DisplayAllAlbum();//모든 item을 출력한다.
		system("Pause");
		return 0;
	}

	cout << "<========DELETE SUCCESS !===========>" << endl;
	my_AlbumList.Delete(item);
	this->DisplayAllAlbum(); // 모든 item을 출력한다.
	return 1;
}

// 앨범 갱신
int Application::ReplaceAlbum()
{
	DisplayAllAlbum();
	AlbumType item;
	item.EnterKeyFromKB(); // 앨범명, 가수명을 입력받음

	AlbumType newitem; // 새로운 아이템
	newitem.SetName(item.GetName()); // 앨범명 설정
	newitem.SetSinger(item.GetSinger()); // 가수명 설정
	
	MusicType m_item;
	m_item.SetAlbum(item.GetName());
	m_item.SetSinger(item.GetSinger());

	if (!my_AlbumList.Get(item))
	{
		cout << "<======== Cannot Find It!==========>" << endl;
		return 0;
	}

	cout << "<======== Replace ==========>" << endl;

	my_AlbumList.Replace(newitem); // 앨범 리스트 갱신	 
	UpdateMLByAlbum(item,newitem);		// 음악 리스트 갱신

	this->DisplayAllAlbum(); // 모든 item을 출력한다.
	return 1;
}

void Application::ArtistListMenu()
{
	int com;

	while (1)
	{	
		system("cls");
		cout << " ArtistList" << endl;
		cout << endl << "________________________ " << endl;
		cout << "1. Add Artist " << endl;
		cout << "2. Delete Artist " << endl;
		cout << "3. Replace Artist" << endl;
		cout << "4. Search by Artist" << endl;
		cout << "5. Display all Album" << endl;
		cout << "6. Go Previous" << endl;

		cout << "command -> ";

		cin >> com;

		if (cin.fail())
		{
			// 버퍼를 제거해 주어 무한루프 방지
			cin.clear();
			cin.ignore();
		}

		switch (com)
		{
		case 1: // 가수 추가
			AddArtist();
			system("Pause");
			break;
		case 2: // 가수 삭제
			DeleteArtist();
			system("Pause");
			break;
		case 3: // 가수 갱신
			ReplaceArtist();
			system("Pause");
			break;

		case 4: // 가수 별 검색
			system("cls");
			DisplayAllSinger();
			SearchByArtist(); 
			system("Pause");
			break;

		case 5: // 모든 앨범 안에 있는 곡 출력
			system("cls");
			DisplayArtistAlbum();
			system("Pause");
			break;

		case 6: // 이전 메뉴
			system("cls");
			Run();
			return ;

		default: // 예외 처리
			cout << "Wrong Input!!";
		}

	}
	system("Pause");

}

void Application::GenreListMenu()
{
	int com;

	while (1)
	{
		system("cls");
		cout << " GenreList" << endl;
		cout << endl << "________________________ " << endl;
		cout << "1. Search by Genre " << endl;		  // 장르로 검색
		cout << "2. Display Music by Genre " << endl; // 장르 별로 음악 출력
		cout << "3. Go Previous" << endl;

		cout << "command -> ";

		cin >> com;

		if (cin.fail())
		{
			// 버퍼를 제거해 주어 무한루프 방지
			cin.clear();
			cin.ignore();
		}

		string id;
		string pass;

		switch (com)
		{
		case 1: // 장르로 음악 검색
			SearchByGenre();
			system("Pause");
			break;
		case 2: // 장르 별 음악 출력
			DisplayMusicByGenre();
			system("Pause");
			break;
		case 3: // 이전 메뉴
			system("cls");
			Run();
			return ;

		default: // 예외 처리
			cout << "Wrong Input!!";
		}

	}
	system("Pause");

}
// 음악을 재생한다.
int Application::PlayMusic()
{

	MusicType* item;
	item = new MusicType();

	SimpleMusicType s_item;
	bool found=false;

	item->EnterNumFromKB(); // 키보드로부터 재생하고자 하는 곡 번호를 읽어옴
	
	s_item.SetNum(item->GetPrimaryKey());
	s_item.SetTitle(item->GetTitle());

	item = MusicList.GetPointer(item,found);

	if (!found) // 아이템을 찾지 못한 경우
	{
		cout << "<======== Cannot Find Music==========>" << endl;
		system("Pause");
		return 0;
	}

	system("cls");

	item->DisplayRecordOnScreen(); // 재생하는 음악 정보 출력


	// 새 곡을 최근 재생목록에 추가	

	if (PlayedRecentlyMusicList.IsFull()) // 최근 재생 목록이 꽉 차면
	{
		SimpleMusicType d_item; // 지우고자 하는 아이템
		PlayedRecentlyMusicList.DeQueue(d_item); // 가장 앞에 있는 아이템 제거하고
		PlayedRecentlyMusicList.EnQueue(s_item); // 새로운 아이템 추가

		cout << "Recently Played Music List is Full!" << endl; // 최신 재생 리스트 꽉 찼음
	}

	else // 새 곡을 최근 재생목록에 추가
	{
		PlayedRecentlyMusicList.EnQueue(s_item);
	}

	item->PlayMusic(); // 곡을 재생!!
	system("Pause");

	return 0;
}

// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;cout << "\t   1 : Music List" << endl;
	cout << "\t   2 : Album List" << endl;
	cout << "\t   3 : Singer List" << endl;
	cout << "\t   4 : Genre List" << endl;
	cout << "\t   5 : Read from file" << endl;
	cout << "\t   6 : Write to file" << endl;
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	

	if (cin.fail())
	{
		// 버퍼를 제거해 주어 무한루프 방지
		cin.clear();
		cin.ignore();
	}

	cout << endl;

	return command;
}

// Add new record into list.
int Application::AddMusic()
{
	// 입력받은 레코드를 리스트에 추가

	MusicType item;
	item.SetRecordFromKB();
	
	// 새 곡을 음악 리스트에 추가
	// 중복 제거 알고리즘 - 곡 번호 생성
	CreateMusicNum(item);
	MusicList.Add(item);

	SimpleMusicType s_item; // 간단한 음악 타입
	SimpleAlbumType s_album; // 간단한 앨범 타입

	s_item.SetNum(item.GetPrimaryKey()); // 곡 번호 설정
	s_item.SetTitle(item.GetTitle()); // 곡 제목 설정

	// 새 곡을 장르 리스트에 추가
	
	GenreType genre; // 장르 타입
	genre.SetGenre(item.GetGenre()); // 장르 설정

	GenreType* mygenre = my_GenreList.GetPointer(genre);

	if (mygenre) // 일치하는 장르 타입을 발견할 경우
	{
		mygenre->Add(s_item); // 해당 장르 타입에 간단한 음악 타입 하나만 추가
	}
	else
	{
		genre.Add(s_item); // 먼저 장르 타입에 간단한 음악 하나 추가
		my_GenreList.Add(genre); // 장르 리스트에 장르 추가
	}

	AlbumType album; // 앨범 타입
	album.SetName(item.GetAlbum()); // 앨범명 설정
	album.SetSinger(item.GetSinger()); // 가수 설정
	
	AlbumType* myalbum = my_AlbumList.GetPointer(album);
	
	if (myalbum) // 일치하는 앨범 타입을 발견할 경우
	{
		myalbum->Add(s_item); // 해당 앨범 타입에 간단한 음악 타입 하나만 추가
	}
	else
	{
		album.Add(s_item); // 먼저 앨범타입에 간단한 음악 타입 아이템 하나 추가
		my_AlbumList.Add(album); // 앨범리스트에 앨범 추가										 
	}

	SingerType singer; // 가수 타입
	singer.SetName(item.GetSinger()); // 가수명 설정
	singer.SetGenre(item.GetGenre()); // 장르 설정

	SingerType* mysinger = my_SingerList.GetPointer(singer);

	s_album.SetName(item.GetAlbum()); // 앨범 명 설정
	s_album.SetSinger(item.GetSinger()); // 가수 명 설정


	if (mysinger) // 일치하는 앨범 타입을 발견할 경우
	{
		mysinger->Add(s_album); // 해당 가수 타입에 간단한 앨범 타입 하나만 추가
	}
	else
	{
		singer.Add(s_album); // 먼저 가수타입에 간단한 앨범 타입 아이템 하나 추가
		my_SingerList.Add(singer); // 가수리스트에 가수 추가										 
	}

	if (AddRecentlyMusicList.IsFull()) // 최근 추가 목록이 꽉 차면
	{
		SimpleMusicType d_item; // 지우고자 하는 아이템
		AddRecentlyMusicList.DeQueue(d_item); // 가장 앞에 있는 아이템 제거하고
		AddRecentlyMusicList.EnQueue(s_item); // 새로운 아이템 추가
		cout << "Recently Music List is Full!";
	}
	else // 새 곡을 최근 추가목록에 추가
	{
		AddRecentlyMusicList.EnQueue(s_item);
	}

	// 현재 list 출력
	DisplayAllMusic();
	return 1;
}

// 아티스트의 앨범 및 수록곡을 모두 출력
int Application::DisplayArtistAlbum()
{
	DisplayAllSinger(); // 현재 모든 가수를 출력

	SingerType* mysinger = new SingerType(); // 가수 타입
	mysinger->SetNameFromKB(); // 가수 선택을 위한 정보 입력

	SimpleMusicType s_item; // 간단한 음악 타입
	SimpleAlbumType s_album; // 간단한 앨범 타입
	int num; // 음악 리스트에서 찾을 음악의 곡 번호 

	MusicType item; // 비교를 위한 음악타입 객체
	AlbumType album; // 비교를 위한 앨범타입 객체

	mysinger = my_SingerList.GetPointer(*mysinger); // 가수를 찾음

	if (mysinger == NULL) // 가수를 찾지 못한 경우
	{
		cout << "<========I CAN'T FIND ARTIST !==========>" << endl;
		return 0;
	}

	cout << mysinger->GetName() << "'s Album." << endl; // 가수 이름 출력

	cout << "********************************" << endl;

	mysinger->ResetSAList(); // 리스트 리셋

	bool finished = false;
	bool found = false;

	while (!finished)
	{
		mysinger->GetNextItem(s_album, finished); // 앨범 타입에서 다음 간단한 음악 타입 객체를 얻음
		album.SetName(s_album.GetName()); // 앨범 이름 설정
		album.SetSinger(s_album.GetSinger()); // 가수 명 설정
		my_AlbumList.Get(album); // 앨범리스트에서 검색

		album.DisplayRecordOnScreen(); // 앨범 정보 출력
		
	}

	cout << endl << "********************************" << endl;
	cout << "which album do you want?" << endl;
	album.EnterKeyFromKB();

	my_AlbumList.Get(album); // 앨범리스트에서 검색

	cout << "********************************" << endl;
	album.ResetSMList();

	finished = false;
	found = false;

	while (!finished)
	{
		album.GetNextItem(s_item, finished); // 앨범 타입에서 다음 간단한 음악 타입 객체를 얻음
		item.SetPrimaryKey(s_item.GetNum()); // 음악 객체의 번호를 설정
		MusicList.RetrieveItem(item, found); // 음악 리스트에서 찾음

		if (found)
		{
			item.DisplayRecordOnScreen(); // 음악 정보 출력
		}
	}

	cout << endl << "********************************" << endl;


	return 1;


}

// 장르 별로 화면에 출력
void Application::DisplayMusicByGenre()
{
	GenreType myGenre; // 장르 타입
	SimpleMusicType s_item; // 간단한 음악 타입
	int num; // 음악 리스트에서 찾을 음악의 곡 번호 

	MusicType item; // 비교를 위한 음악타입 객체
	DoublyIterator<GenreType> itor(my_GenreList);


	for (int i = 0; i < my_GenreList.GetLength(); i++) // 장르 리스트의 갯수 만큼 ex) 랩, 댄스, 발라드 - 3개
	{
		myGenre = *itor.Next(); // 장르 리스트의 다음 아이템을 얻어옴

		cout << myGenre.GetGenre() << endl; // 장르 출력

		cout << "********************************" << endl;
		myGenre.ResetSMList();	// SMLIST 리셋
		
		bool finished = false;
		bool found = false;


		while (!finished)
		{	
			myGenre.GetNextItem(s_item,finished);	// 장르 타입에서 다음 간단한 음악 타입 객체를 얻음
			item.SetPrimaryKey(s_item.GetNum());	// 음악 객체의 번호를 설정
			MusicList.RetrieveItem(item, found);	// 음악 리스트에서 찾음
			
			if (found)
			{
				item.DisplayRecordOnScreen();	// 음악 정보 출력
			}
		}

		cout << endl << "********************************" << endl;
	}
}

// 앨범 별로 화면에 출력
int Application::DisplayMusicByAlbum()
{
	DisplayAllAlbum(); // 현재 모든 앨범을 출력

	AlbumType* myAlbum = new AlbumType(); // 앨범 타입
	myAlbum->EnterKeyFromKB(); // 출력하고자 하는 앨범을 찾기 위해 주요 키 입력

	SimpleMusicType s_item; // 간단한 음악 타입
	int num; // 음악 리스트에서 찾을 음악의 곡 번호 

	MusicType item; // 비교를 위한 음악타입 객체
	
	DoublyIterator<AlbumType> itor(my_AlbumList);
	myAlbum = my_AlbumList.GetPointer(*myAlbum); // 앨범을 찾음

	if (myAlbum == NULL)
	{
		cout << "<========I CAN'T FIND ALBUM !==========>" << endl;
		return 0;
	}
	cout << myAlbum->GetName() << endl; // 앨범 명 출력

	cout << "********************************" << endl;
	myAlbum->ResetSMList();

	bool finished = false;
	bool found = false;

	while (!finished)
	{
		myAlbum->GetNextItem(s_item, finished); // 앨범 타입에서 다음 간단한 음악 타입 객체를 얻음
		item.SetPrimaryKey(s_item.GetNum()); // 음악 객체의 번호를 설정
		MusicList.RetrieveItem(item, found); // 음악 리스트에서 찾음

		if (found)
		{
			item.DisplayRecordOnScreen(); // 음악 정보 출력
		}
	}

	cout << endl << "********************************" << endl;
	return 1;
}

/** 최근에 추가된 30곡의 자세한 정보 출력

* 만약 MUSIC LIST에 A B C 가 있는 상태에서 
* B를 삭제하고 새로운 D를 생성하는 경우
* MUSIC LIST에는 곡 번호 순으로 A D C
* AML(추가기록) 에는 A C D 순으로 기록이 남는다.
  
*/

void Application::DisplayNewMusic()
{
	temp = AddRecentlyMusicList; // 큐는 Dequeue하면 데이터를 잃어버리므로 백업

	MusicType item; // 음악 타입
	
	SimpleMusicType s_item; // 간단한 음악 타입
	bool found=false;

	if (temp.IsEmpty()) // 최근 재생목록이 비어있으면
	{
		cout << "Recently Music List is Empty!" << endl;
	}

	else // 최근 재생목록이 존재하면
	{
		cout << "Recently Added Music" << endl;

		while (!temp.IsEmpty()) // 큐가 빌 때 까지
		{
			temp.DeQueue(s_item); // 최근 재생 음악에 대한 간단한 정보를 받아옴	
			item.SetPrimaryKey(s_item.GetNum()); // 곡 번호 설정
			MusicList.RetrieveItem(item,found);

			if (found) // 아이템을 찾은 경우
			{
				item.DisplayRecordOnScreen(); // 곡 정보를 출력
			}		
		}
	}
}

// 플레이 리스트를 출력
void Application::DisplayMyPlayList() 
{
	temp_p = PlayedRecentlyMusicList; // 큐는 Dequeue하면 데이터를 잃어버리므로 백업

	MusicType item; // 음악 타입
	SimpleMusicType s_item; // 간단한 음악 타입

	if (temp_p.IsEmpty()) // 최근 재생목록이 비어있으면
	{
		cout << "My PlayList is Empty!" << endl;
	}

	else // 최근 재생목록이 존재하면
	{
		cout << "\t\tMy PlayList" << endl;

		while (!temp_p.IsEmpty()) // 큐가 빌 때 까지
		{
			temp_p.DeQueue(s_item); // 최근 재생 음악에 대한 간단한 정보를 받아옴	
			item.SetPrimaryKey(s_item.GetNum()); // 곡 번호 설정
			bool found;
			MusicList.RetrieveItem(item,found); // 뮤직 리스트에서 검색

			if (found) // 아이템을 찾은 경우
			{
				item.DisplayRecordOnScreen(); // 곡 정보를 출력
			}
		}

		string com;
		cout << "You Want Play Music (press 'y' if you want) ?\t command -> ";

		cin >> com;

		if(com == "y")
			PlayMusic(); // 음악 재생
					

	}
}

// 가수 추가
int Application::AddArtist()
{
	// 입력받은 레코드를 리스트에 추가

	SingerType item;
	item.SetRecordFromKB();

	if (my_SingerList.Get(item)) // 중복 검사
	{
		cout << "Duplication in Singer!!" << endl;
		return 0;
	}
	my_SingerList.Add(item); // 새 가수를 가수리스트에 추가
	return 1;
}

// 가수 제거
int Application::DeleteArtist()
{
	SingerType item;
	item.SetNameFromKB(); 

	if (!my_SingerList.Get(item))
	{
		cout << "<========DELETE FAIL !=======>" << endl; // 찾지 못한 경우
		this->DisplayAllSinger();//모든 item을 출력한다.
		return 0;
	}

	cout << "<========DELETE SUCCESS !===========>" << endl;
	my_SingerList.Delete(item);
	this->DisplayAllSinger(); // 모든 item을 출력한다.
	return 1;
}

// 앨범 정보를 바꾼 경우 음악 리스트에서도 업데이트
int Application::UpdateMLByAlbum(AlbumType& album,AlbumType& newalbum)
{

	MusicType *item_p;
	MusicType item;

	bool found = false;
	bool finished = false;

	MusicList.ResetTree(); // 트리를 리셋함

	while (!finished)
	{
		MusicList.GetNextItem(item, finished); // 다음 아이템 얻음
		if (item.GetAlbum() == album.GetName()) // 같은 앨범 아이템을 찾으면
		{
			item_p = MusicList.GetPointer(&item, found);
			item_p->SetAlbum(newalbum.GetName()); // 음악 리스트 정보 갱신
			item_p->SetSinger(newalbum.GetSinger()); // 음악 리스트 정보 갱신
		}
	}

	if (found)
		return 1; // 성공
	else
		return 0; //실패
		
}

// 가수 정보를 바꾼 경우 음악 리스트에서도 업데이트
int Application::UpdateMLBySinger(SingerType& singer, SingerType& newsinger)
{
	MusicType *item_p;
	MusicType item;

	bool found = false;
	bool finished = false;

	MusicList.ResetTree(); // 트리를 리셋함


	while (!finished)
	{
		MusicList.GetNextItem(item, finished); // 다음 아이템 얻음
		if (item.GetSinger() == singer.GetName()) // 같은 가수 아이템을 찾으면
		{
			item_p = MusicList.GetPointer(&item, found);
			item_p->SetSinger(newsinger.GetName()); // 새 가수명 설정
		}
	}


	if (found)
		return 1; // 성공
	else
		return 0; //실패

}

// 가수 갱신
int Application::ReplaceArtist()
{
	DisplayAllSinger();
	SingerType item;
	item.SetNameFromKB(); 

	if (!my_SingerList.Get(item))
	{
		cout << "<======== Cannot Find It!==========>" << endl;
		return 0;
	}

	cout << "<======== Replace ==========>" << endl;

	SingerType newitem;
	newitem.SetName(item.GetName());

	my_SingerList.Replace(newitem); // 가수 리스트 갱신

	UpdateMLBySinger(item,newitem); // 음악 리스트 갱신


	this->DisplayAllSinger(); // 모든 item을 출력한다.
	return 1;
}


// 곡 제목으로 item을 찾아 출력한다.
int Application::SearchByName()
{
	MusicType item;

	item.SetTitleFromKB();	//id를 입력받는다
	cout << "<====================================>" << endl;

	if (GetByTitle(item))	// 검색어를 포함한다면
	{
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 반환
	}
	//발견 못할시
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 반환

}

//가수명으로 item을 찾아 출력한다.
int Application::SearchByArtist()
{
	MusicType item;
	item.SetSingerFromKB(); //가수 명 입력받는다.

	cout << "<=========================>" << endl;


	if (GetByArtist(item)) //0이 아니면(찾으면)
	{
		cout << "<=========================>" << endl;

		return 1;	//성공(1)을 리턴
	}
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 리턴
}

//앨범명으로 item을 찾아 출력한다.
int Application::SearchByAlbum()
{
	MusicType item;
	item.SetAlbumFromKB(); //앨범 명 입력받는다.

	cout << "<=========================>" << endl;


	if (GetByAlbum(item)) //0이 아니면(찾으면)
	{
		cout << "<=========================>" << endl;

		return 1;	//성공(1)을 리턴
	}
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 리턴
}

//장르명으로 item을 찾아 출력한다.
int Application::SearchByGenre()
{
	MusicType item;
	item.SetGenreFromKB(); //장르 명 입력받는다.

	cout << "<=========================>" << endl;


	if (GetByGenre(item)) //0이 아니면(찾으면)
	{

		cout << "<=========================>" << endl;

		return 1;	//성공(1)을 리턴
	}
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 리턴
}

// 곡 제목으로 찾는다
int Application::GetByTitle(MusicType& music)
{
	MusicType item;
	bool found = false;
	bool finished = false;

	MusicList.ResetTree(); // 트리를 리셋함

	while (!finished)
	{
		MusicList.GetNextItem(item, finished); // 다음 아이템 얻음
		if (strstr(item.GetTitle().c_str(), music.GetTitle().c_str())) // 곡명이 포함되면
		{
			item.DisplayRecordOnScreen(); // 정보 출력
			found = true; // 찾음
		}
	}
	if (found)
		return 1; // 성공
	else
		return 0; //실패

	return 1;

}

// 앨범명으로 찾는다
int Application::GetByAlbum(MusicType& music)
{
	MusicType item;
	bool found = false;
	bool finished = false;

	MusicList.ResetTree(); // 트리를 리셋함

	while (!finished)
	{
		MusicList.GetNextItem(item, finished); // 다음 아이템 얻음
		if (strstr(item.GetAlbum().c_str(), music.GetAlbum().c_str())) // 앨범명이 포함되면
		{
			item.DisplayRecordOnScreen(); // 정보 출력
			found = true; // 찾음
		}
	}
	if (found)
		return 1; // 성공
	else
		return 0; //실패

}

// 가수명으로 찾는다
int Application::GetByArtist(MusicType& music)
{
	MusicType item;
	bool found = false;
	bool finished = false;

	MusicList.ResetTree(); // 트리를 리셋함

	while (!finished)
	{
		MusicList.GetNextItem(item, finished); // 다음 아이템 얻음
		if (strstr(item.GetSinger().c_str(), music.GetSinger().c_str())) // 가수명이 포함되면
		{
			item.DisplayRecordOnScreen(); // 정보 출력
			found = true; // 찾음
		}
	}
	if (found)
		return 1; // 성공
	else
		return 0; //실패
	
	return 1;
}

// 장르명으로 찾는다
int Application::GetByGenre(MusicType& music)
{
	MusicType item;
	bool found = false;
	bool finished = false;
	
	MusicList.ResetTree(); // 트리를 리셋함

	while (!finished)   
	{
		MusicList.GetNextItem(item, finished); // 다음 아이템 얻음
		if (strstr(item.GetGenre().c_str(), music.GetGenre().c_str())) // 장르명이 포함되면
		{
			item.DisplayRecordOnScreen(); // 정보 출력
			found = true; // 찾음
		}
	}
	if (found)
		return 1; // 성공
	else
		return 0; //실패
}

//id로 item을 찾아서 제거한다.
int Application::DeleteMusic()
{
	temp = AddRecentlyMusicList; // 큐는 Dequeue하면 데이터를 잃어버리므로 백업

	int pre = MusicList.GetLength();//이전 item개수를 받아온다.

	MusicType item;
	item.EnterNumFromKB(); // 음악 타입에 설정할 곡 번호를 입력 받음
	bool found=false;

	MusicList.RetrieveItem(item, found); // 음악 리스트에서 지우고자 하는 아이템을 받아옴
	
	if(!found)
	{
		cout << "<========DELETE FAIL !=======>" << endl; // 찾지 못한 경우
		this->DisplayAllMusic();//모든 item을 출력한다.
		return 0;
	}

	MusicList.DeleteItem(item); // 음악 리스트에서 해당 번호의 아이템을 삭제

	GenreType* genre_p;
	GenreType genre;

	int itemnum;

	genre.SetGenre(item.GetGenre()); // 장르 입력

	genre_p = my_GenreList.GetPointer(genre); // 해당 곡에 대한 SimpleMusicType을 포함하는 GenreType 포인터를 반환	

	if (genre_p != NULL)
	{
		genre_p->Delete(item.GetPrimaryKey()); // 해당 장르 타입에서 음악 제거
		
		itemnum = genre_p->GetSMListSize();

		if (itemnum == 0) // SIMPLETYPE 아이템이 하나도 없으면 
		{
			my_GenreList.Delete(*genre_p); // 그 장르 제거
		}
	}
	
	AlbumType* album_p;
	AlbumType album;

	album.SetName(item.GetAlbum()); // 앨범명 입력
	album.SetSinger(item.GetSinger()); // 가수 명 입력

	album_p = my_AlbumList.GetPointer(album); // 해당 곡에 대한 SimpleMusicType을 포함하는 AlbumType 포인터를 반환	

	SingerType* singer_p;
	SingerType singer;

	singer.SetName(item.GetSinger()); // 가수명 입력
	singer_p = my_SingerList.GetPointer(singer); // 가수 검색

	SimpleAlbumType s_album;
	s_album.SetName(item.GetAlbum());
	s_album.SetSinger(item.GetSinger());
	
	if (album_p != NULL)
	{

		album_p->Delete(item.GetPrimaryKey()); // 해당 앨범 타입에서 음악 제거

		itemnum = album_p->GetSMListSize();

		if (itemnum == 0) // SIMPLETYPE 아이템이 하나도 없으면 
		{
			my_AlbumList.Delete(*album_p); // 그 앨범 제거
			
			if (singer_p != NULL) // 가수를 찾은 경우
				singer_p->Delete(s_album.GetName(), s_album.GetSinger()); // 해당 가수 안에 있는 앨범 삭제 
		}

	}


	if (pre > MusicList.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		cout << "<========DELETE SUCCESS !===========>" << endl;

		deleted_num.Add(item.GetPrimaryKey()); // 지우고자 하는 곡 번호를 리스트에 넣음
		this->DisplayAllMusic(); //모든 item을 출력한다.
		return 1;
	}
	
	cout<<"<========DELETE FAIL !=======>"<<endl;
	this->DisplayAllMusic();//모든 item을 출력한다.
	return 0;
}

// 음악 리스트의 마지막 곡 번호를 리턴
int Application::GetLastMusicNum()
{
	MusicType item;
	MusicList.GetLastItem(item); // 마지막 번호를 얻음
	return (item.GetPrimaryKey());
}

// 새로운 곡 번호를 생성
int Application::CreateMusicNum(MusicType& music)
{
	int mynum;

	if (MusicList.GetLength() == 0) // 음악 리스트가 비어 있을 때
	{
		if (deleted_num.GetLength() == 0)
			mynum = 1; // 처음 번호는 1 
		else // 전에 지운 번호가 존재할 때
		{
			mynum = deleted_num.GetLastNum() + 1;
		}
	}

	else if (deleted_num.GetLength() != 0 && deleted_num.GetLastNum() > GetLastMusicNum()) // 마지막 번호를 지웠을 때
	{
		mynum = deleted_num.GetLastNum() + 1; // 지운 마지막 번호 + 1로 번호를 생성
	}

	else // 일반적인 경우
		mynum = GetLastMusicNum() + 1; // 맨 끝 번호 + 1로 번호를 생성
	
	music.SetPrimaryKey(mynum); // 곡 번호 설정
	return 1;
}

//해당 노래 제목의 아이템을 변경한다.
int Application::ReplaceMusic()
{
	MusicType item;

	item.EnterNumFromKB(); //키보드로부터 바꾸고자 하는 노래제목을 입력받음
	bool found=false;
	
	MusicList.RetrieveItem(item,found); // 아이템 정보 얻어옴 - 바꾸기 전 아이템으로 

	if (!found) // 노래를 못 찾은 경우
	{
		cout << "<======== Cannot Find It!==========>" << endl;
		return 0;
	}

	else
	{
		MusicList.DeleteItem(item); // 기존 item 삭제
		item.SetRecordFromKB(); // 바꾸고자 하는 새로운 정보 받음

		cout << "<======== Replace ==========>" << endl;
	
		GenreType* genre_p;
		GenreType genre;
		GenreType new_genre;

		genre.SetGenre(item.GetGenre()); // 장르 입력

		genre_p = my_GenreList.GetPointer(genre); // 해당 곡에 대한 SimpleMusicType을 포함하는 GenreType 포인터를 반환	
	
		int itemnum;

		if (genre_p != NULL)
		{
			genre_p->Delete(item.GetPrimaryKey()); // 해당 장르 타입에서 음악 제거

			 itemnum = genre_p->GetSMListSize();

			if (itemnum == 0) // SIMPLETYPE 아이템이 하나도 없으면 
			{
				my_GenreList.Delete(*genre_p); // 그 장르 제거
			}
		}

		AlbumType* album_p;
		AlbumType album;
		AlbumType new_album;

		album.SetName(item.GetAlbum()); // 앨범명 입력

		album_p = my_AlbumList.GetPointer(album); // 해당 곡에 대한 SimpleMusicType을 포함하는 AlbumType 포인터를 반환	
		
		
		if (album_p != NULL)
		{
			album_p->Delete(item.GetPrimaryKey()); // 해당 앨범 타입에서 음악 제거

			itemnum = album_p->GetSMListSize();

			if (itemnum == 0) // SIMPLETYPE 아이템이 하나도 없으면 
			{
				my_AlbumList.Delete(*album_p); // 그 앨범 제거
			}

		}

		MusicList.Add(item);
	
		SimpleMusicType s_item;
		s_item.SetNum(item.GetPrimaryKey());
		s_item.SetTitle(item.GetTitle());

		new_genre.SetGenre(item.GetGenre()); // 장르 입력
		new_album.SetName(item.GetAlbum()); // 앨범명 입력
		new_album.SetSinger(item.GetSinger()); // 가수명 입력

		this->DisplayAllMusic();
		return 1;
	}
}

// 모든 앨범 레코드를 출력
void Application::DisplayAllAlbum()
{
	AlbumType data;

	cout << "\n\tCurrent Album List" << endl;

	// list의 모든 데이터를 화면에 출력
	DoublyIterator<AlbumType> itor(my_AlbumList);
	itor.Next();

	while (itor.NextNotNull())
	{
		itor.Current()->DisplayRecordOnScreen();
		itor.Next();
	}

}

// Display all records in the list on screen.
void Application::DisplayAllMusic()
{
	MusicType data;
	bool finished = false;

	cout << "\n\tCurrent list" << endl;
	MusicList.ResetTree(); // 트리를 리셋함

	// list의 모든 데이터를 화면에 출력
	while (!finished)
	{
		MusicList.GetNextItem(data, finished);
		data.DisplayRecordOnScreen();
	}
}

// Display all records in the list on screen.
void Application::DisplayAllSinger()
{
	SingerType data;

	cout << "\n\tCurrent Singers" << endl;

	// list의 모든 데이터를 화면에 출력
	DoublyIterator<SingerType> itor(my_SingerList);
	itor.Next();

	while (itor.NextNotNull())
	{
		itor.Current()->DisplayRecordOnScreen();
		itor.Next();
	}
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_InFile)	return 0;
	else	return 1;
}

// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_OutFile)	return 0;
	else	return 1;
}

// 앨범, 가수DB를 읽어옴
int Application::ReadInfo()
{
	AlbumType data;
	SingerType data2;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile("AlbumDB.txt"))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{

		data.ReadDataFromFile(m_InFile); // 파일에서 데이터를 읽어옴
		my_AlbumList.Add(data);
	}

	m_InFile.close();	// 파일 닫음

						// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile("SingerDB.txt"))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{

		data2.ReadDataFromFile(m_InFile); // 파일에서 데이터를 읽어옴
		my_SingerList.Add(data2);
	}

	m_InFile.close();	// 파일 닫음


	return 1;

}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	MusicType data;	// 읽기용 임시 변수
	
	MusicList.MakeEmpty(); // 음악 리스트 초기화
	AddRecentlyMusicList.MakeEmpty(); // 최신 30곡 리스트 초기화
	temp.MakeEmpty(); // 백업용 최신 리스트 초기화
	my_GenreList.MakeEmpty(); // 장르 리스트 초기화
	PlayedRecentlyMusicList.MakeEmpty(); // 나의 플레이 리스트 초기화
	temp_p.MakeEmpty(); // 백업용 플레이 리스트 초기화
	deleted_num.MakeEmpty(); // 지운 번호들 초기화

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	SimpleMusicType s_item; // 간단한 음악 타입
	SimpleAlbumType s_album; // 간단한 앨범 타입

	// file open, open error가 발생하면 0을 리턴
	if(!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while(!m_InFile.eof())
	{

		GenreType genre; // 장르 타입
		AlbumType album; // 앨범 타입
		SingerType singer; // 가수 타입

		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);

		CreateMusicNum(data); // 곡 번호 생성
		MusicList.Add(data); // 음악 리스트에 곡 추가
		
		s_item.SetNum(data.GetPrimaryKey()); // 간단한 곡 번호 설정
		s_item.SetTitle(data.GetTitle()); // 간단한 곡 제목 설정
		
		s_album.SetName(data.GetAlbum()); // 간단한 앨범 명 설정
		s_album.SetSinger(data.GetSinger()); // 간단한 가수 명 설정
	
		 // 새 곡을 장르 리스트에 추가

		genre.SetGenre(data.GetGenre()); // 장르 설정

		GenreType* mygenre = my_GenreList.GetPointer(genre);

		if (mygenre) // 일치하는 장르 타입을 발견할 경우
		{
			mygenre->Add(s_item); // 해당 장르 타입에 간단한 음악 타입 하나만 추가
		}
		else
		{
			genre.Add(s_item); // 먼저 장르 타입에 간단한 음악 하나 추가
			my_GenreList.Add(genre); // 장르 리스트에 장르 추가
		}

		album.SetName(data.GetAlbum()); // 앨범명 설정
		album.SetSinger(data.GetSinger()); // 가수 설정

		AlbumType* myalbum = my_AlbumList.GetPointer(album);

		if (myalbum) // 일치하는 앨범 타입을 발견할 경우
		{
			myalbum->Add(s_item); // 해당 앨범 타입에 간단한 음악 타입 하나만 추가
		}
		else
		{
			album.Add(s_item); // 먼저 앨범타입에 간단한 음악 타입 아이템 하나 추가
			my_AlbumList.Add(album); // 앨범리스트에 앨범 추가										 
		}

		singer.SetName(data.GetSinger()); // 가수명 설정
		singer.SetGenre(data.GetGenre()); // 장르 설정

		SingerType* mysinger = my_SingerList.GetPointer(singer);

		s_album.SetName(data.GetAlbum()); // 앨범 명 설정
		s_album.SetSinger(data.GetSinger()); // 가수 명 설정


		if (mysinger) // 일치하는 앨범 타입을 발견할 경우
		{
			mysinger->Add(s_album); // 해당 가수 타입에 간단한 앨범 타입 하나만 추가
		}
		else
		{
			singer.Add(s_album); // 먼저 가수타입에 간단한 앨범 타입 아이템 하나 추가
			my_SingerList.Add(singer); // 가수리스트에 가수 추가										 
		}
		
		// 새 곡을 최근 재생목록에 추가	

		if (AddRecentlyMusicList.IsFull()) // 최근 재생 목록이 꽉 차면
		{
			SimpleMusicType d_item; // 지우고자 하는 아이템
			AddRecentlyMusicList.DeQueue(d_item); // 가장 앞에 있는 아이템 제거하고
			AddRecentlyMusicList.EnQueue(s_item); // 새로운 아이템 추가
			
			cout << "Recently Music List is Full!" << endl; // 최신 재생 리스트 꽉 찼음
		}

		else // 새 곡을 최근 재생목록에 추가
		{
			AddRecentlyMusicList.EnQueue(s_item);
		}

	}

	m_InFile.close();	// 파일 닫음

	return 1;
}

// 파일을 읽기 전용으로 읽음
int Application::WriteDataToFile()
{
	MusicType data;	// 쓰기용 임시 변수
	bool finished = false;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if(!OpenOutFile(filename))
		return 0;

	// list의 모든 데이터를 파일에 쓰기

	if (MusicList.GetLength() == 0) // 아무런 음악도 존재하지 않으면
	{
		cout << "No Music in List!" << endl;
		return 0;
	}
	
	MusicList.ResetTree(); // 트리를 리셋함

	while (!finished)
	{
		MusicList.GetNextItem(data, finished);
		data.WriteDataToFile(m_OutFile);
	}

	return 1;
}

