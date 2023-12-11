#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>

template <typename T>	
class DoublyList {
public:
	struct Node {
		Node *prev;
		Node *next;
		T data;
		Node() : prev(nullptr), next(nullptr), data(0) {}
		Node(T val) : prev(nullptr), next(nullptr), data(val){}
		Node(Node&& other) noexcept
			: prev(other.prev)
			, next(other.next) {}
		~Node() { delete prev;
				  delete next;
			}
	};
	private:
		Node* head;
		Node* tail;
public:
	void push_back(T val);
	void push_front(T val);
	void pop_back();
	void pop_front();
	T search(T val);
	void insert(int pos, T val);
	void deleteNode(T pos);
	void insert(int pos, DoublyList<T>&) ;
	bool empty() const;
	int size() const;
	
	void traverse_from_head() const;
	void traverse_from_tail() const;
	void reverse();
	 
	Node* getMiddleNode() const;
	bool hasCycle() const;
	Node* reverse_rec();

public:
	DoublyList() : head{}, tail{} {}
	DoublyList(const DoublyList& d) 
		: head(d.head)
		, tail(d.tail){}
	DoublyList(DoublyList&& d) noexcept
		: head(d.head)
		, tail(d.tail) {
			d.head = d.tail = nullptr;
		}
/*	~DoublyList() {
		delete head;
		delete tail;
	}*/
	
	
};
#include "doubly.tpp"
#endif //DOUBLE_H
