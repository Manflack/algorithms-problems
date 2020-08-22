#include <iostream>

using namespace std;

template <class T>
void createMatrix(T** &m, int rows, int cols);

template <class T>
void printMatrix(T** &m, int rows, int cols);

template <class T>
void changeLength1D(T** &m, int row, int newCols);

int main() {
  
	cout << "--- create matrix ---" << endl;
	int **m;
	int rows = 2, cols = 4;

	createMatrix(m, rows, cols);

	for(int f = 0; f<rows; f++)
		for(int c = 0; c<cols; c++)
			cin >> m[f][c];

	// print original matrix
	printMatrix(m, rows, cols);

	// change a[1] by a[0, 2] -> is 5, 6
	changeLength1D(m, 1, 2);
	
	// holy shit doesn't works
	printMatrix(m, rows, cols);
}

template <class T>
void createMatrix(T** &m, int rows, int cols)
{
	m = new T * [rows];

	for(int i=0; i<rows; i++)
		m[i] = new T [cols];
}

template <class T>
void changeLength1D(T** &m, int row, int newCols)
{
	T * tmp = m[row];
	delete [] m[row];
	m[row] = new T [newCols];
	for(int i=0; i<row; i++)
		//m[row][i] = tmp[i];
		cout << tmp [i] << endl;
}

template <class T>
void printMatrix(T** &m, int rows, int cols)
{
	for(int f = 0; f<rows; f++)
	{
		//cout << " -" << f << "- ";
		for(int c = 0; c<cols; c++)
		{
			//cout << " -" << c << "- ";
			cout << m[f][c] << " ";
		}
		cout << endl;
	}
}