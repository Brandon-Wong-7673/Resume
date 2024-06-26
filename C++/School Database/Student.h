#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
    Student(int studentID, string studentName, string studentLevelField, string studentMajor, double studentGPA, int studentAdvisor);
    Student(Student* student);
    ~Student();
    void print();
    void write(ofstream& outputFile);
    int ID;
    string name;
    string levelField;
    string major;
    double GPA;
    int advisor;
    bool operator==(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
};


#endif