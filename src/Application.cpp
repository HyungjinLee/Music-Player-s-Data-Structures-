#include "Application.h"
#include <Windows.h>

// �ܼ� �󿡼� Ŀ���� �̵�
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
		case 1:	// ���� ����Ʈ �޴�
			MusicListMenu();
			break;
		case 2:	// �ٹ� ����Ʈ �޴�
			AlbumListMenu();
			break;
		case 3:	// ���� ����Ʈ �޴�
			ArtistListMenu();
			break;
		case 4:	// �帣 ����Ʈ �޴�
			GenreListMenu();
			break;
		case 5: // txt ���Ͽ��� ���������� �о�´�
			if (ReadDataFromFile()) // �ε� �����ϸ�
			{
				cout << "Loading Success!" << endl;
				system("Pause");
			}
			
			break;
		case 6:	// txt ���Ͽ� ���������� ����
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

// ���� ����Ʈ �޴�

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
			// ���۸� ������ �־� ���ѷ��� ����
			cin.clear();
			cin.ignore();
		}

		string id;
		string pass;

		switch (com)
		{
		case 1: // ���� ����Ʈ �߰�
			AddMusic();
			system("Pause");
			break;
		case 2: // ���� ����Ʈ ����
			DeleteMusic();
			system("Pause");
			break;
		case 3: // ���� ����Ʈ ����
			ReplaceMusic();
			system("Pause");
			break;

		case 4: // ���� ���
			system("cls");
			DisplayAllMusic(); // �ϴ� ���� ����Ʈ�� ��� ����� ��
			PlayMusic(); // ������ ��� �ϳ��� �÷���
			break;

		case 5: // �ֱ� �߰� ��� 30��
			system("cls");
			DisplayNewMusic(); // �� 30���� ���
			system("Pause");
			break;

		case 6: // �ֱ� ��� ��� 30��
			system("cls");
			DisplayMyPlayList(); // �� ������ 30�� ���
			system("Pause");
			break;

		case 7: // ���� �޴�
			system("cls");
			Run();
			return ;

		default: // ���� ó��
			cout << "Wrong Input!!";
		}

	}
	system("Pause");

}
// �ٹ� ����Ʈ �޴�
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
			// ���۸� ������ �־� ���ѷ��� ����
			cin.clear();
			cin.ignore();
		}

		switch (com)
		{
		case 1: // �ٹ� �߰�
			system("cls");
			AddAlbum();
			system("Pause");
			break;
		case 2: // �ٹ� ����
			system("cls");
			DeleteAlbum();
			system("Pause");
			break;
		case 3: // �ٹ� ����
			system("cls");
			ReplaceAlbum();
			system("Pause");
			break;

		case 4: // ��� �ٹ� ���
			system("cls");
			DisplayAllAlbum();
			system("Pause");
			break;

		case 5: // �ٹ� �� ���� ���
			system("cls");
			DisplayMusicByAlbum();
			system("Pause");
			break;
		case 6: // ���� �޴�
			system("cls");
			Run();
			return ;

		default: // ���� ó��
			cout << "Wrong Input!!";
		}

	}
	
}

// �ٹ� �߰�
int Application::AddAlbum()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� �߰�

	AlbumType item;
	item.SetRecordFromKB();

	if (my_AlbumList.Get(item))// �ߺ� �˻�
	{
		cout << "Duplication in Album!!" << endl;
		return 0; // ����
	}

	// �� �ٹ��� �ٹ�����Ʈ�� �߰�
	my_AlbumList.Add(item);

	return 1;
}

// �ٹ� ����
int Application::DeleteAlbum()
{
	AlbumType item;
	item.EnterKeyFromKB(); // �ٹ���, �������� �Է¹���

	if (!my_AlbumList.Get(item))
	{
		cout << "<========DELETE FAIL !=======>" << endl; // ã�� ���� ���
		this->DisplayAllAlbum();//��� item�� ����Ѵ�.
		system("Pause");
		return 0;
	}

	cout << "<========DELETE SUCCESS !===========>" << endl;
	my_AlbumList.Delete(item);
	this->DisplayAllAlbum(); // ��� item�� ����Ѵ�.
	return 1;
}

