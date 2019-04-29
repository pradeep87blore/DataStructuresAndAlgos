#include "StackFromLists.h"
#include <iostream>

using namespace::std;


StackFromLists::StackFromLists()
{

}


StackFromLists::~StackFromLists()
{

}

// Push onto the stack
void StackFromLists::Push(const std::string &str)
{
    stackList.push_front(str);
}

// Pop from the top
string StackFromLists::Pop()
{
    if (IsEmpty())
        return std::string(); // Return an empty string

    string res = stackList.front();
    stackList.pop_front();

    return res;
}

// Returns true if stack is empty
bool StackFromLists::IsEmpty()
{
    return stackList.empty();
}

// Get the current item count
size_t StackFromLists::GetCount()
{
    return stackList.size();
}

// Non-ADT operation, more for a testing / debugging purpose
void StackFromLists::PrintStack()
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