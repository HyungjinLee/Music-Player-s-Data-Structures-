#pragma once
#include <iostream>
#include <algorithm>
#include "Queue.h"
using namespace std;

// Tree를 구성하는 Node (node data, left 포인터, right 포인터)
template<class ItemType>
struct TreeNode
{
	ItemType data;
	TreeNode* left;
	TreeNode* right;
};

// Binary Search Tree 
template<class ItemType>
class BinarySearchTree
{
public:
	// 생성자
	BinarySearchTree();
	// 소멸자
	~BinarySearchTree() { }

	
	/**
	*	@brief	Tree가 Empty인지 확인
	*	@pre	none
	*	@post	none
	*	@return	Tree가 비어있으면 true리턴, 아니면 false 리턴
	*/
	bool IsEmpty()const;

	/**
	*	@brief	Tree가 Full인지 확인
	*	@pre	none
	*	@post	none
	*	@return	Tree가 Full이면 true 리턴, 아니면 false 리턴
	*/
	bool IsFull()const;

	/**
	*	@brief	Tree를 비운다
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree에 node가 몇 개인지 확인함
	*	@pre	none
	*	@post	none
	*	@return	Tree의 node 개수를 리턴
	*/
	int GetLength() const;

	/**
	*	@brief	Tree에 새 node를 추가한다
	*	@pre	ItemType의 객체를 생성
	*	@post	Tree에 새 node가 추가됨
	*/
	void Add(ItemType item);

	/**
	*	@brief	Tree에서 지우고자 하는 node를 찾고 지움
	*	@pre	ItemType의 객체를 생성
	*	@post	Tree에서 입력한 node가 삭제됨
	*/
	void DeleteItem(ItemType item);

	/**
	*	@brief	다음 아이템 값을 얻음
	*	@pre	얻고자 하는 item과 마지막 아이템을 얻은 여부에 대한 finished 설정
	*	@post	tree 상의 다음 아이템을 얻음
	*/
	void GetNextItem(ItemType& item, bool& finished);

	/**
	*	@brief	입력한 값의 node를 Tree에서 검색함
	*	@pre	찾고자 하는 item과 검색결과에 대한 found 설정
	*	@post	node가 Tree에 있는지 검색결과를 알려줌
	*/
	void RetrieveItem(ItemType& item, bool &found)const;


	/**
	*	@brief	입력한 값의 node를 Tree에서 검색함
	*	@pre	찾고자 하는 item과 검색결과에 대한 found 설정
	*	@post	찾은 노드의 주소를 리턴
	*/
	ItemType* GetPointer(ItemType* item, bool &found)const;

	/**
	*	@brief	Tree를 리셋한다.
	*	@pre	none
	*	@post	트리가 InOrder 방법으로 리셋됨
	*/
	void ResetTree();


	/**
	*	@brief	마지막 아이템을 얻는다.
	*	@pre	item 선언
	*	@post	마지막 아이템 리턴
	*/
	void GetLastItem(ItemType& item);

private:
	TreeNode<ItemType>* root;		// Node 타입의 root
	Queue<ItemType> inQue; // 트리 순회를 위한 큐
};

// 생성자
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
	root = NULL;
}

// 트리를 리셋하는 함수
template <class ItemType>
void BinarySearchTree<ItemType>::ResetTree()
{
	InOrder(root, inQue);
}


// InOrder 방법으로 큐에 넣는 함수
template<class ItemType>
void InOrder(TreeNode<ItemType>*tree, Queue<ItemType>& inQue)
{
	if (tree != NULL)
	{
		InOrder(tree->left, inQue);
		inQue.Enqueue(tree->data); // 아이템 큐에 집어넣음
		InOrder(tree->right, inQue);
	}
}

// InOrder 방법으로 다음 아이템을 가져오는 함수
template<class ItemType>
void BinarySearchTree<ItemType>::GetNextItem(ItemType& item, bool& finished)
{
	finished = false;

	inQue.Dequeue(item); // 아이템을 큐에서 빼냄
	if (inQue.IsEmpty()) // 만약 큐가 비어 있다면
		finished = true; // 종료
}



// Tree가 비어있는지 확인
template<class ItemType>
bool BinarySearchTree<ItemType>::IsEmpty()const
{
	if (root == NULL)			// root 노드가 NULL인 경우 true 리턴
		return true;
	else
		return false;			// root 노드가 NULL이 아닌 경우 false 리턴
}

// Tree가 Full인지 확인
template<class ItemType>
bool BinarySearchTree<ItemType>::IsFull()const
{
	TreeNode* room;					// 임시의 node를 만들고
	try
	{
		room = new TreeNode;		// 새 노드를 추가할 수 있는지 확인
		delete room;			// 임시로 만든 room 노드를 지움
		return false;			// isFull에 대한 false 리턴
	}
	catch (std::bad_alloc exception)		// 더 이상 아이템 추가를 할 수 없고 Full일 경우
	{
		return true;					// isFull에 대한 true 리턴
	}
}

