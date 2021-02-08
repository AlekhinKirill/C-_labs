#include <iostream>
using namespace std;

int main()
{
	int element, num;
	num = -1;
	do
	{
		cin >> element;
		if (element % 2 == 0)
		{
			num = num + 1;
		}
	}
	while (element != 0);
	cout << num << endl;
}