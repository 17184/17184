#ifndef BST_H
#define BST_H

#include <cstddef>

template <typename T>
class BST {
private:
	struct Node {
		Node* left;
		Node* right;
		T val;
		Node() : left(nullptr), right(nullptr), val() {}
		Node(T v) : left(nullptr), right(nullptr), val(v) {}
	};
private:
		Node* root;
private:
		T getMin(Node* root);//helper
		T getMax(Node* root);
		size_t getHeight(Node* root);
		void inorderTraverse(Node*);
		void postorderTraveerse(Node*);
		void preorderTraverse(Node*);
		void search(Node*, const T&);
		void deleteVal(Node*, const T&);
		T getPredecessor(Node*);
		T getSucessor(Node*);
		Node* insert(Node*, const T&);
public:
		T getMin() const;
		T getMax() const;
		size_t getHeight() const;
		void inorderTraverse();
		void postorderTraveerse();
		void preorderTraverse();
		void search(const T&);
		void deleteVal(const T&);
		T getPredecessor() const;
		T getSucessor() const;
		void insert(const T&);
};
#include "bst.tpp"
#endif //BST_H
