#pragma once

#include "IntLinkedListNode.h"

class IntLinkedList
{
    IntLinkedListNode* head = nullptr;
    IntLinkedListNode* tail = nullptr;

    int count = 0;
public:
    IntLinkedList();
    ~IntLinkedList();

    // Insert into the list
    void Insert(int iNum, int iPos = 0);

    // Push to the end
    void PushBack(int iNum);

    // Push to the front
    void PushFront(int iNum);

    // Remove an element based on the position
    void DeleteElement(int iPos);

    // Get an element at pos
    int GetElementAt(int iPos) const;

    // Pop front
    int PopFront();

    // Pop back
    int PopBack();

    // Is Empty
    bool IsEmpty() const;

    // Count of elements
    int GetCount() const;
};