// �ٹ� ����
int Application::ReplaceAlbum()
{
	DisplayAllAlbum();
	AlbumType item;
	item.EnterKeyFromKB(); // �ٹ���, �������� �Է¹���

	AlbumType newitem; // ���ο� ������
	newitem.SetName(item.GetName()); // �ٹ��� ����
	newitem.SetSinger(item.GetSinger()); // ������ ����
	
	MusicType m_item;
	m_item.SetAlbum(item.GetName());
	m_item.SetSinger(item.GetSinger());

	if (!my_AlbumList.Get(item))
	{
		cout << "<======== Cannot Find It!==========>" << endl;
		return 0;
	}

	cout << "<======== Replace ==========>" << endl;

	my_AlbumList.Replace(newitem); // �ٹ� ����Ʈ ����	 
	UpdateMLByAlbum(item,newitem);		// ���� ����Ʈ ����

	this->DisplayAllAlbum(); // ��� item�� ����Ѵ�.
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
			// ���۸� ������ �־� ���ѷ��� ����
			cin.clear();
			cin.ignore();
		}

		switch (com)
		{
		case 1: // ���� �߰�
			AddArtist();
			system("Pause");
			break;
		case 2: // ���� ����
			DeleteArtist();
			system("Pause");
			break;
		case 3: // ���� ����
			ReplaceArtist();
			system("Pause");
			break;

		case 4: // ���� �� �˻�
			system("cls");
			DisplayAllSinger();
			SearchByArtist(); 
			system("Pause");
			break;

		case 5: // ��� �ٹ� �ȿ� �ִ� �� ���
			system("cls");
			DisplayArtistAlbum();
			system("Pause");
			break;

		case 6: // ���� �޴�
			system("cls");
			Run();
			return ;

		default: // ���� ó��
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
		cout << "1. Search by Genre " << endl;		  // �帣�� �˻�
		cout << "2. Display Music by Genre " << endl; // �帣 ���� ���� ���
		cout << "3. Go Previous" << endl;

		cout << "command -> ";

		cin >> com;

		if (cin.fail())
		{
			// ���۸� ������ �־� ���ѷ��� ����
			cin.clear();
			cin.ignore();
		}

		string id;
		string pass;

		switch (com)
		{
		case 1: // �帣�� ���� �˻�
			SearchByGenre();
			system("Pause");
			break;
		case 2: // �帣 �� ���� ���
			DisplayMusicByGenre();
			system("Pause");
			break;
		case 3: // ���� �޴�
			system("cls");
			Run();
			return ;

		default: // ���� ó��
			cout << "Wrong Input!!";
		}

	}
	system("Pause");

}
// ������ ����Ѵ�.
int Application::PlayMusic()
{

	MusicType* item;
	item = new MusicType();

	SimpleMusicType s_item;
	bool found=false;

	item->EnterNumFromKB(); // Ű����κ��� ����ϰ��� �ϴ� �� ��ȣ�� �о��
	
	s_item.SetNum(item->GetPrimaryKey());
	s_item.SetTitle(item->GetTitle());

	item = MusicList.GetPointer(item,found);

	if (!found) // �������� ã�� ���� ���
	{
		cout << "<======== Cannot Find Music==========>" << endl;
		system("Pause");
		return 0;
	}

	system("cls");

	item->DisplayRecordOnScreen(); // ����ϴ� ���� ���� ���


	// �� ���� �ֱ� �����Ͽ� �߰�	

	if (PlayedRecentlyMusicList.IsFull()) // �ֱ� ��� ����� �� ����
	{
		SimpleMusicType d_item; // ������� �ϴ� ������
		PlayedRecentlyMusicList.DeQueue(d_item); // ���� �տ� �ִ� ������ �����ϰ�
		PlayedRecentlyMusicList.EnQueue(s_item); // ���ο� ������ �߰�

		cout << "Recently Played Music List is Full!" << endl; // �ֽ� ��� ����Ʈ �� á��
	}

	else // �� ���� �ֱ� �����Ͽ� �߰�
	{
		PlayedRecentlyMusicList.EnQueue(s_item);
	}

	item->PlayMusic(); // ���� ���!!
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
		// ���۸� ������ �־� ���ѷ��� ����
		cin.clear();
		cin.ignore();
	}

	cout << endl;

	return command;
}

// Add new record into list.
int Application::AddMusic()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� �߰�

	MusicType item;
	item.SetRecordFromKB();
	
	// �� ���� ���� ����Ʈ�� �߰�
	// �ߺ� ���� �˰��� - �� ��ȣ ����
	CreateMusicNum(item);
	MusicList.Add(item);

	SimpleMusicType s_item; // ������ ���� Ÿ��
	SimpleAlbumType s_album; // ������ �ٹ� Ÿ��

	s_item.SetNum(item.GetPrimaryKey()); // �� ��ȣ ����
	s_item.SetTitle(item.GetTitle()); // �� ���� ����

	// �� ���� �帣 ����Ʈ�� �߰�
	
	GenreType genre; // �帣 Ÿ��
	genre.SetGenre(item.GetGenre()); // �帣 ����

	GenreType* mygenre = my_GenreList.GetPointer(genre);

	if (mygenre) // ��ġ�ϴ� �帣 Ÿ���� �߰��� ���
	{
		mygenre->Add(s_item); // �ش� �帣 Ÿ�Կ� ������ ���� Ÿ�� �ϳ��� �߰�
	}
	else
	{
		genre.Add(s_item); // ���� �帣 Ÿ�Կ� ������ ���� �ϳ� �߰�
		my_GenreList.Add(genre); // �帣 ����Ʈ�� �帣 �߰�
	}

	AlbumType album; // �ٹ� Ÿ��
	album.SetName(item.GetAlbum()); // �ٹ��� ����
	album.SetSinger(item.GetSinger()); // ���� ����
	
	AlbumType* myalbum = my_AlbumList.GetPointer(album);
	
	if (myalbum) // ��ġ�ϴ� �ٹ� Ÿ���� �߰��� ���
	{
		myalbum->Add(s_item); // �ش� �ٹ� Ÿ�Կ� ������ ���� Ÿ�� �ϳ��� �߰�
	}
	else
	{
		album.Add(s_item); // ���� �ٹ�Ÿ�Կ� ������ ���� Ÿ�� ������ �ϳ� �߰�
		my_AlbumList.Add(album); // �ٹ�����Ʈ�� �ٹ� �߰�										 
	}

	SingerType singer; // ���� Ÿ��
	singer.SetName(item.GetSinger()); // ������ ����
	singer.SetGenre(item.GetGenre()); // �帣 ����

	SingerType* mysinger = my_SingerList.GetPointer(singer);

	s_album.SetName(item.GetAlbum()); // �ٹ� �� ����
	s_album.SetSinger(item.GetSinger()); // ���� �� ����


	if (mysinger) // ��ġ�ϴ� �ٹ� Ÿ���� �߰��� ���
	{
		mysinger->Add(s_album); // �ش� ���� Ÿ�Կ� ������ �ٹ� Ÿ�� �ϳ��� �߰�
	}
	else
	{
		singer.Add(s_album); // ���� ����Ÿ�Կ� ������ �ٹ� Ÿ�� ������ �ϳ� �߰�
		my_SingerList.Add(singer); // ��������Ʈ�� ���� �߰�										 
	}

	if (AddRecentlyMusicList.IsFull()) // �ֱ� �߰� ����� �� ����
	{
		SimpleMusicType d_item; // ������� �ϴ� ������
		AddRecentlyMusicList.DeQueue(d_item); // ���� �տ� �ִ� ������ �����ϰ�
		AddRecentlyMusicList.EnQueue(s_item); // ���ο� ������ �߰�
		cout << "Recently Music List is Full!";
	}
	else // �� ���� �ֱ� �߰���Ͽ� �߰�
	{
		AddRecentlyMusicList.EnQueue(s_item);
	}

	// ���� list ���
	DisplayAllMusic();
	return 1;
}

