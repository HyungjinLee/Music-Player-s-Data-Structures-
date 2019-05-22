#include "ArrayListForInt.h"


// Make list empty.
void ArrayListForInt::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int ArrayListForInt::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool ArrayListForInt::IsFull()
{
	if (m_Length > 99)
		return true;
	else
		return false;
}


// add a new data into list.
int ArrayListForInt::Add(int inData)
{
	if (!IsFull())
	{
		int CurItem;
		ResetList();
		GetNextItem(CurItem);

		while (m_CurPointer <= m_Length) //ó������ ������
		{
			if (CurItem > inData || m_CurPointer == m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//�ǵڿ��� ���� �ϳ��� �����.
					m_Array[i] = m_Array[i - 1];	//�迭 �б�
				m_Array[m_CurPointer] = inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����



				break;
			}
			GetNextItem(CurItem);	//��������������
		}

	}
	else
		return 0;

	return 1;
}


// Initialize list iterator.
void ArrayListForInt::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayListForInt::GetNextItem(int& data)
{
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == 100)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//id�� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ��
int ArrayListForInt::Get(int& data)
{
	int CurItem;

	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù������ ������
	while (m_CurPointer < m_Length)	//ó������ ������
	{
		if (CurItem == data)	//��ġ�ϸ�
		{
			data = CurItem;	//data�� ���� �������� ��ȯ
			return 1;	//����(1)�� ����
		}
		else if (CurItem > data) //���� �������� id�� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
		{
			return 0;	//����(0)�� ����
		}
		else	//���� �������� id�� �� ������
		{
			GetNextItem(CurItem);	//���� �������� �����´�.(��� Ž��)
		}
	}
	return 0; //���н�0
}

//id�� ��ġ�ϴ� item�� ã�Ƽ� ������
int ArrayListForInt::Delete(int& data)
{
	if (Get(data))	//id�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i] = m_Array[i + 1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//id��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//id�� ��ġ�ϴ� item�� ������ ��ü��Ŵ
int ArrayListForInt::Replace(int data)
{
	int tmp(data);	//�Է¹��� item�� ���

	if (Get(data))	//��ġ�ϴ� �������� ã�� ���
	{
		m_Array[m_CurPointer] = tmp;	//�迭���� ���������Ͱ� ����Ű�� ���� ����ߴ� ���������� ��ü��Ŵ
		return 1;	//����(1)�� ����
	}
	return 0;	//id��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//id�� ��ġ�ϴ� item�� ����Ž������ �˻��ؼ� ��ȯ�Ѵ�.
int ArrayListForInt::GetBinarySearch(int& data)
{
	if (m_Length == 0)	//���� �迭�� ����ٸ�
		return 0;	//����(0)�� ����
	int currentPos = m_Length / 2;	//�迭�� �߰����� ����
	while (1)
	{
		if (m_Array[currentPos] == data) // ��ġ�ϸ�
		{
			data = m_Array[currentPos];	//data�� �߰��� ���� ����
			return 1;	//����(1)�� ����
		}
		else if (m_Array[currentPos] > data)
		{
			if (currentPos == 0)	//ó�� �迭�� ������ �������
				return 0;	//����(0)�� ����
			currentPos /= 2;	//�� ������ �ε����� ���ݷ� �̵�
		}
		else
		{//���� �������� id�� �Է� �������� id���� �۴ٸ�
			if (currentPos == m_Length - 1)	//������ �迭�� ������ ū���
				return 0;	//����(0)�� ����
			currentPos = (currentPos + m_Length) / 2;	//�� ū�� �ε����� �������� �̵�
		}
	}
	return 0;	//ȣ��� �� ���� ����(WARNING ������)
}
