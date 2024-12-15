#include <iostream>
#include <string>
using namespace std;

class toDo {
public:
    toDo(string n) {
        note = n;
        count++;
    }
    toDo() {
        count++;
    }
    ~toDo() {
        count--;
    }
    void input() {
        string s;
        getline(cin, s);
        note = s;
    }

    void print() {
        cout << note << endl;
    }
    static int getCount() {
        return count;
    }
    string getNote() {
        return note;
    }
private:
    string note;
    static int count;
};

int toDo::count = 0;

int main() {
    int n, max_size = 10000;
    toDo* a = new toDo[max_size];
    int current_count = 0;

    cout << "WELCOME TO THE TO-DO LIST APP" << endl;
    cout << "\nHere is the list of functions:" << endl;
    cout << "1 \t Print the note list" << endl;
    cout << "2 \t Add note" << endl;
    cout << "3 \t Delete note" << endl;
    cout << "4 \t Exit" << endl;
    while (true) {
        cout << "Please enter your choice: ";
        cin >> n;
        cin.ignore();
        if (n == 1) {
            if (current_count == 0) {
                cout << "EMPTY!!" << endl;
            }
            else {
                for (int i = 0; i < current_count; i++) {
                    cout << i + 1 << "\t";
                    a[i].print();
                }
            }
        }
        else if (n == 2) {
            if (current_count < max_size) {
                cout << "Enter your note: ";
                a[current_count].input();
                current_count++;
            }
            else {
                cout << "The note list is full" << endl;
            }
        }
        else if (n == 3) {
            int index;
            cout << "Enter the position of the note you want to delete (starting from 0): ";
            cin >> index;

            if (index >= 0 && index < current_count) {
                string s = a[index].getNote();
                for (int i = index; i < current_count - 1; i++) {
                    a[i] = a[i + 1];
                }
                current_count--;
                cout << "The note: \"" << s << "\" has been deleted!" << endl;
                //cout << "Note has been deleted!" << endl;
            }
            else {
                cout << "Invalid position!" << endl;
            }
        }
        else if (n == 4) {
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
    delete[] a;

    return 0;
}
