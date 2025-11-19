#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef RECORD_H
#define RECORD_H


struct Day {
    float Input;  // Array for user input (filled w/ 0's)
    string Note;      // Array for user notes
    int Date;          // Date for the day
    int Month;
    int Year;
    int Hour;
    int Minute;
    string AMPM;

    Day* Next = nullptr; // Pointer to the next node in the list
    Day* Prev = nullptr; // Pointer to the previous node in the list
};

class RecordedList {
public:

    void SetCurrentTime();
    void SearchDate(int n);
    //Function to find the first Day node in list with a given date
    void DeleteList();
    //Function to delete the list
    void NewDay();
    //Function to create a new day to add to the linked list
    void WriteInput();
    //Function to write input to the list
    void WriteGlucose();
    //Function to record glucose levels
    void WriteNotes();
    //Function to record notes

    void DisplayCurrentDay();
    //Function to display the current day's information
    void DisplayCurrentWeek();
    void DisplayCurrentMonth();
    void DisplayAll();

    void DisplaySearchedDay();
    void SaveSearchedDay();
    void SaveDay();
    void SaveWeek();
    void SaveMonth();
    void SaveAll();
    void ResetList();
    void SaveMenu();
    void RecordMain();
    // Constructor
    RecordedList() : Head(nullptr), Current(nullptr){
        SetCurrentTime();
    }



    // Destructor
    ~RecordedList() {
        DeleteList();
    }

private:
    Day* Head;    // Pointer to the first day in the list
    Day* Current; // Pointer to the current day
    int UserDate;
    int UserMonth;
    int UserYear;
    int UserHour;
    int UserMinute;
    string UserAMPM;
    int Count;
};

void RecordedList::SetCurrentTime() {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    //Date,Month,Year
    UserDate = localTime->tm_mday;
    UserMonth = localTime->tm_mon + 1;
    UserYear = localTime->tm_year + 1900;

    //HH:MM + AM/PM
    UserHour = localTime->tm_hour;
    UserMinute = localTime->tm_min;
    UserAMPM = (UserHour >= 12) ? "PM" : "AM";

    //Determine AM/PM
    if (UserHour == 0) {
        UserHour = 12;
    } else if (UserHour > 12) {
        UserHour -= 12;
    }
    //print data
    cout << "Date: " << UserDate << " " << UserMonth << " " << UserYear << endl;
    cout << "Time: " << UserHour << ":" << UserMinute << " " << UserAMPM << endl;
}


void RecordedList::SearchDate(int n) {
    Current = Head;
    while (Current != nullptr) {
        if (Current -> Date == n) {
            return; //sets current to the 1st instance of a note of n date
        }
        Current = Current->Next; //otherwise, traverse entire list
    }

    if (Current == nullptr) {
        cout << "Day not found" << endl;
    }
}



void RecordedList::DeleteList() {
    Day* temp = Head;
    while (temp) {
        Day* toDelete = temp;
        temp = temp->Next;
        delete toDelete;
    }
    Head = nullptr;
    Current = nullptr;
}



void RecordedList::NewDay() {
    ResetList();
    SetCurrentTime();
    Day* newDay = new Day();
    newDay->Date = UserDate;  // Set date for sorting list
    newDay->Month = UserMonth;
    newDay->Year = UserYear;
    newDay->Hour = UserHour;
    newDay->Minute = UserMinute;
    newDay->AMPM = UserAMPM;

    // Insert into list
    if (Head == nullptr) {  // List is empty
        Head = newDay;
        Current = newDay; // Optionally set Current to the first node
    } else {
        // Find the correct position to insert (sorted by date)
        Day* temp = Head;
        while (temp->Next != nullptr) {
            temp = temp->Next;
        }
        temp->Next = newDay;
        newDay->Prev = temp;
    }

    cout << "Would you like to record your glucose level for today? Please enter 1 for yes or 2 for no." << endl;
    int choice;
    cin >> choice;

    while (choice < 1 || choice > 2) {
        cout << "Please enter a valid choice." << endl;
        cin >> choice;
    }

    if (choice == 1) {
        Current = newDay; // Set Current to the newly added day
        WriteInput();
        Count++;
    } else if (choice == 2) {
        delete newDay;
        cout << "No input recorded for today." << endl;
    }
}

