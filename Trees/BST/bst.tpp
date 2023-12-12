#include <iostream>
#include <cstddef>


//private helper funcitons
template <typename T>
T BST<T>::getMin(Node *root) {
	while(!root) {
		throw std::runtime_error("Root is not here \n");
	}
	while(root -> left) {
		root = root -> left;
	}
	return root -> val;
}

template <typename T>
T BST<T>::getMax(Node* root) {
	if(!root) {
		throw std::runtime_error("Tree is empty\n");
	}
	while(root -> right) {
		root = root -> right;
	}
	return root -> val;
}

template <typename T>
size_t BST<T>::getHeight(Node* root) {
	if(!root) {
		return -1;
	}
	return std::max(getHeight(root -> left), getHeight(root -> right)) + 1;
}

template <typename T>
void BST<T>::inorderTraverse(Node* root) {
	if(!root) { return; }
	inorderTraverse(root -> left);
	std::cout << root -> val << " ";
	inorderTraverse(root -> right);
}

template <typename T>
void BST<T>::postorderTraveerse(Node* root) {
	if(!root) { return; }
	postorderTraveerse(root -> left);
	postorderTraveerse(root -> right);
	std::cout << root -> val << " ";
}

template <typename T>
void BST<T>::preorderTraverse(Node* root) {
	if(!root) { return; }
	std::cout << root -> val << " ";
	preorderTraverse(root -> left);
	preorderTraverse(root -> right);
}

template <typename T>
void BST<T>::search(Node* root, const T& key) {
	if(!root) {
		throw std::runtime_error("Tree is empty\n");
	}
	if(root -> val == key) {
		std::cout << "Val is in tree\n";
	} 
	else if(key < root -> val) {
		search(root -> left, key);
	} else {
		search(root -> right, key);
	}
}
//iterative search
/*
void BST<T>::search(Node* root, const T& key) {
	if(!root) {
		throw std::tunrime_error("Tree is empty\n");
	}
	while(root) {
		while(root -> left){
			if(root -> val == key) {
				std::cout << "Val found in tree\n";
				return;
			}
			else if(root -> val < key) {
				root = root -> right;
			}	
			else {
				root = root -> left;
			}
		}
	}
}
*/
template <typename T>
typename BST<T>::Node*BST<T>::insert(Node* root, const T& key) {
	if(!root) {
		return new Node(key);
	} else if(key < root -> val) {
		root -> left = insert(root -> left, key);
	} else{
		root -> right = insert(root -> right, key);
	}
	return root;
}

//public original functions
template <typename T>
T BST<T>::getMin()  const {
	return getMin(root);
}

template <typename T>
T BST<T>::getMax() const {
	return getMax(root); 
}

template <typename T>
size_t BST<T>::getHeight() const {
	return getHeight(root);
}

template <typename T>
void BST<T>::inorderTraverse() {
	inorderTraverse(root);
}

template <typename T>
void BST<T>::postorderTraveerse() {
	postorderTraveerse(root);
}

template <typename T>
void BST<T>::preorderTraverse() {
	preorderTraverse(root);
}

template <typename T>
void BST<T>::search(const T& key) {
	search(root, key);
}

template <typename T>
void BST<T>::insert(const T& key) {
	root  = insert(root, key);
}

