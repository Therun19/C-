#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

class Worker {
private:
    static constexpr int kMax = 100;

    int n{};                      // current number of workers
    int id[kMax];                 // up to 100 workers
    string name[kMax];
    string gender[kMax];
    int salary[kMax];
    int rate[kMax];
    int hour[kMax];
    float income[kMax];

    // helpers
    void calcIncomeAt(int i) {
        income[i] = static_cast<float>(salary[i]) + static_cast<float>(rate[i]) * static_cast<float>(hour[i]);
    }

    int indexById(int targetId) const {
        for (int i = 0; i < n; ++i) {
            if (id[i] == targetId) return i;
        }
        return -1;
    }

    // Move a full record from 'from' index to 'to' index (no swap)
    void moveRecord(int from, int to) {
        id[to]     = id[from];
        name[to]   = name[from];
        gender[to] = gender[from];
        salary[to] = salary[from];
        rate[to]   = rate[from];
        hour[to]   = hour[from];
        income[to] = income[from];
    }

public:
    void Choice() {
        cout << "\n===== Worker Menu =====\n";
        cout << "1) Input\n";
        cout << "2) Income (recalculate)\n";
        cout << "3) Output\n";
        cout << "4) Search (by ID)\n";
        cout << "5) Maximum Income\n";
        cout << "6) Minimum Income\n";
        cout << "7) Equal Income (find by value)\n";
        cout << "8) Sort (by income)\n";
        cout << "9) Sum (total income)\n";
        cout << "10) Update (by ID)\n";
        cout << "11) Insert (append)\n";
        cout << "12) Delete (by ID)\n";
        cout << "0) Exit\n";
        cout << "Select: ";
    }

    void Input() {
        cout << "Enter Total Worker (0-100): ";
        int m;
        cin >> m;
        if (!cin || m < 0 || m > kMax) {
            cout << "Invalid number. Aborting input.\n";
            // clear error state
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        n = m;
        for (int i = 0; i < n; i++) {
            cout << "\nWorker " << i + 1 << '\n';
            cout << "Enter ID: "; cin >> id[i];
            cout << "Enter Name: "; cin >> name[i];
            cout << "Enter Gender: "; cin >> gender[i];
            cout << "Enter Salary: "; cin >> salary[i];
            cout << "Enter Rate: "; cin >> rate[i];
            cout << "Enter Hour: "; cin >> hour[i];
            calcIncomeAt(i);
        }
        cout << "\nInput completed. Income calculated.\n";
    }

    void Income() {
        for (int i = 0; i < n; i++) calcIncomeAt(i);
        cout << "Income recalculated for " << n << " workers.\n";
    }

    void Output() const {
        if (n == 0) {
            cout << "No data.\n";
            return;
        }
        cout << "\n--- Worker Information ---\n";
        cout << left << setw(5) << "No"
             << setw(8) << "ID"
             << setw(12) << "Name"
             << setw(10) << "Gender"
             << right << setw(10) << "Salary"
             << setw(8) << "Rate"
             << setw(8) << "Hour"
             << setw(12) << "Income" << '\n';
        cout << string(73, '-') << '\n';
        cout.setf(ios::fixed); cout << setprecision(2);
        for (int i = 0; i < n; i++) {
            cout << left << setw(5) << (i + 1)
                 << setw(8) << id[i]
                 << setw(12) << name[i]
                 << setw(10) << gender[i]
                 << right << setw(10) << salary[i]
                 << setw(8) << rate[i]
                 << setw(8) << hour[i]
                 << setw(12) << income[i] << '\n';
        }
    }

    void SearchById() const {
        if (n == 0) { cout << "No data.\n"; return; }
        int target; cout << "Enter ID to search: "; cin >> target;
        int idx = indexById(target);
        if (idx == -1) {
            cout << "ID " << target << " not found.\n";
            return;
        }
        cout << "\nFound worker:\n";
        cout << "ID: " << id[idx] << "\nName: " << name[idx]
             << "\nGender: " << gender[idx] << "\nSalary: " << salary[idx]
             << "\nRate: " << rate[idx] << "\nHour: " << hour[idx]
             << "\nIncome: " << income[idx] << '\n';
    }

    void MaxIncome() const {
        if (n == 0) { cout << "No data.\n"; return; }
        int idx = 0;
        for (int i = 1; i < n; ++i) if (income[i] > income[idx]) idx = i;
        cout << "Maximum income: " << income[idx] << " (ID " << id[idx] << ", " << name[idx] << ")\n";
    }

    void MinIncome() const {
        if (n == 0) { cout << "No data.\n"; return; }
        int idx = 0;
        for (int i = 1; i < n; ++i) if (income[i] < income[idx]) idx = i;
        cout << "Minimum income: " << income[idx] << " (ID " << id[idx] << ", " << name[idx] << ")\n";
    }

    void EqualIncome() const {
        if (n == 0) { cout << "No data.\n"; return; }
        float x; cout << "Find workers with income equal to: "; cin >> x;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (income[i] == x) {
                cout << "ID " << id[i] << " - " << name[i] << " (Income " << income[i] << ")\n";
                ++cnt;
            }
        }
        if (cnt == 0) cout << "No workers with income = " << x << '\n';
    }

