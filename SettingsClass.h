#include <iostream>
#include <string>
#include <chrono>
using namespace std;

class Settings{
    private:
        float LowThreshold;
        float HighThreshold;
        string TimeZone;
        bool NotificationsEnabled;


    public:
        Settings() :
        LowThreshold(70.0),
        HighThreshold(180.0),
        TimeZone("UTC"),
        NotificationsEnabled(true) {}
        void SettingsMain();



        void updateThresholds(float low, float high) {
            if (low < 0 || low >= high) {
                cerr << "Error: Invalid threshold values. Low must be less than High and both must be non-negative numbers." << endl;
                return;
            }
            LowThreshold = low;
            HighThreshold = high;
            cout << "Thresholds updated. Low: " << LowThreshold << ", High: " << HighThreshold << endl;
        }



        void setTimeZone() {
            TimeZone = chrono::current_zone()->name();
            cout << "Timezone updated to: " << TimeZone << endl;
        }



        void setNotifications(bool enable) {
            NotificationsEnabled = enable;
            if (NotificationsEnabled) {
                cout << "Notifications updated to: " << NotificationsEnabled << endl;
            }
        }



        void displaySettings() const{
            cout << "Settings:" << endl;
            cout << "Low Threshold: " << LowThreshold << endl;
            cout << "HighThreshold: " << HighThreshold << endl;
            cout << "Timezone: " << TimeZone << endl;
            cout << "Notifications: " << (NotificationsEnabled ? "Enabled" : "Disabled") << endl;
        }



        //accessors for other classes
        float getLowThreshold() const { return LowThreshold; }
        float getHighThreshold() const { return HighThreshold; }
        string getTimeZone() const { return TimeZone; }
        bool areNotificationsEnabled() const {return NotificationsEnabled; }

};

void Settings::SettingsMain() {
    cout << "Welcome to the settings menu" << endl;
    int j=0;
    while (j != 4) {
        cout << "Please enter a Number: ";
        cout << "|| 1. Set/Update Thresholds || 2. Set Timezone || 3. Set Notification Preferences || 4. Display Current Preferences || 5. Quit ||" << endl;
        cin >> j;

        if (j < 1 || j > 5) {
            cout << "Please enter a Number between 1-4 "<< endl;
        }

        switch (j) {
            case 1:
                cout << "please enter a value for your minimum reading threshold: ";
                float low;
                cout << "please enter a value for your maximum reading threshold: ";
                float high;
                updateThresholds(low, high);
                break;
            case 2:
                setTimeZone();
                break;
            case 3:
                setNotifications(true);
                break;
            case 4:
                displaySettings();
                break;
            case 5:
                cout << "Good bye!" << endl;
                break;

        }
    }
}

//#endif

