#include <iostream>
using namespace std;


struct Cell
{
	int value;
	Cell* next_ptr;
};


struct Stack
{
	int length;
	Cell* last;
	Cell* first;
};


Stack create_empty()
{
	Stack stack;
	stack.length = 0;
	stack.last = nullptr;
	return stack;
}


Stack push(Stack stack, int value)
{
	Cell* cell = new Cell;
	cell->value = value;
	cell->next_ptr = nullptr;
	if (stack.length == 0)
	{
		stack.first = cell;
		stack.last = cell;
	}
	else
	{
		stack.last->next_ptr = cell;
		stack.last = cell;
	}
	stack.length += 1;
	return stack;
}


Stack pop(Stack stack)
{
	Cell* cell;
	cell = stack.first;
	while (cell->next_ptr->next_ptr != nullptr)
		cell = cell->next_ptr;
	cell->next_ptr = nullptr;
	stack.last = cell;
	stack.length -= 1;
	return stack;
}


void print(Stack queue)
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
	Stack stack;
	stack = create_empty();
	stack = push(stack, 5);
	stack = push(stack, 12);
	stack = push(stack, 17);
	stack = push(stack, 1);
	stack = pop(stack);
	stack = push(stack, 8);
	stack = push(stack, 11);
	stack = push(stack, 7);
	stack = pop(stack);
	print(stack);
}