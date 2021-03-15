#include <iostream>
#include <ctime>
#include <complex>
#include <cmath>
using namespace std;

struct Matrix
{
	int size;
	float** ptr_matrix;
};

Matrix create_empty(int n)
{
	Matrix matrix;
	matrix.size = n;
	int i;
	matrix.ptr_matrix = new float* [n];
	for (i = 1; i <= n; i++)
	{
		matrix.ptr_matrix[i] = new float[n];
	}
	return matrix;
}

Matrix create(int n)
{
	Matrix matrix;
	int i, j;
	float value;
	matrix = create_empty(n);
	for (j = 1; j <= n; j++)
	{
		for (i = 1; i <= n; i++)
		{
			cin >> value;
			matrix.ptr_matrix[j][i] = value;
		}
	}
	return matrix;
}

Matrix multiplication_by_definition(Matrix first_matrix, Matrix second_matrix)
{
	Matrix result;
	int i, j, k;
	int n;
	n = first_matrix.size;
	result = create_empty(n);
	for (j = 1; j <= n; j++)
	{
		for (i = 1; i <= n; i++)
		{
			result.ptr_matrix[i][j] = 0;
			for (k = 1; k <= n; k++)
				result.ptr_matrix[i][j] += first_matrix.ptr_matrix[i][k] * second_matrix.ptr_matrix[k][j];
		}
	}
	return result;
}

void print_matrix(Matrix matrix)
{
	int i, j;
	int n;
	n = matrix.size;
	for (j = 1; j <= n; j++)
	{
		for (i = 1; i <= n; i++)
			cout << matrix.ptr_matrix[j][i] << " ";
		cout << endl;
	}
}

Matrix addition(Matrix first_matrix, Matrix second_matrix)
{
	int i, j;
	int n;
	Matrix result;
	n = first_matrix.size;
	result = create_empty(n);
	for (j = 1; j <= n; j++)
	{
		for (i = 1; i <= n; i++)
		{
			result.ptr_matrix[j][i] = first_matrix.ptr_matrix[j][i] + second_matrix.ptr_matrix[j][i];
		}
	}
	return result;
}


Matrix* cut_into_four_blocks(Matrix matrix)
{
	int n, i, j, k;
	n = matrix.size;
	Matrix* blocks = new Matrix[4];
	for (k = 1; k <= 4; k++)
	{
		blocks[k].size = n / 2;
		blocks[k].ptr_matrix = new float* [n / 2];
		for (i = 1; i <= n / 2; i++)
			blocks[k].ptr_matrix[i] = new float [n/2];
	}
	for (j = 1; j <= n/2; j++)
		for (i = 1; i <= n/2; i++)
			blocks[1].ptr_matrix[j][i] = matrix.ptr_matrix[j][i];
	for (j = n/2 + 1; j <= n; j++)
		for (i = 1; i <= n / 2; i++)
			blocks[2].ptr_matrix[j-2][i] = matrix.ptr_matrix[j][i];
	for (j = 1; j <= n / 2; j++)
		for (i = n/2 + 1; i <= n; i++)
			blocks[3].ptr_matrix[j][i-2] = matrix.ptr_matrix[j][i];
	for (j = n/2 + 1; j <= n; j++)
		for (i = n/2 + 1; i <= n; i++)
			blocks[4].ptr_matrix[j-2][i-2] = matrix.ptr_matrix[j][i];
	return blocks;
}

/*Matrix multiplication_by_Strassman(Matrix first_matrix, Matrix second_matrix)
{
	Matrix f1, f2, f3, f4, f5, f6, f7;
	int length_of_set, k, d;
	d = log(first_matrix.size) / log(2);
	Matrix* set_of_first_matrixes = new Matrix[pow(7, (d - 1))];
	Matrix* set_of_second_matrixes = new Matrix[pow(7, (d - 1))];
	for (k = 1; k <= length_of_set; k++)
	{

	}
}*/

int main()
{
	setlocale(0, "");
	Matrix* blocks;
	int i;
	Matrix first_matrix, second_matrix, result;
	int n;
	cout << "Введите размер матрицы" << endl;
	cin >> n;
	cout << "Введите первую матрицу" << endl;
	first_matrix = create(n);
	blocks = cut_into_four_blocks(first_matrix);
	cout << "Блоки:" << endl;
	for (i = 1; i <= 4; i++)
		print_matrix(blocks[i]);
}