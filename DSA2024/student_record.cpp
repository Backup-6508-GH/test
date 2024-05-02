#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudent(Student student) {
    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
        cout << "Error opening file for writing." << endl;
        return;
    }
    outFile << student.rollNumber << " "
            << student.name << " "
            << student.division << " "
            << student.address << endl;
    outFile.close();
    cout << "Student added successfully." << endl;
}

void deleteStudent(int rollNumber) {
    ifstream inFile("students.txt");
    ofstream outFile("temp.txt");
    Student student;
    bool found = false;
    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber != rollNumber) {
            outFile << student.rollNumber << " "
                    << student.name << " "
                    << student.division << " "
                    << student.address << endl;
        } else {
            found = true;
        }
    }
    inFile.close();
    outFile.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found) {
        cout << "Student deleted successfully." << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

void displayStudent(int rollNumber) {
    ifstream inFile("students.txt");
    Student student;
    bool found = false;
    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumber) {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }
    inFile.close();
    if (!found) {
        cout << "Student not found." << endl;
    }
}

int main() {
    int choice;
    Student student;
    int rollNumber;
    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter roll number: ";
                cin >> student.rollNumber;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, student.name);
                cout << "Enter division: ";
                cin >> student.division;
                cout << "Enter address: ";
                cin.ignore();
                getline(cin, student.address);
                addStudent(student);
                break;
            case 2:
                cout << "Enter roll number of student to delete: ";
                cin >> rollNumber;
                deleteStudent(rollNumber);
                break;
            case 3:
                cout << "Enter roll number of student to display: ";
                cin >> rollNumber;
                displayStudent(rollNumber);
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}