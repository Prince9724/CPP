#include <iostream>
#include <cstring>

using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:
   
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;  
    }

    
    Train(int number, const char name[], const char src[], const char dest[], const char time[]) {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }
 
    ~Train() {
        trainCount--;
    }

 
    void setTrainNumber(int number) { trainNumber = number; }
    int getTrainNumber() const { return trainNumber; }

    void setTrainName(const char name[]) { strcpy(trainName, name); }
    const char* getTrainName() const { return trainName; }

    void setSource(const char src[]) { strcpy(source, src); }
    const char* getSource() const { return source; }

    void setDestination(const char dest[]) { strcpy(destination, dest); }
    const char* getDestination() const { return destination; }

    void setTrainTime(const char time[]) { strcpy(trainTime, time); }
    const char* getTrainTime() const { return trainTime; }

    static int getTrainCount() {
        return trainCount;
    }


    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore(); 
        
        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);
        
        cout << "Enter Source: ";
        cin.getline(source, 50);
        
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
        
        cout << "Enter Train Time (e.g., 10 AM): ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails() const {
        cout << "Train Number: " << trainNumber << "\n";
        cout << "Train Name:   " << trainName << "\n";
        cout << "Source:       " << source << "\n";
        cout << "Destination:  " << destination << "\n";
        cout << "Train Time:   " << trainTime << "\n";
    }
};

int Train::trainCount = 0;

 
class RailwaySystem {
private:
    Train trains[100];  
    int totalTrains;  

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    // Method to add a new train record
    void addTrain() {
        if (totalTrains >= 100) {
            cout << "System Error: Cannot add more trains. Maximum capacity reached!\n";
            return;
        }
        
        cout << "\n--- Adding a New Train Record ---\n";
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
        cout << "Train Record Added Successfully!\n";
    }

    void addMockTrain(int number, const char name[], const char src[], const char dest[], const char time[]) {
        if (totalTrains < 100) {
            trains[totalTrains] = Train(number, name, src, dest, time);
            totalTrains++;
        }
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "\nNo train records available in the system.\n";
            return;
        }

        cout << "\n=========================================\n";
        cout << "        ALL TRAIN RECORDS IN SYSTEM      \n";
        cout << "=========================================\n";
        for (int i = 0; i < totalTrains; i++) {
            cout << "Train " << (i + 1) << " details:\n";
            trains[i].displayTrainDetails();
            cout << "-----------------------------------------\n";
        }
    }

    void searchTrainByNumber(int number) const {
        bool found = false;
        
        cout << "\nSearching for Train Number: " << number << "...\n";
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "\n[Match Found] Train Details:\n";
                trains[i].displayTrainDetails();
                found = true;
                break; // Break loop once match is found
            }
        }
        
        if (!found) {
            cout << "Train with number " << number << " not found!\n";
        }
    }
};
int main() {
    RailwaySystem system;
    int choice;

    system.addMockTrain(101, "Okha Express", "Surat", "Mumbai", "10 AM");
    system.addMockTrain(102, "Rajdhani Express", "Delhi", "Mumbai", "4 PM");
    system.addMockTrain(103, "Shatabdi Express", "Ahmedabad", "Mumbai", "6 AM");

    do {
        cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "Invalid choice execution! Please input a correct number indicator.\n";
            continue;
        }

        switch (choice) {
            case 1:
                system.addTrain();
                break;
            case 2:
                system.displayAllTrains();
                break;
            case 3: {
                int searchNumber;
                cout << "Enter Train Number to search: ";
                cin >> searchNumber;
                system.searchTrainByNumber(searchNumber);
                break;
            }
            case 4:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid Option selection! Try matching given numeric codes (1-4).\n";
        }
    } while (choice != 4);

    return 0;
}
