#ifndef TRUCK_H
#define TRUCK_H

#include"MotorHehicle.h"

class Truck:public MotorVehicle
{
    public:
        Truck(const int& whe,const double& size,const int& pas,const double& capa):
            MotorVehicle(whe,size,pas)
        {
            setCapacity(capa);
            setTax();
            setWheels(whe);
            setEnginSize(size);
            setPassengers(pas);
        }
        ~Truck()=default;
        virtual void setWheels(const int& whe)
        {
            if(whe<=4)
                wheels = 5;
            else wheels = whe;
        }
        virtual void setPassengers(const int& passen)
        {
            if(passen>=4)
                passengers = 3;
            else passengers = passen;
        }
        virtual void setTax()
        {
            tax = loadCapacity*engineSize;
        }
        void setCapacity(const double& capa)
        {
            if(capa <= 10)
                loadCapacity = 11;
            else
                loadCapacity = capa;
        }
        const double& getCapacity(){return loadCapacity;}
    private:
        double loadCapacity;
};

#endif