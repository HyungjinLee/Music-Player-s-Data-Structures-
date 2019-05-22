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
	void Enqueue(T& data); // 아이템 추가
	void Dequeue(T& data); // 아이템 제거
	T& Front();  // 맨 첫번째 아이템 얻음
	T& Rear(); // 맨 마지막 아이템 얻음
	bool IsEmpty(); // 비어 있는지 검사
private:
	Node<T>* head; // 헤드 노드

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
	if(IsEmpty()) // 비어 있다면
	{
		head->link = newNode; // 맨 앞 헤드에 새로운 노드 추가
	}
	else
	{
		Node<T>* current = head;
		while (current->link != head) {
			current = current->link; // 마지막 노드까지 이동
		}
		current->link = newNode; // 마지막에 아이템 추가
	}
	newNode->link = head;
}

template <typename T>
void Queue<T>::Dequeue(T& data) {
	if (!IsEmpty()) {
		Node<T>* firstNode = head->link; // 맨 앞 다음 노드를 가리키게 함
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
			current = current->link; // 다음 노드로 이동
		}
		data = head->link->data; // 맨 끝의 노드의 아이템을 선택
	}
	return data; // 마지막 아이템 반환 
}
