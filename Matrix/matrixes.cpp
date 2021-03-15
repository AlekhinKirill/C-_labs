#include <iostream>
#include <ctime>
#include <complex>
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

int main()
{
	setlocale(0, "");
	Matrix first_matrix, second_matrix, result;
	int n;
	cout << "Введите размер матрицы" << endl;
	cin >> n;
	cout << "Введите первую матрицу" << endl;
	first_matrix = create(n);
	cout << "Введите вторую матрицу" << endl;
	second_matrix = create(n);
	result = multiplication_by_definition(first_matrix, second_matrix);
	cout << "Произведение:" << endl;
	print_matrix(result);
}