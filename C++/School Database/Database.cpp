#include "Database.h"

Database::Database(){
    studentTable = new LazyBST<Student>();
    facultyTable = new LazyBST<Faculty>();
    tempStudent = new Student(0, "temp", "temp", "temp", 0.0, 0);
    tempFaculty = new Faculty(0, "temp", "temp", "temp");
    deleting = false;
}

Database::~Database(){
    delete studentTable;
    delete facultyTable;
}

void Database::printStudents(){
    cout << "-----Students-----" << endl;
      if (!(studentTable->isEmpty()))
        studentTable->printTree();
    else
        cout << "Student database is empty" << endl;
    cout << endl;
}

void Database::printFaculty(){
    cout << "-----Faculty-----" << endl;
    if (!(facultyTable->isEmpty()))
        facultyTable->printTree();
    else
        cout << "Faculty database is empty" << endl;
    cout << endl;
}

void Database::writeStudents(ofstream& outputFile){

    // Check if the file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error opening the file!" << std::endl;
        return; // Return error code
    }
    outputFile << "-----Students-----" << endl;
    if (!(studentTable->isEmpty()))
        studentTable->writeTree(outputFile);
    else
        outputFile << "Student database is empty" << endl;
}

void Database::writeFaculty(ofstream& outputFile){

    // Check if the file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error opening the file!" << std::endl;
        return; // Return error code
    }
    outputFile << "-----Faculty-----" << endl;
    if (!(facultyTable->isEmpty()))
        facultyTable->writeTree(outputFile);
    else
        outputFile << "Faculty database is empty" << endl;
}

Student* Database::getStudent(int ID){
    tempStudent->ID = ID;
    return studentTable->search(tempStudent);
}

void Database::findStudent(int ID){
    if (!(studentTable->contains(getStudent(ID)))){
        cout << "Student with the ID " << ID << " is not in the database." << endl;
        return;
    }
    studentTable->search(getStudent(ID))->print();
}

Faculty* Database::getFaculty(int ID){
    tempFaculty->ID = ID;
    return facultyTable->search(tempFaculty);
}

void Database::findFaculty(int ID){
    if (!(facultyTable->contains(getFaculty(ID)))){
        cout << "Faculty with the ID " << ID << " is not in the database." << endl;
        return;
    }
    facultyTable->search(getFaculty(ID))->print();
}

void Database::addStudent(int studentID, string studentName, string studentLevelField, string studentMajor, double studentGPA, int studentAdvisor){
    Student* newStudent = new Student(studentID, studentName, studentLevelField, studentMajor, studentGPA, studentAdvisor);
    studentTable->insert(newStudent);
}

void Database::addStudent(int studentID){
    string studentName;
    string studentLevelField;
    string studentMajor;
    string Answer;
    double studentGPA;
    int studentAdvisor;
    while (studentID < 0){
        cout << "Input student's ID: " << endl;
        cin >> studentID;
        getline(cin, Answer);
        if (studentID < 0)
            cout << "student's ID can not be negative" << endl;
    }
    cout << "Input student's name: " << endl;
    getline(cin, studentName);
    cout << "Input student's level: " << endl;
    cin >> studentLevelField;
    getline(cin, Answer);
    cout << "Input student's major: " << endl;
    getline(cin, studentMajor);
    cout << "Input student's GPA: " << endl;
    cin >> studentGPA;
    getline(cin, Answer);
    cout << "Input student's advisor: " << endl;
    cin >> studentAdvisor;
    getline(cin, Answer);
    tempFaculty->ID = studentAdvisor;
    if (!(facultyTable->contains(tempFaculty))){
        cout << "Faculty with the ID " << studentAdvisor << " is not in the database." << endl;
        cout << "Do you want to add a faculty member with this ID (y/n)" << endl;
        getline(cin, Answer);
        if (Answer == "n")
            return;
        addFaculty(studentAdvisor);
    }
    facultyTable->search(getFaculty(studentAdvisor))->addAdvisee(studentID);
    Student* newStudent = new Student(studentID, studentName, studentLevelField, studentMajor, studentGPA, studentAdvisor);
    studentTable->insert(newStudent);
}

