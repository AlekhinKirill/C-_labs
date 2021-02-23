﻿#include <iostream>
using namespace std;

struct Cells
{
	int value;
	Cells* next_ptr;
};

struct List
{
	int length;
	Cells* first;
	Cells* last;
};

List create_empty()
{
	List list;
	list.length = 0;
	list.first = nullptr;
	list.last = nullptr;
	return list;
}

List append(List list, int value)
{
	Cells* cell = new Cells;
	(*cell).value = value;
	(*cell).next_ptr = nullptr;
	if (list.length == 0)
	{
		list.first = cell;
	}
	else
	{
		if (list.length == 1)
		{
			list.last = list.first;
			(*list.first).next_ptr = cell;
		}
		(*list.last).next_ptr = cell;
		list.last = cell;
	}
	list.length += 1;
	return list;
}

void print_list(List list)
{
	if (list.length == 0)
		cout << "Лист пуст" << endl;
	else
	{
		Cells last_cell;
		last_cell = *list.first;
		while (last_cell.next_ptr != nullptr)
		{
			cout << last_cell.value << endl;
			last_cell = *last_cell.next_ptr;
		}
		cout << last_cell.value << endl;
	}
}

List remove(List list, int a)
{
	List new_list;
	Cells *cell, *previous_cell;
	int warning;
	warning = 0;
	if (list.length >= 2)
	{
		if ((*list.first).value == a)
		{
			new_list.first = (*list.first).next_ptr;
			new_list.length = list.length - 1;
			new_list.last = list.last;
			return new_list;
		}
		else
		{
			cell = (*list.first).next_ptr;
			previous_cell = list.first;
			new_list.first = list.first;
			new_list.length = list.length - 1;
			new_list.last = list.last;
			while ((*cell).value != a)
			{
				if ((*cell).next_ptr != nullptr)
				{
					previous_cell = cell;
					cell = (*cell).next_ptr;
				}
				else
				{
					cout << "Элемента " << a << " в списке нет!" << endl;
					warning = 1;
					break;
				}
			}
			if (warning == 0)
			{
				(*previous_cell).next_ptr = (*cell).next_ptr;
				return new_list;
			}
			else
				return list;
		}
	}
	else
	{
		if (list.length == 0)
			return list;
		else
		{
			if ((*list.first).value == a)
				return create_empty();
			else
			{
				cout << "Элемента " << a << " в списке нет!" << endl;
				return list;
			}
		}
	}
}

List merge(List first_list, List second_list)
{
	Cells* cell;
	if (second_list.length != 0)
	{
		cell = second_list.first;
		while ((*cell).next_ptr != nullptr)
		{
			first_list = append(first_list, (*cell).value);
			cell = (*cell).next_ptr;
		}
		first_list = append(first_list, (*cell).value);
	}
	return first_list;
}


List add_i(List list, int value, int i)
{
	List new_list;
	Cells* cell;
	Cells* new_cell = new Cells;
	int j;
	if (i == 1)
	{
		new_list = create_empty();
		new_list.length = list.length + 1;
		(*new_cell).value = value;
		(*new_cell).next_ptr = list.first;
		new_list.first = new_cell;
		new_list.last = list.last;
		return new_list;
	}
	else if ((list.length != 0) && (list.length >= i))
	{
		new_list = create_empty();
		new_list.length = list.length + 1;
		cell = list.first;
		for (j = 1; j < i - 1; j++)
		{
			cell = (*cell).next_ptr;
		}
		(*new_cell).value = value;
		(*new_cell).next_ptr = (*cell).next_ptr;
		(*cell).next_ptr = new_cell;
		new_list.first = list.first;
		new_list.last = list.last;
		return new_list;
	}
	else
	{
		cout << "В списке нет "<< i << "-ого элемента" << endl;
		return list;
	}
}

List clear()
{
	return create_empty();
}

List del_i(List list, int i)
{
	List new_list;
	Cells* cell;
	Cells* previous_cell = new Cells;
	if (i == 1)
	{
		return remove(list, (*list.first).value);
	}
	else
	{
		int j;
		new_list = create_empty();
		new_list.length = list.length - 1;
		cell = list.first;
		for (j = 1; j < i; j++)
		{
			previous_cell = cell;
			cell = (*cell).next_ptr;
		}
		(*previous_cell).next_ptr = (*cell).next_ptr;
		new_list.first = list.first;
		new_list.last = list.last;
		return new_list;
	}
}


int main()
{
	setlocale(0, "");
	List list, second_list, new_list;
	list = create_empty();
	list = append(list, 5);
	list = append(list, 7);
	list = append(list, 3);
	list = append(list, 9);
	list = append(list, 8);
	list = remove(list, 3);  //удаление последнего элемента ???
	list = add_i(list, 15, 3);
	second_list = create_empty();
	second_list = append(second_list, 4);
	second_list = append(second_list, 10);
	second_list = append(second_list, 1);
	new_list = merge(list, second_list);
	new_list = del_i(new_list, 6); //удаление первого -???
	print_list(new_list);
}