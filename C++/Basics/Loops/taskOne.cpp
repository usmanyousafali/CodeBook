#include<iostream>
int main()
{
	int i, lim;
	std::cout << "Enter limit: ";
	std::cin >> lim;
	for (i = 1; i <= lim; i++)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}