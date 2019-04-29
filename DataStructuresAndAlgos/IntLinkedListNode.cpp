#include "IntLinkedListNode.h"



IntLinkedListNode::IntLinkedListNode(int iNum, IntLinkedListNode* nextNode)
{
    this->data = iNum;
    this->next = nextNode;
}


IntLinkedListNode::~IntLinkedListNode()
{
}
