#include <iostream>
using namespace std;

struct Stack
{
	int length;
	int memory;
	int* array;
};

Stack create_empty()
{
	Stack stack;
	stack.length = 0;
	stack.memory = 3;
	int* array = new int[3];
	stack.array = array;
	return stack;
}

Stack push(Stack stack, int element)
{
	if (stack.length < stack.memory)
	{
		stack.array[stack.length] = element;
	}
	else
	{
		int i;
		int* new_array = new int[stack.memory + 3];
		stack.memory += 3;
		for (i = 0; i < stack.length;i++)
			new_array[i] = stack.array[i];
		new_array[stack.length] = element;
		delete[] stack.array;
		stack.array = new_array;
	}
	stack.length += 1;
	return stack;
}

Stack pop(Stack stack)
{
	int i;
	int* new_array = new int[stack.memory];
	stack.length -= 1;
	for (i = 0; i < stack.length; i++)
		new_array[i] = stack.array[i];
	delete[] stack.array;
	stack.array = new_array;
	return stack;
}

void print_stack(Stack stack)
{
	int i;
	for (i = 0; i < stack.length; i++)
		cout << stack.array[i] << endl;
}

int main()
{
	Stack stack;
	stack = create_empty();
	stack = push(stack, 8);
	stack = push(stack, 5);
	stack = push(stack, 10);
	stack = push(stack, 7);
	stack = pop(stack);
	stack = push(stack, 9);
	stack = push(stack, 6);
	stack = pop(stack);
	stack = push(stack, 1);
	stack = push(stack, 4);
	print_stack(stack);
}