// Write input to the current day
void RecordedList::WriteInput() {
    if (Current == nullptr) {
        cout << "Error: Current node is null. No input can be recorded." << endl;
        return;
    }

    WriteGlucose();

    cout << "Would you like to record a note for this recording as well? Please enter 1 for yes or 2 for no." << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        WriteNotes();
    }
}

void RecordedList::WriteGlucose() {
    while (true) {
        cout << "Please enter your glucose level recording: " << endl;
        float GlucoseLevel = 0;
        cin >> GlucoseLevel;
        cout << "Your recorded glucose level is: " << GlucoseLevel << " Is that correct? Please enter 1 for yes or 2 for no." << endl;
        int choice = 0;
        cin >> choice;
        if (choice == 1) {
            cout << "Thank you, your glucose level has been recorded as " << GlucoseLevel << endl;
            Current -> Input = GlucoseLevel;
            break;
        }
        else {
            cout << "Input not confirmed, please try again" << endl;
        }
    }

}

void RecordedList::WriteNotes() {
    while (true) {
        cout << "Please enter your note for the recording: " << endl;
        string note;
        cin.ignore();
        getline(cin, note);

        cout << "Your recorded note is: \"" << note << "\". Is that correct? Please enter 1 for yes or 2 for no." << endl;
        int choice = 0;
        cin >> choice;

        if (choice == 1) {
            cout << "Thank you, your note has been recorded as: \"" << note << "\"" << endl;
            Current->Note = note;
            return; // Exit the loop once the input is confirmed
        } else {
            cout << "Input not confirmed, please try again." << endl;
        }
    }
}


// Display the current day's data
void RecordedList::DisplayCurrentDay()  {
    Current = Head;
    if (Current == nullptr) {
        cout << "Enter data to start! " << endl;
        return;
    }
    cout << "Here are all the inputs for today:" << endl;

    while(Current -> Next != nullptr) { // traverse to end of list
        if (Current -> Date == UserDate) { //only print if the current day is = the node's date
            cout << "Date: " << Current->Date << "-" << Current->Month << "-" << Current->Year << endl;
            cout << "Time: " << Current->Hour << ":" << Current->Minute << " " << Current->AMPM << endl;
            cout << "Glucose level recording: " << Current -> Input << endl;
            cout << " Notes: " << Current -> Note << endl;
            Current = Current -> Next; //advance current
        }
    }
}

void RecordedList::DisplayCurrentWeek() {
    if (Head == nullptr) {
        cout << "No data recorded yet." << endl;
        return;
    }

    cout << "Displaying recordings for the current week:" << endl;
    Day* temp = Head;
    while (temp != nullptr) {
        if (temp->Year == UserYear && temp->Month == UserMonth && temp->Date >= UserDate - 6 && temp->Date <= UserDate) {
            cout << "Date: " << temp->Date << "-" << temp->Month << "-" << temp->Year << endl;
            cout << "Time: " << temp->Hour << ":" << (temp->Minute < 10 ? "0" : "") << temp->Minute << " " << temp->AMPM << endl;
            cout << "Glucose level: " << temp->Input << endl;
            cout << "Note: " << temp->Note << endl;
            cout << "-----------------------------" << endl;
        }
        temp = temp->Next;
    }
}

void RecordedList::DisplayCurrentMonth() {
    if (Head == nullptr) {
        cout << "No data recorded yet." << endl;
        return;
    }

    cout << "Displaying recordings for the current month:" << endl;
    Day* temp = Head;
    while (temp != nullptr) {
        if (temp->Year == UserYear && temp->Month == UserMonth) {
            cout << "Date: " << temp->Date << "-" << temp->Month << "-" << temp->Year << endl;
            cout << "Time: " << temp->Hour << ":" << (temp->Minute < 10 ? "0" : "") << temp->Minute << " " << temp->AMPM << endl;
            cout << "Glucose level: " << temp->Input << endl;
            cout << "Note: " << temp->Note << endl;
            cout << "-----------------------------" << endl;
        }
        temp = temp->Next;
    }
}

