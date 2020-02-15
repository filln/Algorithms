#pragma once

/*Algorithms for lists and some lists (STL and custom) for these algorithms.*/

#include <list>
#include <forward_list>
#include <memory>
#include <iostream>

using namespace std;

/*Algorithms for lists.*/


template <class T>
class ListAlgorithms
{
public:
	ListAlgorithms();
	~ListAlgorithms();

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

	list<int> STLList = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	forward_list<int> STLForwardList = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	MyForwardList* beginMyForwardList = nullptr;
	shared_ptr<MyForwardListSharedPtr> beginMyForwardListSharedPtr;
	size_t sizeOfMyForwardList = 10;

public:


private:

	void CreateMyForwardList();
	void CreateMyForwardListSharedPtr();
	void DeleteMyForwardList();

public:

	inline const list<int>& GetSTLList() const { return STLList; }
	inline const forward_list<int>& GetSTLForwardList() const { return STLForwardList; }
	MyForwardList* GetBeginMyForwardList();
	shared_ptr<MyForwardListSharedPtr> GetBeginMyForwardListSharedPtr();
	inline const size_t GetSizeOfMyForwardList() const { return sizeOfMyForwardList; }


};

template <class T>
ListAlgorithms<T>::ListAlgorithms()
{
}

template <class T>
ListAlgorithms<T>::~ListAlgorithms()
{
	DeleteMyForwardList();
}

template <class T>
void ListAlgorithms<T>::CreateMyForwardList()
{
	MyForwardList* tmpPointerToList = new MyForwardList;
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
}

template <class T>
void ListAlgorithms<T>::CreateMyForwardListSharedPtr()
{
	auto tmpPointerList = make_shared<MyForwardListSharedPtr>();
	tmpPointerList->value = 0;
	beginMyForwardListSharedPtr = tmpPointerList;
	for (size_t i = 1; i < sizeOfMyForwardList; i++)
	{
		auto pointerToList = make_shared<MyForwardListSharedPtr>();
		pointerToList->value = (int)i;

		tmpPointerList->next = pointerToList;
		tmpPointerList = pointerToList;
	}
	tmpPointerList->next = nullptr;
}

template <class T>
typename ListAlgorithms<T>::MyForwardList* ListAlgorithms<T>::GetBeginMyForwardList()
{
	CreateMyForwardList();
	return beginMyForwardList;
}

template <class T>
shared_ptr<typename ListAlgorithms<T>::MyForwardListSharedPtr> ListAlgorithms<T>::GetBeginMyForwardListSharedPtr()
{
	CreateMyForwardListSharedPtr();
	return beginMyForwardListSharedPtr;
}

template <class T>
void ListAlgorithms<T>::DeleteMyForwardList()
{
	size_t count = 0;
	while (beginMyForwardList)
	{
		MyForwardList* tmpPointer = beginMyForwardList->next;
		delete beginMyForwardList;
		beginMyForwardList = tmpPointer;
		count++;
	}
	if (count)
	{
		cout << endl << "Delete " << count << " nodes in ~ListAlgorithms()" << endl;
	}
}
