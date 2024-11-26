#include <iostream>
using namespace std;

class Shape
{
    protected:
        double area,circumference;
    public:
        virtual void print_type() = 0;
        virtual void set_area() = 0;
        virtual void set_circumference() = 0;

        double getArea(){return area;}
        double getCircumference(){return circumference;}
};

class Rectangle:public Shape
{
    public:
        Rectangle(double a,double b, double c, double height):a(a),b(b),c(c),height(height){}
        void print_type(){cout << "It is a rectangle\n";}
        void set_area(){area = c*height/2;}
        void set_circumference(){circumference = a + b + c;}
    private:
        double a, b, c, height;
};

class Square:public Shape
{
    public:
        Square(double a,double b):a(a),b(b){}
        void print_type(){cout << "It is a square\n";}
        void set_area(){area = a*b;}
        void set_circumference(){circumference = 2*(a + b);}
    private:
        double a, b;
};

class Circle:public Shape
{
    public:
        Circle(double c):radius(c){}
        void print_type(){cout << "It is a circle\n";}
        void set_area(){area = 3.14*radius*radius;}
        void set_circumference(){circumference = 2 * 3.14 * radius;}
    private:
        double radius;
};

int main()
{
    Shape* shapes[3];
    shapes[0] = new Rectangle(1,2,3,4);
    shapes[1] = new Square(4,5);
    shapes[2] = new Circle(9);

    for(int i = 0;i<3;i++)
    {
        shapes[i]->print_type();

        shapes[i]->set_area();
        shapes[i]->set_circumference();

        cout << "Area = " << shapes[i]->getArea() << endl;
        cout << "Circumference = " << shapes[i]->getCircumference() << endl;
        cout << "-------\n";
    }


    return 0;
}
