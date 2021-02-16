#include<iostream>
using namespace std;

int main()
{
	int N, M, K, i, k, x, y, j, l;
	cin >> N >> M >> K;
	int** field = new int* [N + 2];
	for (l = 0; l <= N + 1; l++)
		field[l] = new int[M + 2];
	for (i = 0; i <= N + 1; i++)
		for (j = 0; j <= M + 1; j++)
			field[i][j] = 0;
	for (k = 0; k < K; k++)
	{
		cin >> y >> x;
		field[y][x] = -1;
		for (i = y - 1; i <= y + 1; i++)
			for (j = x - 1; j <= x + 1; j++)
				if (field[i][j] != -1)
					field[i][j] += 1;
	}
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
		{
			if (j < M)
				cout << field[i][j] << " ";
			else if ((j = M) && (i < N))
				cout << field[i][j] << endl;
			else if ((j = M) && (i = N))
				cout << field[i][j];
		}
}
