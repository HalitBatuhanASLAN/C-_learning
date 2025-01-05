#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
using namespace std;

template<class T>
typename T::value_type findMaxInContainer(const T& cont)
{
    if(cont.begin() == cont.end())
        throw runtime_error("Container is empty\n");
    auto it = cont.begin();
    auto max_element = *it;
    for(;it != cont.end();it++)
        if(*it > max_element)
            max_element = *it;
    return max_element;
}

int main()
{
    const vector<int> v1{1,225,2,18,-5};
    list<double> l1{-15.98,-78,15.98,15.99};
    forward_list<int> fl1;
    try
    {
        cout << findMaxInContainer(v1) << endl;
        cout << findMaxInContainer(l1) << endl;
        cout << findMaxInContainer(fl1) << endl;    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}