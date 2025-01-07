#include<iostream>
using namespace std;

template<typename T>
class Vector
{
    public:
        Vector():size(0),capacity(5)
        {
            data = new T[capacity];
            //data = nullptr;
        }
        Vector(const Vector& o):size(o.size),capacity(o.capacity)
        {
            data = new T[capacity];
            for(int i = 0;i<size;i++)
                data[i] = o.data[i];
        }
        Vector& operator=(const Vector& o)
        {
            if(*this == o) return *this;
            size = o.size;
            capacity = o.capacity;
            delete[] data;
            data = new T[capacity];
            for(int i = 0;i<size;i++)
                data[i] = o.data[i];
            return *this;
        }
        Vector(Vector&& o)noexcept:size(o.size),capacity(o.capacity),data(o.data)
        {
            o.data = nullptr;
            o.capacity = 0;
            o.size = 0;
        }
        Vector& operator=(Vector&& o)noexcept
        {
            if(*this == o) return *this;
            size = o.size;
            capacity = o.capacity;
            delete[] data;
            data = move(o.data);
            o.data = nullptr;
            o.capacity = 0;
            o.size = 0;
            return *this;
        }
        ~Vector(){delete[] data;}

        Vector operator+(const Vector& o)const
        {
            Vector tmp = *this;
            for(int i = 0;i<o.size;i++)
                tmp.data[i] += o.data[i];
            return tmp;
        }
        bool operator==(const Vector& o)const
        {
            if(size != o.size)
                return false;
            for(int i = 0;i<size;i++)
                if(data[i] != o.data[i])
                    return false;
            return true;
        }
        const T& operator[](const int& index)const
        {
            if(index < 0 || index >= size)
                throw out_of_range("index is out of range");
            else
            {
                return data[index];
            }
        }
        T& operator[](const int& index)
        {
            if(index < 0 || index >= size)
                throw out_of_range("index is out of range");
            else
            {return data[index];}
        }

        void print()const
        {
            if(size == 0)
                cerr << "There is no any elements\n";
            else
            {
                for(int i = 0;i<size;i++)
                    cout << data[i] << " ";
                cout << endl;
            }
        }
        void push_back(const T& element)
        {
            if(size >= capacity)
            {
                capacity += 10;
                T *tmp = new T[capacity];
                for(int i = 0;i<size;i++)
                    tmp[i] = data[i];
                delete[] data;
                data = tmp;
                //delete[] tmp;
            }
            data[size] = element;
            size++;
            
        }
    private:
        T *data;
        size_t size;
        size_t capacity;
};

int main()
{
    Vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.print();

    Vector<int> v2 = v1; // Copy constructor
    v2.push_back(30);
    v2.print();

    Vector<int> v3 = std::move(v1); // Move constructor
    v3.push_back(40);
    v3.print();

    Vector<int> v4;
    v4 = v2; // Copy assignment operator
    v4.push_back(50);
    v4.print();

    Vector<int> v5;
    v5 = std::move(v3); // Move assignment operator

    Vector<int> v6 = v2 + v4; // Concatenation using operator+

    if (v2 == v4) { // Equality check using operator==
        std::cout << "v2 and v4 are equal!" << std::endl;
    } else {
        std::cout << "v2 and v4 are not equal!" << std::endl;
    }

    v6[0] = 100; // Using operator[] to modify an element
    std::cout << "v6: ";
    v6.print();

    std::cout << "v2: ";
    v2.print();

    std::cout << "v4: ";
    v4.print();

    std::cout << "v5: ";
    v5.print();

    return 0;
}