#include <iostream>
#include "IntLinkedList.h"

using namespace::std;


void PrintLL(const IntLinkedList& ll)
{
    int iCount = ll.GetCount();

    for (int iIndex = 0; iIndex < iCount; iIndex++)
    {
        cout << "Element at node : " << iIndex << " : " << ll.GetElementAt(iIndex) << endl;
    }
}
void TestLinkedLists()
{
    IntLinkedList ll;
    ll.Insert(1);
    ll.Insert(2);
    ll.Insert(3);
    ll.Insert(4);
    ll.Insert(5);
    ll.Insert(6);
    ll.Insert(7, 3);
    ll.PushBack(8);
    ll.PushFront(9);
    PrintLL(ll);
}