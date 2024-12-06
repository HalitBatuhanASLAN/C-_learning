#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> nums(5,6);//allocates 5 int num spaces and assigns 6 all of them
    for(auto x : nums)
        cout << x << " ";
    cout << endl;

    vector<int> num2(5);//allocates 5 int num spaces
    num2 = {1,2,3,3,5,6,9,12,4};//we can chane capacity
    for(auto x : num2)
        cout << x << " ";
    cout << endl;

    cout << "3'd element is " << num2.at(3) << endl;
    cout << "Last element is " << num2.back() << endl;
    cout << "First element is " << num2.front() << endl;

    cout << "Last element is " << *(num2.end()-1) << endl;
    cout << "First element is " << *(num2.begin()) << endl;

    //c constant demek
    cout << "Last element is " << *(num2.cend()-1) << endl;
    cout << "First element is " << *(num2.cbegin()) << endl;

    for(auto x = num2.rbegin();x!= num2.rend();x++)
        cout << *x << " ";
    cout << endl;

    for(auto x = num2.crbegin();x!= num2.crend();x++)
        cout << *x << " ";
    cout << endl;

    return 0;
}
