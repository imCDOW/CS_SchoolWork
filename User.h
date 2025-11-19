#include <iostream>
#include "SettingsClass.h"
#include "NotificationsClass.h"

class Notifications;
using namespace std;

#ifndef USER_H
#define USER_H

class User {
public:
    User() {};
    void SetUserInformation();
    void SetUserName();
    void SetUserAge();
    void SetUserAccount();
    Settings UserSettings;
    NotificationsManager UserNotifications;
private:
    int Age;
    string Name;

};

void User::SetUserName() {
    cout << "What is your name?" << endl;
    cin >> Name;
    cout << "Your name is " << Name << endl;
}
void User::SetUserAge() {
    cout << "What is your age?" << endl;
    cin >> Age;
    cout << "Your age is " << Age << endl;
}
void User::SetUserAccount() {
    SetUserName();
    SetUserAge();
    // add more if more to account
}
#endif //USER_H
