#ifndef STUDENT_H
#define STUDEN_H    
#include"Person.h"

namespace School
{
    class Student:public Person
    {
        public:
            void study();
            string grade;
    };
}

#endif