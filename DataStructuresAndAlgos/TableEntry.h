#pragma once

#include <string>
#include <iostream> 
// This class's objects shall be what is inserted into the hash table
class TableEntry
{

public:
	//TODO: Make the data members private

	int64_t phoneNumber;
	std::string userName;
	std::string emailId;

	TableEntry() = default;
	~TableEntry() = default;
	TableEntry(int64_t phoneNum, const std::string &user_name, const std::string &email_id); // Custom constructor


	friend std::ostream& operator << (std::ostream& out, const class TableEntry& c);

};