void RecordedList::DisplayAll() {
    if (Head == nullptr) {
        cout << "No data recorded yet." << endl;
        return;
    }

    cout << "Displaying all recordings:" << endl;
    Day* temp = Head;
    while (temp != nullptr) {
        cout << "Date: " << temp->Date << "-" << temp->Month << "-" << temp->Year << endl;
        cout << "Time: " << temp->Hour << ":" << (temp->Minute < 10 ? "0" : "") << temp->Minute << " " << temp->AMPM << endl;
        cout << "Glucose level: " << temp->Input << endl;
        cout << "Note: " << temp->Note << endl;
        cout << "-----------------------------" << endl;
        temp = temp->Next;
    }
}



inline void RecordedList::DisplaySearchedDay() {
    Current = Head;
    cout << "Please enter a day to search for: " << endl;
    int day;
    cin >> day;
    SearchDate(day);
    while(Current -> Next != nullptr) { // traverse to end of list
        if (Current -> Date == day) { //only print if the searched day is = the node's date
            cout << "Date: " << Current->Date << "-" << Current->Month << "-" << Current->Year << endl;
            cout << "Time: " << Current->Hour << ":" << Current->Minute << " " << Current->AMPM << endl;
            cout << "Glucose level recording: " << Current -> Input << endl;
            cout << " Note: " << Current -> Note << endl;
            Current = Current -> Next; //advance current
        }
    }
}

void RecordedList::SaveSearchedDay() {
    if (Head == nullptr) {
        cout << "No day to save! " << endl;
        return;
    }

    cout << "Please enter the day, month, and year to save (DD MM YYYY): ";
    int day, month, year;
    cin >> day >> month >> year;

    // Open file for saving
    ofstream outFile("SearchedDay.txt");
    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return;
    }

    bool found = false;
    Day* temp = Head;
    while (temp != nullptr) {
        if (temp->Date == day && temp->Month == month && temp->Year == year) {
            found = true;
            outFile << "Date: " << temp->Date << "-" << temp->Month << "-" << temp->Year << endl;
            outFile << "Time: " << temp->Hour << ":" << temp->Minute << " " << temp->AMPM << endl;
            outFile << "Glucose level recording: " << temp->Input << endl;
            outFile << "Note: " << temp->Note << endl;
            outFile << "-----------------------------" << endl;
        }
        temp = temp->Next;
    }

    if (found) {
        cout << "Nodes with the date " << day << "-" << month << "-" << year << " have been saved to SearchedDay.txt." << endl;
    } else {
        cout << "No nodes with the specified date were found." << endl;
    }

    outFile.close();
}

void RecordedList::SaveDay() {
    if (Head == nullptr) {
        cout << "No data recorded to save." << endl;
        return;
    }

    ofstream outFile("CurrentDay.txt");
    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return;
    }

    Day* temp = Head;
    while (temp != nullptr) {
        if (temp->Date == UserDate && temp->Month == UserMonth && temp->Year == UserYear) {
            outFile << "Date: " << temp->Date << "-" << temp->Month << "-" << temp->Year << endl;
            outFile << "Time: " << temp->Hour << ":" << (temp->Minute < 10 ? "0" : "") << temp->Minute << " " << temp->AMPM << endl;
            outFile << "Glucose level: " << temp->Input << endl;
            outFile << "Note: " << temp->Note << endl;
            outFile << "-----------------------------" << endl;
        }
        temp = temp->Next;
    }
    outFile.close();
    cout << "Current day's data saved to CurrentDay.txt." << endl;
}

void RecordedList::SaveWeek() {
    if (Head == nullptr) {
        cout << "No data recorded to save." << endl;
        return;
    }

    ofstream outFile("CurrentWeek.txt");
    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return;
    }

    Day* temp = Head;
    while (temp != nullptr) {
        if (temp->Year == UserYear && temp->Month == UserMonth && temp->Date >= UserDate - 6 && temp->Date <= UserDate) {
            outFile << "Date: " << temp->Date << "-" << temp->Month << "-" << temp->Year << endl;
            outFile << "Time: " << temp->Hour << ":" << (temp->Minute < 10 ? "0" : "") << temp->Minute << " " << temp->AMPM << endl;
            outFile << "Glucose level: " << temp->Input << endl;
            outFile << "Note: " << temp->Note << endl;
            outFile << "-----------------------------" << endl;
        }
        temp = temp->Next;
    }
    outFile.close();
    cout << "Current week's data saved to CurrentWeek.txt." << endl;
}

