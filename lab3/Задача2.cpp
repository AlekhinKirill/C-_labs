#include <iostream>
using namespace std;

int* now_get_me_some_bytes(int n)
{
    int* arr = new int[n];
    return arr;
}

void now_free_some_bytes(int* p)
{
	delete[] p;
}

int main()
{
	int N, i;
	cin >> N;
	int* a = now_get_me_some_bytes(N);
	for (i = 0; i < N; i++)
		cin >> a[i];
	int S = 0;
	for (i = 0; i < N; i++)
		S += a[i];
	cout << S << endl;
	now_free_some_bytes(a);
	return 0;
}
