/* Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place? */

#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void transpose(int arr[][4], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			swap(arr[i][j], arr[j][i]);
		}
	}
	for(int i = 0; i < n/2; i++)
	{
		for(int j = 0; j < n; j++)
		{
			swap(arr[i][j], arr[n - i -1][j]);
		}
	}

}

int main()
{
	int matrix[4][4] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15,16}
	};

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	transpose(matrix, 4);

	cout << endl << "After transpose, the matrix looks like this way: " << endl << endl;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

//	system("pause");
	return 0;
}