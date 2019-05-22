#include "SingerType.h"

int SingerType::Add(SimpleAlbumType& item)
{
	SAList.Add(item); // SimpleAlbum ������ �߰�
	return 1;
}

// �帣 Ÿ�� SAList���� �ٹ� ����
int SingerType::Delete(string name, string singer)
{
	SimpleAlbumType s_item; 
	s_item.SetName(name); // �ٹ� �� �Է�
	s_item.SetSinger(singer); // ���� �� �Է�
	SAList.DeleteItem(s_item); // ��ġ�ϴ� ������ ����
	return 1;
}


// ���Ϸκ��� ���ڵ带 �Է¹���
int SingerType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_name;
	fin >> m_startdate;
	fin >> m_genre;

	return 1;
}

// SA����Ʈ �ȿ� �ش� �ٹ��� �ִ��� �˻�
int SingerType::Get(SimpleAlbumType album)
{
	bool found;
	SAList.RetrieveItem(album, found); // �ش� �ٹ� �˻�
	
	if(found)
		return 1;
	else
		return 0;
}

// SMList�� ����� ����
int SingerType::GetSMListSize()
{
	return SAList.GetLength();
}

// ���� ������ ���� ����
void SingerType::GetNextItem(SimpleAlbumType& item, bool& finished)
{
	SAList.GetNextItem(item, finished);
}
