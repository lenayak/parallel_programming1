#include <stdio.h>
#include <iostream>
#include <ctime>
#include <chrono>

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

int main()
{
	srand(time(nullptr));
	const int size = 4;
	int** a = create_random_matrix(size);
	int** b = create_random_matrix(size);
	multiply_matrix(a, b, size);
}