#include<iostream>
#include<iomanip>
int main()
{
	float cel, fah;
	std::cout << "Enter temperature in Celsius: ";
	std::cin >> cel;
	fah = (9 / 5) * cel + 32;
	std::cout << cel << " Celsius = " << std::fixed << std::setprecision(2) << fah << " Fahrenheit" << std::endl;
	system("pause");
	return 0;
}