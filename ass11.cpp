#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student {
    int rollNumber;
    char name[50];
    char division;
    char address[100];
};

void addStudent() {
    ofstream file("students.dat", ios::binary | ios::app);

    if (!file) {
        cout << "Error in opening the file!" << endl;
        return;
    }

    Student student;

    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;

    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(student.name, 50);

    cout << "Enter Division: ";
    cin >> student.division;

    cout << "Enter Address: ";
    cin.ignore();
    cin.getline(student.address, 100);

    file.write(reinterpret_cast<const char*>(&student), sizeof(Student));

    cout << "Student record added successfully!" << endl;

    file.close();
}

void deleteStudent() {
    fstream file("students.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cout << "Error in opening the file!" << endl;
        return;
    }

    int rollNumber;
    bool found = false;

    cout << "Enter Roll Number of student to delete: ";
    cin >> rollNumber;

    Student student;
    ofstream tempFile("temp.dat", ios::binary);

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber == rollNumber) {
            found = true;
        } else {
            tempFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
        }
    }

    file.close();
    tempFile.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found) {
        cout << "Student record deleted successfully!" << endl;
    } else {
        cout << "Student record not found!" << endl;
    }
}

void displayStudent() {
    ifstream file("students.dat", ios::binary);

    if (!file) {
        cout << "Error in opening the file!" << endl;
        return;
    }

    int rollNumber;
    bool found = false;

    cout << "Enter Roll Number of student to display: ";
    cin >> rollNumber;

    Student student;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber == rollNumber) {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;

            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student record not found!" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "========== STUDENT INFORMATION ==========" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}
