#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    double gpa;

    void display() {
        cout << "ID: " << id << " | Name: " << name << " | GPA: " << gpa << endl;
    }

    // تحويل البيانات لنص ليتم حفظها في ملف
    string toString() {
        return to_string(id) + "," + name + "," + to_string(gpa);
    }
};

class Management {
private:
    vector<Student> students;
    string fileName = "students.txt";

public:
    Management() {
        loadFromFile();
    }

    void addStudent(int id, string name, double gpa) {
        Student s = {id, name, gpa};
        students.push_back(s);
        saveToFile();
        cout << "✅ Student added successfully!\n";
    }

    void viewAll() {
        if (students.empty()) {
            cout << "📂 No records found.\n";
            return;
        }
        for (auto &s : students) s.display();
    }

    void saveToFile() {
        ofstream out(fileName);
        for (auto &s : students) out << s.toString() << endl;
        out.close();
    }

    void loadFromFile() {
        ifstream in(fileName);
        if (!in) return;
        string line;
        while (getline(in, line)) {
            // منطق بسيط لتقسيم النص (Parsing) يمكن تطويره لاحقاً
            cout << "Loading: " << line << endl;
        }
        in.close();
    }
};

int main() {
    Management system;
    int choice, id;
    string name;
    double gpa;

    while (true) {
        cout << "\n--- Student System ---\n1. Add Student\n2. View All\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter ID, Name, GPA: ";
            cin >> id >> name >> gpa;
            system.addStudent(id, name, gpa);
        } else if (choice == 2) {
            system.viewAll();
        } else if (choice == 3) {
            break;
        }
    }
    return 0;
}