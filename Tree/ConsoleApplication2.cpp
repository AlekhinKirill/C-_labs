#include <iostream>
using namespace std;


struct Cell
{
	int value;
	Cell* left_ptr;
	Cell* right_ptr;
	Cell* privious_ptr;
};


struct Tree
{
	Cell* root;
	int capacity;
};


struct Queue_elements
{
	Cell* value;
	Queue_elements* next_ptr;
};

struct Queue
{
	int length;
	Queue_elements* first;
	Queue_elements* last;
};


Queue create()
{
	Queue list;
	list.length = 0;
	list.first = nullptr;
	list.last = nullptr;
	return list;
}


Queue enqueue(Queue queue, Cell* value_ptr)
{
	Queue_elements* element = new Queue_elements;
	element->value = value_ptr;
	element->next_ptr = nullptr;
	if (queue.length == 0)
	{
		queue.first = element;
	}
	else
	{
		if (queue.length == 1)
		{
			queue.last = queue.first;
			queue.first->next_ptr = element;
		}
		queue.last->next_ptr = element;
		queue.last = element;
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

Tree create_empty(int value)
{
	Tree tree;
	Cell* root = new Cell;
	tree.capacity = 0;
	root->value = value;
	root->left_ptr = nullptr;
	root->right_ptr = nullptr;
	root->privious_ptr = nullptr;
	tree.root = root;
	return tree;
}


Cell* append_auxiliary_function(int value, Cell* root)
{
	Cell* cell = new Cell;
	Cell* leaf = new Cell;
	cell = root;
	if ((value <= cell->value) && (cell->left_ptr != nullptr))
	{
		cell = cell->left_ptr;
		append_auxiliary_function(value, cell);
	}
	if ((value > cell->value) && (cell->right_ptr != nullptr))
	{
		cell = cell->right_ptr;
		append_auxiliary_function(value, cell);
	}
	leaf->value = value;
	leaf->left_ptr = leaf->right_ptr = nullptr;
	if (value <= cell->value)
		cell->left_ptr = leaf;
	else
		cell->right_ptr = leaf;
	leaf->privious_ptr = cell;
	return root;
}


Tree append(Tree tree, int value)
{
	tree.root = append_auxiliary_function(value, tree.root);
	tree.capacity += 1;
	return tree;
}


Queue left_descent(Queue queue, Cell* cell)
{
	while (cell->left_ptr != nullptr)
	{
		if (cell->right_ptr != nullptr)
		{
			queue = enqueue(queue, cell->right_ptr);
			cout << cell->right_ptr->value << endl;
		}
		cell = cell->left_ptr;
	}
	return queue;
}


Queue right_descent(Queue queue, Cell* cell)
{
	while (cell->right_ptr != nullptr)
	{
		if (cell->left_ptr != nullptr)
		{
			queue = enqueue(queue, cell->left_ptr);
			cout << cell->right_ptr->value << endl;
		}
		cell = cell->right_ptr;
	}
	return queue;
}


void print(Tree tree)
{
	Queue left_queue = create();
	Queue right_queue = create();
	left_queue = enqueue(left_queue, tree.root);
	right_queue = enqueue(right_queue, tree.root);
	cout << tree.root->value << endl;
	while ((left_queue.length != 0) && (right_queue.length != 0))
	{
		if (left_queue.length != 0)
		{
			right_queue = left_descent(right_queue, left_queue.first->value);
			left_queue = dequeue(left_queue);
		}
		if (right_queue.length != 0)
		{
			left_queue = right_descent(left_queue, right_queue.first->value);
			right_queue = dequeue(right_queue);
		}
	}
}


int main()
{
	Tree tree;
	tree = create_empty(10);
	tree = append(tree, 5);
	tree = append(tree, 12);
	tree = append(tree, 17);
	tree = append(tree, 1);
	tree = append(tree, 8);
	tree = append(tree, 11);
	tree = append(tree, 7);
	print(tree);
}