// ��Ƽ��Ʈ�� �ٹ� �� ���ϰ��� ��� ���
int Application::DisplayArtistAlbum()
{
	DisplayAllSinger(); // ���� ��� ������ ���

	SingerType* mysinger = new SingerType(); // ���� Ÿ��
	mysinger->SetNameFromKB(); // ���� ������ ���� ���� �Է�

	SimpleMusicType s_item; // ������ ���� Ÿ��
	SimpleAlbumType s_album; // ������ �ٹ� Ÿ��
	int num; // ���� ����Ʈ���� ã�� ������ �� ��ȣ 

	MusicType item; // �񱳸� ���� ����Ÿ�� ��ü
	AlbumType album; // �񱳸� ���� �ٹ�Ÿ�� ��ü

	mysinger = my_SingerList.GetPointer(*mysinger); // ������ ã��

	if (mysinger == NULL) // ������ ã�� ���� ���
	{
		cout << "<========I CAN'T FIND ARTIST !==========>" << endl;
		return 0;
	}

	cout << mysinger->GetName() << "'s Album." << endl; // ���� �̸� ���

	cout << "********************************" << endl;

	mysinger->ResetSAList(); // ����Ʈ ����

	bool finished = false;
	bool found = false;

	while (!finished)
	{
		mysinger->GetNextItem(s_album, finished); // �ٹ� Ÿ�Կ��� ���� ������ ���� Ÿ�� ��ü�� ����
		album.SetName(s_album.GetName()); // �ٹ� �̸� ����
		album.SetSinger(s_album.GetSinger()); // ���� �� ����
		my_AlbumList.Get(album); // �ٹ�����Ʈ���� �˻�

		album.DisplayRecordOnScreen(); // �ٹ� ���� ���
		
	}

	cout << endl << "********************************" << endl;
	cout << "which album do you want?" << endl;
	album.EnterKeyFromKB();

	my_AlbumList.Get(album); // �ٹ�����Ʈ���� �˻�

	cout << "********************************" << endl;
	album.ResetSMList();

	finished = false;
	found = false;

	while (!finished)
	{
		album.GetNextItem(s_item, finished); // �ٹ� Ÿ�Կ��� ���� ������ ���� Ÿ�� ��ü�� ����
		item.SetPrimaryKey(s_item.GetNum()); // ���� ��ü�� ��ȣ�� ����
		MusicList.RetrieveItem(item, found); // ���� ����Ʈ���� ã��

		if (found)
		{
			item.DisplayRecordOnScreen(); // ���� ���� ���
		}
	}

	cout << endl << "********************************" << endl;


	return 1;


}

// �帣 ���� ȭ�鿡 ���
void Application::DisplayMusicByGenre()
{
	GenreType myGenre; // �帣 Ÿ��
	SimpleMusicType s_item; // ������ ���� Ÿ��
	int num; // ���� ����Ʈ���� ã�� ������ �� ��ȣ 

	MusicType item; // �񱳸� ���� ����Ÿ�� ��ü
	DoublyIterator<GenreType> itor(my_GenreList);


	for (int i = 0; i < my_GenreList.GetLength(); i++) // �帣 ����Ʈ�� ���� ��ŭ ex) ��, ��, �߶�� - 3��
	{
		myGenre = *itor.Next(); // �帣 ����Ʈ�� ���� �������� ����

		cout << myGenre.GetGenre() << endl; // �帣 ���

		cout << "********************************" << endl;
		myGenre.ResetSMList();	// SMLIST ����
		
		bool finished = false;
		bool found = false;


		while (!finished)
		{	
			myGenre.GetNextItem(s_item,finished);	// �帣 Ÿ�Կ��� ���� ������ ���� Ÿ�� ��ü�� ����
			item.SetPrimaryKey(s_item.GetNum());	// ���� ��ü�� ��ȣ�� ����
			MusicList.RetrieveItem(item, found);	// ���� ����Ʈ���� ã��
			
			if (found)
			{
				item.DisplayRecordOnScreen();	// ���� ���� ���
			}
		}

		cout << endl << "********************************" << endl;
	}
}

