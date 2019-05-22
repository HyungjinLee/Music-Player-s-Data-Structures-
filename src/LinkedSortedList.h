#include "SimpleMusicType.h"
#include "SimpleAlbumType.h"
#include "SingerType.h"
#include "GenreType.h"
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H



/**
*	연결 리스트에 사용 되는 노드 타입
*/
template <typename T>
struct NodeType
{
	T data;	// 각각의 노드 안에 들어가는 정보
	NodeType* next;	// 다음 노드를 가리키는 포인터
};


/**
*	정렬된 연결 리스트 클래스
*/
template <typename T>
class LinkedList
{
public:
	/**
	*	생성자
	*/
	LinkedList();     

	/**
	*	소멸자
	*/
	~LinkedList();   
	
	/**
	*	@brief	리스트를 비어 있는 상태로 초기화
	*	@pre	
	*	@post	리스트가 비워진다.
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트 안의 아이템 갯수를 얻는다.
	*	@pre	
	*	@post	리스트 안의 원소 갯수를 리턴한다.
	*	@return	리스트 안의 원소 갯수
	*/
	int GetLength() const;

	/**
	*	@brief	리스트 안의 적절한 위치에 아이템을 추가한다.
	*	@pre	리스트가 꽉 차지 않고, 넣고자 하는 아이템이 추가되지 않은 상태 
	*	@post	아이템이 리스트에 삽입된다.
	*	@return	성공시 1, 실패시 0
	*/
	int Add(T& item);

	/**
	*	@brief	리스트에서 아이템을 제거한다.
	*	@pre	리스트가 비어있지 않고, 지우고자 하는 아이템이 리스트에 존재
	*	@post	아이템이 리스트에서 제거된다.
	*	@return	성공시 1, 실패시 0
	*/
	int Delete(T& item);

	/**
	*	@brief	리스트에 있는 아이템 정보를 변경한다.
	*	@pre	리스트가 비어있지 않고, 바꾸고자 하는 아이템이 리스트에 존재
	*	@post	아이템 값이 변경된다.
	*	@return	성공시 1, 실패시 0
	*/
	int Replace(T& item);

	/**
	*	@brief	key가 일치하는 아이템을 찾는다.
	*	@pre	아이템의 key 멤버가 초기화 되어 있어야 함
	*	@post	key가 일치하는 아이템이 존재하면, 해당 레코드가 item에 복사된다.
	*	@return	성공시 1, 실패시 0
	*/
	int Get(T& item);

	/**
	*	@brief	key가 일치하는 아이템을 찾는다.
	*	@pre	아이템의 key 멤버가 초기화 되어 있어야 함
	*	@post	key가 일치하는 아이템이 존재하면, 해당 레코드가 item에 복사된다.
	*	@return	성공시 1, 실패시 0
	*/
	T* GetPointer(T& item);

	/**
	*	@brief	마지막 아이템을 반환한다.
	*	@pre	
	*	@post	마지막 아이템의 포인터 리턴
	*	@return	포인터 리턴
	*/
	T* GetLastPointer();


	/**
	*	@brief	다음 아이템의 포인터를 리턴한다.
	*	@pre
	*	@post	다음 아이템의 포인터 리턴
	*	@return	포인터 리턴
	*/
	T* GetNextPointer();

	/**
	*	@brief	현재 포인터를 초기화한다.
	*	@pre	
	*	@post	현재 포인터가 리스트 맨 앞에 오면서 초기화된다.
	*/
	void ResetList();

	/**
	*	@brief	리스트의 다음 값을 얻는다.
	*	@pre	현재 포인터가 정의되어 있어야 하고, 현재 포인터가 리스트 마지막 아이템을 가리키고 있으면 안된다.
	*	@post	현재 포인터가 다음 아이템 위치로 넘어간다. 현재 포인터의 다음 아이템 값으로 item이 복사된다.
	*	@return 현재 포인터가 NULL이면 0, 아니면 1 리턴
	*/
	int GetNextItem(T& item);
	
private:
	
	NodeType<T>* m_pList;	// 첫번째 노드를 가리키는 포인터
	NodeType<T>* m_pCurPointer;	// ITERATION을 사용하여 현재 노드를 가리키는 노드 포인터
	int m_nLength;	// 리스트의 노드 수 
};

// 클래스 생성자
template <typename T>
LinkedList<T>::LinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}

// 클래스 소멸자
template <typename T>
LinkedList<T>::~LinkedList()
{
	//리스트내의 모든 node 제거
	if(typeid(T) != typeid(SimpleMusicType) && typeid(T) != typeid(SimpleAlbumType))
		MakeEmpty();
}


