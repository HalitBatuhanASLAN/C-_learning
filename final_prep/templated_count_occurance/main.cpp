#include<iostream>
#include<list>
#include<vector>
#include<exception>
using namespace std;

template<class T,class C>
int find_occurance(const T& cont,const C& find_val)
{
    if(cont.begin() == cont.end())
        throw runtime_error("There is no any elements in container");
    int number = 0;
    for(auto it = cont.begin();it != cont.end();it++)
        if(*it == find_val)
            number++;
    return number;
}

int main()
{
    vector<int>v1{1,2,15,19,5,5,17,18,5,-5};
    list<string>l1{"A","B","b","A,","A"};

    try
    {
        cout << find_occurance(v1,5) << endl;
        cout << find_occurance(v1,0) << endl;
        cout << find_occurance(v1,1) << endl;
        cout << find_occurance(l1,"c") << endl;
        cout << find_occurance(l1,"HBA") << endl;
        cout << find_occurance(l1,"A") << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}