#pragma once
#include <iostream>
#include <algorithm>
#include "Queue.h"
using namespace std;

// Tree�� �����ϴ� Node (node data, left ������, right ������)
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
	// ������
	BinarySearchTree();
	// �Ҹ���
	~BinarySearchTree() { }

	
	/**
	*	@brief	Tree�� Empty���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� ��������� true����, �ƴϸ� false ����
	*/
	bool IsEmpty()const;

	/**
	*	@brief	Tree�� Full���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� Full�̸� true ����, �ƴϸ� false ����
	*/
	bool IsFull()const;

	/**
	*	@brief	Tree�� ����
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree�� node�� �� ������ Ȯ����
	*	@pre	none
	*	@post	none
	*	@return	Tree�� node ������ ����
	*/
	int GetLength() const;

	/**
	*	@brief	Tree�� �� node�� �߰��Ѵ�
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree�� �� node�� �߰���
	*/
	void Add(ItemType item);

	/**
	*	@brief	Tree���� ������� �ϴ� node�� ã�� ����
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree���� �Է��� node�� ������
	*/
	void DeleteItem(ItemType item);

	/**
	*	@brief	���� ������ ���� ����
	*	@pre	����� �ϴ� item�� ������ �������� ���� ���ο� ���� finished ����
	*	@post	tree ���� ���� �������� ����
	*/
	void GetNextItem(ItemType& item, bool& finished);

	/**
	*	@brief	�Է��� ���� node�� Tree���� �˻���
	*	@pre	ã���� �ϴ� item�� �˻������ ���� found ����
	*	@post	node�� Tree�� �ִ��� �˻������ �˷���
	*/
	void RetrieveItem(ItemType& item, bool &found)const;


	/**
	*	@brief	�Է��� ���� node�� Tree���� �˻���
	*	@pre	ã���� �ϴ� item�� �˻������ ���� found ����
	*	@post	ã�� ����� �ּҸ� ����
	*/
	ItemType* GetPointer(ItemType* item, bool &found)const;

	/**
	*	@brief	Tree�� �����Ѵ�.
	*	@pre	none
	*	@post	Ʈ���� InOrder ������� ���µ�
	*/
	void ResetTree();


	/**
	*	@brief	������ �������� ��´�.
	*	@pre	item ����
	*	@post	������ ������ ����
	*/
	void GetLastItem(ItemType& item);

private:
	TreeNode<ItemType>* root;		// Node Ÿ���� root
	Queue<ItemType> inQue; // Ʈ�� ��ȸ�� ���� ť
};

// ������
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
	root = NULL;
}

// Ʈ���� �����ϴ� �Լ�
template <class ItemType>
void BinarySearchTree<ItemType>::ResetTree()
{
	InOrder(root, inQue);
}


// InOrder ������� ť�� �ִ� �Լ�
template<class ItemType>
void InOrder(TreeNode<ItemType>*tree, Queue<ItemType>& inQue)
{
	if (tree != NULL)
	{
		InOrder(tree->left, inQue);
		inQue.Enqueue(tree->data); // ������ ť�� �������
		InOrder(tree->right, inQue);
	}
}

// InOrder ������� ���� �������� �������� �Լ�
template<class ItemType>
void BinarySearchTree<ItemType>::GetNextItem(ItemType& item, bool& finished)
{
	finished = false;

	inQue.Dequeue(item); // �������� ť���� ����
	if (inQue.IsEmpty()) // ���� ť�� ��� �ִٸ�
		finished = true; // ����
}



// Tree�� ����ִ��� Ȯ��
template<class ItemType>
bool BinarySearchTree<ItemType>::IsEmpty()const
{
	if (root == NULL)			// root ��尡 NULL�� ��� true ����
		return true;
	else
		return false;			// root ��尡 NULL�� �ƴ� ��� false ����
}

// Tree�� Full���� Ȯ��
template<class ItemType>
bool BinarySearchTree<ItemType>::IsFull()const
{
	TreeNode* room;					// �ӽ��� node�� �����
	try
	{
		room = new TreeNode;		// �� ��带 �߰��� �� �ִ��� Ȯ��
		delete room;			// �ӽ÷� ���� room ��带 ����
		return false;			// isFull�� ���� false ����
	}
	catch (std::bad_alloc exception)		// �� �̻� ������ �߰��� �� �� ���� Full�� ���
	{
		return true;					// isFull�� ���� true ����
	}
}

// Tree�� ���
template<class ItemType>
void BinarySearchTree<ItemType>::MakeEmpty()
{
	MakeEmptyTree(root);				// Tree �ʱ�ȭ �Լ� ȣ��
}

