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


Tree append(Tree tree,int value)
{
	tree.root = append_auxiliary_function(value, tree.root);
	tree.capacity += 1;
	return tree;
}


void left_descent(Cell* cell)
{
	while (cell->left_ptr != nullptr)
	{
		cell = cell->left_ptr;
		cout << cell->value << endl;
	}
}


void right_descent(Cell* cell)
{
	while (cell->right_ptr != nullptr)
	{
		cell = cell->right_ptr;
		cout << cell->value << endl;
	}
}


void print(Tree tree)
{
	cout << tree.root->value << endl;
	left_descent(tree.root);
	right_descent(tree.root);
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