#include <iostream>
using namespace std;

int main()
{
	int speed, salary;
	string identificator;
	salary = 0;
	do
	{
		cin >> speed >> identificator;
		if ((speed > 60) && (identificator != "A999AA"))
		{
			if ((identificator[1] == identificator[2]) && (identificator[2] == identificator[3]))
			{
				salary = salary + 1000;
			}
			else if ((identificator[1] == identificator[2]) || (identificator[2] == identificator[3]) || (identificator[1] == identificator[3]))
			{
				salary = salary + 500;
			}
			else
			{
				salary = salary + 100;
			}
		}
	} 
	while (identificator != "A999AA");
	cout << salary << endl;
}