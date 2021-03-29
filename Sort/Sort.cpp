#include <iostream>
using namespace std;

void Bubble_sort(int* array, int length, string mod)
{
	int i, j, c;
	for (i = 1; i < length; i++)
	{
		for (j = 0; j < length - 1; j++)
		{
			if (((array[j] >= array[i])&&(mod == "ascending"))||((array[j] <= array[i]) && (mod == "descending")))
			{
				c = array[j];
				array[j] = array[i];
				array[i] = c;
			}
		}
	}
	for (i = 0; i < length; i++)
		cout << array[i] << " ";
	cout << endl;
}


int main()
{
	int value, i, j, N, c;
	int* array = new int[10000];
	i = 0;
	while (cin.peek() != '\n')
	{
		cin >> value;
		array[i] = value;
		i++;
	}
	N = i;
	Bubble_sort(array, N, "ascending");
	Bubble_sort(array, N, "descending");
}