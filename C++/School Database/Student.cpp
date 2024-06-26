#include "Student.h"

Student::Student(int studentID, string studentName, string studentLevelField, string studentMajor, double studentGPA, int studentAdvisor){
    ID = studentID;
    name = studentName;
    levelField = studentLevelField;
    major = studentMajor;
    GPA = studentGPA;
    advisor = studentAdvisor;
}

Student::~Student(){
    
}

Student::Student(Student* student){
    ID = student->ID;
    name = student->name;
    levelField = student->levelField;
    major = student->major;
    GPA = student->GPA;
    advisor = student->advisor;
}

void Student::print(){
    cout << "   " << name << ": " << ID << endl;
    cout << "Level: " << levelField << endl;
    cout << "Major: " << major << endl;
    cout << "GPA: " << GPA << endl;
    cout << "Advising: " << advisor << endl;
}

void Student::write(ofstream& outputFile){

    // Check if the file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error opening the file!" << std::endl;
        return; // Return error code
    }
    outputFile << "   " << name << ": " << ID << endl;
    outputFile << "Level: " << levelField << endl;
    outputFile << "Major: " << major << endl;
    outputFile << "GPA: " << GPA << endl;
    outputFile << "Advising: " << advisor << endl;
}

bool Student::operator==(const Student& other) const {
        return this->ID == other.ID;
}


bool Student::operator>(const Student& other) const{
    return this->ID > other.ID;
}

bool Student::operator<(const Student& other) const {
    return this->ID < other.ID;
}