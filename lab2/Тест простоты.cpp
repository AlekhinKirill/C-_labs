#include <iostream>
using namespace std;

int main()
{
	int number, i, key;
	cin >> number;
	key = 1;
	for (i = 2; i <= number - 1; i++)
	{
		if (number % i == 0)
		{
			key = 0;
		}
	}
	cout << key << endl;
}
