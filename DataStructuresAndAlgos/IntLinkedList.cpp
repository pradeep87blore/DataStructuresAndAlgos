#include "IntLinkedList.h"



IntLinkedList::IntLinkedList()
{
}


IntLinkedList::~IntLinkedList()
{
}


// Insert into the list
void IntLinkedList::Insert(int iNum, int iPos)
{
    if ((iPos > count) || (iPos < 0))
    {
        // Error. TODO: Throw an exception here
        return;
    }

    if (head == nullptr) // Empty list
    {
        head = new IntLinkedListNode(iNum);
        tail = head;
        count++;
        return;
    }

    if (iPos == count) // Insert after the current last node
    {
        if (head == tail) // Only one node
        {
            tail->next = new IntLinkedListNode(iNum);
            count++;
            return;
        }
        tail->next = new IntLinkedListNode(iNum);
        tail = tail->next;        
    }

    if (iPos == 0) // Insert at the beginning
    {
        auto tempNode = head;        
        head = new IntLinkedListNode(iNum, tempNode);
        count++;
        return;
    }

    auto tempNode = head;
    for (int iIndex = 0; iIndex < iPos - 1; iIndex++)
    {
        tempNode = tempNode->next;

        if (tempNode == nullptr) // Error, since this scenario cant be encountered
            return; // TODO: Throw an exception here
    }

    tempNode->next = new IntLinkedListNode(iNum, tempNode->next);
    count++;
}

// Push to the end
void IntLinkedList::PushBack(int iNum)
{
    Insert(iNum, count);
}

// Push to the front
void IntLinkedList::PushFront(int iNum)
{
    Insert(iNum);
}

// Remove an element based on the position
void IntLinkedList::DeleteElement(int iPos)
{
    //if ((IsEmpty()) || (iPos > count - 1))
    //{
    //    return; // TODO: Thrown an exception here
    //}

    //if (iPos == 0) // Delete the head
    //{
    //    auto temp = head;

    //    head = head->next;

    //    if (head == nullptr) // There was only one node earlier
    //        tail = nullptr;
    //    else if (head->next == nullptr) // Now, there is only one node left. Set the tail to point to it.
    //        tail = head;

    //    count--;
    //    delete temp; // Delete the current head

    //    
    //    
    //}
    //if (iPos == count - 1)
    //{
    //    return tail->data;
    //}
}

// Get an element at pos
int IntLinkedList::GetElementAt(int iPos) const
{
    if ((IsEmpty()) || (iPos > count - 1))
    {
        return -1; // TODO: Thrown an exception here
    }
    if (iPos == 0)
    {
        return head->data;
    }
    if (iPos == count - 1)
    {
        return tail->data;
    }

    auto temp = head;

    for (int iIndex = 0; iIndex < iPos; iIndex++)
    {
        temp = temp->next;
    }

    return temp->data;
}

// Pop front
int IntLinkedList::PopFront()
{
    return -1; // TODO: Implement
}

// Pop back
int IntLinkedList::PopBack()
{
    return -1; // TODO: Implement
}

// Is Empty
bool IntLinkedList::IsEmpty() const
{
    return (head == nullptr);
}

// Count of elements
int IntLinkedList::GetCount() const
{
    return count;
}