// Tree�� node������ �˷���
template<class ItemType>
int BinarySearchTree<ItemType>::GetLength()const
{
	return CountNodes(root);			// node ������ ���� �Լ� ȣ��
}

// Tree�� ���ο� node �߰�
template<class ItemType>
void BinarySearchTree<ItemType>::Add(ItemType item)
{
	Insert(root, item);					// �� node �߰��ϴ� �Լ� ȣ��
	
}

// Tree�� node�� ����
template<class ItemType>
void BinarySearchTree<ItemType>::DeleteItem(ItemType item)
{
	Delete(root, item);					// �����ϴ� node �����ϴ� �Լ��� ȣ��
}

// Tree���� ã���� �ϴ� ���� node�� �˻�
template<class ItemType>
void BinarySearchTree<ItemType>::RetrieveItem(ItemType& item, bool &found)const
{
	Retrieve(root, item, found);		// Tree �˻� �Լ� ȣ��
}

// Tree���� ã���� �ϴ� ���� node�� �˻�
template<class ItemType>
ItemType* BinarySearchTree<ItemType>::GetPointer(ItemType* item, bool &found)const
{
	return RetrievePointer(root, item, found);		// Tree �˻� �Լ� ȣ��
}

// ���� ū ���� ��� �Լ�
template<class ItemType>
void BinarySearchTree<ItemType>::GetLastItem(ItemType& item)
{
	GetPredecessor(root, item);
}



/////////////////////////////Global functions//////////////////////////
// Tree�� �ʱ�ȭ�ϴ� �Լ�
template<class ItemType>
void MakeEmptyTree(TreeNode<ItemType>*& root)
{
	root = NULL;			// root ��带 Null�� ��
}

// Tree�� node ������ ���� �Լ�
template<class ItemType>
int CountNodes(TreeNode<ItemType>* root)
{
	if (root == NULL)		// root ��尡 null�ϰ�� 0�� ����
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;		// ����� ����, �����ʿ� ���� ����� ȣ��� root�� �ش��ϴ� 1�� ���ؼ� ���� ����
}

// BinarySearchTree�� ���ο� ��� �߰�
template<class ItemType>
void Insert(TreeNode<ItemType>*& root, ItemType item)
{
	if (root == NULL)				// root�� null�� ��� 
	{
		root = new TreeNode<ItemType>;	// root ��� ����
		root->left = NULL;			// root ����̹Ƿ� left�� right�� NULL�� ����
		root->right = NULL;
		root->data = item;			// root ����� ��
	}
	else if (root->data > item)		// root�� �����ϰ�, �� ���� ���ο� item ������ Ŭ ��
	{
		Insert(root->left, item);	// root�� �������� Insert �Լ� �ٽ� ȣ��
		balance(root);
	}
	else if (root->data < item)		// root�� �����ϰ�, �� ���� ���ο� item ������ ���� ��
	{
		Insert(root->right, item);	// root�� ���������� Insert �Լ� �ٽ� ȣ��
		balance(root);
	}
}

// ���� ū ���� ã�� �Լ� 
template<class ItemType>
void GetPredecessor(TreeNode<ItemType> *root, ItemType& item)
{
	while (root->right != NULL)			// root�� �������� ������ ���
		root = root->right;				// root�� ������ ��尪�� root�� ������ �Ѵ�
	item = root->data;					// root ����� ���� item�� �����Ѵ�.
}

