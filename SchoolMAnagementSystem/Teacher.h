#ifndef TEACHER_H
#define TEACHER_H
#include"Person.h"

namespace School
{
    class Teacher:public Person
    {
        public:
            string subject;
            void teach();
    };
}

#endif