#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	float num1, num2;
	char act, check;
	do
	{
		cout << "Enter the number 1 and number 2: ";
		cin >> num1 >> num2;
		cout << "Which operation you want to perform (+, -, *, /, a): ";
		cin >> act;
		switch (act)
		{
		case '+':
			cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
			break;
		case '-':
			cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
			break;
		case '*':
			cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
			break;
		case '/':
			cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
			break;
		case 'a':
			cout << "Average of " << num1 << " and " << num2 << " is " << (num1 + num2) / 2 << endl;
			break;
		default:
			cout << "Operation not supported" << endl;
			break;
		}	
		cout << "Do you want to operate more: (y/n)";
		cin >> check;
	} while (check == 'y' || check == 'Y');
	cout << "Happy ending!" << endl;
	system("pause");
	return 0;
}