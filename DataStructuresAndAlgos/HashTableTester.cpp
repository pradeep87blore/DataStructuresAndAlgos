
#include "HashTable.h"
#include <random>
#include <limits>
#include <algorithm>
#include "Utils.h"

using namespace std;

std::vector<std::string> names = { "Ram", "Raj", "Rohan", "Praveen", "Suma", "Gita", "Sita", "Raju", "Mohan", "Rama" };

void InsertFindDeleteIntoHashTable();

void BulkInsertionRehashTest();

TableEntry CreateRandomEntry()
{
	TableEntry newTableEntry;
	newTableEntry.phoneNumber = Utils::GetInstance()->GetRandomNumber(0, 9999999999);
	newTableEntry.userName = names[Utils::GetInstance()->GetRandomNumber(0, 9)] + " " 
		+ names[Utils::GetInstance()->GetRandomNumber(0, 9)];
	newTableEntry.emailId = newTableEntry.userName + "@gmail.com";
	return newTableEntry;
}


void TestHashTable()
{
	
	BulkInsertionRehashTest();

	for (int iIndex = 0; iIndex < 10; iIndex++)
	{
		InsertFindDeleteIntoHashTable();
	}


}

void BulkInsertionRehashTest()
{
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Bulk Insertion and Rehash test" << endl;

	HashTable hashTable;

	for (int iIndex = 0; iIndex < 200; iIndex++)
	{
		hashTable.InsertIntoTable(CreateRandomEntry());

		// cout << "Current load factor: " << hashTable.GetLoadFactor() << endl;
	}

	hashTable.PrintHashTable();

	hashTable.PrintHashKeyDistribution();

	hashTable.ReHash();

	cout << endl << "Post a rehash: " << endl;

	hashTable.PrintHashTable();

	hashTable.PrintHashKeyDistribution();

	// TODO: Explore a bar plot option for C++ and show the distribution before and after the rehashing
	// This can also be useful to show the distribution of various hashing functions.
}

void InsertFindDeleteIntoHashTable()
{
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Insert, Fetch and delete operation test" << endl;

	HashTable hashTable;

	cout << "Current hash table size : " << hashTable.GetCurrentTableSize() << endl;
	auto randomEntry = CreateRandomEntry();
	if (hashTable.InsertIntoTable(randomEntry))
	{
		cout << "Size after inserting " << randomEntry << " is " << hashTable.GetCurrentTableSize() << endl;
	}
	else
	{
		cout << "Failed to insert " << randomEntry << endl;
	}

	// Fetching from the hash table:

	TableEntry fetchedEntry;
	if (hashTable.GetTableEntry(randomEntry.phoneNumber, fetchedEntry))
	{
		cout << "Fetched the entry " << fetchedEntry << " from the hash table" << endl;

		if (hashTable.DeleteFromTable(fetchedEntry.phoneNumber))
		{
			cout << "Deleted the entry " << fetchedEntry << " from the hash table" << endl;
			cout << "New count is : " << hashTable.GetCurrentTableSize() << endl;
		}
		else
		{
			cout << "Failed to delete the existing entry from the table" << endl;
		}
	}
	else
	{
		cout << "Failed to get any matching entries " << endl;
	}
}