    // Selection sort using moveRecord and a temporary record (no std::swap)
    void SortByIncome(bool ascending = true) {
        for (int i = 0; i < n - 1; ++i) {
            int best = i;
            for (int j = i + 1; j < n; ++j) {
                if (ascending ? (income[j] < income[best])
                              : (income[j] > income[best])) {
                    best = j;
                }
            }
            if (best != i) {
                // Save the 'best' record
                int     idTmp     = id[best];
                string  nameTmp   = name[best];
                string  genderTmp = gender[best];
                int     salaryTmp = salary[best];
                int     rateTmp   = rate[best];
                int     hourTmp   = hour[best];
                float   incomeTmp = income[best];

                // Move i -> best
                moveRecord(i, best);

                // Put saved best into i
                id[i]     = idTmp;
                name[i]   = nameTmp;
                gender[i] = genderTmp;
                salary[i] = salaryTmp;
                rate[i]   = rateTmp;
                hour[i]   = hourTmp;
                income[i] = incomeTmp;
            }
        }
        cout << "Sorted by income " << (ascending ? "ascending" : "descending") << ".\n";
    }

    void SumIncome() const {
        if (n == 0) { cout << "No data.\n"; return; }
        double s = 0.0;
        for (int i = 0; i < n; ++i) s += income[i];
        cout.setf(ios::fixed); cout << setprecision(2);
        cout << "Total income of all workers: " << s << '\n';
    }

    void UpdateById() {
        if (n == 0) { cout << "No data.\n"; return; }
        int target; cout << "Enter ID to update: "; cin >> target;
        int idx = indexById(target);
        if (idx == -1) { cout << "Not found.\n"; return; }
        cout << "Updating worker ID " << id[idx] << '\n';
        cout << "Enter Name: "; cin >> name[idx];
        cout << "Enter Gender: "; cin >> gender[idx];
        cout << "Enter Salary: "; cin >> salary[idx];
        cout << "Enter Rate: "; cin >> rate[idx];
        cout << "Enter Hour: "; cin >> hour[idx];
        calcIncomeAt(idx);
        cout << "Updated.\n";
    }

    void InsertOne() {
        if (n >= kMax) { cout << "List full. Cannot insert.\n"; return; }
        cout << "Insert new worker:\n";
        cout << "Enter ID: "; cin >> id[n];
        cout << "Enter Name: "; cin >> name[n];
        cout << "Enter Gender: "; cin >> gender[n];
        cout << "Enter Salary: "; cin >> salary[n];
        cout << "Enter Rate: "; cin >> rate[n];
        cout << "Enter Hour: "; cin >> hour[n];
        calcIncomeAt(n);
        ++n;
        cout << "Inserted. Total workers: " << n << '\n';
    }

    void DeleteById() {
        if (n == 0) { cout << "No data.\n"; return; }
        int target; cout << "Enter ID to delete: "; cin >> target;
        int idx = indexById(target);
        if (idx == -1) { cout << "Not found.\n"; return; }
        for (int i = idx; i < n - 1; ++i) {
            id[i] = id[i + 1];
            name[i] = name[i + 1];
            gender[i] = gender[i + 1];
            salary[i] = salary[i + 1];
            rate[i] = rate[i + 1];
            hour[i] = hour[i + 1];
            income[i] = income[i + 1];
        }
        --n;
        cout << "Deleted ID " << target << ". Remaining: " << n << '\n';
    }

    void Run() {
        int opt;
        do {
            Choice();
            if (!(cin >> opt)) {
                cout << "Invalid input. Exiting.\n";
                return;
            }

            switch (opt) {
                case 1: Input(); break;
                case 2: Income(); break;
                case 3: Output(); break;
                case 4: SearchById(); break;
                case 5: MaxIncome(); break;
                case 6: MinIncome(); break;
                case 7: EqualIncome(); break;
                case 8: {
                    int dir;
                    cout << "1 = Ascending, 2 = Descending: ";
                    cin >> dir;
                    SortByIncome(dir != 2);
                    break;
                }
                case 9: SumIncome(); break;
                case 10: UpdateById(); break;
                case 11: InsertOne(); break;
                case 12: DeleteById(); break;
                case 0: cout << "Goodbye!\n"; break;
                default: cout << "Unknown option.\n"; break;
            }
            cout << '\n';
        } while (opt != 0);
    }
};

int main() {
    Worker obj;
    obj.Run();
}
