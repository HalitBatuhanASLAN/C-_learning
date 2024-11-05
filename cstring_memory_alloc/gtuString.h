#ifndef GTUST_H
#define GTUST_H

#include<iostream>
using namespace std;

class GTUString{
    public:
	    GTUString();//ok
	    GTUString(const char* cStr);//ok
	    ~GTUString();//ok
	    GTUString operator+=(const GTUString& other);
	    char & operator[](int i);//ok
	    char operator[](int i) const;//ok
	    char at(int i);//ok
        int len() const;//ok
		friend ostream& operator<<(ostream& out,const GTUString& tmp);
	    bool operator==(const GTUString& o) const;
	    bool operator!=(const GTUString& o) const;
 
    private:
	    char* d;
};
#endif