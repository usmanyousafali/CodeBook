#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	float bmi, wei_in_pound, hei_in_inc;
	cout << "Enter weight in pounds: ";
	cin >> wei_in_pound;
	cout << "Enter height in inches: ";
	cin >> hei_in_inc;
	bmi = (wei_in_pound * 703) / pow(hei_in_inc, 2);
	if (bmi < 18.5)
	{
		cout << "You are Underweight at " << bmi << " BMI" << endl;
	}
	else if (bmi >= 18.5 && bmi <= 24.9)
	{
		cout << "You are Normal at " << bmi << " BMI" << endl;
	}
	else if (bmi >= 25 && bmi <= 29.9)
	{
		cout << "You are Overweight at " << bmi << " BMI" << endl;
	}
	else if (bmi >= 30)
	{
		cout << "You are Obese at " << bmi << " BMI" << endl;
	}
	system("pause");
	return 0;
}