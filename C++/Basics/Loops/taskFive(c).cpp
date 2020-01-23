#include<iostream>
int main()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int a = 10; a >= i; a--)
			std::cout << "*";
		std::cout << std::endl;
		for (int b = 1; b <= i; b++)
			std::cout << " ";
	}
	std::cout << std::endl;
	system("pause"); 
	return 0;
}