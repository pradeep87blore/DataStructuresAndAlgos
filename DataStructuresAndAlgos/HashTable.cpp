#include "HashTable.h"
#include <memory>
#include "Utils.h"

using namespace std;

HashTable::HashTable()
{
	table_contents.resize(key_size); // Resize the required key size
}


HashTable::~HashTable()
{

}

int HashTable::Hash(TableEntry entry)
{
	return Hash(entry.phoneNumber);	
}

int HashTable::Hash(int64_t phoneNum)
{
	// TODO: Use a more efficient hashing function once we switch to a generic template input type
	// Use a simple modulo operator as the hash function for now
	return phoneNum % key_size; // This ensures that the return value is always within the key space
}



bool HashTable::ReHash()
{
	int new_key_size = Utils::GetInstance()->GetNextPrimeNumber(key_size * 2); // Use a prime number more than twice the current key size

	std::vector<std::list<TableEntry>> new_table;
	new_table.resize(new_key_size); // Create a new table with the new key size

	key_size = new_key_size;

	int iHashKey = 0;
	for (auto hashkeyIterator = begin(table_contents); hashkeyIterator != end(table_contents); hashkeyIterator++) // Outer vector iterator
	{
		for (auto chainIterator = begin(*hashkeyIterator); chainIterator != end(*hashkeyIterator); chainIterator++) // Inner list iterator
		{
			int64_t newHashValue = Hash(*chainIterator);
			new_table[newHashValue].push_back(*chainIterator);
		}
	}

	table_contents = new_table; // Replace the old table with the newly rehashed one
	return true;
}

// Insert into Hash table
bool HashTable::InsertIntoTable(const TableEntry& entry)
{
	//TODO: Check if the value already exists. If it does, overwrite it instead of adding a new entry
	int64_t hashValue = Hash(entry);

	table_contents[hashValue].push_back(entry);
	table_count++;

	return true;
}

// Search / Retrieve from Hash table
bool HashTable::GetTableEntry(int64_t phoneNum, TableEntry &result)
{
	auto chain = table_contents[Hash(phoneNum)];
	
	for (auto iterator = begin(chain); iterator != end(chain); iterator++)
	{
		if ((*iterator).phoneNumber == phoneNum)
		{
			result = (*iterator);
			return true;
		}
	}

	return false; // Element not found
}

// Delete fro Hash table
bool HashTable::DeleteFromTable(int64_t phoneNum)
{
	if (table_contents[Hash(phoneNum)].size() == 0)
	{
		// No entries added to the bucket mapping to the hash key. Hence, return false since the element was not found
		return false;
	}

	auto chain = table_contents[Hash(phoneNum)];
	for (auto chainIterator = begin(chain); chainIterator != end(chain); chainIterator++) // Inner list iterator
	{
		if ((*chainIterator).phoneNumber == phoneNum)
		{
			chain.erase(chainIterator);
			break;
		}
	}
	table_count--;

	return true;
}

// Size of the Hash table
int HashTable::GetCurrentTableSize() // Contains the number of entries present in the hash table (not the same as the key size)
{
	return table_count;
}

// Load factor
float HashTable::GetLoadFactor() // Returs the load factor
{
	return (float)table_count / key_size;
}

void HashTable::PrintHashTable()
{
	int iHashKey = 0;
	for (auto hashkeyIterator = begin(table_contents); hashkeyIterator != end(table_contents); hashkeyIterator++) // Outer vector iterator
	{
		for (auto chainIterator = begin(*hashkeyIterator); chainIterator != end(*hashkeyIterator); chainIterator++) // Inner list iterator
		{
			std::cout << "Hash Key: " << iHashKey << ", Contents: " << *chainIterator << std::endl;
		}
		std::cout << std::endl;
		iHashKey++;
	}
}

// Print the count of the entries at each hash key
void HashTable::PrintHashKeyDistribution()
{
	int iHashKey = 0, iEntryCountPerKey = 0;;
	for (auto hashkeyIterator = begin(table_contents); hashkeyIterator != end(table_contents); hashkeyIterator++) // Outer vector iterator
	{
		iEntryCountPerKey = (*hashkeyIterator).size();
		
		std::cout << "Hash Key : " << iHashKey << ", Chain length: " << iEntryCountPerKey << std::endl;
		iHashKey++;
	}
}

// Clear all entries
void HashTable::ClearAllEntries()
{
	
	for (int iIndex = 0; iIndex < table_contents.size(); iIndex++)
	{
		auto chain = table_contents[iIndex];
		chain.clear(); // Remove all the chains
	}
	table_contents.clear();

}