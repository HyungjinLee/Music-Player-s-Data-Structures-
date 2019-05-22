#include "SimpleMusicType.h"
#include "SimpleAlbumType.h"
#include "SingerType.h"
#include "GenreType.h"
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H



/**
*	���� ����Ʈ�� ��� �Ǵ� ��� Ÿ��
*/
template <typename T>
struct NodeType
{
	T data;	// ������ ��� �ȿ� ���� ����
	NodeType* next;	// ���� ��带 ����Ű�� ������
};


/**
*	���ĵ� ���� ����Ʈ Ŭ����
*/
template <typename T>
class LinkedList
{
public:
	/**
	*	������
	*/
	LinkedList();     

	/**
	*	�Ҹ���
	*/
	~LinkedList();   
	
	/**
	*	@brief	����Ʈ�� ��� �ִ� ���·� �ʱ�ȭ
	*	@pre	
	*	@post	����Ʈ�� �������.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ ���� ������ ������ ��´�.
	*	@pre	
	*	@post	����Ʈ ���� ���� ������ �����Ѵ�.
	*	@return	����Ʈ ���� ���� ����
	*/
	int GetLength() const;

	/**
	*	@brief	����Ʈ ���� ������ ��ġ�� �������� �߰��Ѵ�.
	*	@pre	����Ʈ�� �� ���� �ʰ�, �ְ��� �ϴ� �������� �߰����� ���� ���� 
	*	@post	�������� ����Ʈ�� ���Եȴ�.
	*	@return	������ 1, ���н� 0
	*/
	int Add(T& item);

	/**
	*	@brief	����Ʈ���� �������� �����Ѵ�.
	*	@pre	����Ʈ�� ������� �ʰ�, ������� �ϴ� �������� ����Ʈ�� ����
	*	@post	�������� ����Ʈ���� ���ŵȴ�.
	*	@return	������ 1, ���н� 0
	*/
	int Delete(T& item);

	/**
	*	@brief	����Ʈ�� �ִ� ������ ������ �����Ѵ�.
	*	@pre	����Ʈ�� ������� �ʰ�, �ٲٰ��� �ϴ� �������� ����Ʈ�� ����
	*	@post	������ ���� ����ȴ�.
	*	@return	������ 1, ���н� 0
	*/
	int Replace(T& item);

	/**
	*	@brief	key�� ��ġ�ϴ� �������� ã�´�.
	*	@pre	�������� key ����� �ʱ�ȭ �Ǿ� �־�� ��
	*	@post	key�� ��ġ�ϴ� �������� �����ϸ�, �ش� ���ڵ尡 item�� ����ȴ�.
	*	@return	������ 1, ���н� 0
	*/
	int Get(T& item);

	/**
	*	@brief	key�� ��ġ�ϴ� �������� ã�´�.
	*	@pre	�������� key ����� �ʱ�ȭ �Ǿ� �־�� ��
	*	@post	key�� ��ġ�ϴ� �������� �����ϸ�, �ش� ���ڵ尡 item�� ����ȴ�.
	*	@return	������ 1, ���н� 0
	*/
	T* GetPointer(T& item);

	/**
	*	@brief	������ �������� ��ȯ�Ѵ�.
	*	@pre	
	*	@post	������ �������� ������ ����
	*	@return	������ ����
	*/
	T* GetLastPointer();


	/**
	*	@brief	���� �������� �����͸� �����Ѵ�.
	*	@pre
	*	@post	���� �������� ������ ����
	*	@return	������ ����
	*/
	T* GetNextPointer();

	/**
	*	@brief	���� �����͸� �ʱ�ȭ�Ѵ�.
	*	@pre	
	*	@post	���� �����Ͱ� ����Ʈ �� �տ� ���鼭 �ʱ�ȭ�ȴ�.
	*/
	void ResetList();

	/**
	*	@brief	����Ʈ�� ���� ���� ��´�.
	*	@pre	���� �����Ͱ� ���ǵǾ� �־�� �ϰ�, ���� �����Ͱ� ����Ʈ ������ �������� ����Ű�� ������ �ȵȴ�.
	*	@post	���� �����Ͱ� ���� ������ ��ġ�� �Ѿ��. ���� �������� ���� ������ ������ item�� ����ȴ�.
	*	@return ���� �����Ͱ� NULL�̸� 0, �ƴϸ� 1 ����
	*/
	int GetNextItem(T& item);
	
private:
	
	NodeType<T>* m_pList;	// ù��° ��带 ����Ű�� ������
	NodeType<T>* m_pCurPointer;	// ITERATION�� ����Ͽ� ���� ��带 ����Ű�� ��� ������
	int m_nLength;	// ����Ʈ�� ��� �� 
};

// Ŭ���� ������
template <typename T>
LinkedList<T>::LinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}

