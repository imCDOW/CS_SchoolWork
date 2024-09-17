#include <iostream>
using namespace std;
#include "arrayListType.h"

// Add a recursive binary search algorithm as a member function in the class arrayListType described in Chapter 3. Write a program to ask the user to enter 10 integers, create an array-based list including the 10 integers, and search an item specified by the user
// Part 1 = make recursive binary search algorithm function.
// part 2 = make a sorting function (sorting can be approached different ways, not just a function)
// Part 3 = in main, make array based list using arrayListType class, using a loop, get 10 int from user, use sorting function on list, use new function to search for an item.
int main() 
{
    arrayListType<int> list;
    cout << "This code makes an unsorted array of 10 integers, then searches the array using a recursive binary search algorithm" << endl;

    cout << "Please enter 10 integers" << endl;
    int num;
    for (int i = 0; i < 10; i++) {
        cin >> num;
        list.insertEnd(num);
    }

    list.sort();

    cout << "Enter a number to search for, enter -999 to stop searching: " << endl;
    while (true) {
        cin >> num;
        if (num == -999) {
            break; // Exit loop if -999 is entered
        }
        int first = 0;
        int last = 9;
        list.binarySearch(num, first, last);
    }

    return 0;
}