// ������� ��带 ã���� ������ Ʈ������ �� ��带 ����� �Լ�
template<class ItemType>
void DeleteNode(TreeNode<ItemType> *&root)
{
	ItemType item;
	TreeNode<ItemType>* tempPtr;			// �ӽ� ��带 �����ϰ� root ��带 �ӽ� ��忡 ����
	tempPtr = root;

	if (root->left == NULL)				// ���ʳ�尡 ���� ��
	{
		root = root->right;				// ������ ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else if (root->right == NULL)		// �����ʳ�尡 ���� ��
	{
		root = root->left;				// ���� ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);	// �߰��� �ִ� ��带 ����� ���� �� (left, right, child ��� ���� ���)
		root->data = item;					// ������� ��庸�� ���� ���� �߿� ���� ū ��带 ã��
		Delete(root->left, item);			// �� ���� ���� ��忡 ���縦 �ؼ� ���� ��ó�� ������
	}
}

// ���� ������� �ϴ� ��带 ã�� recursive �Լ�
template<class ItemType>
void Delete(TreeNode<ItemType> *&root, ItemType item)
{
	if (root == NULL)					// root�� NULL�� ��� -> ������ �� �˻����� ��
		return; 

	if (item < root->data)				// root��尪���� item��尡 ���� ��
		Delete(root->left, item);		// ���ʳ��� ���� delete�Լ� ȣ��
	else if (item > root->data)			// root��尪���� item��尡 Ŭ ��
		Delete(root->right, item);		// �����ʳ��� ���� delete�Լ� ȣ��
	else
		DeleteNode(root);				// ã���� �ϴ� ���� ��ġ�ϴ� ��� deletenode �Լ� ȣ��
}

// Tree���� node�� �˻��ϴ� �Լ�
template<class ItemType>
void Retrieve(TreeNode<ItemType> *root, ItemType& item, bool &found)
{
	
	if (root == NULL)						// root�� NULL�� ��� found�� false 
		found = false;
	else if (item < root->data)				// ã���� �ϴ� �����۰��� root������ ���� �� 
		Retrieve(root->left, item, found);	// ���� ���� ���� retrieve �Լ� ȣ��
	else if (item > root->data)				// ã���� �ϴ� �����۰��� root������ Ŭ ��
		Retrieve(root->right, item, found);	// ������ ���� ���� retrieve �Լ� ȣ��
	else
	{										// ã���� �ϴ� ���� ��ġ�� ��
		item = root->data;					// item�� ��� ������ ����
		found = true;						// found���� true�� �ؼ� ã�� ������ ����
	}
}

// Tree���� node�� �˻��ϴ� �Լ�
template<class ItemType>
ItemType* RetrievePointer(TreeNode<ItemType> *root, ItemType* item, bool &found)
{
	
	if (root == NULL)						// root�� NULL�� ��� found�� false 
		found = false;
	else if (*item < root->data)				// ã���� �ϴ� �����۰��� root������ ���� �� 
		RetrievePointer(root->left, item, found);	// ���� ���� ���� retrieve �Լ� ȣ��
	else if (*item > root->data)				// ã���� �ϴ� �����۰��� root������ Ŭ ��
		RetrievePointer(root->right, item, found);	// ������ ���� ���� retrieve �Լ� ȣ��
	else
	{										// ã���� �ϴ� ���� ��ġ�� ��		
		found = true;						// found���� true�� �ؼ� ã�� ������ ����		
		return &root->data;					// item�� ��� �ּҸ� ����
	}
}



// AVL Ʈ���� ���̸� ���
template<class ItemType>
int height(TreeNode<ItemType>* &temp)
{
	int h = 0;
	if (temp != NULL)
	{
		// ��������� ���� Ȥ�� ���������� �˻�

		int left = height(temp->left);
		int right = height(temp->right);
		int maxHeight = max(left, right);

		h = maxHeight + 1;
	}
	return h;
}

// �����μ�(������ ����)�� ��ȯ
template <class ItemType>
int diff(TreeNode<ItemType>* &temp)
{
	// ���� �ڽ��� ���̿� ������ �ڽ��� ���� ���̸� ��ȯ�մϴ�. 
	int left = height(temp->left);
	int right = height(temp->right);
	int factor = left - right;
	return factor;
}

// RR ȸ��

template<class ItemType>
TreeNode<ItemType>* rr(TreeNode<ItemType>* &parent)
{
	TreeNode<ItemType> *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

// LL ȸ��

template<class ItemType>
TreeNode<ItemType>* ll(TreeNode<ItemType>* &parent)
{
	TreeNode<ItemType> *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

// RL ȸ��

template<class ItemType>
TreeNode<ItemType>* rl(TreeNode<ItemType>* &parent)
{
	TreeNode<ItemType> *temp;
	temp = parent->right;
	parent->right = ll(temp);
	return rr(parent);
}
// LR ȸ��

template<class ItemType>
TreeNode<ItemType>* lr(TreeNode<ItemType>* &parent)
{
	TreeNode<ItemType> *temp;
	temp = parent->left;
	parent->left = rr(temp);
	return ll(parent);
}

// AVL Ʈ���� ������ ���ߴ� �Լ�

template<class ItemType>
TreeNode<ItemType>* balance(TreeNode<ItemType> *&temp)
{
	int factor = diff(temp);
	// ���� ����Ʈ�������� ������ �Ǿ� ������ ���� ���
	if (factor > 1)
	{
		// �� ���� �ڽĳ�忡 ������ �߻�
		if (diff(temp->left) > 0)
		{
			temp = ll(temp);
		}
		// �� ������ �ڽ� ��忡 ������ �߻�
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