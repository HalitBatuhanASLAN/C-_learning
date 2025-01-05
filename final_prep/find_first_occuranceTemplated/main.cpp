#include<iostream>
#include<list>
#include<vector>
#include<exception>
using namespace std;

template<class T,class C>
typename T::const_iterator find_first_occurance(const T& cont,const C& find_val)
{
    if(cont.begin() == cont.end())
        throw runtime_error("There is no any elements in container");
    for(auto it = cont.begin();it != cont.end();it++)
        if(*it == find_val)
            return it;
    throw runtime_error("Element could not found in container");
}

int main()
{
    const vector<int>v1{1,2,15,19,5,5,17,18,5,-5};
    const list<string>l1{"A","B","b","A,","A"};

    try
    {
        auto it = find_first_occurance(v1,5);
        cout << *it << endl;
        it = find_first_occurance(v1,0);
        cout << *it << endl;
        it = find_first_occurance(v1,1);
        cout << *it << endl;

        auto it2 = find_first_occurance(l1,"c");
        cout << *it2 << endl;
        it2 = find_first_occurance(l1,"HBA");
        cout << *it2 << endl;
        it2 = find_first_occurance(l1,"A");
        cout << *it2 << endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}