#include <iostream>
using namespace std;

int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new)
{
	int j;
	int* arr = new int[n_new];
	if (source != NULL)
	{
		if (n_old <= n_new)
			for (j = 0; j < n_old; j++)
				arr[j] = source[j];
		else
			for (j = 0; j < n_new; j++)
		                arr[j] = source[j];
		delete[] source;
		return arr;
	}
}


int main()
{
	unsigned int N, i, S;
	S = 0;
	cin >> N;
	int* a = my_slightly_dumb_reallocation(NULL, 0, N / 2);
	for (i = 0; i < N / 2; i++)
		cin >> a[i];
	a = my_slightly_dumb_reallocation(a, N / 2, N);
	for (; i < N; i++)
		cin >> a[i];
	for (i = 0; i < N; i++)
		S += a[i];
	cout << S << endl;
	a = my_slightly_dumb_reallocation(a, N, N / 2);
	a = my_slightly_dumb_reallocation(a, N / 2, 0);
	a = my_slightly_dumb_reallocation(a, 0, 0);
	return 0;
}
