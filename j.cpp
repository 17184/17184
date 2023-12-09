#include <iostream>

int add(int a, int b) {
	return a +b;
}
int main()
{
	decltype (add(2,3)) res = add(2,3);
//	std::cout << res << std::endl;
	int x = 10;
	decltype ((x)) y = x 
	std::cout << y << std::endl;
}