// 리스트를 비어 있는 상태로 되돌린다.
template <typename T>
void LinkedList<T>::MakeEmpty()
// 리스트를 비우고, 모든 포인터를 반환한다.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T>* tempPtr;
	
    while (m_pList != NULL)
    {
        tempPtr = m_pList;
        m_pList = m_pList->next;
        delete tempPtr;
    }
	m_nLength = 0;
}

// 리스트의 원소의 개수를 얻음
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}

//리스트 안에 아이템을 추가
template <typename T>
int LinkedList<T>::Add(T &item)
{	
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			if (m_pCurPointer->data>node->data)
			{
				if (pre == NULL)
				{
					node->next = m_pCurPointer;
					m_pList = node;
					break;
				}	//넣을 자리 앞 원소가 존재하지 않을 때 첫번째 원소로 삽입.

				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}	//지금 가리키는 원소의 data값이 node의 data값보다 클 경우 pre 뒷자리에 삽입.

				// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}

//리스트에서 아이템 삭제
template <typename T>
int LinkedList<T>::Delete(T &item)
{
	bool moreToSearch, found;
	NodeType<T>* pre=NULL;	//변수 선언

	m_pCurPointer = m_pList;
	found = false;
	moreToSearch = (m_pCurPointer != NULL);	//변수 초기화
	
	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == m_pCurPointer->data)	//현재 가리키는 원소의 값과 item의 값이 일치할 때
		{
			found = true;	//찾았으므로 found 값 변경
			if(pre==NULL)
				m_pList=m_pCurPointer->next;	//항목 이전에 다른 원소가 없을 때 항목의 다음 원소를 첫번째 원소로 한다.
			else
			{
				pre->next=m_pCurPointer->next;
				delete m_pCurPointer;
			}	//이전의 원소의 다음 원소를 '가리키는 항목의 다음 원소'로 바꾼다.
			m_nLength--;	//리스트의 길이를 1 줄여준다.
		}
		else
		{
			pre=m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);
		}	//일치하지 않을 때 다음 원소를 가리킨다. 단, pre는 지금의 원소를 가리킨다.
	}

	if(found)
		return 1;
	else
		return 0;	//삭제가 성공하면 1, 아니면 0을 리턴한다.
}

// 리스트 안의 아이템 정보를 변경
template <typename T>
int LinkedList<T>::Replace(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화
	
	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data) // 일치하는 아이템을 발견하면
		{
			found = true;
			item.SetRecordFromKB(); // 키보드로부터 바꾸고자하는 아이템 정보 입력

			if (typeid(T) == typeid(AlbumType) || typeid(T) == typeid(SingerType)) // 앨범이나 가수면
			{
				if (Get(item)) // 중복된다면
				{
					cout << "Duplicate Item!!" << endl;
					return 0;
				}

			}
			
			location->data=item;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 리스트의 항목에 item을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if(found)
		return 1;
	else
		return 0;	//수정에 성공하면 1, 그렇지 못하면 0을 리턴한다.
}

// key가 일치하는 아이템을 찾는다.
template <typename T>
T* LinkedList<T>::GetPointer(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return &(location->data);
	else
		return NULL;	//찾으면 포인터, 그렇지 못하면 null을 리턴한다.
}

// 마지막 아이템의 포인터를 반환
template <typename T>
T* LinkedList<T>::GetLastPointer()
{
	bool moreToSearch;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	moreToSearch = (location->next != NULL);	//변수 초기화

	while (moreToSearch)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
			location = location->next;
			moreToSearch = (location->next != NULL);
	}
	return &(location->data); // 마지막 아이템 반환
}

// key가 일치하는 아이템을 찾는다.
template <typename T>
int LinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화
	
	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if(found)
		return 1;
	else
		return 0;	//찾으면 1, 그렇지 못하면 0을 리턴한다.
}

// 현재 포인터를 초기화
template <typename T>
void LinkedList<T>::ResetList()
{	
	// current pointer 초기화
	m_pCurPointer = NULL;
}

// 리스트의 다음 아이템을 얻음
template <typename T>
int LinkedList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	if (m_pCurPointer == NULL) // current pointer이 NULL이면 0을 리턴
		return 0;
	else
	{
		//item 에 current position 의 info 를 삽입
		item = m_pCurPointer->data;
		return 1;
	}
}

// 리스트의 다음 포인터값을 얻음
template <typename T>
T* LinkedList<T>::GetNextPointer()
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	if (m_pCurPointer == NULL) // current pointer이 NULL이면 0을 리턴
		return NULL;
	else
	{
		return &m_pCurPointer->data; // 데이터의 주소를 리턴
	}
}

#endif	// LINKED_LIST