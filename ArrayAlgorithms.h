#pragma once

/*Algorithms for arrays and some containers for these algorithms.*/

#include <vector>
#include <array>
#include <random>

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
	vector<T> Shuffle(const vector<T>& container);

	/*Bubble sort.*/
	vector<T> BubbleSort(const vector<T>& container);


};

template <class T>
std::vector<T> ArrayAlgorithms<T>::BubbleSort(const vector<T>& container)
{
	auto resultContainer = container;
	if (resultContainer.size() <= 1) return;

	const auto firstConst = resultContainer.begin();
	auto last = resultContainer.end() - 1;

	bool isSwap = true;
	while (isSwap)
	{
		isSwap = false;
		for (auto first = firstConst; first < last; first++)
		{
			if (*first > * (first + 1))
			{
				swap(*first, *(first + 1));
				isSwap = true;
			}
		}
		last--;
	}
}

template <class T>
vector<T> ArrayAlgorithms<T>::Shuffle(const vector<T>& container)
{
	auto resultContainer = container;
	size_t lastIndex = resultContainer.size() - 1;

	random_device rd;
	//	mt19937 generator(rd());
	default_random_engine generator(rd());

	for (size_t index = 0; index <= lastIndex; index++)
	{
		uniform_int_distribution<int> distribution(0, (int)lastIndex);
		size_t randomIndex = distribution(generator);

		if (randomIndex == index)
		{
			if (randomIndex == lastIndex)
			{
				--randomIndex;
			}
			else
			{
				++randomIndex;
			}
		}
		swap(resultContainer[index], resultContainer[randomIndex]);
	}

	return resultContainer;
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



