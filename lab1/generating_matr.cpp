#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

int** generate_matrix(int size)
{
	int** a = new int* [size];
	for (int i = 0; i < size; i++)
	{
		a[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			a[i][j] = rand() % 1000;
			cout << a[i][j] << "  ";   // ����� � ����
		}
		cout << endl;                  // ��� ���������� � ���� ��� ������� ����� ���������, � �� ���������
	}
	return a;
}

int main()
{
	srand(time(NULL));
	int exp_size[5] = {4, 2, 3, 5, 7};    // ������� ��� ������������
	for (int i = 0; i < 5; i++)
	{
		generate_matrix(exp_size[i]);  //��� ��� ������������ ������ �������������� 2 �������
		cout << endl;
		generate_matrix(exp_size[i]); 
		cout << endl << endl;
	}
	return 0;
}