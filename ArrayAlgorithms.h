#pragma once

/*Algorithms for arrays and some containers for these algorithms.*/

#include <vector>
#include <array>

using namespace std;

/*Algorithms for arrays.*/

template <class T>
class ArrayAlgorithms
{
public:
	/*Constructors and destructors.*/


private:
	/*Private variables.*/


public:
	/*Public variables.*/


private:
	/*Private methods.*/


public:
	/*Public methods.*/

	/*The sum of arr elements.*/
	T Sum(T* arr, size_t arrSize);

	/*The sum of arr elements, recursion.*/
	T SumRecur(T* arr, size_t arrSize);

	/*Binary search.*/
	int BinarySearch(T* arr, size_t arrSize, T searchedElement);

	/*Binary search with vector.*/
	typename vector<T>::const_iterator BinarySearch(const vector<T>& container, T searchedElement);

	/*Search duplicates*/

	/*Shuffle container.*/


};

template <class T>
int ArrayAlgorithms<T>::BinarySearch(T* arr, size_t arrSize, T searchedElement)
{
	size_t
		first = 0,
		last = arrSize - 1;

	while (first <= last)
	{
		const int middle = first + (last - first) / 2;

		if (searchedElement == arr[middle])
		{
			return middle;
		}

		if (searchedElement < arr[middle])
		{
			last = middle - 1;
		}

		if (searchedElement > arr[middle])
		{
			first = middle + 1;
		}
	}

	return -1;
}

template <class T>
typename vector<T>::const_iterator ArrayAlgorithms<T>::BinarySearch(const vector<T>& container, T searchedElement)
{

	const auto endIt = container.end();

	auto
		first = container.begin(),
		last = endIt;

	if (container.size() == 0
		|| container.front() > searchedElement
		|| container.back() < searchedElement)
	{
		return endIt;
	}

	while (distance(first, last) > 0)
	{
		const auto middle = first + (distance(first, last)) / 2;

		if (searchedElement == *middle)
		{
			return middle;
		}

		if (searchedElement < *middle)
		{
			last = middle;
		}

		if (searchedElement > * middle)
		{
			first = middle;
		}
	}

	return endIt;
}

template <class T>
T ArrayAlgorithms<T>::Sum(T* arr, size_t arrSize)
{
	T total = arr[0];
	for (size_t i = 1; i < arrSize; i++)
	{
		total += arr[i];
	}

	return total;
}

template <class T>
T ArrayAlgorithms<T>::SumRecur(T* arr, size_t arrSize)
{

	T total = arr[arrSize - 1];
	if (arrSize > 1)
	{
		total += SumRecur(arr, arrSize - 1);
	}

	return total;
}



