#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	float num1, num2, res;
	char act;
	cout << "Enter the number 1 and number 2: ";
	cin >> num1 >> num2;
	cout << "Which operation you want to perform (+, -, *, /, a): ";
	cin >> act;
	switch (act)
	{
	case '+':
		res = num1 + num2;
		cout << num1 << " + " << num2 << " = " << res << endl;
		break;
	case '-':
		res = num1 - num2;
		cout << num1 << " - " << num2 << " = " << res << endl;
		break;
	case '*':
		res = num1 * num2;
		cout << num1 << " * " << num2 << " = " << res << endl;
		break;
	case '/':
		res = num1 / num2;
		cout << num1 << " / " << num2 << " = " << res << endl;
		break;
	case 'a':
		res = (num1 + num2) / 2;
		cout << "Average of " << num1 << " and " << num2 << " is " << res << endl;
		break;
	default: 
		cout << "The operation is not valid" << endl;
		break;
	}
	system("pause");
	return 0;
}