// Ŭ���� �Ҹ���
template <typename T>
LinkedList<T>::~LinkedList()
{
	//����Ʈ���� ��� node ����
	if(typeid(T) != typeid(SimpleMusicType) && typeid(T) != typeid(SimpleAlbumType))
		MakeEmpty();
}


// ����Ʈ�� ��� �ִ� ���·� �ǵ�����.
template <typename T>
void LinkedList<T>::MakeEmpty()
// ����Ʈ�� ����, ��� �����͸� ��ȯ�Ѵ�.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;
	
    while (m_pList != NULL)
    {
        tempPtr = m_pList;
        m_pList = m_pList->next;
        delete tempPtr;
    }
	m_nLength = 0;
}

// ����Ʈ�� ������ ������ ����
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}

//����Ʈ �ȿ� �������� �߰�
template <typename T>
int LinkedList<T>::Add(T &item)
{	
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (m_pCurPointer->data>node->data)
			{
				if (pre == NULL)
				{
					node->next = m_pCurPointer;
					m_pList = node;
					break;
				}	//���� �ڸ� �� ���Ұ� �������� ���� �� ù��° ���ҷ� ����.

				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}	//���� ����Ű�� ������ data���� node�� data������ Ŭ ��� pre ���ڸ��� ����.

				// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}

//����Ʈ���� ������ ����
template <typename T>
int LinkedList<T>::Delete(T &item)
{
	bool moreToSearch, found;
	NodeType<T>* pre=NULL;	//���� ����

	m_pCurPointer = m_pList;
	found = false;
	moreToSearch = (m_pCurPointer != NULL);	//���� �ʱ�ȭ
	
	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == m_pCurPointer->data)	//���� ����Ű�� ������ ���� item�� ���� ��ġ�� ��
		{
			found = true;	//ã�����Ƿ� found �� ����
			if(pre==NULL)
				m_pList=m_pCurPointer->next;	//�׸� ������ �ٸ� ���Ұ� ���� �� �׸��� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.
			else
			{
				pre->next=m_pCurPointer->next;
				delete m_pCurPointer;
			}	//������ ������ ���� ���Ҹ� '����Ű�� �׸��� ���� ����'�� �ٲ۴�.
			m_nLength--;	//����Ʈ�� ���̸� 1 �ٿ��ش�.
		}
		else
		{
			pre=m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);
		}	//��ġ���� ���� �� ���� ���Ҹ� ����Ų��. ��, pre�� ������ ���Ҹ� ����Ų��.
	}

	if(found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �ƴϸ� 0�� �����Ѵ�.
}

// ����Ʈ ���� ������ ������ ����
template <typename T>
int LinkedList<T>::Replace(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ
	
	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data) // ��ġ�ϴ� �������� �߰��ϸ�
		{
			found = true;
			item.SetRecordFromKB(); // Ű����κ��� �ٲٰ����ϴ� ������ ���� �Է�

			if (typeid(T) == typeid(AlbumType) || typeid(T) == typeid(SingerType)) // �ٹ��̳� ������
			{
				if (Get(item)) // �ߺ��ȴٸ�
				{
					cout << "Duplicate Item!!" << endl;
					return 0;
				}

			}
			
			location->data=item;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if(found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}

// key�� ��ġ�ϴ� �������� ã�´�.
template <typename T>
T* LinkedList<T>::GetPointer(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return &(location->data);
	else
		return NULL;	//ã���� ������, �׷��� ���ϸ� null�� �����Ѵ�.
}

// ������ �������� �����͸� ��ȯ
template <typename T>
T* LinkedList<T>::GetLastPointer()
{
	bool moreToSearch;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	moreToSearch = (location->next != NULL);	//���� �ʱ�ȭ

	while (moreToSearch)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
			location = location->next;
			moreToSearch = (location->next != NULL);
	}
	return &(location->data); // ������ ������ ��ȯ
}

// key�� ��ġ�ϴ� �������� ã�´�.
template <typename T>
int LinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ
	
	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if(found)
		return 1;
	else
		return 0;	//ã���� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}

// ���� �����͸� �ʱ�ȭ
template <typename T>
void LinkedList<T>::ResetList()
{	
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}

// ����Ʈ�� ���� �������� ����
template <typename T>
int LinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	if (m_pCurPointer == NULL) // current pointer�� NULL�̸� 0�� ����
		return 0;
	else
	{
		//item �� current position �� info �� ����
		item = m_pCurPointer->data;
		return 1;
	}
}

// ����Ʈ�� ���� �����Ͱ��� ����
template <typename T>
T* LinkedList<T>::GetNextPointer()
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	if (m_pCurPointer == NULL) // current pointer�� NULL�̸� 0�� ����
		return NULL;
	else
	{
		return &m_pCurPointer->data; // �������� �ּҸ� ����
	}
}

#endif	// LINKED_LIST