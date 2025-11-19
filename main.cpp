#include <iostream>
#include "Record.h"
#include "User.h"

using namespace std;

int main() {
    User NewUser;
    RecordedList MyList;
    cout << "Hello, you are debugging the Glucose app!" << endl;
    int i=0;
    while (i != 4) {
        cout << "|| Please enter a Number: 1. Record/View Daily entries || 2. Edit Settings || 3. Display current day || 4. quit ||" << endl;
        cin >> i;

        if (i < 1 || i > 4) {
            cout << "Please enter a Number: 1. Record/View Daily entries  " << "2. Edit Settings " << "3. Edit Notification Preferences " << "4. quit ";
        }

        switch (i) {
            case 1:
                MyList.RecordMain();
                break;
            case 2:
                NewUser.UserSettings.SettingsMain();
            break;
            case 3:
                NewUser.UserNotifications.NotificationMenu();
            break;
            case 4:
                cout << "Goodbye" << endl;
            break;
        }
    }
}