#include<iostream>
int main()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int a = 1; a <= 11; a++)
		{
			if (i % 2 == 0)
				(a % 2 == 0) ? (std::cout << "0") : (std::cout << "*");
			else
				std::cout << "*";
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}