// Tree를 비움
template<class ItemType>
void BinarySearchTree<ItemType>::MakeEmpty()
{
	MakeEmptyTree(root);				// Tree 초기화 함수 호출
}

// Tree의 node개수를 알려줌
template<class ItemType>
int BinarySearchTree<ItemType>::GetLength()const
{
	return CountNodes(root);			// node 개수를 새는 함수 호출
}

// Tree에 새로운 node 추가
template<class ItemType>
void BinarySearchTree<ItemType>::Add(ItemType item)
{
	Insert(root, item);					// 새 node 추가하는 함수 호출
	
}

// Tree의 node를 지움
template<class ItemType>
void BinarySearchTree<ItemType>::DeleteItem(ItemType item)
{
	Delete(root, item);					// 존재하는 node 삭제하는 함수를 호출
}

// Tree에서 찾고자 하는 값의 node를 검색
template<class ItemType>
void BinarySearchTree<ItemType>::RetrieveItem(ItemType& item, bool &found)const
{
	Retrieve(root, item, found);		// Tree 검색 함수 호출
}

// Tree에서 찾고자 하는 값의 node를 검색
template<class ItemType>
ItemType* BinarySearchTree<ItemType>::GetPointer(ItemType* item, bool &found)const
{
	return RetrievePointer(root, item, found);		// Tree 검색 함수 호출
}

// 가장 큰 값을 얻는 함수
template<class ItemType>
void BinarySearchTree<ItemType>::GetLastItem(ItemType& item)
{
	GetPredecessor(root, item);
}



/////////////////////////////Global functions//////////////////////////
// Tree를 초기화하는 함수
template<class ItemType>
void MakeEmptyTree(TreeNode<ItemType>*& root)
{
	root = NULL;			// root 노드를 Null로 함
}

// Tree의 node 개수를 세는 함수
template<class ItemType>
int CountNodes(TreeNode<ItemType>* root)
{
	if (root == NULL)		// root 노드가 null일경우 0을 리턴
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;		// 노드의 왼쪽, 오른쪽에 대한 재귀적 호출과 root에 해당하는 1을 더해서 값을 리턴
}

// BinarySearchTree에 새로운 노드 추가
template<class ItemType>
void Insert(TreeNode<ItemType>*& root, ItemType item)
{
	if (root == NULL)				// root가 null일 경우 
	{
		root = new TreeNode<ItemType>;	// root 노드 생성
		root->left = NULL;			// root 노드이므로 left와 right는 NULL로 설정
		root->right = NULL;
		root->data = item;			// root 노드의 값
	}
	else if (root->data > item)		// root가 존재하고, 그 값이 새로운 item 값보다 클 때
	{
		Insert(root->left, item);	// root의 왼쪽으로 Insert 함수 다시 호출
		balance(root);
	}
	else if (root->data < item)		// root가 존재하고, 그 값이 새로운 item 값보다 작을 때
	{
		Insert(root->right, item);	// root의 오른쪽으로 Insert 함수 다시 호출
		balance(root);
	}
}

// 가장 큰 값을 찾는 함수 
template<class ItemType>
void GetPredecessor(TreeNode<ItemType> *root, ItemType& item)
{
	while (root->right != NULL)			// root의 오른쪽이 존재할 경우
		root = root->right;				// root의 오른쪽 노드값이 root에 오도록 한다
	item = root->data;					// root 노드의 값을 item에 복사한다.
}

// 지우려는 노드를 찾으면 실제로 트리에서 그 노드를 지우는 함수
template<class ItemType>
void DeleteNode(TreeNode<ItemType> *&root)
{
	ItemType item;
	TreeNode<ItemType>* tempPtr;			// 임시 노드를 생성하고 root 노드를 임시 노드에 복사
	tempPtr = root;

	if (root->left == NULL)				// 왼쪽노드가 없을 때
	{
		root = root->right;				// 오른쪽 노드가 root가 되도록 복사하고 임시노드를 지움
		delete tempPtr;
	}
	else if (root->right == NULL)		// 오른쪽노드가 없을 때
	{
		root = root->left;				// 왼쪽 노드가 root가 되도록 복사하고 임시노드를 지움
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);	// 중간에 있는 노드를 지우고 싶을 때 (left, right, child 노드 있을 경우)
		root->data = item;					// 지우려는 노드보다 작은 노드들 중에 가장 큰 노드를 찾음
		Delete(root->left, item);			// 그 값을 지울 노드에 복사를 해서 지운 것처럼 눈속임
	}
}

