#ifndef FACULTY_H
#define FACULTY_H

#include "SingleLinkedList.h"
#include <fstream>

class Faculty
{
public:
    Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment);
    Faculty( Faculty *faculty);
    ~Faculty();
    void print();
    void write(ofstream& outputFile);
    void addAdvisee(int studentID);
    int removeAdvisee(int studentID);
    int ID;
    string name;
    string level;
    string department;
    SingleLinkedList* advisees;
    bool operator==(const Faculty& other);
    bool operator<(const Faculty& other);
    bool operator>(const Faculty& other);
};



#endif