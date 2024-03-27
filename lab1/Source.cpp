#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

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

void write_to_file(int** matrix, int size, string filename)
{
	ofstream fout(filename);
	if (!fout.is_open()) return;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fout << matrix[i][j] << "  ";
		}
		fout << endl;
	}
	fout.close();
	return;
}

void write_to_file(int** matrix, int size, string filename, unsigned int time)
{
	ofstream fout(filename);
	if (!fout.is_open()) return;
	fout << "Size: " << size << endl;
	fout << "Time: " << time << " milliseconds" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fout << matrix[i][j] << "  ";
		}
		fout << endl;
	}
	fout.close();
	return;
}

void write_to_file(const int* sizes, string filename, unsigned int* times)
{
	ofstream fout(filename);
	if (!fout.is_open()) return;
	for (int i = 0; i < 5; i++)
	{
		fout << "Size: " << sizes[i] << "\t Time: " << times[i] << " milliseconds" << endl;
	}
	fout.close();
	return;
}

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
		string filenane_matrix_a = "matrix_a_" + to_string(sizes[i]) + ".txt";
		string filename_matrix_b = "matrix_b_" + to_string(sizes[i]) + ".txt";
		string filename_result = "matrix_result_" + to_string(sizes[i]) + ".txt";
		write_to_file(a, sizes[i], filenane_matrix_a);
		write_to_file(b, sizes[i], filename_matrix_b);
		write_to_file(result, sizes[i], filename_result, time);
	 }
	
	// подсчет среднего времени

	string filename_times = "average_times.txt";
	unsigned int average_times[5] = { 0,0,0,0,0 };
	for (int i = 0; i < 5; i++)
	{
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
	}
	write_to_file(sizes, filename_times, average_times);

	return 0;
}