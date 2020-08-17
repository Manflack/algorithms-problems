#include <iostream>
#include <vector>
#include <fstream>

#include <stdlib.h>

using namespace std;

/* -- Data structures, algorithms and applications problems --
*
* 1. Write a template function count that returns the number of occurrences of value in the array a[0:n-1]. Test your code.
*
* 2. Write a template function fill that sets a[start: end-1] to value. Test your code.
*
* 3. write a template function inner_product that returns sum i=0, n-1 a[i]*b[i]. Test your code.
*
*
*
*/

// Declare functions
template <class T>
int count(vector<T> array, T value);

template <class T>
vector<T> fill(vector <T> array, int start, int end, T value);

template <class T>
long long int inner_product(vector<T> a, vector<T> b)
{
	long long int innerProduct = 0;
	for(int i=0; i<a.size(); i++)
	{
		innerProduct+=a[i]*b[i];
	}
	return innerProduct;
}

// 1. First exercise
vector<int> myVector = {5, 2, 3, 1, 8, 7, 10, 8, 6, 5, 2, 4, 7, 4, 8, 6, 7, 1, 2, 3, 7, 4};
int myValue = 10;

// 2. Second
int myStart = 2;
int myEnd = 7;
int myReplaceValue = 10;
vector <int> myFilledArray = fill(myVector, myStart, myEnd, myReplaceValue);

// main
int main()
{
	cout << count(myVector, myValue) << endl;
	cout << inner_product(myVector, myFilledArray) << endl;
}

// Declared functions
template <class T>
int count(vector<T> array, T value)
{
	int count = 0;
	for(auto i: array)
	{
		if(i == value)
			count++;
	}
	return count;
}

template <class T>
vector <T> fill(vector <T> array, int start, int end, T value)
{
	for(int i=start; i<end; i++)
	{
		array[i] = value;
	}
	return array;
}

