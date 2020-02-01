#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void multiplyByThree(int num[]);
void display(int num[]);
int main()
{
	int num[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter Number " << i + 1 << ": ";
		cin >> num[i];
	}
	multiplyByThree(num);
	display(num);
	system("pause");
	return 0;
}
void multiplyByThree(int num[])
{
	for (int i = 0; i < 5; i++)
		num[i] *= 3;
}
void display(int num[])
{
	for (int i = 0; i < 5; i++)
		cout << (num[i] / 3) << " * 3" << " = " << num[i] << endl;
}