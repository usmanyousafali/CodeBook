#include<iostream>
#include<iomanip>
int main() 
{
	std::cout << std::setfill('*') << std::setw(34) << "*" << std::endl;
	std::cout << "*" << std::setfill(' ') << std::setw(4) << " " << "Programming Assignment 1" << std::setfill(' ') << std::setw(5) << "*" << std::endl;
	std::cout << "*" << std::setfill(' ') << std::setw(5) << " " << "Computer Programming 1" << std::setfill(' ') << std::setw(6) << "*" << std::endl;
	std::cout << "*" << std::setfill(' ') << std::setw(9) << " " << "Author: ??" << std::setfill(' ') << std::setw(14) << "*" << std::endl;
	std::cout << "*" << std::setfill(' ') << std::setw(3) << " " << "Due Date: Thursday, Jan. 24" << std::setfill(' ') << std::setw(3) << "*" << std::endl;
	std::cout << std::setfill('*') << std::setw(34) << "*" << std::endl;
	system("pause");
	return 0;
}