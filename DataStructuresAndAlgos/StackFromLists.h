#pragma once

#include <list> // Standard Library List
#include <string>
class StackFromLists
{
    std::list<std::string> stackList;

public:
    StackFromLists();
    ~StackFromLists();

    void Push(const std::string &str); // Push onto the stack

    std::string Pop(); // Pop from the top

    bool IsEmpty(); // Returns true if stack is empty
    
    size_t GetCount(); // Get the current item count

    void PrintStack(); // Non-ADT operation, more for a testing / debugging purpose
};

