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


};

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

