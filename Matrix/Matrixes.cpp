#include <iostream>
#include <ctime>
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

Matrix subtraction(Matrix first_matrix, Matrix second_matrix)
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
			result.ptr_matrix[j][i] = first_matrix.ptr_matrix[j][i] - second_matrix.ptr_matrix[j][i];
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

Matrix unite(Matrix* blocks)
{
	Matrix result;
	int i, j, k, n;
	n = 2*blocks[0].size;
	result = create_empty(n);
	result.size = n;
	for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			result.ptr_matrix[j][i] = blocks[0].ptr_matrix[j][i];
	for (i = n / 2; i < n; i++)
		for (j = 0; j < n / 2; j++)
			result.ptr_matrix[j][i] = blocks[2].ptr_matrix[j][i- n/2];
	for (i = 0; i < n / 2; i++)
		for (j = n / 2; j < n; j++)
			result.ptr_matrix[j][i] = blocks[1].ptr_matrix[j - n/2][i];
	for (i = n / 2; i < n; i++)
		for (j = n / 2; j < n; j++)
			result.ptr_matrix[j][i] = blocks[3].ptr_matrix[j - n/2][i - n/2];
	return result;
	delete[] blocks;
}


Matrix multiplication_by_Strassen(Matrix first_matrix, Matrix second_matrix)
{
	Matrix* first_set_of_blocks;
	Matrix* second_set_of_blocks;
	Matrix* set_of_matrixes = new Matrix[4];
	Matrix f1, f2, f3, f4, f5, f6, f7;
	first_set_of_blocks = cut_into_four_blocks(first_matrix);
	second_set_of_blocks = cut_into_four_blocks(second_matrix);
	if (first_set_of_blocks[0].size == 2)
	{
		f1 = multiplication_by_definition(addition(first_set_of_blocks[0], first_set_of_blocks[3]), addition(second_set_of_blocks[0], second_set_of_blocks[3]));
		f2 = multiplication_by_definition(addition(first_set_of_blocks[1], first_set_of_blocks[3]), second_set_of_blocks[0]);
		f3 = multiplication_by_definition(first_set_of_blocks[0], subtraction(second_set_of_blocks[2], second_set_of_blocks[3]));
		f4 = multiplication_by_definition(first_set_of_blocks[3], subtraction(second_set_of_blocks[1], second_set_of_blocks[0]));
		f5 = multiplication_by_definition(addition(first_set_of_blocks[0], first_set_of_blocks[2]), second_set_of_blocks[3]);
		f6 = multiplication_by_definition(subtraction(first_set_of_blocks[1], first_set_of_blocks[0]), addition(second_set_of_blocks[0], second_set_of_blocks[2]));
		f7 = multiplication_by_definition(subtraction(first_set_of_blocks[2], first_set_of_blocks[3]), addition(second_set_of_blocks[1], second_set_of_blocks[3]));
	}
	else
	{
		f1 = multiplication_by_Strassen(addition(first_set_of_blocks[0], first_set_of_blocks[3]), addition(second_set_of_blocks[0], second_set_of_blocks[3]));
		f2 = multiplication_by_Strassen(addition(first_set_of_blocks[1], first_set_of_blocks[3]), second_set_of_blocks[0]);
		f3 = multiplication_by_Strassen(first_set_of_blocks[0], subtraction(second_set_of_blocks[2], second_set_of_blocks[3]));
		f4 = multiplication_by_Strassen(first_set_of_blocks[3], subtraction(second_set_of_blocks[1], second_set_of_blocks[0]));
		f5 = multiplication_by_Strassen(addition(first_set_of_blocks[0], first_set_of_blocks[2]), second_set_of_blocks[3]);
		f6 = multiplication_by_Strassen(subtraction(first_set_of_blocks[1], first_set_of_blocks[0]), addition(second_set_of_blocks[0], second_set_of_blocks[2]));
		f7 = multiplication_by_Strassen(subtraction(first_set_of_blocks[2], first_set_of_blocks[3]), addition(second_set_of_blocks[1], second_set_of_blocks[3]));
	}
	set_of_matrixes[0] = addition(subtraction(addition(f1, f4), f5), f7);
	set_of_matrixes[1] = addition(f2, f4);
	set_of_matrixes[2] = addition(f3, f5);
	set_of_matrixes[3] = addition(addition(subtraction(f1, f2), f3), f6);
	return unite(set_of_matrixes);
	delete[] first_matrix.ptr_matrix;
	delete[] second_matrix.ptr_matrix;
}

int main()
{
	setlocale(0, "");
	float start, stop, time;
	int j, m, N;
	N = 4;
	float** standart_1 = new float*[N];
	float** standart_2 = new float* [N];
	for (j = 0; j < N; j++)
	{
		standart_1[j] = new float[N];
		for (m = 0; m < N; m++)
			standart_1[j][m] = m + 2*j;
	}
	for (j = 0; j < N; j++)
	{
		standart_2[j] = new float[N];
		for (m = 0; m < N; m++)
			standart_2[j][m] = 3*m + j;
	}
	Matrix* blocks;
	int i;
	Matrix first_matrix, second_matrix;
	first_matrix = create_empty(N);
	first_matrix.ptr_matrix = standart_1;
	print_matrix(first_matrix);
	second_matrix = create_empty(N);
	second_matrix.ptr_matrix = standart_2;
	cout << endl;
	print_matrix(second_matrix);
	cout << endl;
	start = clock();
	/*print_matrix(multiplication_by_definition(first_matrix, second_matrix));*/
	print_matrix(multiplication_by_Strassen(first_matrix, second_matrix));
	stop = clock();
	time = stop - start;
	cout << "Время = " << time;
	delete[] first_matrix.ptr_matrix;
	delete[] second_matrix.ptr_matrix;
}