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
	for (i = 0; i < n; i++)
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
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
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
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			result.ptr_matrix[i][j] = 0;
			for (k = 0; k < n; k++)
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
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
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
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
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
	for (k = 0; k < 4; k++)
	{
		blocks[k].size = n / 2;
		blocks[k].ptr_matrix = new float* [n / 2];
		for (i = 0; i < n / 2; i++)
			blocks[k].ptr_matrix[i] = new float [n/2];
	}
	for (j = 0; j < n/2; j++)
		for (i = 0; i < n/2; i++)
			blocks[0].ptr_matrix[j][i] = matrix.ptr_matrix[j][i];
	for (j = n/2; j < n; j++)
		for (i = 0; i < n / 2; i++)
			blocks[1].ptr_matrix[j-n/2][i] = matrix.ptr_matrix[j][i];
	for (j = 0; j < n / 2; j++)
		for (i = n/2; i < n; i++)
			blocks[2].ptr_matrix[j][i-n/2] = matrix.ptr_matrix[j][i];
	for (j = n/2; j < n; j++)
		for (i = n/2; i < n; i++)
			blocks[3].ptr_matrix[j-n/2][i-n/2] = matrix.ptr_matrix[j][i];
	return blocks;
}

Matrix* cut_into_2x2_blocks(Matrix matrix)
{
	Matrix* blocks;
	Matrix* new_set_of_matrixes;
	int length_of_set, k, i, n, j;
	n = matrix.size;
	Matrix* set_of_matrixes = new Matrix[1];
	length_of_set = 1;
	set_of_matrixes[0] = matrix;
	for (i = 0; i < int(log(n)/log(2)) - 1; i++)
	{
		Matrix* new_set_of_matrixes = new Matrix[int(pow(4,i+ 1))];
		for (k = 0; k < length_of_set; k++)
		{
			blocks = cut_into_four_blocks(set_of_matrixes[k]);
			for (j = 0; j < 4; j++)
				new_set_of_matrixes[4 * k + j] = blocks[j];
		}
		set_of_matrixes = new_set_of_matrixes;
		length_of_set *= 4;
	}
	return set_of_matrixes;
}

int main()
{
	setlocale(0, "");
	int j, m;
	float** standart = new float*[16];
	for (j = 0; j < 16; j++)
	{
		standart[j] = new float[16];
		for (m = 0; m < 16; m++)
			standart[j][m] = m + 2*j;
	}
	Matrix* blocks;
	int i;
	Matrix first_matrix, second_matrix, result;
	first_matrix = create_empty(16);
	first_matrix.ptr_matrix = standart;
	blocks = cut_into_2x2_blocks(first_matrix);
	print_matrix(first_matrix);
	cout << "Блоки:" << endl;
	cout << endl;
	for (i = 0; i < 64; i++)
	{
		print_matrix(blocks[i]);
		cout << endl;
	}
}