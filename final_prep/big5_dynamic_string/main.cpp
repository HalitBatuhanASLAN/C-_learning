#include <iostream>
#include <string> // For comparison and utility
using namespace std;
#include<memory>
#include<utility>
#include<cstdlib>
#include<cstring>

class DynamicString
{
    public:
        DynamicString():length(0)
        {
            data = nullptr;
        }
        DynamicString(const char* o):length(strlen(o))
        {
            data = new char[length+1];
            strcpy(data,o);
            data[length] = '\0';
        }
        DynamicString(const DynamicString& o):length(o.length)
        {
            data = new char[length+1];
            for(int i = 0;i<length;i++)
                data[i] = o.data[i];
            data[length] = '\0';
        }
        DynamicString& operator=(const DynamicString& o)
        {
            if(data == o.data)return *this;
            delete[] data;
            length = o.length;
            data = new char[length+1];
            for(int i = 0;i<length;i++)
                data[i] = o.data[i];
            return *this;
        }

        DynamicString(DynamicString&& o)noexcept:length(o.length)
        {
            data = move(o.data);
            o.length = 0;
            o.data = nullptr;
        }
        DynamicString& operator=(DynamicString&& o)noexcept
        {
            length = o.length;
            data = move(o.data);
            o.length = 0;
            o.data = nullptr;
            return *this;
        }

        friend ostream& operator<<(ostream& out,const DynamicString& tmo);
        DynamicString operator+(const DynamicString& o)
        {
            DynamicString res;
            res.length = length + o.length;
            res.data = new char[res.length];
            for(int i = 0;i<length;i++)
                res.data[i] = data[i];
            for(int i = 0;i<o.length;i++)
                res.data[i+length] = o.data[i];
            res.data[res.length] = '\0';
            return res;
        }

        bool operator==(const DynamicString& o)
        {
            if(length != o.length) return false;
            for(int i = 0;i<length;i++)
                if(data[i] != o.data[i])
                    return false;
            return true;
        }
        bool operator!=(const DynamicString& o)
        {
            if(length != o.length) return true;
            for(int i = 0;i<length;i++)
                if(data[i] != o.data[i])
                    return true;
            return false;
        }
        int getSize(){return length;}

        ~DynamicString(){delete[] data;}
    private:
        char *data;
        int length;
};

ostream& operator<<(ostream& out,const DynamicString& tmo)
{
    for(int i = 0;i<tmo.length;i++)
        out << tmo.data[i];
    return out;
}
        

void testDynamicString() {
    cout << "==== Testing DynamicString ====" << endl;

    // 1. Test Default Constructor and Parameterized Constructor
    cout << "Creating strings..." << endl;
    DynamicString str1("Hello");
    DynamicString str2("World");
    DynamicString str3;

    cout << "str1: " << str1 << endl; // Should print "Hello"
    cout << "str2: " << str2 << endl; // Should print "World"
    cout << "str3 (default): " << str3 << endl; // Should print an empty string

    // 2. Test Copy Constructor
    cout << "\nTesting Copy Constructor..." << endl;
    DynamicString str4 = str1; // Copy str1 into str4
    cout << "str4 (copy of str1): " << str4 << endl; // Should print "Hello"

    // 3. Test Copy Assignment Operator
    cout << "\nTesting Copy Assignment..." << endl;
    str3 = str2; // Copy str2 into str3
    cout << "str3 (after copy assignment from str2): " << str3 << endl; // Should print "World"

    // 4. Test Move Constructor
    cout << "\nTesting Move Constructor..." << endl;
    DynamicString str5 = std::move(str1); // Move str1 into str5
    cout << "str5 (moved from str1): " << str5 << endl; // Should print "Hello"
    cout << "str1 (after move): " << str1 << endl; // Should be empty or invalid

    // 5. Test Move Assignment Operator
    cout << "\nTesting Move Assignment..." << endl;
    str4 = std::move(str2); // Move str2 into str4
    cout << "str4 (after move assignment from str2): " << str4 << endl; // Should print "World"
    cout << "str2 (after move): " << str2 << endl; // Should be empty or invalid

    // 6. Test Concatenation
    cout << "\nTesting Concatenation..." << endl;
    DynamicString str6 = str5 + str4; // Concatenate str5 ("Hello") and str4 ("World")
    cout << "str6 (str5 + str4): " << str6 << endl; // Should print "HelloWorld"

    // 7. Test Comparison
    cout << "\nTesting Comparison..." << endl;
    cout << "str5 == str4? " << (str5 == str4 ? "True" : "False") << endl; // Should print "False"
    cout << "str5 != str4? " << (str5 != str4 ? "True" : "False") << endl; // Should print "True"

    // 8. Test Self-Assignment
    cout << "\nTesting Self-Assignment..." << endl;
    str6 = str6; // Assign to itself
    cout << "str6 (after self-assignment): " << str6 << endl; // Should still print "HelloWorld"

    cout << "==== Testing Complete ====" << endl;
}

int main() {
    try {
        testDynamicString();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