// �ٹ� ���� ȭ�鿡 ���
int Application::DisplayMusicByAlbum()
{
	DisplayAllAlbum(); // ���� ��� �ٹ��� ���

	AlbumType* myAlbum = new AlbumType(); // �ٹ� Ÿ��
	myAlbum->EnterKeyFromKB(); // ����ϰ��� �ϴ� �ٹ��� ã�� ���� �ֿ� Ű �Է�

	SimpleMusicType s_item; // ������ ���� Ÿ��
	int num; // ���� ����Ʈ���� ã�� ������ �� ��ȣ 

	MusicType item; // �񱳸� ���� ����Ÿ�� ��ü
	
	DoublyIterator<AlbumType> itor(my_AlbumList);
	myAlbum = my_AlbumList.GetPointer(*myAlbum); // �ٹ��� ã��

	if (myAlbum == NULL)
	{
		cout << "<========I CAN'T FIND ALBUM !==========>" << endl;
		return 0;
	}
	cout << myAlbum->GetName() << endl; // �ٹ� �� ���

	cout << "********************************" << endl;
	myAlbum->ResetSMList();

	bool finished = false;
	bool found = false;

	while (!finished)
	{
		myAlbum->GetNextItem(s_item, finished); // �ٹ� Ÿ�Կ��� ���� ������ ���� Ÿ�� ��ü�� ����
		item.SetPrimaryKey(s_item.GetNum()); // ���� ��ü�� ��ȣ�� ����
		MusicList.RetrieveItem(item, found); // ���� ����Ʈ���� ã��

		if (found)
		{
			item.DisplayRecordOnScreen(); // ���� ���� ���
		}
	}

	cout << endl << "********************************" << endl;
	return 1;
}

/** �ֱٿ� �߰��� 30���� �ڼ��� ���� ���

* ���� MUSIC LIST�� A B C �� �ִ� ���¿��� 
* B�� �����ϰ� ���ο� D�� �����ϴ� ���
* MUSIC LIST���� �� ��ȣ ������ A D C
* AML(�߰����) ���� A C D ������ ����� ���´�.
  
*/

void Application::DisplayNewMusic()
{
	temp = AddRecentlyMusicList; // ť�� Dequeue�ϸ� �����͸� �Ҿ�����Ƿ� ���

	MusicType item; // ���� Ÿ��
	
	SimpleMusicType s_item; // ������ ���� Ÿ��
	bool found=false;

	if (temp.IsEmpty()) // �ֱ� �������� ���������
	{
		cout << "Recently Music List is Empty!" << endl;
	}

	else // �ֱ� �������� �����ϸ�
	{
		cout << "Recently Added Music" << endl;

		while (!temp.IsEmpty()) // ť�� �� �� ����
		{
			temp.DeQueue(s_item); // �ֱ� ��� ���ǿ� ���� ������ ������ �޾ƿ�	
			item.SetPrimaryKey(s_item.GetNum()); // �� ��ȣ ����
			MusicList.RetrieveItem(item,found);

			if (found) // �������� ã�� ���
			{
				item.DisplayRecordOnScreen(); // �� ������ ���
			}		
		}
	}
}

// �÷��� ����Ʈ�� ���
void Application::DisplayMyPlayList() 
{
	temp_p = PlayedRecentlyMusicList; // ť�� Dequeue�ϸ� �����͸� �Ҿ�����Ƿ� ���

	MusicType item; // ���� Ÿ��
	SimpleMusicType s_item; // ������ ���� Ÿ��

	if (temp_p.IsEmpty()) // �ֱ� �������� ���������
	{
		cout << "My PlayList is Empty!" << endl;
	}

	else // �ֱ� �������� �����ϸ�
	{
		cout << "\t\tMy PlayList" << endl;

		while (!temp_p.IsEmpty()) // ť�� �� �� ����
		{
			temp_p.DeQueue(s_item); // �ֱ� ��� ���ǿ� ���� ������ ������ �޾ƿ�	
			item.SetPrimaryKey(s_item.GetNum()); // �� ��ȣ ����
			bool found;
			MusicList.RetrieveItem(item,found); // ���� ����Ʈ���� �˻�

			if (found) // �������� ã�� ���
			{
				item.DisplayRecordOnScreen(); // �� ������ ���
			}
		}

		string com;
		cout << "You Want Play Music (press 'y' if you want) ?\t command -> ";

		cin >> com;

		if(com == "y")
			PlayMusic(); // ���� ���
					

	}
}

