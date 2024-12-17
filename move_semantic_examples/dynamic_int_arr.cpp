#include <iostream>
#include <stdexcept> // For std::out_of_range

class DynamicIntArray
{
    public:
        DynamicIntArray():size(0),capacity(10){data = nullptr;}
        ~DynamicIntArray(){delete[] data;}

        DynamicIntArray(DynamicIntArray&& other):size(other.size),capacity(other.capacity),data(other.data)
        {
            other.data = nullptr;
        }

        DynamicIntArray(DynamicIntArray& other):size(other.size),capacity(other.capacity)
        {
            data = new int[size];
            for(int i = 0;i<size;i++)
                data[i] = other.data[i];
        }

        DynamicIntArray operator=(DynamicIntArray& other)
        {
            capacity = other.capacity;
            size = other.size;
            data = new int[size];
            for(int i = 0;i<size;i++)
                data[i] = other.data[i];
            return *this;
        }

        DynamicIntArray operator=(DynamicIntArray&& other)
        {
            capacity = other.capacity;
            size = other.size;
            for(int i = 0;i<size;i++)
                data[i] = other.data[i];
            other.data = nullptr;
            return *this;
        }


        int getSize(){return size;}
        int getElement(int pos)
        {
            try
            {
                if(pos >= 0 && pos< size)
                    return data[pos];
                throw std::out_of_range("Out of range");
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        void addElement(int value)
        {
            int *ptr = new int[size+1];
            for(int i = 0;i<size;i++)
                ptr[i] = data[i];
            size++;
            ptr[size-1] = value;
            delete[] data;
            data = ptr;
        }
    private:
        int size;
        int capacity;
        int *data;
};

int main() {
    std::cout << "Creating arr...\n";
    DynamicIntArray arr;
    arr.addElement(10);
    arr.addElement(20);
    arr.addElement(30);

    std::cout << "Creating arr2 as a copy of arr...\n";
    DynamicIntArray arr2 = arr; // Invokes copy constructor

    std::cout << "Creating arr3 by moving arr...\n";
    DynamicIntArray arr3 = std::move(arr); // Invokes move constructor

    std::cout << "Contents of arr2 (copy): ";
    for (std::size_t i = 0; i < arr2.getSize(); ++i) {
        std::cout << arr2.getElement(i) << ' ';
    }
    std::cout << "\n";

    std::cout << "Contents of arr3 (moved): ";
    for (std::size_t i = 0; i < arr3.getSize(); ++i) {
        std::cout << arr3.getElement(i) << ' ';
    }
    std::cout << "\n";

    std::cout << "Assigning arr2 to arr3...\n";
    arr3 = arr2; // Invokes copy assignment operator

    std::cout << "Assigning a new DynamicIntArray to arr3 via move...\n";
    arr3 = DynamicIntArray(); // Invokes move assignment operator

    return 0;
}