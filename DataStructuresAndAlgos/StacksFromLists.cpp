#include "StacksFromLists.h"
#include <iostream>

using namespace::std;


StacksFromLists::StacksFromLists()
{

}


StacksFromLists::~StacksFromLists()
{

}

// Push onto the stack
void StacksFromLists::Push(const std::string &str)
{
    stackList.push_front(str);
    count++;
}

// Pop from the top
string StacksFromLists::Pop()
{
    if (IsEmpty())
        return std::string(); // Return an empty string

    string res = stackList.front();
    stackList.pop_front();
    count--;

    return res;
}

// Returns true if stack is empty
bool StacksFromLists::IsEmpty()
{
    // list<> doesnt support a count operation. Hence use our internal counter
    if (count == 0)
    {
        return true;
    }

    return false;
}

// Get the current item count
int StacksFromLists::GetCount()
{
    return count;
}

// Non-ADT operation, more for a testing / debugging purpose
void StacksFromLists::PrintStack()
{
    if (IsEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    
    cout << "Printing the stack contents:" << endl;
    for (auto iIndex = begin(stackList); iIndex != end(stackList); iIndex++)
    {
        cout << *iIndex << endl;
    }
}