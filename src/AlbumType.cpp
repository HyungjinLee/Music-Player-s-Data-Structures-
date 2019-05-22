#include "AlbumType.h"

int AlbumType::Add(SimpleMusicType item)
{
	SMList.Add(item); // SimpleMusic 아이템 추가
	return 1;
}

// SMList의 사이즈를 얻어옴
int AlbumType::GetSMListSize()
{
	return SMList.GetLength();
}
// 장르 타입 SMList에서 곡 삭제
int AlbumType::Delete(int num)
{
	SimpleMusicType s_item;
	s_item.SetNum(num);
	SMList.DeleteItem(s_item);
	return 1;
}


// 파일로부터 레코드를 입력받음
int AlbumType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_name;
	fin >> m_company;
	fin >> m_singer;
	fin >> m_date;

	return 1;
};


void AlbumType::GetNextItem(SimpleMusicType& item, bool& finished)
{
	SMList.GetNextItem(item, finished);
}
