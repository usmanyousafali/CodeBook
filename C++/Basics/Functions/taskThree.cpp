#include<iostream>
using std::cout;
using std::cin;
using std::endl;
float compute(float num1, float num2, char op);
int main()
{
	int num1, num2;
	char ch;
	cout << "Enter Two Numbers: ";
	cin >> num1 >> num2;
	cout << "Enter Operation (+, -, /, *): ";
	cin >> ch;
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
		float result = compute(num1, num2, ch);
		cout << num1 << " " << ch << " " << num2 << " = " << result << endl;
	}
	else
		cout << "You Enter Wrong." << endl;
	system("pause");
	return 0;
}
float compute(float num1, float num2, char op)
{
	switch (op)
	{
	case '+':
		return num1 + num2;
		break;
	case '-':
		return num1 - num2;
		break;
	case '*':
		return num1 * num2;
		break;
	case '/':
		return num1 / num2;
		break;
	default:
		return 0;
	}
}