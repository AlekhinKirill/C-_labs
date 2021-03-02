#include <iostream>
using namespace std;

struct Stack
{
	int length;
	int memory;
	float* array;
};

Stack create_empty()
{
	Stack stack;
	stack.length = 0;
	stack.memory = 3;
	float* array = new float[3];
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
		float* new_array = new float[stack.memory + 3];
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
	float* new_array = new float[stack.memory];
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
	char a;
	float x;
	int warning;
	warning = 0;
	setlocale(0, "");
	cout << "Инструкция" << endl;
	cout << "Введите выражение в обратной польской нотации, содержащее натуральные числа (и, возможно, ноль) и знаки операций +, -, *, / и заканчивающееся символом '!'" << endl;
	cout << "Если Вы хотите ввести отрицательное число, например -5, то введите 0 5 - ; если хотите ввести дробное, например 1.25, то введите 5 4 / " << endl;
	cin >> a;
	while (a != '!')
	{
		if ((float)a >= 48)
		{
			stack = push(stack, (float)a - 48);
		}
		else
		{
			if (a == '+')
				stack.array[stack.length - 2] += stack.array[stack.length - 1];
			else if (a == '-')
				stack.array[stack.length - 2] -= stack.array[stack.length - 1];
			else if (a == '*')
				stack.array[stack.length - 2] *= stack.array[stack.length - 1];
			else if (a == '/')
			{
				if (stack.array[stack.length - 1] != 0)
					stack.array[stack.length - 2] /= stack.array[stack.length - 1];
				else
				{
					cout << "Делить на ноль нехорошо!" << endl;
					warning = 1;
					break;
				}
			}
			x = stack.array[stack.length - 2];
			stack = pop(stack);
		}
		cin >> a;
	}
	if ((warning == 0) && (stack.length == 1))
		cout << "Ответ: " << x << endl;
	else if (stack.length != 1)
		cout << "Выражение записано некоректно: число операндов не соответствует числу операций!" << endl;
}