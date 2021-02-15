#include <iostream>
using namespace std;

int main()
{
	int number, max;
	max = 0;
	do
	{
		cin >> number;
		if ((number % 2 == 0) && (number > max))
		{
			max = number;
		}
	} while (number != 0);
	cout << max << endl;
}
