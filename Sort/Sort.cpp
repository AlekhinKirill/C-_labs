#include <iostream>
#include <random>
#include <ctime>
using namespace std;


struct Arrays
{
	int* values;
	int length;
};


Arrays bubble_sort(Arrays array)
{
	int i, j, c;
	for (i = 1; i < array.length; i++)
	{
		for (j = 0; j < array.length - 1; j++)
		{
			if (array.values[j] >= array.values[i])
			{
				c = array.values[j];
				array.values[j] = array.values[i];
				array.values[i] = c;
			}
		}
	}
	return array;
}


Arrays shake_sort(Arrays array)
{
	int left_border, right_border, i, c;
	left_border = 0;
	right_border = array.length - 1;
	while (left_border < right_border)
	{
		for (i = left_border; i < right_border ; i++)
		{
			if (array.values[left_border] > array.values[i])
			{
				c = array.values[i];
				array.values[i] = array.values[left_border];
				array.values[left_border] = c;
			}
		}
		left_border += 1;
		for (i = right_border; i > left_border; i--)
		{
			if (array.values[right_border] < array.values[i])
			{
				c = array.values[i];
				array.values[i] = array.values[right_border];
				array.values[right_border] = c;
			}
		}
		right_border -= 1;
	}
	return array;
}


Arrays selection_sort(Arrays array)
{
	int i, j, c, min, min_index;
	for (i = 0; i < array.length; i++)
	{
		min = array.values[i];
		min_index = i;
		for (j = i + 1; j < array.length - 1; j++)
			if (array.values[j] < min)
			{
				min_index = j;
				min = array.values[j];
			}
		c = array.values[min_index];
		array.values[min_index] = array.values[i];
		array.values[i] = c;
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


Arrays merge_sort(Arrays array)
{
	Arrays first_array, second_array;
	int i, j;
	if (array.length <= 100)
	{
		return(bubble_sort(array));
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
		first_array = merge_sort(first_array);
		second_array = merge_sort(second_array);
		return merge(first_array, second_array);
	}
}


Arrays quick_sort(Arrays array)
{
	Arrays first_array, second_array, third_array, result;
	first_array.values = new int[array.length];
	second_array.values = new int[array.length];
	third_array.values = new int[array.length];
	first_array.length = second_array.length = third_array.length = 0;
	int n, i;
	n = 2*array.length/5;
	for (i = 0; i < array.length; i++)
	{
		if (array.values[i] < array.values[n])
		{
			first_array.values[first_array.length] = array.values[i];
			first_array.length += 1;
		}
		else if (array.values[i] == array.values[n])
		{
			second_array.values[second_array.length] = array.values[i];
			second_array.length += 1;
		}
		else
		{
			third_array.values[third_array.length] = array.values[i];
			third_array.length += 1;
		}
	}
	if (first_array.length > 1)
	{
		first_array = quick_sort(first_array);
	}
	if (third_array.length > 1)
	{
		third_array = quick_sort(third_array);
	}
	result.values = new int[first_array.length + second_array.length + third_array.length];
	result.length = first_array.length + second_array.length + third_array.length;
	for (i = 0; i < first_array.length; i++)
		result.values[i] = first_array.values[i];
	for (i = first_array.length; i < first_array.length + second_array.length; i++)
		result.values[i] = second_array.values[i - first_array.length];
	for (i = first_array.length + second_array.length; i < first_array.length + second_array.length + third_array.length; i++)
		result.values[i] = third_array.values[i - first_array.length - second_array.length];
	return result;
}


int main()
{
	setlocale(0, "");
	float start, stop, time;
	Arrays array;
	int i, N;
	N = 57;
	array.values = new int[N];
	i = 0;
	for (i = 0; i < N; i++)
		array.values[i] = rand();
	array.length = N;
	start = clock();
	print_array(array);
	print_array(quick_sort(array));
	print_array(merge_sort(array));
	print_array(bubble_sort(array));
	print_array(selection_sort(array));
	print_array(shake_sort(array));
	stop = clock();
	time = stop - start;
	cout << "Время = " << time << endl;
}