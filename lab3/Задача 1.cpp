#include <iostream>
using namespace std;

int main()
{
	int N, i, Answer;
	float mean, Sum_1;
	Sum_1 = 0;
	Answer = 0;
	cin >> N;
	int* arr = new int[N];
	for (i = 0; i <= N - 1; i++)
	{
		cin >> arr[i];
		Sum_1 += arr[i];
	}
	mean = Sum_1 / N;
	for (i = 0; i <= N - 1; i++)
	{
		if (arr[i] > mean)
		{
			Answer += arr[i];
		}
	}
	cout << Answer << endl;
}