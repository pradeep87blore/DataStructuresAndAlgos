#include "Utils.h"

Utils* Utils::instance;


using namespace std;

Utils* Utils::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Utils();
	}
	return instance;
}

// Return the prime number than the passed in number
int Utils::GetNextPrimeNumber(int number)
{
	int iOuter = 0, iInner = 0, count = 0;
	for (iOuter = number + 1; 1; iOuter++)
	{
		for (iInner = 2, count = 0; iInner <= iOuter; iInner++)
		{
			if (iOuter % iInner == 0)
			{
				count++;
				if (count > 1)
					break; // Since there are more than 1 divisors
			}
		}
		if (count == 1)
		{
			return iOuter;
		}
	}

	return -1;
}

int64_t Utils::GetRandomNumber(int min, int max)
{
	std::mt19937 rng(rand()); // Some seed
	std::uniform_int_distribution<int64_t> gen(min, max); // uniform, unbiased

	return gen(rng);
}