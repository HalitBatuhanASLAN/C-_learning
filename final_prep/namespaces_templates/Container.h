#ifndef Cont_H
#define Cont_H

namespace MyNamespace
{
    template<class T>
    class Container
    {
        public:
            Container(const T& input):value(input){}
            void const display()const{std::cout << "Value is " << value << std::endl;}
        protected:
            T value;
    };
}

#endif