#include <iostream>
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
	Cells last_cell;
	last_cell = *list.first;
	while (last_cell.next_ptr != nullptr)
	{
		cout << last_cell.value << endl;
		last_cell = *last_cell.next_ptr;
	}
	cout << last_cell.value << endl;
}

int main()
{
	Cells last_cell;
	List list;
	list = create_empty();
	list = append(list, 5);
	list = append(list, 7);
	list = append(list, 10);
	list = append(list, 9);
	list = append(list, 8);
	print_list(list);
}