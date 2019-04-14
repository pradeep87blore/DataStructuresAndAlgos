#pragma once

#include <random>

class Utils
{
	Utils() {}

	static Utils *instance; // Singleton instance

public:
	~Utils() {}

	static Utils* GetInstance(); // Get the singleton instance

	int GetNextPrimeNumber(int num); // Return the prime number than the passed in number

	// Get a random number between the passed in min and max values
	int64_t GetRandomNumber(int min, int max); // Note: rand() is used for seeding
	
};