// 내가 지우려고 하는 노드를 찾는 recursive 함수
template<class ItemType>
void Delete(TreeNode<ItemType> *&root, ItemType item)
{
	if (root == NULL)					// root가 NULL인 경우 -> 끝까지 다 검사했을 때
		return; 

	if (item < root->data)				// root노드값보다 item노드가 작을 때
		Delete(root->left, item);		// 왼쪽노드로 가서 delete함수 호출
	else if (item > root->data)			// root노드값보다 item노드가 클 때
		Delete(root->right, item);		// 오른쪽노드로 가서 delete함수 호출
	else
		DeleteNode(root);				// 찾고자 하는 값이 일치하는 경우 deletenode 함수 호출
}

// Tree에서 node를 검색하는 함수
template<class ItemType>
void Retrieve(TreeNode<ItemType> *root, ItemType& item, bool &found)
{
	
	if (root == NULL)						// root가 NULL인 경우 found는 false 
		found = false;
	else if (item < root->data)				// 찾고자 하는 아이템값이 root값보다 작을 때 
		Retrieve(root->left, item, found);	// 왼쪽 노드로 가서 retrieve 함수 호출
	else if (item > root->data)				// 찾고자 하는 아이템값이 root값보다 클 때
		Retrieve(root->right, item, found);	// 오른쪽 노드로 가서 retrieve 함수 호출
	else
	{										// 찾고자 하는 값과 일치할 때
		item = root->data;					// item에 노드 정보를 복사
		found = true;						// found값을 true로 해서 찾는 과정을 멈춤
	}
}

// Tree에서 node를 검색하는 함수
template<class ItemType>
ItemType* RetrievePointer(TreeNode<ItemType> *root, ItemType* item, bool &found)
{
	
	if (root == NULL)						// root가 NULL인 경우 found는 false 
		found = false;
	else if (*item < root->data)				// 찾고자 하는 아이템값이 root값보다 작을 때 
		RetrievePointer(root->left, item, found);	// 왼쪽 노드로 가서 retrieve 함수 호출
	else if (*item > root->data)				// 찾고자 하는 아이템값이 root값보다 클 때
		RetrievePointer(root->right, item, found);	// 오른쪽 노드로 가서 retrieve 함수 호출
	else
	{										// 찾고자 하는 값과 일치할 때		
		found = true;						// found값을 true로 해서 찾는 과정을 멈춤		
		return &root->data;					// item에 노드 주소를 리턴
	}
}



// AVL 트리의 높이를 출력
template<class ItemType>
int height(TreeNode<ItemType>* &temp)
{
	int h = 0;
	if (temp != NULL)
	{
		// 재귀적으로 왼쪽 혹은 오른쪽으로 검색

		int left = height(temp->left);
		int right = height(temp->right);
		int maxHeight = max(left, right);

		h = maxHeight + 1;
	}
	return h;
}

// 균형인수(높이의 차이)를 반환
template <class ItemType>
int diff(TreeNode<ItemType>* &temp)
{
	// 왼쪽 자식의 높이와 오른쪽 자식의 높이 차이를 반환합니다. 
	int left = height(temp->left);
	int right = height(temp->right);
	int factor = left - right;
	return factor;
}

// RR 회전

template<class ItemType>
TreeNode<ItemType>* rr(TreeNode<ItemType>* &parent)
{
	TreeNode<ItemType> *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

// LL 회전

template<class ItemType>
TreeNode<ItemType>* ll(TreeNode<ItemType>* &parent)
{
	TreeNode<ItemType> *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

// RL 회전

template<class ItemType>
TreeNode<ItemType>* rl(TreeNode<ItemType>* &parent)
{
	TreeNode<ItemType> *temp;
	temp = parent->right;
	parent->right = ll(temp);
	return rr(parent);
}
// LR 회전

template<class ItemType>
TreeNode<ItemType>* lr(TreeNode<ItemType>* &parent)
{
	TreeNode<ItemType> *temp;
	temp = parent->left;
	parent->left = rr(temp);
	return ll(parent);
}

// AVL 트리의 균형을 맞추는 함수

template<class ItemType>
TreeNode<ItemType>* balance(TreeNode<ItemType> *&temp)
{
	int factor = diff(temp);
	// 왼쪽 서브트리쪽으로 삽입이 되어 균형이 깨진 경우
	if (factor > 1)
	{
		// 그 왼쪽 자식노드에 문제가 발생
		if (diff(temp->left) > 0)
		{
			temp = ll(temp);
		}
		// 그 오른쪽 자식 노드에 문제가 발생
		else
		{
			temp = lr(temp);
		}
	}
	else if (factor < -1)
	{
		if (diff(temp->right) > 0)
		{
			temp = rl(temp);
		}
		else
		{
			temp = rr(temp);
		}
	}
	return temp;
}