// ���� �߰�
int Application::AddArtist()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� �߰�

	SingerType item;
	item.SetRecordFromKB();

	if (my_SingerList.Get(item)) // �ߺ� �˻�
	{
		cout << "Duplication in Singer!!" << endl;
		return 0;
	}
	my_SingerList.Add(item); // �� ������ ��������Ʈ�� �߰�
	return 1;
}

// ���� ����
int Application::DeleteArtist()
{
	SingerType item;
	item.SetNameFromKB(); 

	if (!my_SingerList.Get(item))
	{
		cout << "<========DELETE FAIL !=======>" << endl; // ã�� ���� ���
		this->DisplayAllSinger();//��� item�� ����Ѵ�.
		return 0;
	}

	cout << "<========DELETE SUCCESS !===========>" << endl;
	my_SingerList.Delete(item);
	this->DisplayAllSinger(); // ��� item�� ����Ѵ�.
	return 1;
}

// �ٹ� ������ �ٲ� ��� ���� ����Ʈ������ ������Ʈ
int Application::UpdateMLByAlbum(AlbumType& album,AlbumType& newalbum)
{

	MusicType *item_p;
	MusicType item;

	bool found = false;
	bool finished = false;

	MusicList.ResetTree(); // Ʈ���� ������

	while (!finished)
	{
		MusicList.GetNextItem(item, finished); // ���� ������ ����
		if (item.GetAlbum() == album.GetName()) // ���� �ٹ� �������� ã����
		{
			item_p = MusicList.GetPointer(&item, found);
			item_p->SetAlbum(newalbum.GetName()); // ���� ����Ʈ ���� ����
			item_p->SetSinger(newalbum.GetSinger()); // ���� ����Ʈ ���� ����
		}
	}

	if (found)
		return 1; // ����
	else
		return 0; //����
		
}

// ���� ������ �ٲ� ��� ���� ����Ʈ������ ������Ʈ
int Application::UpdateMLBySinger(SingerType& singer, SingerType& newsinger)
{
	MusicType *item_p;
	MusicType item;

	bool found = false;
	bool finished = false;

	MusicList.ResetTree(); // Ʈ���� ������


	while (!finished)
	{
		MusicList.GetNextItem(item, finished); // ���� ������ ����
		if (item.GetSinger() == singer.GetName()) // ���� ���� �������� ã����
		{
			item_p = MusicList.GetPointer(&item, found);
			item_p->SetSinger(newsinger.GetName()); // �� ������ ����
		}
	}


	if (found)
		return 1; // ����
	else
		return 0; //����

}

// ���� ����
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

	my_SingerList.Replace(newitem); // ���� ����Ʈ ����

	UpdateMLBySinger(item,newitem); // ���� ����Ʈ ����


	this->DisplayAllSinger(); // ��� item�� ����Ѵ�.
	return 1;
}


