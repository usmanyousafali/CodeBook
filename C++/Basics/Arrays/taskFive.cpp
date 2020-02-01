#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void displayResult(int mul[][2]);
int main()
{
	const int m_rows = 2, m_cols = 3, n_rows = 3, n_cols = 2;
	int m[m_rows][m_cols] =
	{
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};
	int n[n_rows][n_cols] = 
	{
		{ 7, 8 },
		{ 9, 10 },
		{ 11, 12 }
	};
	int mul[m_rows][n_cols] = { 0 };
	for (int row = 0; row < m_rows; row++)
	{
		for (int col = 0; col < n_cols; col++)
		{
			for (int i = 0; i < m_cols; i++)
			{
				mul[row][col] += m[row][i] * n[i][col];
			}
		}
	}
	displayResult(mul);
	system("pause");
	return 0;
}
void displayResult(int mul[][2])
{
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			cout << mul[row][col] << "\t";
		}
		cout << endl;
	}
}