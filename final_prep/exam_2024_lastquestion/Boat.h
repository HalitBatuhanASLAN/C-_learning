#ifndef BOAT_H
#define BOAT_H

#include"MotorHehicle.h"

class Boat:public MotorVehicle
{
    public:
        Boat(const int& whe,const double& size,const int& pas,const int& wei):
            MotorVehicle(whe,size,pas)
        {
            setWeight(wei);
            setTax();
            setWheels(whe);       // Call overridden setWheels
            setPassengers(pas);   // Call overridden setPassengers
        }
        ~Boat()=default;
        virtual void setWheels(const int& whe)
        {
            if(whe!=0)
                wheels = 0;
            else wheels = whe;
        }
        virtual void setPassengers(const int& passen)
        {
            if(passen>=13 || passen <=1)
                passengers = 3;
            else passengers = passen;
        }
        virtual void setTax()
        {
            tax = weight *100;
        }
        void setWeight(const int& we)
        {
            if(we<=100)
                weight = 101;
            else
                weight = we;
        }
        const int getWeight()const
        {
            return weight;
        }
    private:
        int weight;
};

#endif