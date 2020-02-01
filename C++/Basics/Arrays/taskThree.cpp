#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	const int size = 5;
	int num[size], check, index;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter Number " << i + 1 << ": ";
		cin >> num[i];
	}
	cout << "Which Array Element And Index To Find: ";
	cin >> check;
	index = 0;
	while (index < size)
	{
		if (check == num[index])
			break;
		index++;
	}
	if (index > size - 1)
		cout << "Element Is Not Found." << endl;
	else
		cout << check << " is stored into array[" << index << "]" << endl;
	system("pause");
	return 0;
}