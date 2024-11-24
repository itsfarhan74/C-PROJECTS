#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int id;
    double grade;
};

Student* students;
int numStudents = 0;

void addStudent() {
    Student* newStudent = new Student;
    cout << "Enter student name: ";
    cin >> newStudent->name;
    cout << "Enter student ID: ";
    cin >> newStudent->id;
    cout << "Enter student grade: ";
    cin >> newStudent->grade;

    students[numStudents++] = *newStudent;
    delete newStudent;
}

void deleteStudent(int id) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            cout << "Student deleted successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void searchStudent(int id) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            cout << "Student found:\n";
            cout << "Name: " << students[i].name << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Grade: " << students[i].grade << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void modifyStudent(int id) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            cout << "Enter new name: ";
            cin >> students[i].name;
            cout << "Enter new grade: ";
            cin >> students[i].grade;
            cout << "Student modified successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

int main() {
    students = new Student[100]; // Assuming a maximum of 100 students

    while (true) {
        cout << "1. Add student\n";
        cout << "2. Delete student\n";
        cout << "3. Search student\n";
        cout << "4. Modify student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                int deleteId;
                cout << "Enter student ID to delete: ";
                cin >> deleteId;
                deleteStudent(deleteId);
                break;
            case 3:
                int searchId;
                cout << "Enter student ID to search: ";
                cin >> searchId;
                searchStudent(searchId);
                break;
            case 4:
                int modifyId;
                cout << "Enter student ID to modify: ";
                cin >> modifyId;
                modifyStudent(modifyId);
                break;
            case 5:
                cout << "Exiting..." << endl;
                delete[] students;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}
