#include<iostream>
int main() {
	float gall, cf;
	std::cout << "Enter number of gallons: ";
	std::cin >> gall;
	cf = gall / 7.48;
	std::cout << gall << " gallons = " << cf << " cubic feet" << std::endl;
	system("pause");
	return 0;
}