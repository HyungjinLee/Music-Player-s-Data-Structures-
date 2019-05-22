#include "GenreType.h"
#include "DoublyIterator.h"

int GenreType::Add(SimpleMusicType& item)
{
	SMList.Add(item); // SimpleMusic ������ �߰�
	return 1;
}

// SMList�� ������
void GenreType::ResetSMList()
{
	SMList.ResetTree();
}

// �帣 Ÿ�� SMList���� �� ����
int GenreType::Delete(int num)
{
	SimpleMusicType s_item;
	s_item.SetNum(num);
	SMList.DeleteItem(s_item);
	return 1;
}

// ���� ������ ���� ����
void GenreType::GetNextItem(SimpleMusicType& item, bool& finished)
{
	SMList.GetNextItem(item, finished);
}


