#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void swapByRef(int& num1, int& num2)
{
	int t = num1;
	num1 = num2;
	num2 = t;
}
int main()
{
	int num1, num2;
	cout << "Enter Two Values: ";
	cin >> num1 >> num2;
	cout << "Before: " << num1 << ", " << num2 << endl;
	swapByRef(num1, num2);
	cout << "After: " << num1 << ", " << num2 << endl;
	system("pause");
	return 0;
}