#include <iostream>  
using namespace std;

class Main {
private:
    // Declare private data members (student information)
    string name;
    string gender;
    string born;
    string cda; // Current residence address
    string faculty;
    string department;
    string major;
    string year;
    string studentClass; // Changed variable name (Class is a reserved keyword)
    string room;
    int choice; // Used for menu selection

public:
    void Menu() {
        cout << "__________________________" << endl
             << "=========| CARD |=========" << endl
             << "========| NISETH |========" << endl
             << "=========| ITE |==========" << endl
             << "--------------------------" << endl;

        // Show menu options
        cout << "1. Create new card\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle menu choice
        if (choice == 1) {
            NewCard(); // Call function to create a new card
        } else {
            cout << "Exiting program..." << endl; // Exit message
        }
    }

    void NewCard() {
        cout << "\n===== Fill in Information =====" << endl;

        cout << "Name: ";
        cin >> name; // Using >> will stop at first space (e.g. only first name)
        
        cout << "Gender: ";
        cin >> gender;

        cout << "Born (DD/MM/YYYY): ";
        cin >> born;

        cout << "Current residence address: ";
        cin.ignore(); // Clear input buffer before getline()
        getline(cin, cda);

        cout << "Faculty: ";
        getline(cin, faculty);

        cout << "Department: ";
        getline(cin, department);

        cout << "Major: ";
        getline(cin, major);

        cout << "Year: ";
        getline(cin, year);

        cout << "Class: ";
        getline(cin, studentClass);

        cout << "Room: ";
        getline(cin, room);

        cout << "\n===== CARD CREATED =====" << endl;

        // Display the created card information
        ShowCard();
    }

    void ShowCard() {
        cout << "-------------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Born: " << born << endl;
        cout << "Address: " << cda << endl;
        cout << "Faculty: " << faculty << endl;
        cout << "Department: " << department << endl;
        cout << "Major: " << major << endl;
        cout << "Year: " << year << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Room: " << room << endl;
        cout << "-------------------------------" << endl;
    }
};

int main() {
    Main obj; // Create object of Main class
    obj.Menu(); // Call menu function to start the program
    return 0;
}
