#include "AlbumType.h"

int AlbumType::Add(SimpleMusicType item)
{
	SMList.Add(item); // SimpleMusic ������ �߰�
	return 1;
}

// SMList�� ����� ����
int AlbumType::GetSMListSize()
{
	return SMList.GetLength();
}
// �帣 Ÿ�� SMList���� �� ����
int AlbumType::Delete(int num)
{
	SimpleMusicType s_item;
	s_item.SetNum(num);
	SMList.DeleteItem(s_item);
	return 1;
}


// ���Ϸκ��� ���ڵ带 �Է¹���
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
