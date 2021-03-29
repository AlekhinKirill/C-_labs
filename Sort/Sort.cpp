﻿#include <iostream>
#include <random>
using namespace std;

struct Arrays
{
	int* values;
	int length;
};


Arrays Bubble_sort(Arrays array, string mod)
{
	int i, j, c;
	for (i = 1; i < array.length; i++)
	{
		for (j = 0; j < array.length - 1; j++)
		{
			if (((array.values[j] >= array.values[i])&&(mod == "ascending"))||((array.values[j] <= array.values[i]) && (mod == "descending")))
			{
				c = array.values[j];
				array.values[j] = array.values[i];
				array.values[i] = c;
			}
		}
	}
	return array;
}

void print_array(Arrays array)
{
	int i;
	for (i = 0; i < array.length; i++)
		cout << array.values[i] << " ";
	cout << endl;
}


Arrays merge(Arrays first_array, Arrays second_array)
{
	int i, j, tooking_from_first_array, tooking_from_second_array;
	tooking_from_first_array = tooking_from_second_array = i = 0;
	Arrays result;
	result.values = new int[first_array.length + second_array.length];
	result.length = first_array.length + second_array.length;
	while ((tooking_from_first_array < first_array.length) && (tooking_from_second_array < second_array.length))
	{
		if (first_array.values[tooking_from_first_array] <= second_array.values[tooking_from_second_array])
		{
			result.values[i] = first_array.values[tooking_from_first_array];
			tooking_from_first_array += 1;
		}
		else
		{
			result.values[i] = second_array.values[tooking_from_second_array];
			tooking_from_second_array += 1;
		}
		i++;
	}
	if (tooking_from_first_array >= first_array.length)
		for (j = i ; j < first_array.length + second_array.length; j++)
		{
			result.values[j] = second_array.values[tooking_from_second_array];
			tooking_from_second_array += 1;
		}
	else if (tooking_from_second_array >= second_array.length)
		for (j = i; j < first_array.length + second_array.length; j++)
		{
			result.values[j] = first_array.values[tooking_from_first_array];
			tooking_from_first_array += 1;
		}
	return result;
}


Arrays Merge_sort(Arrays array)
{
	Arrays first_array, second_array, result;
	int i, j;
	if (array.length <= 10)
	{
		return(Bubble_sort(array, "ascending"));
	}
	else
	{
		first_array.length = array.length / 2;
		second_array.length = array.length - array.length / 2;
		first_array.values = new int[first_array.length];
		second_array.values = new int[second_array.length];
		for (i = 0; i < first_array.length; i++)
		{
			first_array.values[i] = array.values[i];
		}
		for (j = 0; j < second_array.length; j++)
		{
			second_array.values[j] = array.values[first_array.length + j];
		}
		first_array = Merge_sort(first_array);
		second_array = Merge_sort(second_array);
		return merge(first_array, second_array);
	}
}


int main()
{
	Arrays array, x;
	int i, j, k, N;
	N = 37;
	array.values = new int[N];
	i = 0;
	for (i = 0; i < N; i++)
		array.values[i] = rand() % 300;
	array.length = N;
	print_array(array);
	print_array(Bubble_sort(array, "ascending"));
	print_array(Merge_sort(array));
}