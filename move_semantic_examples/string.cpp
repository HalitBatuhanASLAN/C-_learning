#include <iostream>
#include <utility> // std::move
#include<cstdlib>
#include<cstring>
using namespace std;

class String
{
    public:
        String()=default;
        ~String(){delete[] data;}

        String(const char* tmp):size(strlen(tmp)+1)
            {strcpy(data,tmp);}


        String(String& tmp):size(tmp.size)
        {
            data = new char[size+1];
            for(int i = 0;i<size;i++)
                data[i] = tmp.data[i];
            data[size] = '\0';
        }
        String(String&& ref)noexcept :size(ref.size)
        {
            data = new char[size+1];
            for(int i = 0;i<size;i++)
                data[i] = ref.data[i];
            ref.data = nullptr;
            data[size] = '\0';
        }

        String& operator=(String& tmp)
        {
            size = tmp.size;
            data = new char[size+1];
            for(int i = 0;i<size;i++)
                data[i] = tmp.data[i];
            data[size] = '\0';
            return *this;
        }

        String& operator=(String&& tmp)noexcept
        {
            size = tmp.size;
            data = new char[size+1];
            for(int i = 0;i<size;i++)
                data[i] = tmp.data[i];
            tmp.data = nullptr;
            data[size] = '\0';
            return *this;            
        }
        
        void print()
        {
            for(int i = 0;i<size;i++)
                cout << data[i];
            cout << endl;
        }
    private:
        char* data;
        int size;
};

int main() {
    // Default Constructor
    /*String s1;
    s1.print();*/

    // Parameterized Constructor
    String s2("Hello, World!");
    s2.print();

    // Copy Constructor
    String s3 = s2;
    s3.print();

    // Move Constructor
    String s4 = std::move(s2);
    s4.print();
    //s2.print(); // s2 artık boş

    // Copy Assignment
    String s5;
    s5 = s3;
    s5.print();

    // Move Assignment
    String s6;
    s6 = std::move(s3);
    s6.print();
    //s3.print(); // s3 artık boş

    return 0;
}
