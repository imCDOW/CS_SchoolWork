//****************************************************************
// Using the hashT class provided (hashT.h ), which uses quadratic probing to resolve collision, create a hash table to keep track of student IDs and names.
// Write a C++ code to:
// A). Ask the user to enter IDs and names of five students to be added to the hash table.
// B). Calculate the hash index from the student ID using the folding method.
// C). Add the information to the hash table.
// D). Ask the user to enter the student information to be deleted from the hash table.
// E). Remove the information from the hash table.
// F). Print the information.
//****************************************************************
#include <iostream>
using namespace std;
#include "hashT.h"


int main() 
{
    // Make hash table for storing Student structs
    hashT<int> Students(101);
    string Names[5];
    int IDs[5]; //make table to hold names and id to print outside of hash table for reader
    cout << "Please enter the student name and their associated ID in that order. This action will repeat 5 times, two students cannot have the same ID." << endl;

    for (int i = 0; i < 5; i++) {
        string StudentName;
        int StudentID;

        cout << "Please enter the student's name." << endl;
        cin >> StudentName;
        cout << "Please enter the student's ID." << endl;
        cin >> StudentID;

        // implement fold method on hashtable to sort. hashT class should deal w/ collision
        int HTPlacement = Students.FoldMethod(101, StudentID);
        Students.insert(HTPlacement, StudentID);
        Names[i] = StudentName;
        IDs[i] = StudentID; // fill table to print for reader
    }

    // print names / ids to reader to understand the sorting
    cout << endl << "The 5 students names and IDs are: " << endl;
    for (int i = 0; i < 5; i++)
      {
        cout << Names[i] << ": " << IDs[i] << " || ";
      }

    // print hash table
    cout << endl << "The hash table is for the student IDs is: " << endl;
    Students.print();

    // ask user to delete a student, loop for practicality
    cout << endl << "If you wish to remove a student from the list, please enter their ID. To quite removing, please enter -999." << endl;
    int num;
    cin >> num;
    while (num != -999) 
      {
        int HTPlacement = Students.FoldMethod(101, num); // make variable to find where to remove
        Students.remove(HTPlacement, num); // i've gone mad methinks
        
        cout << "If you wish to remove a student from the list, please enter their ID. To quite removing, please enter -999." << endl;
          cin >> num;
      }

    // print hash table for the final time    
    cout << endl << "Your updated hash table for the student IDs is: " << endl;
    Students.print();

    return 0; //finish
};


/*
int HTTemp;
int NUMBERS;
bool tf;
HTTemp = Students.FoldMethod(101, IDs[i]);
NUMBERS = Students.search(HTTemp, IDs[i], tf);

*/