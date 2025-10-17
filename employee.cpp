#include<iostream>
#include<iomanip>
using namespace std;

class Employee {
private:
    int id;
    string name, gender, pos;
    float salary;

public:
    void CreateData() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Position: ";
        cin >> pos;
        cout << "Enter Salary: $";
        cin >> salary;
    }

    void ShowData() {
        cout<<left 
            << setw(12) << id
            << setw(14) << name
            << setw(16) << gender
            << setw(18) << pos
            << setw(10) << salary
            << endl;
    }

    int getID() { return id; }
    string getName() { return name; }
};

void Header() {
    cout<<left 
        <<setw(12) << "ID"
        << setw(14) << "Name"
        << setw(16) << "Gender"
        << setw(18) << "Position"
        << setw(10) << "Salary"
        << endl;
}

int main() {
    int op, n = 0;
    Employee emp[20];

    do {
        cout << "==========================================================" << endl;
        cout << "| 1.Create Data                                          |" << endl;
        cout << "| 2.Show Data                                            |" << endl;
        cout << "| 3.Sort Data                                            |" << endl;
        cout << "| 4.Search Data                                          |" << endl;
        cout << "| 5.Update Data                                          |" << endl;
        cout << "| 6.Add Data                                             |" << endl;
        cout << "| 7.Insert Data                                          |" << endl;
        cout << "| 8.Delete Data                                          |" << endl;
        cout << "| 9.Delete all Data                                      |" << endl;
        cout << "| 0.Exit                                                 |" << endl;
        cout << "==========================================================" << endl;
        cout << "Choose Option: ";
        cin >> op;

        switch (op) {
            case 1: {
                cout << "How many data you want to input: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    emp[i].CreateData();
                }
            } break;
            case 2: {
                if (n == 0) {
                    cout << "No data available!" << endl;
                } else {
                    Header();
                    for (int i = 0; i < n; i++) {
                        emp[i].ShowData();
                    }
                }
            } break;
            case 3: {
                bool check_sort = false;
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (emp[i].getID() > emp[j].getID()) {
                            Employee temp = emp[i];
                            emp[i] = emp[j];
                            emp[j] = temp;
                            check_sort = true;
                        }
                    }
                }
                Header();
                for (int i = 0; i < n; i++) {
                    emp[i].ShowData();
                }
                if (check_sort) {
                    cout << endl << "Data has been sorted successfully!" << endl;
                } else {
                    cout << "It's already in order!" << endl;
                }
            } break;
            case 4: {
                bool check_search = false;
                int search_id;
                cout << "Enter ID that you want to search: ";
                cin >> search_id;
                for (int i = 0; i < n; i++) {
                    if (search_id == emp[i].getID()) {
                        emp[i].ShowData();
                        check_search = true;
                    }
                }
                if (check_search) {
                    cout << endl << "\033[32mSearch Found!\033[0m" << endl << endl;
                } else {
                    cout << endl << "\033[31mSearch Not Found!\033[0m" << endl << endl;
                }
            } break;
        }
    } while (op != 0);

    cout << "Exiting Program..................." << endl;
    return 0;
}
