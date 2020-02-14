// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*A project to study algorithms. */


#include <iostream>
#include "ArrayAlgorithms.h"
#include "ListAlgorithms.h"

using namespace std;

int main()
{
	/*Array algorithms, variables and containers.*/
	ArrayAlgorithms<int> ArrayAlgorithmsObject;
	auto arrSize = ArrayAlgorithmsObject.GetArrSize();
	auto arr = ArrayAlgorithmsObject.GetArr();
	auto vec = ArrayAlgorithmsObject.GetVec();

	/*List algorithms, variables and containers.*/
	ListAlgorithms<int> ListAlgorithmsObject;
	auto beginMyForwardList = ListAlgorithmsObject.GetBeginMyForwardList();
	while (beginMyForwardList)
	{
		cout << beginMyForwardList->value;
		beginMyForwardList = beginMyForwardList->next;
	}


	//    auto result = ArrayAlgorithmsObject.Sum(arr, arrSize);
	//    auto result = ArrayAlgorithmsObject.SumRecur(arr, arrSize);
	//    auto result = ArrayAlgorithmsObject.BinarySearch(arr, arrSize, 7);
	//	  auto result = ArrayAlgorithmsObject.BinarySearch(vec, 8);

	//	cout << *result;
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
