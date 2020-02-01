#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	const int section = 2, student = 3, subject = 4;
	double result[section][student][subject], sum = 0;
	for (int sec = 0; sec < section; sec++)
	{
		cout << "Enter marks of four subjects for section " << sec + 1 << " and ";
		for (int row = 0; row < student; row++)
		{
			cout << "student " << row + 1 << endl;
			for (int col = 0; col < subject; col++)
			{
				cout << "\tSubject " << col + 1 << ": ";
				cin >> result[sec][row][col];
			}
		}
	}
	system("CLS");
	for (int sec = 0; sec < section; sec++)
	{
		cout << "Section " << sec + 1 << endl;
		for (int row = 0; row < student; row++)
		{
			cout << "\tstudent " << row + 1 << endl;
			for (int col = 0; col < subject; col++)
			{
				sum += result[sec][row][col];
			}
			cout << "\t\tObtained Marks: " << sum << endl;
			cout << "\t\tPercentage: " << (sum / 400) * 100 << "%" << endl;
			sum = 0;
		}
	}
	system("pause");
	return 0;
}