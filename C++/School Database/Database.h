#ifndef DATABASE_H
#define DATABASE_H

#include "LazyBST.h"
#include "Student.h"
#include "Faculty.h"

class Database
{
private:
    LazyBST<Student>* studentTable;
    LazyBST<Faculty>* facultyTable;
    Student* tempStudent;
    Faculty* tempFaculty;
    bool deleting;
public:
    Database();
    ~Database();
    void printStudents(); 
    void findStudent(int ID);
    void printFaculty();
    void findFaculty(int ID);
    void writeStudents(ofstream& outputFile); 
    void writeFaculty(ofstream& outputFile);
    Student* getStudent(int ID);
    Faculty* getFaculty(int ID);
    void addStudent(int studentID, string studentName, string studentLevelField, string studentMajor, double studentGPA, int studentAdvisor);
    void addStudent(int studentID);
    void removeStudent(int ID);
    void addFaculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment);
    void addFaculty(int facultyID);
    void removeFaculty(int ID);
    void changeAdvisor(int StudentID, int FacultyID);
    void removeAdvisee(int FacultyID, int StudentID);
    void openDatabase();
    void printMenu();
};

#endif