void RecordedList::SaveMonth() {
    if (Head == nullptr) {
        cout << "No data recorded to save." << endl;
        return;
    }

    ofstream outFile("CurrentMonth.txt");
    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return;
    }

    Day* temp = Head;
    while (temp != nullptr) {
        if (temp->Year == UserYear && temp->Month == UserMonth) {
            outFile << "Date: " << temp->Date << "-" << temp->Month << "-" << temp->Year << endl;
            outFile << "Time: " << temp->Hour << ":" << (temp->Minute < 10 ? "0" : "") << temp->Minute << " " << temp->AMPM << endl;
            outFile << "Glucose level: " << temp->Input << endl;
            outFile << "Note: " << temp->Note << endl;
            outFile << "-----------------------------" << endl;
        }
        temp = temp->Next;
    }
    outFile.close();
    cout << "Current month's data saved to CurrentMonth.txt." << endl;
}

void RecordedList::SaveAll() {
    if (Head == nullptr) {
        cout << "No data recorded to save." << endl;
        return;
    }

    ofstream outFile("AllRecordings.txt");
    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return;
    }

    Day* temp = Head;
    while (temp != nullptr) {
        outFile << "Date: " << temp->Date << "-" << temp->Month << "-" << temp->Year << endl;
        outFile << "Time: " << temp->Hour << ":" << (temp->Minute < 10 ? "0" : "") << temp->Minute << " " << temp->AMPM << endl;
        outFile << "Glucose level: " << temp->Input << endl;
        outFile << "Note: " << temp->Note << endl;
        outFile << "-----------------------------" << endl;
        temp = temp->Next;
    }
    outFile.close();
    cout << "All recordings saved to AllRecordings.txt." << endl;
}

inline void RecordedList::ResetList() {
    if (Count == 50) {
        SaveAll();
        DeleteList();
        Count = 0;
        Head = nullptr;
        Current = nullptr;
    }
}


inline void RecordedList::SaveMenu() {
    cout << "Welcome to the save menu! " << endl;
    int i = 0; // Menu option

    while (true) { // Infinite loop, break only when user chooses to quit
        cout << "\nPlease select an option: " << endl;
        cout << "|| 1. Save Current Day || 2. Save latest Week || 3. Save latest Month || 4. Save All || 5. Quit ||" << endl;
        cin >> i;

        // Validate user input
        if (i < 1 || i > 5) {
            cout << "Please enter a Number 1-5 " << endl;
        }

        // Handle menu options
        switch (i) {
            case 1:
                cout << "1. Save Current Day" << endl;
                SaveDay();
            break;
            case 2:
                cout << "2. Save latest Week" << endl;
                SaveWeek();
            break;
            case 3:
                cout << "3. Save latest Month" << endl;
                SaveMonth();
            break;
            case 4:
                cout << "4. Save All" << endl;
                SaveAll();
            break;
            case 5:
                cout << "Goodbye!" << endl;
            break; // Exit the function and loop
            default: ;
        }
    }
}


void RecordedList::RecordMain() {
    cout << "You are debugging the Record function" << endl;
    int i = 0; // Menu option

    while (true) { // Infinite loop, break only when user chooses to quit
        cout << "\nPlease select an option: " << endl;
        cout << "|| 1. Record New Input || 2. View Today's recordings || 3. Search for a given Day's recordings || 4. Save Recordings to Files || 5. Quit ||" << endl;
        cin >> i;

        // Validate user input
        if (i < 1 || i > 5) {
            cout << "Please enter a Number 1-5 " << endl;
        }

        // Handle menu options
        switch (i) {
            case 1:
                cout << "1. Record New Input" << endl;
            NewDay();
            break;
            case 2:
                cout << "2. View Today's recordings" << endl;
            DisplayCurrentDay();
            break;
            case 3:
                cout << "3. Search for a given Day's recordings" << endl;
            DisplaySearchedDay();
            break;
            case 4:
                cout << "4. Save Recordings to Files" << endl;
            SaveSearchedDay(); // Assuming this is implemented
            break;
            case 5:
                cout << "Goodbye!" << endl;
            return; // Exit the function and loop
        }
    }
}

#endif