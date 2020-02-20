// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*Project to study algorithms and data structures.*/


#include <iostream>
#include "ArrayAlgorithms.h"
#include "ListAlgorithms.h"
#include "Containers.h"

using namespace std;

int main()
{
	/*Create containers.*/
	Containers containersObject;

	/*Array algorithms, variables and containers.*/
	ArrayAlgorithms<int> arrayAlgorithmsObject;
	auto arrSize = containersObject.GetArrSize();
	auto arr = containersObject.GetArr();
	auto vec = containersObject.GetVec();
	auto STLList = containersObject.GetSTLList();

	containersObject.PrintContainer(vec);
	auto shuffleVec = arrayAlgorithmsObject.Shuffle(vec);
	containersObject.PrintContainer(shuffleVec);

	//    auto result = ArrayAlgorithmsObject.Sum(arr, arrSize);
	//    auto result = ArrayAlgorithmsObject.SumRecur(arr, arrSize);
	//    auto result = ArrayAlgorithmsObject.BinarySearch(arr, arrSize, 7);
	//	  auto result = ArrayAlgorithmsObject.BinarySearch(vec, 8);

	//	cout << *result;

	/*List algorithms, variables and containers.*/
	//ListAlgorithms<int> listAlgorithmsObject;

	/*
	auto beginMyForwardList = containersObject.GetBeginMyForwardListSharedPtr();
	containersObject.PrintContainer(beginMyForwardList);
	auto reverseBegin = listAlgorithmsObject.Reverse(beginMyForwardList);
	containersObject.PrintContainer(reverseBegin);

	/*
	int result = listAlgorithmsObject.Sum(beginMyForwardList);
	int resultRecur = listAlgorithmsObject.SumRecur(beginMyForwardList);
	cout << endl << result << endl;
	cout << endl << resultRecur << endl;
	*/



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
