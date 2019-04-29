#include "StackFromVectors.h"
#include <iostream>

using namespace::std;


StackFromVectors::StackFromVectors()
{
}


StackFromVectors::~StackFromVectors()
{
}

// Push onto the stack
void StackFromVectors::Push(const std::string &str)
{
    stackVector.insert(begin(stackVector), str);
}

// Pop from the top
std::string StackFromVectors::Pop()
{
    if (IsEmpty())
        return std::string(); // Return an empty string

    string top = stackVector[0];
    stackVector.erase(begin(stackVector)); // Remove the front element
    return top;
}

// Returns true if stack is empty
bool StackFromVectors::IsEmpty()
{
    return stackVector.empty();
}

// Get the current item count
size_t StackFromVectors::GetCount()
{
    return stackVector.size();
}

// Non-ADT operation, more for a testing / debugging purpose
void StackFromVectors::PrintStack()
{
    if (IsEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Printing the stack contents:" << endl;
    for (auto iIndex = begin(stackVector); iIndex != end(stackVector); iIndex++)
    {
        cout << *iIndex << endl;
    }
}
