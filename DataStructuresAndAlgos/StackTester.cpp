#include <iostream>
#include "StackFromLists.h"
#include "StackFromVectors.h"
#include <string>
#include <sstream>

using namespace::std;

void TestSentenceReverse()
{
    //StackFromLists stack;
    StackFromVectors stack;
    //stack.PrintStack();

    string testSentence = "Lazy dog jumped over a sleeping fox";

    // Split the sentence around the spaces
    istringstream stringstrm(testSentence);
    do {
        string word;
        stringstrm >> word;
        if (word.length() < 1) // Dont push blanks
            continue; 
        stack.Push(word);
    } while (stringstrm);

    cout << "Original sentence: \n" << testSentence << endl;

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