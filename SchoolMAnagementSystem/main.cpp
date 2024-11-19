#include <iostream>
using namespace std;
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
using namespace School;

int main() {
    // Create a Student object
    School::Student student;
    student.name = "Charlie";
    student.grade = "5th";
    student.introduce(); // From Person
    student.study();     // From Student

    // Create a Teacher object
    School::Teacher teacher;
    teacher.name = "Ms. Smith";
    teacher.subject = "Mathematics";
    teacher.introduce(); // From Person
    teacher.teach();     // From Teacher

    return 0;
}
