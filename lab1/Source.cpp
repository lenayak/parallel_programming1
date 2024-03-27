#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int** create_random_matrix(const int size)
{
	int** matrix = new int* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = rand() % 1000;
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	return matrix;
}

int** multiply_matrix(int** a, int** b, const int size)
{
	int** c = new int* [size];
	for (int i = 0; i < size; i++)
		c[i] = new int[size];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < size; k++)
				c[i][j] += a[i][k] * b[k][j];
			cout << c[i][j] << "  ";
		}
		cout << endl;
	}
	return c;
}

void write_to_file(int** matrix, string filename);
void write_to_file(int** matrix, string filename, unsigned int time);

int main()
{
	srand(time(nullptr));

	// записываем в файлы матрицы a, b и результат перемножения

	const int sizes[5] = { 100, 300, 500, 700, 1000 };
	for (int i = 0; i < 5; i++)
	{
		int** a = create_random_matrix(sizes[i]);
		int** b = create_random_matrix(sizes[i]);
		unsigned int start = clock();
		int** result = multiply_matrix(a, b, sizes[i]);
		unsigned int end = clock();
		unsigned int time = end - start;
		string filenane_matrix_a = "matrix_a_" + to_string(sizes[i]);
		string filename_matrix_b = "matrix_b_" + to_string(sizes[i]);
		string filename_result = "matrix_result_" + to_string(sizes[i]);
		write_to_file(a, filenane_matrix_a);
		write_to_file(b, filename_matrix_b);
		write_to_file(result, filename_result, time);
	 }
	
	// подсчет среднего времени

	for (int i = 0; i < 5; i++)
	{
		unsigned int average_times[5] = { 0,0,0,0,0 };
		for (int j = 0; j < 10; j++)
		{
			int** a = create_random_matrix(sizes[i]);
			int** b = create_random_matrix(sizes[i]);
			unsigned int start = clock();
			multiply_matrix(a, b, sizes[i]);
			unsigned int end = clock();
			unsigned int time = end - start;
			average_times[i] += time;
		}
		average_times[i] / 10;
		// тут запись результатов в отдельный файл (размер - время)
	}

	return 0;
}