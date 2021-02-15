#include <iostream>
using namespace std;

int main()
{
	int number, i;
	cin >> number;
	while (number > 1)
	{
		for (i = 2; i <= number; i++)
		{
			if (number % i == 0)
			{
				number = number / i;
				cout << i << endl;
				break;
			}
		}
	}
}