#pragma once

#include <bitset>

using namespace std;

class BitSetAlgorithms
{
public:
	/*Public methods.*/

	/*Sedgewick's Sieve of Eratosthenes.*/
	template<size_t N>
	void SieveOfEratosthenes_Sedgewick(bitset<N>& bitArray);
};

template<size_t N>
void BitSetAlgorithms::SieveOfEratosthenes_Sedgewick(bitset<N>& bitArray)
{
	bitArray.set();

	size_t index;

	for (index = 2; index < N; index++)
	{
		if (bitArray[index] == 1)
		{
			for (size_t index_ = index; index_ * index < N; index_++)
			{
				bitArray[index_ * index] = 0;
			}
		}
	}
}


