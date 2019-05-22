#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue;

template <typename T>
class Node {
	friend class Queue <T>;
public:
	Node():link(0) {};
	Node(const T&);
private:
	T data;
	Node* link;

};

template <typename T>
Node<T>::Node(const T&_data)
{
	data = _data;
	link = 0;
}

template <typename T>
class Queue {
public:
	Queue();
	void Enqueue(T& data); // ������ �߰�
	void Dequeue(T& data); // ������ ����
	T& Front();  // �� ù��° ������ ����
	T& Rear(); // �� ������ ������ ����
	bool IsEmpty(); // ��� �ִ��� �˻�
private:
	Node<T>* head; // ��� ���

};

template <typename T>
Queue<T>::Queue()
{
	head = new Node<T>;
	head->link = head;
}

template <typename T>
bool Queue<T>::IsEmpty()
{
	bool isEmpty = false;
	if (head->link == head) {
		isEmpty = true;
	}
	return isEmpty;
}

template <typename T>
void Queue<T>::Enqueue(T& data)
{
	Node<T>* newNode = new Node<T>(data);
	if(IsEmpty()) // ��� �ִٸ�
	{
		head->link = newNode; // �� �� ��忡 ���ο� ��� �߰�
	}
	else
	{
		Node<T>* current = head;
		while (current->link != head) {
			current = current->link; // ������ ������ �̵�
		}
		current->link = newNode; // �������� ������ �߰�
	}
	newNode->link = head;
}

template <typename T>
void Queue<T>::Dequeue(T& data) {
	if (!IsEmpty()) {
		Node<T>* firstNode = head->link; // �� �� ���� ��带 ����Ű�� ��
		head->link = firstNode->link;
		data = firstNode->data;
		delete firstNode;
	}
}

template <typename T>
T& Queue<T>::Front() {
	T data = NULL;

	if (!IsEmpty())
	{
		data = head->link->data;
	}
	return data;
}

template <typename T>
T& Queue<T>::Rear() {
	T data = NULL;

	if (!IsEmpty())
	{
		Node<T>* current = head;
		while (current->link != head) {
			current = current->link; // ���� ���� �̵�
		}
		data = head->link->data; // �� ���� ����� �������� ����
	}
	return data; // ������ ������ ��ȯ 
}
