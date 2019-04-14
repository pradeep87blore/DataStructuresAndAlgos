#pragma once

#include <vector>
#include <list>
#include "TableEntry.h" // TODO: Later, change this class to accept templates
class HashTable
{
private:
	int key_size = 109; // The current key size (use a prime number)
	int table_count = 0; // The current set of elements in the table

	/* Using the separate chaining technique for collision resolution: */
	/* This means that we will have an array of keys and a bucket (linked list) mapping to each key */
	/* Here, we are using the vector to replace a C Style array and a list to replace a linked list */
	std::vector<std::list<TableEntry>> table_contents; 

	int Hash(TableEntry entry);
	int Hash(int64_t phoneNum);
	
public:
	HashTable();
	~HashTable();
	bool ReHash();

	// Insert into Hash table
	bool InsertIntoTable(const TableEntry &entry);

	// Search / Retrieve from Hash table
	bool GetTableEntry(int64_t phoneNum, TableEntry& result);

	// Delete fro Hash table
	bool DeleteFromTable(int64_t phoneNum);

	// Size of the Hash table
	int GetCurrentTableSize(); // Contains the number of entries present in the hash table (not the same as the key size)

	// Load factor
	float GetLoadFactor(); // Returs the load factor

	// Print the contents of the Hash table (utility function)
	void PrintHashTable();

	// Print the count of the entries at each hash key
	void PrintHashKeyDistribution();

	// Clear all entries
	void ClearAllEntries();
};


