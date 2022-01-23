#include <iostream>
using namespace std;

void divisionArr(int **matrix, int n, int m) {

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}
}

void inputArr(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 20;
		}
	}
}

void printArr(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout<<matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
void deleteArr(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		delete[]matrix[i];
	}
}
void sotrArr(int** matrix, int n, int m) {
	for (int k = 0; k < n; k++)
	{
		for (int l = 0; l < m; l++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (i + 1 == n && j + 1 == m) {
						continue;
					}
					else {
						if (j + 1 == m && matrix[i][j] > matrix[i + 1][0]) {
							int temp = matrix[i][j];
							matrix[i][j] = matrix[i + 1][0];
							matrix[i + 1][0] = temp;
						}
						else {
							if (j + 1 == m) {
								continue;
							}
							else {
								if (matrix[i][j] > matrix[i][j + 1]) {
									swap(matrix[i][j], matrix[i][j + 1]);
								}
							}
						}
					}
				}

			}

		}

	}
}
int main()
{
	int** matrix = nullptr;
	int n = 5;
	int m = 6;
	matrix = new int* [n];

	divisionArr(matrix, n, m);
	inputArr(matrix, n, m);
	printArr(matrix, n, m);
	
	cout << endl;
	cout << "Sort Array" << endl;
	sotrArr(matrix, n, m);
	printArr(matrix, n, m);
	deleteArr(matrix, n, m);
	delete[]matrix;
}

