#pragma once

/*Algorithms for lists and some lists (STL and custom) for these algorithms.*/

#include <list>
#include <forward_list>
#include <memory>

using namespace std;

/*Algorithms for lists.*/


template <class T>
class ListAlgorithms
{
public:
	ListAlgorithms();

	struct MyForwardList
	{
		int value;
		MyForwardList* next;
	};

private:

	list<int> STLList = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	forward_list<int> STLForwardList = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	MyForwardList* beginMyForwardList;
	size_t sizeOfMyForwardList = 10;

public:


private:

	void CreateMyForwardList();

public:

	inline const list<int>& GetSTLList() const { return STLList; }
	inline const forward_list<int>& GetSTLForwardList() const { return STLForwardList; }
	inline MyForwardList* GetBeginMyForwardList() const { return beginMyForwardList; }
	inline const size_t GetSizeOfMyForwardList() const { return sizeOfMyForwardList; }


};


template <class T>
ListAlgorithms<T>::ListAlgorithms()
{
	CreateMyForwardList();
}

template <class T>
void ListAlgorithms<T>::CreateMyForwardList()
{
	MyForwardList* tmpPointerToList;
	tmpPointerToList = new MyForwardList;
	tmpPointerToList->value = 0;
	beginMyForwardList = tmpPointerToList;

	for (size_t i = 1; i < sizeOfMyForwardList; i++)
	{
		MyForwardList* pointerToList = new MyForwardList;
		pointerToList->value = (int)i;

		tmpPointerToList->next = pointerToList;
		tmpPointerToList = pointerToList;
	}
	tmpPointerToList->next = nullptr;

	/*Need delete after new.*/
}
