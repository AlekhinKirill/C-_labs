#include <iostream>
using namespace std;

int main()
{
	int num, denum, intermediate, first_number, second_number;
	cin >> first_number >> second_number;
	if (first_number >= second_number)
	{
		num = first_number;
		denum = second_number;
	}
	else
	{
		denum = first_number;
		num = second_number;
	}
	while (denum != 0)
	{
		intermediate = denum;
		denum = num % denum;
		num = intermediate;
	}
	cout << num << endl;
}
