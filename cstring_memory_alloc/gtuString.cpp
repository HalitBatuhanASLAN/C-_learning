#include<cstring>
#include<cstdlib>
#include "gtuString.h"
#include<iostream>
using namespace std;

GTUString::GTUString(const char* cstr)
{
    d = new char[strlen(cstr) + 1];
    strcpy(d,cstr);
}

GTUString::GTUString()
{
    d = new char[1];
    d[0] = '\0';
}

GTUString::~GTUString()
{
    delete[] d;
}

GTUString GTUString::operator+=(const GTUString& other)
{
    int size = len();
    int size_other = other.len();
    char* cstr = new char[size + size_other + 1];

    for(int i = 0;i<size;i++)
        cstr[i] = d[i];
    for(int i = 0;i<size_other;i++)     
        cstr[i + size] = other.d[i];
    cstr[size + size_other] = '\0';
    delete[] d;
    d = cstr;
    return d;
}

char GTUString::at(int i)
{
    if(i < 0 || i >= len())
        exit(-1);
    return d[i];
}
char& GTUString::operator[](int i)
{
    return d[i];
}
char GTUString::operator[](int i) const
{
    return d[i];
}
int GTUString::len()const
{
    char* ptr = d;
    while(*ptr != '\0')
        ptr++;
    return ptr - d;
}

ostream& operator<<(ostream& out,const GTUString& tmp)
{
    for(int i = 0;i<tmp.len();i++)
        out << tmp[i];
    return out;
}
bool GTUString::operator==(const GTUString& o)const
{
    if(o.len() != len())    return false;
    for(int i = 0;i<o.len();i++)
    {
        if(o.d[i] != d[i])
            return false;
    }
    return true;
}
bool GTUString::operator!=(const GTUString& o)const
{
    return(!(o == *this));
}