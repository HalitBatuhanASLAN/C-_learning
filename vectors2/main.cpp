#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> numbers(50);

    for(int i = 0;i<10;i++)
        numbers[i] = i+2;

    int *ptr = numbers.data();//first eleemnts adress
    cout << *ptr << endl;

    numbers = {1,2,3,4,5};
    cout << "Capacity = " << numbers.capacity() << endl;
    cout << "Size = " << numbers.size() << endl;
    cout << "Max size(can be kept in vector) " << numbers.max_size() << endl;

    numbers.resize(18);
    cout << "Size = " << numbers.size() << endl;
    if(numbers.empty())
        cout << "It is empty\n";
    else
        cout << "It is not empty\n";

    vector<int> num(15);
    num = {1,2,3,4,5,6,7,8,9,10};
    cout << "First size = " << num.size() << endl;
    for(int i = 0;i<10;i++)
        cout << num[i] << " ";
    cout << endl;

    num.resize(5);
    for(int i = 0;i<10;i++)
        cout << num[i] << " ";
    cout << endl;

    num.shrink_to_fit();//it deletes elements which ot of current size
    for(int i = 0;i<10;i++)
        cout << num[i] << " ";
    cout << endl;

    vector<int> last(15);
    last.assign(5,12);//assigns 12 to first 5 elements
    for(int i = 0;i< last.size();i++)
        cout << last[i] << " ";
    cout << endl;

    last.push_back(123);//add last position
    cout << last.back() << endl;

    last.pop_back();//deletes last element
    cout << last.back() << endl;

    last.insert(last.end(),999);//add number into given position
    cout << last.back() << endl;

    last.insert(last.begin(),-999);//add number into given position
    cout << last.front() << endl;

    last.insert(last.begin()+5,6999);//add number into given position
    cout << last.at(5) << endl;

    last.erase(last.begin()+5);
    cout << last.at(5) << endl;

    last.emplace(last.end(),4);//same with insert
    cout << last.back() << endl;
    //emplace_back(number) add end of vector
    last.clear();//clears all elements
    cout << last.at(0) << endl;

    numbers.swap(num);//swaps 2 vectors


    return 0;
}
