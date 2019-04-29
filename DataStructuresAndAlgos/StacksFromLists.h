#pragma once

#include <list> // Standard Library List
#include <string>
class StacksFromLists
{
    std::list<std::string> stackList;

    int count = 0;

public:
    StacksFromLists();
    ~StacksFromLists();

    void Push(const std::string &str); // Push onto the stack

    std::string Pop(); // Pop from the top

    bool IsEmpty(); // Returns true if stack is empty
    
    int GetCount(); // Get the current item count

    void PrintStack(); // Non-ADT operation, more for a testing / debugging purpose
};

