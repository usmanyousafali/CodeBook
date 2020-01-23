#include<iostream>
int main()
{
	int i;
	char ch;
	for (i = 90; i >= 65; i--)
	{
		ch = i;
		if (ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U')
			std::cout << ch << "\t";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}