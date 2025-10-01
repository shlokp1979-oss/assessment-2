#include <iostream>
#include <cmath>   // for ceil()
#include <string>
using namespace std;

// Constants (Rate Card)
const double COST_PER_HOUR = 18.50;
const double COST_PER_MINUTE = 0.40;
const double COST_OF_DINNER = 20.70;

// Event Class
class Event {
private:
    string eventName;
    string firstName;
    string lastName;
    int guests;
    int minutes;

public:
    // Constructor
    Event(string eName, string fName, string lName, int g, int m) {
        eventName = eName;
        firstName = fName;
        lastName = lName;
        guests = g;
        minutes = m;
    }

    // Calculate number of servers (1 server per 20 guests)
    int calculateServers() {
        return ceil((double)guests / 20.0);
    }

    // Cost for one server
    double costOneServer() {
        double cost1 = (minutes / 60) * COST_PER_HOUR;   // Full hours
        double cost2 = (minutes % 60) * COST_PER_MINUTE; // Remaining minutes
        return cost1 + cost2;
    }

    // Total food cost
    double totalFoodCost() {
        return guests * COST_OF_DINNER;
    }

    // Average cost per guest
    double avgCostPerPerson() {
        if (guests == 0) return 0;
        return totalFoodCost() / guests;
    }

    // Total event cost
    double totalCost() {
        return totalFoodCost() + (costOneServer() * calculateServers());
    }

    // Deposit amount (25% of total cost)
    double depositAmount() {
        return totalCost() * 0.25;
    }

    // Display summary
    void displaySummary() {
        cout << "\n========== EVENT COST ESTIMATION ==========\n";
        cout << "Event Name         : " << eventName << endl;
        cout << "Organizer          : " << firstName << " " << lastName << endl;
        cout << "Guests             : " << guests << endl;
        cout << "Event Duration     : " << minutes << " minutes" << endl;
        cout << "-------------------------------------------\n";
        cout << "Servers Required   : " << calculateServers() << endl;
        cout << "Cost for One Server: $" << costOneServer() << endl;
        cout << "Total Food Cost    : $" << totalFoodCost() << endl;
        cout << "Average Cost/Guest : $" << avgCostPerPerson() << endl;
        cout << "TOTAL COST         : $" << totalCost() << endl;
        cout << "Deposit (25%)      : $" << depositAmount() << endl;
        cout << "===========================================\n";
    }
};

// Main function
int main() {
    cout << "==== Welcome to Event Organizer ====\n";

    while (true) {
        string eventName, firstName, lastName;
        int guests, minutes;

        // Collect event details
        cout << "Enter the Event Name (Example: Wedding): ";
        getline(cin, eventName);

        cout << "Enter First Name: ";
        getline(cin, firstName);

        cout << "Enter Last Name: ";
        getline(cin, lastName);

        cout << "Enter Number of Guests: ";
        cin >> guests;

        cout << "Enter Event Duration in Minutes: ";
        cin >> minutes;

        // Clear input buffer before next getline
        cin.ignore();

        // Create Event object
        Event myEvent(eventName, firstName, lastName, guests, minutes);

        // Show cost summary
        myEvent.displaySummary();

        // Ask if user wants another event
        string choice;
        cout << "Do you want to plan another event? (yes/no): ";
        getline(cin, choice);

        if (choice != "yes") {
            cout << "👋 Thank you for using Event Organizer. Goodbye!\n";
            break;
        }
    }

    return 0;
}