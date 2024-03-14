#include<iostream>
using namespace std;

class student
{

public:
    string name;
    string grade;
    string age;

    student() : name(" no name"), grade("no grade"), age("no age"){}
    student(string name, string grade, string age) : name(name), grade(grade), age(age){}

    void PrintInfo()
    {
        cout << name << grade << age;  
    }
};

int main()
{
    student student1;
    student student2(" caleb", " 12", " 180");

    student1.PrintInfo();
    cout << endl;

    student2.PrintInfo();
    cout << endl;

    return 0;
};