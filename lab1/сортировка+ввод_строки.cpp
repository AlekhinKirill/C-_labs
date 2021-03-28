#include <iostream>
using namespace std;

int main()
{
	int value, i, j, N, even_numbers_length, odd_numbers_length, c;
	int* array = new int[10000];
	i = 0;
	even_numbers_length = 0;
	odd_numbers_length = 0;
	while (cin.peek() != '\n')
	{
		cin >> value;
		array[i] = value;
		i++;
	}
	N = i;
	int* even_numbers = new int[N + 1];
	int* odd_numbers = new int[N + 1];
	for (i = 0; i < N; i++)
		if (array[i] % 2 == 0)
		{
			even_numbers[even_numbers_length] = array[i];
			even_numbers_length += 1;
		}
		else
		{
			odd_numbers[odd_numbers_length] = array[i];
			odd_numbers_length += 1;
		}
	for (i = 1; i < even_numbers_length; i++)
	{
		for (j = 0; j < even_numbers_length - 1; j++)
		{
			if (even_numbers[j] >= even_numbers[i])
			{
				c = even_numbers[j];
				even_numbers[j] = even_numbers[i];
				even_numbers[i] = c;
			}
		}
	}
	for (i = 1; i < odd_numbers_length; i++)
	{
		for (j = 0; j < odd_numbers_length - 1; j++)
		{
			if (odd_numbers[j] >= odd_numbers[i])
			{
				c = odd_numbers[j];
				odd_numbers[j] = odd_numbers[i];
				odd_numbers[i] = c;
			}
		}
	}
	for (i = 0; i < even_numbers_length; i++)
		cout << even_numbers[i] << " ";
	for (i = 0; i < odd_numbers_length; i++)
		cout << odd_numbers[i] << " ";
}