// �� �������� item�� ã�� ����Ѵ�.
int Application::SearchByName()
{
	MusicType item;

	item.SetTitleFromKB();	//id�� �Է¹޴´�
	cout << "<====================================>" << endl;

	if (GetByTitle(item))	// �˻�� �����Ѵٸ�
	{
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ��ȯ

}

//���������� item�� ã�� ����Ѵ�.
int Application::SearchByArtist()
{
	MusicType item;
	item.SetSingerFromKB(); //���� �� �Է¹޴´�.

	cout << "<=========================>" << endl;


	if (GetByArtist(item)) //0�� �ƴϸ�(ã����)
	{
		cout << "<=========================>" << endl;

		return 1;	//����(1)�� ����
	}
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ����
}

//�ٹ������� item�� ã�� ����Ѵ�.
int Application::SearchByAlbum()
{
	MusicType item;
	item.SetAlbumFromKB(); //�ٹ� �� �Է¹޴´�.

	cout << "<=========================>" << endl;


	if (GetByAlbum(item)) //0�� �ƴϸ�(ã����)
	{
		cout << "<=========================>" << endl;

		return 1;	//����(1)�� ����
	}
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ����
}

//�帣������ item�� ã�� ����Ѵ�.
int Application::SearchByGenre()
{
	MusicType item;
	item.SetGenreFromKB(); //�帣 �� �Է¹޴´�.

	cout << "<=========================>" << endl;


	if (GetByGenre(item)) //0�� �ƴϸ�(ã����)
	{

		cout << "<=========================>" << endl;

		return 1;	//����(1)�� ����
	}
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ����
}

// �� �������� ã�´�
int Application::GetByTitle(MusicType& music)
{
	MusicType item;
	bool found = false;
	bool finished = false;

	MusicList.ResetTree(); // Ʈ���� ������

	while (!finished)
	{
		MusicList.GetNextItem(item, finished); // ���� ������ ����
		if (strstr(item.GetTitle().c_str(), music.GetTitle().c_str())) // ����� ���ԵǸ�
		{
			item.DisplayRecordOnScreen(); // ���� ���
			found = true; // ã��
		}
	}
	if (found)
		return 1; // ����
	else
		return 0; //����

	return 1;

}

// �ٹ������� ã�´�
int Application::GetByAlbum(MusicType& music)
{
	MusicType item;
	bool found = false;
	bool finished = false;

	MusicList.ResetTree(); // Ʈ���� ������

	while (!finished)
	{
		MusicList.GetNextItem(item, finished); // ���� ������ ����
		if (strstr(item.GetAlbum().c_str(), music.GetAlbum().c_str())) // �ٹ����� ���ԵǸ�
		{
			item.DisplayRecordOnScreen(); // ���� ���
			found = true; // ã��
		}
	}
	if (found)
		return 1; // ����
	else
		return 0; //����

}

// ���������� ã�´�
int Application::GetByArtist(MusicType& music)
{
	MusicType item;
	bool found = false;
	bool finished = false;

	MusicList.ResetTree(); // Ʈ���� ������

	while (!finished)
	{
		MusicList.GetNextItem(item, finished); // ���� ������ ����
		if (strstr(item.GetSinger().c_str(), music.GetSinger().c_str())) // �������� ���ԵǸ�
		{
			item.DisplayRecordOnScreen(); // ���� ���
			found = true; // ã��
		}
	}
	if (found)
		return 1; // ����
	else
		return 0; //����
	
	return 1;
}

// �帣������ ã�´�
int Application::GetByGenre(MusicType& music)
{
	MusicType item;
	bool found = false;
	bool finished = false;
	
	MusicList.ResetTree(); // Ʈ���� ������

	while (!finished)   
	{
		MusicList.GetNextItem(item, finished); // ���� ������ ����
		if (strstr(item.GetGenre().c_str(), music.GetGenre().c_str())) // �帣���� ���ԵǸ�
		{
			item.DisplayRecordOnScreen(); // ���� ���
			found = true; // ã��
		}
	}
	if (found)
		return 1; // ����
	else
		return 0; //����
}

//id�� item�� ã�Ƽ� �����Ѵ�.
int Application::DeleteMusic()
{
	temp = AddRecentlyMusicList; // ť�� Dequeue�ϸ� �����͸� �Ҿ�����Ƿ� ���

	int pre = MusicList.GetLength();//���� item������ �޾ƿ´�.

	MusicType item;
	item.EnterNumFromKB(); // ���� Ÿ�Կ� ������ �� ��ȣ�� �Է� ����
	bool found=false;

	MusicList.RetrieveItem(item, found); // ���� ����Ʈ���� ������� �ϴ� �������� �޾ƿ�
	
	if(!found)
	{
		cout << "<========DELETE FAIL !=======>" << endl; // ã�� ���� ���
		this->DisplayAllMusic();//��� item�� ����Ѵ�.
		return 0;
	}

	MusicList.DeleteItem(item); // ���� ����Ʈ���� �ش� ��ȣ�� �������� ����

	GenreType* genre_p;
	GenreType genre;

	int itemnum;

	genre.SetGenre(item.GetGenre()); // �帣 �Է�

	genre_p = my_GenreList.GetPointer(genre); // �ش� � ���� SimpleMusicType�� �����ϴ� GenreType �����͸� ��ȯ	

	if (genre_p != NULL)
	{
		genre_p->Delete(item.GetPrimaryKey()); // �ش� �帣 Ÿ�Կ��� ���� ����
		
		itemnum = genre_p->GetSMListSize();

		if (itemnum == 0) // SIMPLETYPE �������� �ϳ��� ������ 
		{
			my_GenreList.Delete(*genre_p); // �� �帣 ����
		}
	}
	
	AlbumType* album_p;
	AlbumType album;

	album.SetName(item.GetAlbum()); // �ٹ��� �Է�
	album.SetSinger(item.GetSinger()); // ���� �� �Է�

	album_p = my_AlbumList.GetPointer(album); // �ش� � ���� SimpleMusicType�� �����ϴ� AlbumType �����͸� ��ȯ	

	SingerType* singer_p;
	SingerType singer;

	singer.SetName(item.GetSinger()); // ������ �Է�
	singer_p = my_SingerList.GetPointer(singer); // ���� �˻�

	SimpleAlbumType s_album;
	s_album.SetName(item.GetAlbum());
	s_album.SetSinger(item.GetSinger());
	
	if (album_p != NULL)
	{

		album_p->Delete(item.GetPrimaryKey()); // �ش� �ٹ� Ÿ�Կ��� ���� ����

		itemnum = album_p->GetSMListSize();

		if (itemnum == 0) // SIMPLETYPE �������� �ϳ��� ������ 
		{
			my_AlbumList.Delete(*album_p); // �� �ٹ� ����
			
			if (singer_p != NULL) // ������ ã�� ���
				singer_p->Delete(s_album.GetName(), s_album.GetSinger()); // �ش� ���� �ȿ� �ִ� �ٹ� ���� 
		}

	}


	if (pre > MusicList.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << "<========DELETE SUCCESS !===========>" << endl;

		deleted_num.Add(item.GetPrimaryKey()); // ������� �ϴ� �� ��ȣ�� ����Ʈ�� ����
		this->DisplayAllMusic(); //��� item�� ����Ѵ�.
		return 1;
	}
	
	cout<<"<========DELETE FAIL !=======>"<<endl;
	this->DisplayAllMusic();//��� item�� ����Ѵ�.
	return 0;
}

// ���� ����Ʈ�� ������ �� ��ȣ�� ����
int Application::GetLastMusicNum()
{
	MusicType item;
	MusicList.GetLastItem(item); // ������ ��ȣ�� ����
	return (item.GetPrimaryKey());
}

// ���ο� �� ��ȣ�� ����
int Application::CreateMusicNum(MusicType& music)
{
	int mynum;

	if (MusicList.GetLength() == 0) // ���� ����Ʈ�� ��� ���� ��
	{
		if (deleted_num.GetLength() == 0)
			mynum = 1; // ó�� ��ȣ�� 1 
		else // ���� ���� ��ȣ�� ������ ��
		{
			mynum = deleted_num.GetLastNum() + 1;
		}
	}

	else if (deleted_num.GetLength() != 0 && deleted_num.GetLastNum() > GetLastMusicNum()) // ������ ��ȣ�� ������ ��
	{
		mynum = deleted_num.GetLastNum() + 1; // ���� ������ ��ȣ + 1�� ��ȣ�� ����
	}

	else // �Ϲ����� ���
		mynum = GetLastMusicNum() + 1; // �� �� ��ȣ + 1�� ��ȣ�� ����
	
	music.SetPrimaryKey(mynum); // �� ��ȣ ����
	return 1;
}

//�ش� �뷡 ������ �������� �����Ѵ�.
int Application::ReplaceMusic()
{
	MusicType item;

	item.EnterNumFromKB(); //Ű����κ��� �ٲٰ��� �ϴ� �뷡������ �Է¹���
	bool found=false;
	
	MusicList.RetrieveItem(item,found); // ������ ���� ���� - �ٲٱ� �� ���������� 

	if (!found) // �뷡�� �� ã�� ���
	{
		cout << "<======== Cannot Find It!==========>" << endl;
		return 0;
	}

	else
	{
		MusicList.DeleteItem(item); // ���� item ����
		item.SetRecordFromKB(); // �ٲٰ��� �ϴ� ���ο� ���� ����

		cout << "<======== Replace ==========>" << endl;
	
		GenreType* genre_p;
		GenreType genre;
		GenreType new_genre;

		genre.SetGenre(item.GetGenre()); // �帣 �Է�

		genre_p = my_GenreList.GetPointer(genre); // �ش� � ���� SimpleMusicType�� �����ϴ� GenreType �����͸� ��ȯ	
	
		int itemnum;

		if (genre_p != NULL)
		{
			genre_p->Delete(item.GetPrimaryKey()); // �ش� �帣 Ÿ�Կ��� ���� ����

			 itemnum = genre_p->GetSMListSize();

			if (itemnum == 0) // SIMPLETYPE �������� �ϳ��� ������ 
			{
				my_GenreList.Delete(*genre_p); // �� �帣 ����
			}
		}

		AlbumType* album_p;
		AlbumType album;
		AlbumType new_album;

		album.SetName(item.GetAlbum()); // �ٹ��� �Է�

		album_p = my_AlbumList.GetPointer(album); // �ش� � ���� SimpleMusicType�� �����ϴ� AlbumType �����͸� ��ȯ	
		
		
		if (album_p != NULL)
		{
			album_p->Delete(item.GetPrimaryKey()); // �ش� �ٹ� Ÿ�Կ��� ���� ����

			itemnum = album_p->GetSMListSize();

			if (itemnum == 0) // SIMPLETYPE �������� �ϳ��� ������ 
			{
				my_AlbumList.Delete(*album_p); // �� �ٹ� ����
			}

		}

		MusicList.Add(item);
	
		SimpleMusicType s_item;
		s_item.SetNum(item.GetPrimaryKey());
		s_item.SetTitle(item.GetTitle());

		new_genre.SetGenre(item.GetGenre()); // �帣 �Է�
		new_album.SetName(item.GetAlbum()); // �ٹ��� �Է�
		new_album.SetSinger(item.GetSinger()); // ������ �Է�

		this->DisplayAllMusic();
		return 1;
	}
}

// ��� �ٹ� ���ڵ带 ���
void Application::DisplayAllAlbum()
{
	AlbumType data;

	cout << "\n\tCurrent Album List" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
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
	MusicList.ResetTree(); // Ʈ���� ������

	// list�� ��� �����͸� ȭ�鿡 ���
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

	// list�� ��� �����͸� ȭ�鿡 ���
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
	
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_InFile)	return 0;
	else	return 1;
}

// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_OutFile)	return 0;
	else	return 1;
}

// �ٹ�, ����DB�� �о��
int Application::ReadInfo()
{
	AlbumType data;
	SingerType data2;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile("AlbumDB.txt"))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{

		data.ReadDataFromFile(m_InFile); // ���Ͽ��� �����͸� �о��
		my_AlbumList.Add(data);
	}

	m_InFile.close();	// ���� ����

						// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile("SingerDB.txt"))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{

		data2.ReadDataFromFile(m_InFile); // ���Ͽ��� �����͸� �о��
		my_SingerList.Add(data2);
	}

	m_InFile.close();	// ���� ����


	return 1;

}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	MusicType data;	// �б�� �ӽ� ����
	
	MusicList.MakeEmpty(); // ���� ����Ʈ �ʱ�ȭ
	AddRecentlyMusicList.MakeEmpty(); // �ֽ� 30�� ����Ʈ �ʱ�ȭ
	temp.MakeEmpty(); // ����� �ֽ� ����Ʈ �ʱ�ȭ
	my_GenreList.MakeEmpty(); // �帣 ����Ʈ �ʱ�ȭ
	PlayedRecentlyMusicList.MakeEmpty(); // ���� �÷��� ����Ʈ �ʱ�ȭ
	temp_p.MakeEmpty(); // ����� �÷��� ����Ʈ �ʱ�ȭ
	deleted_num.MakeEmpty(); // ���� ��ȣ�� �ʱ�ȭ

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	SimpleMusicType s_item; // ������ ���� Ÿ��
	SimpleAlbumType s_album; // ������ �ٹ� Ÿ��

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while(!m_InFile.eof())
	{

		GenreType genre; // �帣 Ÿ��
		AlbumType album; // �ٹ� Ÿ��
		SingerType singer; // ���� Ÿ��

		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);

		CreateMusicNum(data); // �� ��ȣ ����
		MusicList.Add(data); // ���� ����Ʈ�� �� �߰�
		
		s_item.SetNum(data.GetPrimaryKey()); // ������ �� ��ȣ ����
		s_item.SetTitle(data.GetTitle()); // ������ �� ���� ����
		
		s_album.SetName(data.GetAlbum()); // ������ �ٹ� �� ����
		s_album.SetSinger(data.GetSinger()); // ������ ���� �� ����
	
		 // �� ���� �帣 ����Ʈ�� �߰�

		genre.SetGenre(data.GetGenre()); // �帣 ����

		GenreType* mygenre = my_GenreList.GetPointer(genre);

		if (mygenre) // ��ġ�ϴ� �帣 Ÿ���� �߰��� ���
		{
			mygenre->Add(s_item); // �ش� �帣 Ÿ�Կ� ������ ���� Ÿ�� �ϳ��� �߰�
		}
		else
		{
			genre.Add(s_item); // ���� �帣 Ÿ�Կ� ������ ���� �ϳ� �߰�
			my_GenreList.Add(genre); // �帣 ����Ʈ�� �帣 �߰�
		}

		album.SetName(data.GetAlbum()); // �ٹ��� ����
		album.SetSinger(data.GetSinger()); // ���� ����

		AlbumType* myalbum = my_AlbumList.GetPointer(album);

		if (myalbum) // ��ġ�ϴ� �ٹ� Ÿ���� �߰��� ���
		{
			myalbum->Add(s_item); // �ش� �ٹ� Ÿ�Կ� ������ ���� Ÿ�� �ϳ��� �߰�
		}
		else
		{
			album.Add(s_item); // ���� �ٹ�Ÿ�Կ� ������ ���� Ÿ�� ������ �ϳ� �߰�
			my_AlbumList.Add(album); // �ٹ�����Ʈ�� �ٹ� �߰�										 
		}

		singer.SetName(data.GetSinger()); // ������ ����
		singer.SetGenre(data.GetGenre()); // �帣 ����

		SingerType* mysinger = my_SingerList.GetPointer(singer);

		s_album.SetName(data.GetAlbum()); // �ٹ� �� ����
		s_album.SetSinger(data.GetSinger()); // ���� �� ����


		if (mysinger) // ��ġ�ϴ� �ٹ� Ÿ���� �߰��� ���
		{
			mysinger->Add(s_album); // �ش� ���� Ÿ�Կ� ������ �ٹ� Ÿ�� �ϳ��� �߰�
		}
		else
		{
			singer.Add(s_album); // ���� ����Ÿ�Կ� ������ �ٹ� Ÿ�� ������ �ϳ� �߰�
			my_SingerList.Add(singer); // ��������Ʈ�� ���� �߰�										 
		}
		
		// �� ���� �ֱ� �����Ͽ� �߰�	

		if (AddRecentlyMusicList.IsFull()) // �ֱ� ��� ����� �� ����
		{
			SimpleMusicType d_item; // ������� �ϴ� ������
			AddRecentlyMusicList.DeQueue(d_item); // ���� �տ� �ִ� ������ �����ϰ�
			AddRecentlyMusicList.EnQueue(s_item); // ���ο� ������ �߰�
			
			cout << "Recently Music List is Full!" << endl; // �ֽ� ��� ����Ʈ �� á��
		}

		else // �� ���� �ֱ� �����Ͽ� �߰�
		{
			AddRecentlyMusicList.EnQueue(s_item);
		}

	}

	m_InFile.close();	// ���� ����

	return 1;
}

// ������ �б� �������� ����
int Application::WriteDataToFile()
{
	MusicType data;	// ����� �ӽ� ����
	bool finished = false;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenOutFile(filename))
		return 0;

	// list�� ��� �����͸� ���Ͽ� ����

	if (MusicList.GetLength() == 0) // �ƹ��� ���ǵ� �������� ������
	{
		cout << "No Music in List!" << endl;
		return 0;
	}
	
	MusicList.ResetTree(); // Ʈ���� ������

	while (!finished)
	{
		MusicList.GetNextItem(data, finished);
		data.WriteDataToFile(m_OutFile);
	}

	return 1;
}

