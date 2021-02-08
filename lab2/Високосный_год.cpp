#include <iostream>
using namespace std;

int main()
{
	int year;
	cin >> year;
	if (((year % 100 == 0) && (year / 100 != 4)) || (year % 4 != 0))
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}
}