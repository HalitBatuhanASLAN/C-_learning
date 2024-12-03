#include <iostream>
using namespace std;

template<typename T>
class Shape
{
    public:
        virtual void draw() const = 0;
        virtual T area() const = 0;
};

template<typename T>
class Circle:public Shape<T>
{
    public:
        Circle(T radius) : radius(radius){}
        void draw()const{cout << "Circle it is\n";}
        T area() const{return 3,14*radius*radius;}
    private:
        T radius;
};

template<typename T>
class Rectangle:public Shape<T>
{
    public:
        Rectangle(T len,T wid) : length(len),width(wid){}
        void draw()const{cout << "Rectangle it is\n";}
        T area() const{return width*length;}
    private:
        T length,width;
};

int main() {
    // Create objects of Circle and Rectangle
    Shape<double>* circle = new Circle<double>(5.0);  // Circle with radius 5
    Shape<double>* rectangle = new Rectangle<double>(4.0, 6.0);  // Rectangle with width 4 and height 6
    
    // Process the Circle object using the base class pointer
    cout << "\nProcessing Circle:" << endl;
    Shape<double>* shape = circle;  // Base class pointer pointing to a Circle
    shape->draw();  // Virtual function call (calls Circle's draw)
    cout << "Area of Circle: " << shape->area() << endl;  // Virtual function call (calls Circle's area)

    // Process the Rectangle object using the base class pointer
    cout << "\nProcessing Rectangle:" << endl;
    shape = rectangle;  // Base class pointer pointing to a Rectangle
    shape->draw();  // Virtual function call (calls Rectangle's draw)
    cout << "Area of Rectangle: " << shape->area() << endl;  // Virtual function call (calls Rectangle's area)
    
    // Cleanup
    delete circle;
    delete rectangle;
    
    return 0;
}
