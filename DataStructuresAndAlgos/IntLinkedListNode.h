#pragma once
class IntLinkedListNode
{
    
public:
    IntLinkedListNode(int iNum, IntLinkedListNode* nextNode = nullptr);
    ~IntLinkedListNode();

    int data;
    IntLinkedListNode* next;
};

