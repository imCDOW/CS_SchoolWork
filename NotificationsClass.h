#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

class NotificationsManager {
private:
    struct Notification {
        string message;
        string timeStamp;
        bool isAcknowledged;

        Notification(const string& msg, const string& time)
            : message(msg), timeStamp(time), isAcknowledged(false) {}

        void markAsAcknowledged() {
            isAcknowledged = true;
            cout << "Notification Acknowledged: " << message << endl;
        }

        void display() const {
            cout << "Notification: " << message << endl;
            cout << "Time: " << timeStamp << endl;
            cout << "Acknowledged: " << (isAcknowledged ? "Yes" : "No") << endl;
        }
    };

    vector<Notification> notifications;
    int alertInterval; // in seconds

public:
    NotificationsManager() : alertInterval(300) {} // Default interval of 5 minutes

    void createNotification(const string& message, const string& timeStamp) {
        notifications.emplace_back(message, timeStamp);
        cout << "New Notification: " << message << endl;
    }

    void displayAllNotifications() const {
        if (notifications.empty()) {
            cout << "No notifications to display." << endl;
            return;
        }

        cout << "All Notifications: " << endl;
        for (const auto& notification : notifications) {
            notification.display();
        }
    }

    void acknowledgeNotification(int index) {
        if (index < 0 || index >= notifications.size()) {
            cerr << "Error: Invalid Notification Index." << endl;
            return;
        }
        notifications[index].markAsAcknowledged();
    }

    void setAlertInterval(int minutes) {
        if (minutes <= 0) {
            cerr << "Error: Alert interval must be more than 0 minutes." << endl;
            return;
        }
        alertInterval = minutes * 60; // Convert to seconds
        cout << "Alert interval set to " << minutes << " minutes." << endl;
    }

    void triggerAlerts() {
        while (true) {
            for (const auto& notification : notifications) {
                if (!notification.isAcknowledged) {
                    cout << "ALERT: " << endl;
                    notification.display();
                }
            }
            this_thread::sleep_for(chrono::seconds(alertInterval));
        }
    }

    void NotificationMenu() {
        cout << "Welcome to the Notifications Menu" << endl;
        int choice = 0;
        while (choice != 5) {
            cout << "|| 1. Create Notification || 2. Set Alert Interval || 3. Display All Notifications || 4. Acknowledge Notification || 5. Quit ||" << endl;
            cout << "Please enter a number: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                cout << "Enter notification message: ";
                string message;
                cin.ignore(); // Clear newline from the input buffer
                getline(cin, message);
                cout << "Enter notification timestamp: ";
                string timeStamp;
                getline(cin, timeStamp);
                createNotification(message, timeStamp);
                break;
            }
            case 2: {
                cout << "Enter alert interval in minutes: ";
                int minutes;
                cin >> minutes;
                setAlertInterval(minutes);
                break;
            }
            case 3:
                displayAllNotifications();
                break;
            case 4: {
                cout << "Enter notification index to acknowledge: ";
                int index;
                cin >> index;
                acknowledgeNotification(index);
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            }
        }
    }
};
