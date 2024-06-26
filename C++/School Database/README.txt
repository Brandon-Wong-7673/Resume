Brandon Wong May 2024

The Program stores student and facility information in separate, lazily balanced tree databases.
Both databases are sorted by the student/facility's ID. Each student must have an ID, name, field,
major, GPA, and advisor. If you add a student with a faculty member, not in the database and decide 
not to make the faculty member, the student will also not be made. Each faculty must have an ID, 
name, level, and department. Each faculty also has a list of advisees, but this list Is empty by
default.

To Run:
g++ *.cpp -o A5.out
./A5.out

