#include <iostream>
#include <vector>
#include <fstream>

#include <stdlib.h>

using namespace std;

/* -- Data structures, algorithms and applications problems --
*
* @Aclaration
* In this book I assuming a lot of things. Like the 5th problem, only check if the array is sorted from minor to major.
* Or the maximum value of element on the vector's, we assume that is not result on a segmentation fault.
*
* 1. Write a template function count that returns the number of occurrences of value in the array a[0:n-1]. Test your code.
*
* 2. Write a template function fill that sets a[start: end-1] to value. Test your code.
*
* 3. Write a template function inner_product that returns sum i=0, n-1 a[i]*b[i]. Test your code.
*
* 4. Write a template function iota that sets a[i] = value + i, 0 <= i < n. Test your code.
*
* 5. Write a template function is_sorted that returns true if a[0:n-1] is sorted. Test your code.
*
* 6. Write a template function mismatch that returns the smallest i, 0 <= i < n such that a[i] != b[i]. Test your code.
* This problem has ambiguity. Skipped.
*
*/

// Declare functions
template <class T>
long long int count(vector<T> array, T value);

template <class T>
vector<T> fill(vector <T> array, int start, int end, T value);

template <class T>
long long int inner_product(vector<T> a, vector<T> b);

template <class T>
vector <T> iota (vector <T> array);

template <class T>
bool is_sorted(vector <T> &array);

// 1. First exercise
vector<long long int> myVector = {5, 2, 3, 1, 8, 7, 10, 8, 6, 5, 2, 4, 7, 4, 8, 6, 7, 1, 2, 3, 7, 4};
long long int myValue = 10;

// 2. Second
int myStart = 2;
int myEnd = 7;
long long int myReplaceValue = 10;
vector <long long int> myFilledArray = fill(myVector, myStart, myEnd, myReplaceValue);

// 5. Test array
vector<long long int> mySortedVector1 = {1, 2, 3, 4, 5};
vector<long long int> mySortedVector2 = {2, 2, 3, 4, 5};
vector<long long int> mySortedVector3 = {2, 2, 3, 5, 5};
vector<long long int> myUnsortedVector2 = {1, 2, 3, 4, 3};
vector<long long int> myUnsortedVector3 = {3, 2, 3, 4, 5};
vector<long long int> myUnsortedVector4 = {1, 2, 3, 5, 4};


// main
int main()
{
	cout << count(myVector, myValue) << endl;
	cout << inner_product(myVector, myFilledArray) << endl;
	cout << is_sorted(mySortedVector1) << endl;
	cout << is_sorted(mySortedVector2) << endl;
	cout << is_sorted(mySortedVector3) << endl;
	cout << is_sorted(myUnsortedVector2) << endl;
	cout << is_sorted(myUnsortedVector3) << endl;
	cout << is_sorted(myUnsortedVector4) << endl;
}

// Declared functions
template <class T>
long long int count(vector<T> array, T value)
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

template <class T>
vector <T> iota (vector <T> array)
{
    for(int i=0; i<array.size(); i++)
    {
        array[i]+=i;
    }
    return array;
}

template <class T>
bool is_sorted(vector <T> &array)
{
    for(int i=0; i<array.size()-1; i++)
    {
        if(array[i+1]<array[i])
            return false;
    }
    return true;
}

