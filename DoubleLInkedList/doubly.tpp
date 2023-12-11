template <typename T>
void DoublyList<T>::push_back(T val) {
	if(!head) {
		Node* newNode = new Node(val);
		head = tail =  newNode;
	} else {
		Node *newNode = new Node(val);
			tail -> next = newNode;
			newNode -> prev = tail;
			tail = newNode;	
	}
}

template <typename T>
void DoublyList<T>::push_front(T val) {
	if(!head) {
		Node* newNode = new Node(val);
		head = tail = newNode;
	} else {
	Node* newNode = new Node(val);
	head -> prev = newNode;
	newNode -> next = head;
	newNode -> prev = nullptr;
	head = newNode;
	}
} 
template <typename T>
void DoublyList<T>::pop_back() {
	if(!empty()) {
		if(head == tail) {
			delete head;
			//1elem only
			head = tail = nullptr;
		} else {
			Node* tmp = tail;
			tail = tail -> prev ;
			tail -> next = nullptr;
			delete tmp;
		}
	}
}
template <typename T>
void DoublyList<T>::pop_front() {
	if(!empty()) {
		delete head;
		head = tail = nullptr;
	} else {
		Node* tmp = head;
		head = head -> next;
		head -> prev = nullptr;
		delete tmp;
	}
}

template <typename T>
T DoublyList<T>::search(T val) {
	Node* curr = head;
	while(curr) {
		if(curr -> data = val) {
			return val;
		}
		curr = curr -> next;
	}
	return -1;
}

template <typename T>
void DoublyList<T>::traverse_from_head() const {
	Node* curr = head;
	while(curr) {
		std::cout << curr -> data << " -> " ;
		curr = curr -> next;
	}
	std::cout << " nullptr";
	std::cout << std::endl;
}
template <typename T>
void DoublyList<T>::traverse_from_tail() const {
	Node *curr = tail;
	std::cout << "nullptr";
	while(curr) {
		std::cout << " <- " << curr -> data;
		curr = curr -> prev;
	}
	std::cout << std::endl;
}

template <typename T>
void DoublyList<T>::insert(int pos, T val) {
	if(pos < 0 || pos > size() ) {
		std::cerr << "Invald range\n";
	} else {
		if(pos == 0) {
			push_front(val);
		} else if(pos == size()) {
			push_back(val);
		} else {
			Node *curr = head;
			for(int i = 0; i < pos - 1; ++i) {
				curr = curr -> next;
			}
			Node* newNode = new Node(val);
			newNode -> next = curr -> next;
			curr -> next -> prev = newNode;
			newNode -> prev = curr;
			curr -> next = newNode;
		}
	}
}
template <typename T>
void DoublyList<T>::deleteNode(T pos) {
	if(pos < 0 || pos >= size() ) {
		std::cerr << "Invald range\n";
	} else if(pos == 0) {
		pop_front();
	} else if (pos == size() - 1){
		pop_back();	
	} else{
		Node* curr = head;
		for(int i = 0; i < pos - 1; ++i) {
			curr = curr -> next;
		}
		Node *tmp = curr -> next;
		curr -> next = curr -> next -> next;
		if(curr -> next != nullptr) {
		curr -> next -> prev = curr;
	}
		delete tmp;
	}
}

template <typename T>
void DoublyList<T>::insert(int pos, DoublyList<T>& dl) {
  if (pos < 0 || pos > size()) {
    std::cerr << "Invalid\n";
    return;
  }
  if(pos == 0) {
    head -> prev = dl.tail;
    dl.tail -> next = head;
    head = dl.head;
    dl.head = dl.tail = nullptr;
    return;
  }
  Node* curr = head;
  for(int i = 0; i < pos - 1; ++i) {
    curr = curr -> next;
  }
  curr->next->prev = dl.tail;
  dl.tail->next = curr->next;
  dl.head->prev = curr;
  curr->next = dl.head;
  dl.head = dl.tail = nullptr;
}

template <typename T>
bool DoublyList<T>::empty() const {
	return head == nullptr;
}
template <typename T>
int DoublyList<T>::size() const {
	Node* curr = head;
	int s{};
	while(curr) {
		++s;
		curr = curr -> next;
	}
	return s;
}
/*
template <typename T>
void DoublyList<T>::reverse() {
	Node* tmp = nullptr;
	Node* curr = head;
	std::swap(head, tail);
	while(curr) {
		tmp = curr -> prev;
		curr -> prev = curr -> next;
		curr -> next = tmp;
		curr = curr -> prev;
	}
}
*/

template <typename T>
void DoublyList<T>::reverse() {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
	
        current = current->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
        tail = current; // Assuming current is now nullptr
    }
}

template<typename T>
typename  DoublyList<T>::Node* DoublyList<T>::getMiddleNode() const {
	if(head == nullptr || tail == nullptr) {
		return nullptr;
	}
	Node* slow = head;
	Node* fast = head;
	while(fast != nullptr && fast -> next != nullptr) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow;
}

template <typename T>
bool DoublyList<T>:: hasCycle() const {
	if(head == nullptr || tail == nullptr) {
		return false;
	}
	Node* slow = head;
	Node* fast = head;
	while(fast && fast -> next) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	if(fast == slow) {
		return true;
	}
	return false;
}





