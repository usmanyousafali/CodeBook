#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	int matrixOne[2][2] =
	{
		{ 4, 9 },
		{ 8, 6 }
	};
	int matrixTwo[2][2] =
	{
		{ 2, 10 },
		{ 12, 20 }
	};
	int sum[2][2];
	for (int row = 0; row < 2; row++)
		for (int col = 0; col < 2; col++)
			sum[row][col] = matrixOne[row][col] + matrixTwo[row][col];
	cout << "The Sum Would Be: " << endl;
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 2; col++)
			cout << sum[row][col] << "\t";
		cout << endl;
	}
	system("pause");
	return 0;
}