#pragma once

/*Algorithms for lists and some lists (STL and custom) for these algorithms.*/

#include <list>
#include <forward_list>
#include <memory>
#include <iostream>
#include "Containers.h"

using namespace std;

/*Algorithms for lists.*/


template <class T>
class ListAlgorithms
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

	int Sum(shared_ptr<Containers::MyForwardListSharedPtr> beginMyForwardListSharedPtr);
	int SumRecur(shared_ptr<Containers::MyForwardListSharedPtr> beginMyForwardListSharedPtr);

	shared_ptr<Containers::MyForwardListSharedPtr> Reverse(shared_ptr<Containers::MyForwardListSharedPtr> beginMyForwardListSharedPtr);

	/*Search duplicates*/

	/*Shuffle container.*/


};

template <class T>
shared_ptr<Containers::MyForwardListSharedPtr> ListAlgorithms<T>::Reverse(shared_ptr<Containers::MyForwardListSharedPtr> beginMyForwardListSharedPtr)
{
	shared_ptr<Containers::MyForwardListSharedPtr>
		current = beginMyForwardListSharedPtr,
		temp,
		tempReverse = nullptr;
	while (current)
	{
		temp = current->next;
		current->next = tempReverse;
		tempReverse = current;
		current = temp;
	}

	return tempReverse;
}

template <class T>
int ListAlgorithms<T>::SumRecur(shared_ptr<Containers::MyForwardListSharedPtr> beginMyForwardListSharedPtr)
{
	if (!beginMyForwardListSharedPtr)
	{
		return -1;
	}

	auto beginTmp = beginMyForwardListSharedPtr;
	int sum = beginTmp->value;

	if (beginTmp->next)
	{
		sum += SumRecur(beginTmp->next);
	}
	return sum;
}

template <class T>
int ListAlgorithms<T>::Sum(shared_ptr<Containers::MyForwardListSharedPtr> beginMyForwardListSharedPtr)
{
	if (!beginMyForwardListSharedPtr)
	{
		return -1;
	}

	auto beginTmp = beginMyForwardListSharedPtr;
	int sum = beginTmp->value;

	while (beginTmp->next)
	{
		sum += beginTmp->next->value;
		beginTmp = beginTmp->next;
	}
	return sum;
}

