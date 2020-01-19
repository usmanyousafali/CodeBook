#include<iostream>
int main() 
{
	float num1, num2, sum, mul, minus, divide, percent;
	std::cout << "Enter first number: ";
	std::cin >> num1;
	std::cout << "Enter second number: ";
	std::cin >> num2;
	sum = num1 + num2;
	minus = num1 - num2;
	mul = num1 * num2;
	divide = num1 / num2;
	percent = (num1 / num2) * 100;
	std::cout << num1 << " + " << num2 << " = " << sum << std::endl;
	std::cout << num1 << " - " << num2 << " = " << minus << std::endl;
	std::cout << num1 << " * " << num2 << " = " << mul << std::endl;
	std::cout << num1 << " / " << num2 << " = " << divide << std::endl;
	std::cout << num1 << " % " << num2 << " = " << percent << std::endl;
	system("pause");
	return 0;
}