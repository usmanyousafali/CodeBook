#include<iostream>
#include<string>
int main() 
{
	std::string cn;
	float ob, tol, percent;
	std::cout << "Enter the course name: ";
	getline(std::cin, cn);
	std::cout << "Enter obtained marks: ";
	std::cin >> ob;
	std::cout << "Enter total marks: ";
	std::cin >> tol;
	percent = (ob / tol) * 100;
	std::cout << "You have got " << percent << "% in " << cn << std::endl;
	system("pause");
	return 0;
}