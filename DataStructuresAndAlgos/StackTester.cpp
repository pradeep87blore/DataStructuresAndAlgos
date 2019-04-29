#include <iostream>
#include "StacksFromLists.h"
#include <string>
#include <sstream>

using namespace::std;

void TestSentenceReverse()
{
    StacksFromLists stack;
    //stack.PrintStack();

    string testSentence = "Lazy dog jumped over a sleeping fox";

    // Split the sentence around the spaces
    istringstream stringstrm(testSentence);
    do {
        string word;
        stringstrm >> word;
        stack.Push(word);
    } while (stringstrm);

    cout << "Original sentence: " << testSentence << endl;

    cout << "Reversed sentence: " << endl;

    while (!stack.IsEmpty())
    {
        cout << stack.Pop() << " ";
    }
    cout << endl;
}
void StackTester()
{
    TestSentenceReverse();

}