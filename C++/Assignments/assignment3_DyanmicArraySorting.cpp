#include <iostream>
using namespace std;

//Write a program that asks the user to enter the names of students, the number of class meetings, and the number of days the students attended the class using dynamic arrays. The program should then output each student’s name and the attendance rate. 



int main()
{

    // ask for number of students as input, create as variable
    int* numStudents = new int;
    cout << "Enter the number of students: " << endl;
    cin >> *numStudents;

    // ask for number of class meetings as input, create as variable
    int* numClasses = new int;
    cout << "Enter the number of class meetings: " << endl;
    cin >> *numClasses;



    // ask for names of students as input, use students variable as array size
    string* studentNames = new string[*numStudents];
    for (int i = 0; i < *numStudents; i++)
    {
        cout << "enter the name of the student" << endl;
        cin >> studentNames[i];
        // print names of students using for loop
    }

    // ask days of attendance for each student
    // maybe make days <student> attended to a loop to say name
    int* days = new int[*numStudents];
    for (int i = 0; i < *numStudents; i++)
    {
        cout << "Enter the number of days " << studentNames[i] << " attended the class: " << endl;
        cin >> days[i];
    }


    // print names of each students and attendance rate

    cout << "Student Name: " << "   " << "Attendance Rate: " << endl;
    for (int i = 0; i < *numStudents; i++)
    {
        double average = static_cast<double>(days[i]) / *numClasses * 100;
        cout << studentNames[i] << "            " << average << "%" << endl;
    }

    // Delete
    delete numStudents;
    delete numClasses;
    delete[] studentNames;
    delete[] days;

    // Return
    return 0;
}

