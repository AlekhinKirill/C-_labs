#include <iostream>
using namespace std;

struct Cat
{
	char name[20];
	unsigned int id;
	double weight, lenght;
	unsigned int mice_caught;
};

int count_total_mice_amount(Cat* cats, unsigned int n)
{
	int j, S;
	S = 0;
	for (j = 0; j < n; j++)
		S += cats[j].mice_caught;
	return S;
}


int main()
{
	unsigned int N, i;
	cin >> N;
	Cat* a = new Cat[N];
	for (i = 0; i < N; i++)
	{
		cin >> a[i].name >> a[i].weight >> a[i].lenght >> a[i].mice_caught;
		a[i].id = i;
	}
	cout << count_total_mice_amount(a, N) << endl;
	delete[] a;
	return 0;
}