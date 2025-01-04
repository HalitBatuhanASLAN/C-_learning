#ifndef STRING_MANAGER_H
#define STRING_MANAGER_H

#include<iostream>
using namespace std;
#include<cstring>
#include<exception>
#include<cstdlib>
#include<memory>
#include<utility>

class StringManager
{
    public:
        /*default constructor*/
        StringManager():length(0),my_string(nullptr){}
        /*default destructor*/
        ~StringManager()=default;

        StringManager(const char* input):length(strlen(input))
        {
            my_string = make_unique<char[]>(length+1);
            strcpy(my_string.get(),input);
        }

        /*copy constructor*/
        StringManager(const StringManager& input):length(input.length)
        {
            my_string = make_unique<char[]>(length+1);
            strcpy(my_string.get(),input.my_string.get());
        }
        /*move assignment constructor*/
        StringManager(StringManager&& input)noexcept:length(input.length),my_string(move(input.my_string))
        {
            input.length = 0;
        }

        /*copy assignment*/
        StringManager& operator=(const StringManager& input)
        {
            if(this == &input)return *this;
            length = input.length;
            if(input.my_string)
            {
                my_string = make_unique<char[]>(length+1);
                strcpy(my_string.get(),input.my_string.get());
            }
            else
                my_string.reset();//resets nullptr if input is empty

            return *this;
        }
        /*move assignment operator*/
        StringManager& operator=(StringManager&& input)noexcept
        {
            if(this == &input) return *this;
            length = input.length;
            if(input.my_string)
            {
                my_string = move(input.my_string);
                input.length = 0;
            }
            else
                my_string.reset();
            return *this;
        }

        void print()const
        {
            if(length == 0 || !my_string)
                cout << "String is empty";
            else
                cout << my_string.get();
            cout << endl;
        }
    private:
        unique_ptr<char[]>my_string;
        int length;
};

#endif