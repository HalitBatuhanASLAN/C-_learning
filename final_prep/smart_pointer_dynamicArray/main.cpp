#include<memory>
#include<iostream>
#include<exception>
using namespace std;


//const and parameters
template<class T>
class DynamicArray
{
    public:
        DynamicArray():size(0),data(nullptr){}
        DynamicArray(const int& size,T tmp_element):size(size)
        {
            data = make_unique<T[]>(size);
        }
        DynamicArray(const DynamicArray& prev):size(prev.size)
        {
            data = make_unique<T[]>(size);
            for(int i = 0;i<size;i++)
                data[i] = prev.data[i];
        }
        DynamicArray& operator=(const DynamicArray& prev)
        {
            size = prev.size;
            data = make_unique<T[]>(size);
            for(int i = 0;i<size;i++)
                data[i] = prev.data[i];
            return *this;
        }

        DynamicArray(DynamicArray&& prev) noexcept :size(prev.size),data(move(prev.data))
        {
            prev.size = 0;
        }
        DynamicArray& operator=(DynamicArray&& prev)noexcept
        {
            size = prev.size;
            data = move(prev.data);
            prev.size = 0;
            return *this;
        }

        void setValue(const int& index,const T& new_num)
        {
            if(index<0 || index>=size) throw out_of_range("index must be between 0 and "+to_string(size-1));
            data[index] = new_num;
        }
        T getValue(const int& index)const
        {
            if(index<0 || index>=size) throw out_of_range("index must be between 0 and "+to_string(size-1));
            return data[index];
        }
        void print_array()
        {
            if(data != nullptr)
            {
                for(int i = 0;i<size;i++)
                    cout << data[i] << " ";
                cout << endl;
            }
            else throw runtime_error("There is no any element in array");
        }

        ~DynamicArray()=default;
    private:
        unique_ptr<T[]> data;
        int size;
};

int main()
{
    DynamicArray d1(10,5);
    for(int i = 0;i<10;i++)
        d1.setValue(i,i+11);
    try
    {
        cout << d1.getValue(14) << endl;
    }
    catch(const out_of_range& o)
    {
        std::cerr << o.what() << '\n';
    }

    d1.print_array();

    DynamicArray d2(d1);
    d2.setValue(5,1907);
    d2.print_array();

    DynamicArray<int> d3{};
    d3 = move(d2);
    d3.print_array();
    d2.print_array();
}