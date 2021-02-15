#include <iostream>
using namespace std;

int main()
{
	int number;
	cin >> number;
	while (number % 2 == 0)
	{
		number = number / 2;
	}
	if (number == 1)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}