void Database::removeStudent(int ID){
    if (!(studentTable->contains(getStudent(ID)))){
        cout << "Student with the ID " << ID << " is not in the database." << endl;
        return;
    }
    cout << "a" << endl;
    cout << getStudent(ID)->advisor << endl;
    facultyTable->search(getFaculty(getStudent(ID)->advisor))->removeAdvisee(ID);
    cout << "b" << endl;
    studentTable->deleteNode(getStudent(ID));
}

void Database::addFaculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment){
    Faculty* newFaculty = new Faculty(facultyID, facultyName, facultyLevel, facultyDepartment);
    facultyTable->insert(newFaculty);
}

void Database::addFaculty(int facultyID){
    string facultyName;
    string facultyLevel;
    string facultyDepartment;
    string Answer;
    while (facultyID < 0){
        cout << "Input student's ID: " << endl;
        cin >> facultyID;
        getline(cin, Answer);
        if (facultyID < 0)
            cout << "student's ID can not be negative" << endl;
    }
    cout << "Input Faculty's name: " << endl;
    getline(cin, facultyName);
    cout << "Input Faculty's level: " << endl;
    getline(cin, facultyLevel);
    cout << "Input Faculty's department: " << endl;
    getline(cin, facultyDepartment);
    Faculty* newFaculty = new Faculty(facultyID, facultyName, facultyLevel, facultyDepartment);
    facultyTable->insert(newFaculty);
}

void Database::removeFaculty(int ID){
    if (!(facultyTable->contains(getFaculty(ID)))){
        cout << "Faculty with the ID " << ID << " is not in the database." << endl;
        return;
    }
    if (!(getFaculty(ID)->advisees->isEmpty())){
        string Answer;
        cout << "The faculty member you want to delete has Advisees, Do you still want to continue? (y/n)" << endl;
        getline(cin, Answer);
        if (Answer == "n")
            return;
        cout << "Do you want to change the advisor of all effected students? Choosing no will delete all effected students. (y/n)" << endl;
        getline(cin, Answer);
        cout << "Faculty member " << getFaculty(ID)->name << ": " << ID << " successfully deleted." << endl;
        if (Answer == "n"){
            cout << "students " << getFaculty(ID)->advisees->getStringList() << " successfully deleted.";
        }
        int size = getFaculty(ID)->advisees->getSize();
        cout << getFaculty(ID)->advisees->getStringList() << endl;
        deleting = true;
        for (int i = 0; i < size; ++i){
            if (Answer == "n"){
                studentTable->deleteNode(getStudent((getFaculty(ID)->advisees->findAtPos(i))));
            }else{
                int student = getFaculty(ID)->advisees->findAtPos(i);
                cout << i << " " << student << endl; 
                cout << "Input the new advisor for student " << student << ": "<< endl;
                int newAdvisor;
                cin >> newAdvisor;
                changeAdvisor(student, newAdvisor);
            }      
        }
        deleting = false;
    }
    cout << "V" << endl;
    facultyTable->deleteNode(getFaculty(ID));
}

void Database::changeAdvisor(int StudentID, int FacultyID){
    string Answer;
    if (!(studentTable->contains(getStudent(StudentID)))){
        cout << "Student with the ID " << StudentID << " is not in the database." << endl;
        return;
    }
    Student* student = studentTable->search(getStudent(StudentID));
    // if student does not have advisor then there is no need to remove advisor
    if (student->advisor != -1 && !deleting){
        facultyTable->search(getFaculty(student->advisor))->removeAdvisee(student->ID);
    }
    if (!(facultyTable->contains(getFaculty(FacultyID)))){
        cout << "Faculty with the ID " << FacultyID << " is not in the database." << endl;
        cout << "Do you want to add a faculty member with this ID?";
        if (deleting)
            cout << " Choosing no will delete the student.";
        cout << " (y/n)" << endl;
        getline(cin, Answer);
        if (Answer == "n"){
            if (deleting)
                removeStudent(StudentID);
            return;
        } 
        addFaculty(FacultyID);
    }
    facultyTable->search(getFaculty(FacultyID))->addAdvisee(student->ID);
    student->advisor = FacultyID;
}

