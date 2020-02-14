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
	ArrayAlgorithms();

private:

	static const size_t arrSize = 10;

	int arr[arrSize] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* arrPointer = arr;

	array<int, arrSize> arrCs = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };


public:

	inline size_t GetArrSize() const { return arrSize; }
	inline int* GetArr() const { return arrPointer; }
	inline const vector<int>& GetVec() const { return vec; }
	inline const array<int, arrSize>& GetArrCs() const { return arrCs; }

	/*The sum of arr elements.*/
	T Sum(T* arr, size_t arrSize);

	/*The sum of arr elements, recursion.*/
	T SumRecur(T* arr, size_t arrSize);

	/*Binary search.*/
	int BinarySearch(T* arr, size_t arrSize, T searchedElement);

	/*Binary search with vector.*/
	typename vector<T>::const_iterator BinarySearch(const vector<T>& container, T searchedElement);


};

template <class T>
ArrayAlgorithms<T>::ArrayAlgorithms()
{
}

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



