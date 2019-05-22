#include "SingerType.h"

int SingerType::Add(SimpleAlbumType& item)
{
	SAList.Add(item); // SimpleAlbum 아이템 추가
	return 1;
}

// 장르 타입 SAList에서 앨범 삭제
int SingerType::Delete(string name, string singer)
{
	SimpleAlbumType s_item; 
	s_item.SetName(name); // 앨범 명 입력
	s_item.SetSinger(singer); // 가수 명 입력
	SAList.DeleteItem(s_item); // 일치하는 아이템 삭제
	return 1;
}


// 파일로부터 레코드를 입력받음
int SingerType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_name;
	fin >> m_startdate;
	fin >> m_genre;

	return 1;
}

// SA리스트 안에 해당 앨범이 있는지 검사
int SingerType::Get(SimpleAlbumType album)
{
	bool found;
	SAList.RetrieveItem(album, found); // 해당 앨범 검색
	
	if(found)
		return 1;
	else
		return 0;
}

// SMList의 사이즈를 얻어옴
int SingerType::GetSMListSize()
{
	return SAList.GetLength();
}

// 다음 아이템 값을 얻음
void SingerType::GetNextItem(SimpleAlbumType& item, bool& finished)
{
	SAList.GetNextItem(item, finished);
}
