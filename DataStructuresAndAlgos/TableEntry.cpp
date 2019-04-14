#include "TableEntry.h"

using namespace std;

TableEntry::TableEntry(int64_t phoneNum, const std::string &user_name, const std::string &email_id) // Custom constructor
{
	this->phoneNumber = phoneNum;
	this->emailId = email_id;
	this->userName = user_name;
}

// To support the cout
ostream& operator << (ostream& out, const TableEntry& c)
{
	out << (c.userName);
	out << ", ";
	out << c.phoneNumber;
	out << ", ";
	out << c.emailId;
	return out;
}