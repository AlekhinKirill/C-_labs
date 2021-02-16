#include <iostream>
using namespace std;

struct Cat
{
	char* name;
	unsigned int id;
	double weight, lenght;
	unsigned int mice_caught;
};

Cat* get_home_for_a_cats_pride(unsigned int n)
{
	int i;
	Cat* arr = new Cat[n];
	for (i = 0; i < n; i++)
		arr[i].name = new char[10];
	return arr;
}

void clear_home_of_a_cats_pride(Cat* cats, unsigned int n)
{
	delete[] cats;
}


int main()
{
	unsigned int N, i;
	cin >> N;
	Cat* a = get_home_for_a_cats_pride(N);
	for (i = 0; i < N; i++)
	{
		cin >> a[i].name >> a[i].weight >> a[i].lenght >> a[i].mice_caught;
		a[i].id = i;
	}
	for (i = 0; i < N; i++)
		cout << a[i].name << " ";
	clear_home_of_a_cats_pride(a, N);
	return 0;
}