#include<iostream>
int main()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int b = 9; b >= i; b--)
			std::cout << " ";
		for (int a = 1; a <= i; a++)
			std::cout << "*";
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}