#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>

template <typename T>
class ForwardList {
public:
struct Node {
	Node() : data(0), next(nullptr) {}
	Node(int v) : data(v), next(nullptr){}
	T data;
	Node* next;
};	
	void push_back(T val);
	void push_front(T val);
	void pop_back();
	void pop_front();
	T search(T val);
	void insert(int pos, T val);
	void deleteNode(T pos);
	void insert(int pos, ForwardList<T>);
	void reverse();
	bool empty() const;
	int size() const;
	Node* getHead();
	void traverse() const;

private:
	Node* head;
};
#include "forward.tpp"
#endif //FORWARLIST_H
