#include <iostream>
#include <iomanip>
#include <string> 
using namespace std;

class Employee {
private:
    int id;
    string name, gender, position; 
    float salary;

public:
    int getID() {
        return id;
    }

    string getName() {
        return name;
    }

    void Input() {
        cout << "Input Id      = "; cin >> id;
        cin.ignore();
        cout << "Input Name    = "; getline(cin, name);
        cout << "Input Gender  = "; getline(cin, gender);
        cout << "Input Position= "; getline(cin, position);
        cout << "Input Salary  = "; cin >> salary;
    }

    void Output() {
        cout << setw(12) << id
             << setw(14) << name
             << setw(16) << gender
             << setw(18) << position
             << setw(15) << salary
             << endl;
    }
};

void Header() {
    cout << setw(12) << "ID"
         << setw(14) << "Name"
         << setw(16) << "Gender"
         << setw(18) << "Position"
         << setw(15) << "Salary"
         << endl;
}

int main() {
    int op, i, j, n = 0;
    Employee emp[20];
    Employee temp;

    do {
        cout<<"------------------------------------------------------"<<endl;
        cout<<"| 1 . Create Data                                    |"<<endl;
        cout<<"| 2 . Show Data                                      |"<<endl;
        cout<<"| 3 . Sort Data                                      |"<<endl;
        cout<<"| 4 . Search Data                                    |"<<endl;
        cout<<"| 5 . Update Data                                    |"<<endl;
        cout<<"| 6 . Add Data                                       |"<<endl;
        cout<<"| 7 . Insert Data                                    |"<<endl;
        cout<<"| 8 . Delete Data                                    |"<<endl;
        cout<<"| 9 . Delete All Data                                |"<<endl;
        cout<<"| 10. Exit                                           |"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Choose Option: "; cin >> op; 

        switch (op) {
            case 1: {
                cout << "How many Data you want to input: "; cin >> n;
                for (i = 0; i < n; i++) {
                    emp[i].Input();
                }
            } break;

            case 2: {
                Header();
                for (i = 0; i < n; i++) {
                    emp[i].Output();
                }
            } break;

            case 3: {
                bool check_sort = false; 
                for (i = 0; i < n; i++) {
                    for (j = i + 1; j < n; j++) {
                        if(emp[i].getID() > emp[j].getID()) {
                            temp = emp[i];
                            emp[i] = emp[j];
                            emp[j] = temp;
                            check_sort = true;
                        }
                    }
                }
                Header();
                for (i = 0; i < n; i++) {
                    emp[i].Output();
                }
                if(check_sort) {
                    cout << endl << "Data has been sorted successfully!" << endl;
                } else {
                    cout << "It's Already In order" << endl;
                }
            } break;

            case 4: {
                int search_id;
                bool check_search = false; 
                cout << "Enter your ID to search: "; cin >> search_id;
                for (i = 0; i < n; i++) {
                    if (search_id == emp[i].getID()) { 
                        emp[i].Output();
                        check_search = true;
                    }
                }
                if(check_search){
                    cout << endl << "Search Found!" << endl;
                } else {
                    cout << endl << "Search Not Found!" << endl;
                }
            } break;

        } 

    } while(op != 10);

    return 0;
}