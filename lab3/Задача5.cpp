﻿#include <iostream>
using namespace std;

int do_some_awesome_work(int* parametr1, int* parametr2)
{
	return *parametr1 + *parametr2;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << do_some_awesome_work(&a, &b) << endl;
}