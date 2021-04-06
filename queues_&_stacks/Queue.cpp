#include <iostream>
using namespace std;


struct Cell
{
	int value;
	Cell* next_ptr;
};

struct Queue
{
	int length;
	Cell* first;
	Cell* last;
};


Queue create_empty()
{
	Queue list;
	list.length = 0;
	list.first = nullptr;
	list.last = nullptr;
	return list;
}


Queue enqueue(Queue queue, int value)
{
	Cell* cell = new Cell;
	cell->value = value;
	cell->next_ptr = nullptr;
	if (queue.length == 0)
	{
		queue.first = cell;
		queue.last = cell;
	}
	else
	{
		queue.last->next_ptr = cell;
		queue.last = cell;
	}
	queue.length += 1;
	return queue;
}


Queue dequeue(Queue queue)
{
	queue.first = queue.first->next_ptr;
	queue.length -= 1;
	return queue;
}


void print(Queue queue)
{
	Cell* element_ptr;
	element_ptr = queue.first;
	cout << queue.first->value << " ";
	while (element_ptr->next_ptr != nullptr)
	{
		cout << element_ptr->next_ptr->value << " ";
		element_ptr = element_ptr->next_ptr;
	}
	cout << endl;
}


int main()
{
	Queue queue;
	queue = create_empty();
	queue = enqueue(queue, 5);
	queue = enqueue(queue, 12);
	queue = enqueue(queue, 17);
	queue = enqueue(queue, 1);
	queue = dequeue(queue);
	queue = enqueue(queue, 8);
	queue = enqueue(queue, 11);
	queue = enqueue(queue, 7);
	queue = dequeue(queue);
	print(queue);
}