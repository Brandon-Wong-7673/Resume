#include "Faculty.h"

Faculty::Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment){
    ID = facultyID;
    name = facultyName;
    level = facultyLevel;
    department = facultyDepartment;
    advisees = new SingleLinkedList();
}

Faculty::Faculty( Faculty *faculty){
    ID = faculty->ID;
    name = faculty->name;
    level = faculty->level;
    department = faculty->department;
    advisees = new SingleLinkedList();
    for (int i = 0; i < faculty->advisees->getSize(); i++){
        advisees->insertFront(faculty->advisees->findAtPos(i));
    }
    
}

Faculty::~Faculty()
{
    delete advisees;
}

void Faculty::print(){
    cout << "   " << name << ": " << ID << endl;
    cout << "Level: " << level << endl;
    cout << "Department: " << department << endl;
    cout << "Advisees: ";
    if (advisees->isEmpty())
        cout << "None";
    else{
        for (int i = 0; i < advisees->getSize(); ++i){
            cout << advisees->findAtPos(i) << " ";
        }
    }
    cout << endl;
}

void Faculty::write(ofstream& outputFile){

    // Check if the file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error opening the file!" << std::endl;
        return; // Return error code
    }
    outputFile << "   " << name << ": " << ID << endl;
    outputFile << "Level: " << level << endl;
    outputFile << "Department: " << department << endl;
    outputFile << "Advisees: ";
    if (advisees->isEmpty())
        outputFile << "None";
    else{
        for (int i = 0; i < advisees->getSize(); ++i){
            outputFile << advisees->findAtPos(i) << " ";
        }
    }
    outputFile << endl;
}

void Faculty::addAdvisee(int studentID){
    cout << "added " <<  studentID << endl;
    advisees->insertFront(studentID);
}

int Faculty::removeAdvisee(int studentID){
    cout << advisees->getStringList() << endl;
    return advisees->removeValue(studentID);
}

bool Faculty::operator==(const Faculty& other) {
        return this->ID == other.ID;
}

bool Faculty::operator>(const Faculty& other) {
        return this->ID > other.ID;
}

bool Faculty::operator<(const Faculty& other) {
        return this->ID < other.ID;
}