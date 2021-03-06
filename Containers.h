#pragma once

#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <bitset>
#include <memory>
#include <iostream>

using namespace std;

class Containers
{

public:
	/*Constructors and destructors.*/

	Containers();
	~Containers();

	struct MyForwardList
	{
		int value;
		MyForwardList* next;
	};

	struct MyForwardListSharedPtr
	{
		int value;
		shared_ptr<MyForwardListSharedPtr> next;
	};

private:
	/*Private variables.*/

	static const size_t arrSize = 10;

	int arr[arrSize] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* arrPointer = arr;

	array<int, arrSize> STLarr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	list<int> STLList = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	forward_list<int> STLForwardList = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	MyForwardList* beginMyForwardList = nullptr;
	shared_ptr<MyForwardListSharedPtr> beginMyForwardListSharedPtr;
	size_t sizeOfMyForwardList = 10;

	static const size_t bitsetSize = 1000000;
	bitset<bitsetSize> myBitset;

public:
	/*Public variables.*/


private:
	/*Private methods.*/

	void CreateMyForwardList();
	void CreateMyForwardListSharedPtr();
	void DeleteMyForwardList();

public:
	/*Public methods.*/

	/*Getters.*/

	inline size_t GetArrSize() const { return arrSize; }
	inline int* GetArr() const { return arrPointer; }
	inline const vector<int>& GetVec() const { return vec; }
	inline const array<int, arrSize>& GetArrCs() const { return STLarr; }

	inline const list<int>& GetSTLList() const { return STLList; }
	inline const forward_list<int>& GetSTLForwardList() const { return STLForwardList; }
	MyForwardList* GetBeginMyForwardList();
	shared_ptr<MyForwardListSharedPtr> GetBeginMyForwardListSharedPtr();
	inline const size_t GetSizeOfMyForwardList() const { return sizeOfMyForwardList; }

	inline bitset<bitsetSize>& GetMyBitset() { return myBitset; }
	inline const size_t GetBitsetSize() const { return bitsetSize; }

	/*Print containers.*/
	template <typename T>
	void PrintContainer(T* arrPointer, size_t arrSize) const;
	template <typename T>
	void PrintContainer(array<T, arrSize>& STLarr) const;
	template <typename T>
	void PrintContainer(vector<T>& vec) const;
	template <typename T>
	void PrintContainer(list<T>& STLList) const;
	template <typename T>
	void PrintContainer(forward_list<T>& STLForwardList) const;
	void PrintContainer(shared_ptr<MyForwardListSharedPtr> beginMyForwardListSharedPtr) const;

	/*Print indexes of containers for Sieve Of Eratosthenes.*/
	template <typename T>
	void PrintIndexesForSieveOfEratosthenes(vector<T>& vec) const;
	template <size_t N>
	void PrintIndexesForSieveOfEratosthenes(bitset<N>& myBitset) const;
};

template <typename T>
void Containers::PrintContainer(T* arrPointer, size_t arrSize) const
{
	if (!arrSize)
	{
		cout << endl << "Container is empty." << endl;
		return;
	}
	cout << endl;
	for (size_t i = 0; i < arrSize; i++)
	{
		cout << arrPointer[i] << " ";
	}
	cout << endl;
}

template <typename T>
void Containers::PrintContainer(array<T, arrSize>& STLarr) const
{
	if (STLarr.empty())
	{
		cout << endl << "Container is empty." << endl;
		return;
	}
	cout << endl;
	for (T value : STLarr)
	{
		cout << value << " ";
	}
	cout << endl;
}

template <typename T>
void Containers::PrintContainer(vector<T>& vec) const
{
	if (vec.empty())
	{
		cout << endl << "Container is empty." << endl;
		return;
	}
	cout << endl;
	for (T value : vec)
	{
		cout << value << " ";
	}
	cout << endl;
}

template <typename T>
void Containers::PrintContainer(list<T>& STLList) const
{
	if (STLList.empty())
	{
		cout << endl << "Container is empty." << endl;
		return;
	}
	cout << endl;
	for (T value : STLList)
	{
		cout << value << " ";
	}
	cout << endl;
}

template <typename T>
void Containers::PrintContainer(forward_list<T>& STLForwardList) const
{
	if (STLForwardList.empty())
	{
		cout << endl << "Container is empty." << endl;
		return;
	}
	cout << endl;
	for (T value : STLForwardList)
	{
		cout << value << " ";
	}
	cout << endl;
}

template <typename T>
void Containers::PrintIndexesForSieveOfEratosthenes(vector<T>& vec) const
{
	if (vec.empty())
	{
		cout << endl << "Container is empty." << endl;
		return;
	}
	cout << endl;

	for (size_t index = 2; index < vec.size(); index++)
	{
		if (vec[index])
		{
			cout << endl << index;
		}
	}

	cout << endl;
}

template <size_t N>
void Containers::PrintIndexesForSieveOfEratosthenes(bitset<N>& myBitset) const
{
	if (myBitset.size() == 0)
	{
		cout << endl << "Container is empty." << endl;
		return;
	}
	cout << endl;

	for (size_t index = 2; index < myBitset.size(); index++)
	{
		if (myBitset[index] != 0)
		{
			cout << endl << index;
		}
	}

	cout << endl;
}

