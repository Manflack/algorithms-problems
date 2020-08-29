#include <iostream>
#define log(text) cout<<"--- "<<text<<" ---"<<endl;
#define debug(var) cout<<"-"<<var<<"-"<<endl;

using namespace std;

// functions declarations
template <class T>
void createMatrix(T** &m, int rows, int cols, int* &mySize);

template <class T>
void printMatrix(T** &m, int* &mySize);

template <class T>
void changeLength1D(T** &m, int row, int newCols, int* &mySize);

template <class T>
void changeLength2D(T** &m, int rowToDelete, int* &mySize);

int main() {
  
	log("create matrix 4x2");
	int **m;
	int rows = 2, cols = 4;
	int *mySize; // var for stay the array's size, 0 will be used by rowSize

	createMatrix(m, rows, cols, mySize);

	for(int f = 0; f<rows; f++)
		for(int c = 0; c<cols; c++)
			cin >> m[f][c];

	// print original matrix
	log("matrix:")
	printMatrix(m, mySize);

	// change a[1] by a[0, 2] -> is 5, 6
	changeLength1D(m, 1, 2, mySize);

	log("matrix with execution of changeLength1D");
	
	printMatrix(m, mySize);

	// change length of the matrix deleting one row
	changeLength2D(m, 0, mySize);

	log("matrix with resize by one -> m[0] deleted")
	printMatrix(m, mySize);
}

template <class T>
void createMatrix(T** &m, int rows, int cols, int* &mySize)
{
	m = new T * [rows];
	mySize = new T [rows+1];
	mySize[0] = rows;

	for(int i=0; i<rows; i++) {
		m[i] = new T [cols];
		mySize[i+1] = cols;
	}
}

template <class T>
void changeLength1D(T** &m, int row, int newCols, int* &mySize)
{
	T * tmp = new T[newCols];

	for(int i=0; i<mySize[row+1]; i++) {
		tmp[i] = m[row][i];
	}

	delete [] m[row];

	m[row] = tmp;

	mySize[row+1] = newCols; // we assign the new size of the array given row-th position
}

template <class T>
void printMatrix(T** &m, int* &mySize)
{
	for(int f = 0; f<mySize[0]; f++) {
		for(int c = 0; c<mySize[f+1]; c++) {
			cout << m[f][c] << " ";
		}
		cout << endl;
	}
}

template <class T>
void changeLength2D(T** &m, int rowToDelete, int* &mySize)
{
	// cout << mySize[0] << "-" << mySize[1] << "-" << mySize[2] << endl;
	delete m[rowToDelete];
	// delete mySize[rowToDelete+1];
	// the following code doesn't have the better performance...

	int mySizeElements = mySize[0]+1;

	T * newSize = new T[mySizeElements-1];

	for(int i=0, c=0; i<mySizeElements; i++) {
		if(i != rowToDelete+1) {
			newSize[c] = mySize[i];
			c++;
		}
	}

	delete mySize;

	mySize = new T[newSize[0]];

	for(int i=0; i<newSize[0]; i++)
		mySize[i] = newSize[i];
	//mySize = newSize;

	newSize[0]-=1;
	cout << mySize[0] << "-" << mySize[1] << endl;
}