void Database::removeAdvisee(int FacultyID, int StudentID){
    string Answer;
    if (!(facultyTable->contains(getFaculty(FacultyID)))){
        cout << "Faculty with the ID " << FacultyID << " is not in the database." << endl;
        return;
    }
    if (facultyTable->search(getFaculty(FacultyID))->removeAdvisee(StudentID) == -1){
        cout << "Faculty with the ID " << FacultyID << " Does not have the student " << StudentID << " as an advisee." << endl;
        return;
    }
    cout << "Do you want to change the student's advisor? Choosing no will delete the student. (y/n)" << endl;
    getline(cin, Answer);
    if (Answer == "n"){
        
        studentTable->deleteNode(getStudent(StudentID));
    } else {
        studentTable->search(getStudent(StudentID))->advisor = -1;
        int studentAdvisor;
        cout << "Input student's new advisor: " << endl;
        cin >> studentAdvisor;
        getline(cin, Answer);
        changeAdvisor(StudentID, studentAdvisor);
    }
}

void Database::openDatabase(){
    string temp;
    int input = 0;
    while (input != 11)
    {
        int choice1 = 0;
        int choice2 = 0;
        printMenu();
        cin >> input;
        getline(cin, temp);
        switch (input)
        {
        case 1:
            printStudents();
            break;
        case 2:
            printFaculty();
            break;
        case 3:
            cout << "Input student ID: " << endl;
            cin >> choice1;
            getline(cin, temp);
            findStudent(choice1);
            cout << endl;
            break;
        case 4:
            cout << "Faculty student ID: " << endl;
            cin >> choice1;
            getline(cin, temp);
            findFaculty(choice1);
            cout << endl;
            break;
        case 5:
            cout << "Input student ID: " << endl;
            cin >> choice1;
            getline(cin, temp);
            addStudent(choice1);
            cout << endl;
            break;
        case 6:
            cout << "Input student ID: " << endl;
            cin >> choice1;
            getline(cin, temp);
            removeStudent(choice1);
            cout << endl;
            break;
        case 7:
            cout << "Faculty student ID: " << endl;
            cin >> choice1;
            getline(cin, temp);
            addFaculty(choice1);
            cout << endl;
            break;
        case 8:
            cout << "Faculty student ID: " << endl;
            cin >> choice1;
            getline(cin, temp);
            removeFaculty(choice1);
            cout << endl;
            break;
        case 9:
            cout << "Input student ID: " << endl;
            cin >> choice1;
            cout << "Faculty student ID: " << endl;
            cin >> choice2;
            getline(cin, temp);
            if (getStudent(choice1)->advisor == choice2)
                cout << "Faculty member " << choice2 << " is already student's " << choice1 << " advisor" << endl;
            else
                changeAdvisor(choice1, choice2);
            cout << endl;
            break;
        case 10:
            cout << "Faculty student ID: " << endl;
            cin >> choice1;
            cout << "Input student ID: " << endl;
            cin >> choice2;
            getline(cin, temp);
            removeAdvisee(choice1, choice2);
            cout << endl;
            break;
        default:
            break;
        }
    }
    ofstream outputFile("runLog.txt");

    // Check if the file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error opening the file!" << std::endl;
        return; // Return error code
    }

    writeStudents(outputFile);
    writeFaculty(outputFile);
    outputFile.close();
}

void Database::printMenu(){
    cout << "----Type the number of the choice you want----" << endl;
    cout << "1. Print all students" << endl;
    cout << "2. Print all faculty" << endl;
    cout << "3. Find student" << endl;
    cout << "4. Find faculty" << endl;
    cout << "5. Add student" << endl;
    cout << "6. Delete student " << endl;
    cout << "7. Add faculty" << endl;
    cout << "8. Delete faculty " << endl;
    cout << "9. Change a student’s advisor" << endl;
    cout << "10. Remove an advisee from faculty member" << endl;
    cout << "11. Exit" << endl;
    cout << endl;
}
