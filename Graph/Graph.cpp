#include <iostream>
#include <vector>
using namespace std;


struct Cell
{
	int value;
	vector<Cell> neighbors;
	int number_of_neighbors;
	int distance = 0;
};

struct Graph
{
	int length;
	vector<Cell> list;
};

struct Cell_queue
{
	Cell element;
	Cell_queue* next_ptr;
};

struct Queue
{
	int length;
	Cell_queue* first;
	Cell_queue* last;
};


Queue create_empty_queue()
{
	Queue list;
	list.length = 0;
	list.first = nullptr;
	list.last = nullptr;
	return list;
}


Queue enqueue(Queue queue, Cell value)
{
	Cell_queue* cell = new Cell_queue;
	cell->element = value;
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


void print_queue(Queue queue)
{
	Cell_queue* element_ptr;
	element_ptr = queue.first;
	cout << queue.first->element.value << " ";
	while (element_ptr->next_ptr != nullptr)
	{
		cout << element_ptr->next_ptr->element.value << " ";
		element_ptr = element_ptr->next_ptr;
	}
	cout << endl;
}

Graph create_empty()
{
	Graph graph;
	graph.length = 0;
	return graph;
}


Graph append(Graph graph, Cell cell)
{
	Cell neighbor;
	int number_of_neighbours;
	int i, j;
	for (i = 0; i < cell.number_of_neighbors; i++)
	{
		for (j = 0; j < graph.length; j++)
		{
			if (graph.list[j].value == cell.neighbors[i].value)
			{
				graph.list[j].neighbors.push_back(cell);
				graph.list[j].number_of_neighbors += 1;
			}
		}
	}
	graph.list.push_back(cell);
	graph.length += 1;
	return graph;
}


int index(Graph graph, int value)
{
	int i, indicator;
	indicator = 0;
	for (i = 0; i < graph.length; i++)
		if (graph.list[i].value == value)
		{
			indicator = 1;
			return i;
			break;
		}
	if (indicator == 0)
		cout << "Такого элемента нет" << endl;
}


void print(Graph graph)
{
	int i, j;
	cout << "Граф:" << endl;
	for (i = 0; i < graph.length; i++)
	{
		cout << "Номер элемента" << endl;
		cout << graph.list[i].value << endl;
		cout << "Соседи:" << endl;
		for (j = 0; j < graph.list[i].number_of_neighbors; j++)
			cout << graph.list[i].neighbors[j].value << endl;
	}
}


Graph BFS(Graph graph, int value)
{
	int length, i, j;
	length = 0;
	Queue unverified;
	for (i = 0; i < graph.length; i++)
		graph.list[i].distance = 0;
	unverified = create_empty_queue();
	unverified = enqueue(unverified, graph.list[index(graph, value)]);
	while (unverified.first != nullptr)
	{
		for (i = 0; i < unverified.first->element.number_of_neighbors; i++)
			if ((graph.list[index(graph, unverified.first->element.neighbors[i].value)].distance == 0) && (unverified.first->element.neighbors[i].value != value))
			{
				graph.list[index(graph, unverified.first->element.neighbors[i].value)].distance = graph.list[index(graph, unverified.first->element.value)].distance + 1;
				unverified = enqueue(unverified, graph.list[index(graph, unverified.first->element.neighbors[i].value)]);
			}
		unverified = dequeue(unverified);
	}
	return graph;
}


int main()
{
	int i, root, top;
	setlocale(0, "");
	Cell* cells = new Cell[4];
	Graph graph;
	/*Построение графа*/
	cells[0].value = 1;
	cells[1].value = 2;
	cells[2].value = 3;
	cells[3].value = 4;
	cells[0].number_of_neighbors = 2;
	cells[0].neighbors.push_back(cells[1]);
	cells[0].neighbors.push_back(cells[2]);
	cells[1].number_of_neighbors = 3;
	cells[1].neighbors.push_back(cells[0]);
	cells[1].neighbors.push_back(cells[2]);
	cells[1].neighbors.push_back(cells[3]);
	cells[2].number_of_neighbors = 2;
	cells[2].neighbors.push_back(cells[0]);
	cells[2].neighbors.push_back(cells[1]);
	cells[3].number_of_neighbors = 1;
	cells[3].neighbors.push_back(cells[1]);
	graph = create_empty();
	graph.length = 4;
	for (i = 0; i < 4; i++)
		graph.list.push_back(cells[i]);
	/*Добавление элемента*/
	Cell new_cell;
	new_cell.value = 5;
	new_cell.number_of_neighbors = 3;
	new_cell.neighbors.push_back(graph.list[index(graph, 1)]);
	new_cell.neighbors.push_back(graph.list[index(graph, 3)]);
	new_cell.neighbors.push_back(graph.list[index(graph, 4)]);
	graph = append(graph, new_cell);
	Cell new_cell2;
	new_cell2.value = 6;
	new_cell2.number_of_neighbors = 1;
	new_cell2.neighbors.push_back(graph.list[index(graph, 4)]);
	graph = append(graph, new_cell2);
	Cell new_cell3;
	new_cell3.value = 7;
	new_cell3.number_of_neighbors = 2;
	new_cell3.neighbors.push_back(graph.list[index(graph, 2)]);
	new_cell3.neighbors.push_back(graph.list[index(graph, 6)]);
	graph = append(graph, new_cell3);
	/*BFS*/
	root = 5;
	graph = BFS(graph, root);
	print(graph);
	top = 7;
	cout << "Расстояние между вершинами "<< root << " и " << top << " равно " << graph.list[index(graph, top)].distance << endl;
}