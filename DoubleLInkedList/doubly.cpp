#include <iostream>
#include "doubly.h"

int main()
{
	DoublyList<int> dList;
	dList.push_back(4);
	dList.push_back(5);
	dList.push_back(6);
//	dList.push_back(10);
	std::cout << "DList - ";
	dList.traverse_from_head();
//	dList.reverse();
	
	DoublyList<int>::Node* mid = dList.getMiddleNode();
	if (mid != nullptr) {
		std::cout << "Mid node - " << mid -> data << std::endl;
	} else {
		std::cout << "Empty list" << std::endl;
	}

	if(dList.hasCycle()) {
		std::cout << "yes there is cycle \n";
	} else {
		std::cout << "There is not cycle \n";
	}
	
	//std::cout << "Middle is - " << *getMidNod << std::endl; 
	DoublyList<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	std::cout << "d - ";
	d.traverse_from_head();
//	dList.insert(0, d);

	dList.insert(1, d);
	dList.traverse_from_head();

	
	
	


/*	std::cout << "From head - ";
	dList.traverse_from_head();
	std::cout << "From tail - ";
	dList.traverse_from_tail();
	int search_res = dList.search(1);
	std::cout << "Search result is - " << search_res << std::endl;
	std::cout << "Size - " << dList.size() << std::endl;
	dList.pop_back();
	dList.traverse_from_head();
	std::cout << "Size - " << dList.size() << std::endl;
	dList.insert(1,1650);
	std::cout << std::endl;
	dList.traverse_from_head();
//	dList.deleteNode(2);
	std::cout << "Size - " << dList.size() << std::endl;
	dList.traverse_from_head();
	dList.deleteNode(2);
	std::cout << "Size - " << dList.size() << std::endl;
	dList.traverse_from_head();
	
	*/


	

}
