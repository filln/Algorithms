// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*Project to study algorithms and data structures.*/


#include <iostream>
#include "ArrayAlgorithms.h"
#include "ListAlgorithms.h"
#include "Containers.h"
#include "BitSetAlgorithms.h"

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

	//vector<bool> sieveVec = arrayAlgorithmsObject.SieveOfEratosthenes_Sedgewick(1000000);
	//containersObject.PrintIndexesForSieveOfEratosthenes(sieveVec);
	BitSetAlgorithms bitsetAlgorithms;
	bitsetAlgorithms.SieveOfEratosthenes_Sedgewick(containersObject.GetMyBitset());
	containersObject.PrintIndexesForSieveOfEratosthenes(containersObject.GetMyBitset());


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
