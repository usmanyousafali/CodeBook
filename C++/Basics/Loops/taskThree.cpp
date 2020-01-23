#include<iostream>
int main()
{
	float sum = 1, num = 2;
	while (num <= 45)
	{
		sum = sum + (1 / num);
		num++;
	}
	num = 2;
	std::cout << "1";
	while (num <= 45)
	{
		std::cout << " + 1/" << num;
		num++;
	}
	std::cout << " = " << sum << std::endl;
	system("pause");
	return 0;
}