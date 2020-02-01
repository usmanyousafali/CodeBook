#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	int a[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter Number " << i + 1 << ": ";
		cin >> a[i];
	}
	cout << "Printing The Array Elements: " << endl;
	for (int i = 0; i < 5; i++)
		cout << "array[" << i << "]: " << a[i] << endl;
	system("pause");
	return 0;
}