/* Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0. */

#include <iostream>

using namespace std;

void zero(int **a, const int r, const int c)
{
	bool * row = new bool[r];
	bool * column = new bool[c];
	memset(row, false, sizeof(row));
	memset(column, false, sizeof(column));

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			if(0 == a[i][j])
			{
				row[i] = true;
				column[j] = true;
			}
		}
	}

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			if(row[i] || column[j])
			{
				a[i][j] = 0;
			}
		}
	}

}

int main()
{
	int matrix[][6] = 
	{
		{1, 2, 3, 4, 5, 6},
		{5, 4 ,3, 2, 1, 0},
		{2, 3, 4, 5, 6, 7},
		{3, 4, 5, 6, 7, 8},
		{0, 5, 6, 7, 8, 9}
	};

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	zero(&matrix[0][0], 5, 6);

	cout << endl << "After zeroing, the matrix looks like this: " << endl << endl;

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}