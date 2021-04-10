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
		queue.last = element;
	}
	else
	{
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


void print_queue(Queue queue)
{
	Queue_elements* element_ptr;
	element_ptr = queue.first;
	cout << queue.first->value->value << " ";
	while (element_ptr->next_ptr != nullptr)
	{
		cout << element_ptr->next_ptr->value->value << " ";
		element_ptr = element_ptr->next_ptr;
	}
	cout << endl;
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
		cell = append_auxiliary_function(value, cell);
		return cell->privious_ptr;
	}
	else if ((value > cell->value) && (cell->right_ptr != nullptr))
	{
		cell = cell->right_ptr;
		cell = append_auxiliary_function(value, cell);
		return cell->privious_ptr;
	}
	else
	{
		leaf->value = value;
		leaf->left_ptr = nullptr;
		leaf->right_ptr = nullptr;
		if (value <= cell->value)
			cell->left_ptr = leaf;
		else
			cell->right_ptr = leaf;
		leaf->privious_ptr = cell;
		return root;
	}
}


Tree append(Tree tree, int value)
{
	tree.root = append_auxiliary_function(value, tree.root);
	tree.capacity += 1;
	return tree;
}


Queue descent(Queue queue, Cell* cell, string mod)
{
	Cell* last_knot = new Cell;
	if (mod == "print")
		cout << cell->value << endl;
	while (cell->left_ptr != nullptr)
	{
		if (cell->right_ptr != nullptr)
			queue = enqueue(queue, cell->right_ptr);
		cell = cell->left_ptr;
		if (mod == "print")
			cout << cell->value << endl;
	}
	if (cell->right_ptr != nullptr)
		queue = enqueue(queue, cell->right_ptr);
	else
		if (mod == "print_leaves")
			cout << cell->value << endl;
	queue = dequeue(queue);
	return queue;
}


void print(Tree tree)
{
	Queue queue = create();
	queue = enqueue(queue, tree.root);
	while (queue.length != 0)
	{
		if (queue.length != 0)
		{
			queue = descent(queue, queue.first->value, "print");
		}
	}
}


void print_leaves(Tree tree)
{
	Queue queue = create();
	queue = enqueue(queue, tree.root);
	while (queue.length != 0)
	{
		if (queue.length != 0)
		{
			queue = descent(queue, queue.first->value, "print_leaves");
		}
	}
}


int main()
{
	Tree tree;
	tree = create_empty(10);
	tree = append(tree, 5);
	tree = append(tree, 12);
	tree = append(tree, 9);
	tree = append(tree, 3);
	tree = append(tree, 17);
	tree = append(tree, 1);
	tree = append(tree, 8);
	tree = append(tree, 2);
	tree = append(tree, 6);
	tree = append(tree, 4);
	tree = append(tree, 11);
	tree = append(tree, 7);
	cout << "Tree" << endl;
	print(tree);
	cout << "Leaves" << endl;
	print_leaves(tree);
}