#include "GenreType.h"
#include "DoublyIterator.h"

int GenreType::Add(SimpleMusicType& item)
{
	SMList.Add(item); // SimpleMusic 아이템 추가
	return 1;
}

// SMList를 리셋함
void GenreType::ResetSMList()
{
	SMList.ResetTree();
}

// 장르 타입 SMList에서 곡 삭제
int GenreType::Delete(int num)
{
	SimpleMusicType s_item;
	s_item.SetNum(num);
	SMList.DeleteItem(s_item);
	return 1;
}

// 다음 아이템 값을 얻음
void GenreType::GetNextItem(SimpleMusicType& item, bool& finished)
{
	SMList.GetNextItem(item, finished);
}


