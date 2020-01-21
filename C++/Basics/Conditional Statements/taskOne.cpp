#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	char alphabet;
	cout << "Enter the alphabet: ";
	cin >> alphabet;
	if (alphabet == 'a' || alphabet == 'A') 
	{
		cout << alphabet << " is a vowel." << endl;
	}
	else if (alphabet == 'e' || alphabet == 'E')
	{
		cout << alphabet << " is a vowel." << endl;
	}
	else if (alphabet == 'i' || alphabet == 'I')
	{
		cout << alphabet << " is a vowel." << endl;
	}
	else if (alphabet == 'o' || alphabet == 'O')
	{
		cout << alphabet << " is a vowel." << endl;
	}
	else if (alphabet == 'u' || alphabet == 'U') 
	{
		cout << alphabet << " is a vowel." << endl;
	}
	else 
	{
		cout << alphabet << " is a consonant." << endl;
	}
	system("pause");
	return 0;
}