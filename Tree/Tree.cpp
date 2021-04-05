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
	Cell root;
	tree.capacity = 0;
	root.value = value;
	root.left_ptr = nullptr;
	root.right_ptr = nullptr;
	root.privious_ptr = nullptr;
	tree.root = &root;
	return tree;
}


Cell* append_auxiliary_function(int value, Cell* root)
{
	Cell* cell;
	Cell leaf;
	cell = root;
	if ((value <= cell->value) && (cell->left_ptr != nullptr))
	{
		cell = cell->left_ptr;
		append_auxiliary_function(value, cell);
	}
	else if ((value > cell->value) && (cell->right_ptr != nullptr))
	{
		cell = cell->right_ptr;
		append_auxiliary_function(value, cell);
	}
	leaf.privious_ptr = cell;
	leaf.value = value;
	leaf.left_ptr = leaf.right_ptr = nullptr;
	if (value <= cell->value)
		cell->left_ptr = &leaf;
	else
		cell->right_ptr = &leaf;
	return root;
}

Tree append(Tree tree,int value)
{
	tree.capacity += 1;
	tree.root = append_auxiliary_function(value, tree.root);
	return tree;
}

void descent(Cell* cell)
{
	while (cell->left_ptr != nullptr)
	{
		cout << cell->value << " ";
		cell = cell->left_ptr;
	}
	cout << endl;
	while (cell->right_ptr == nullptr)
		cell = cell->privious_ptr;
	cell = cell->right_ptr;
	descent(cell);
}

void pre_order_print(Tree tree)
{
	descent(tree.root);
}


int main()
{
	Tree tree;
	tree = append(tree, 5);
	tree = append(tree, 12);
	tree = append(tree, 17);
	tree = append(tree, 1);
	tree = append(tree, 8);
	tree = append(tree, 11);
	tree = append(tree, 7);
	pre_order_print(tree);
}