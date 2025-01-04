#ifndef MOTORVE_H
#define MOTORVE_H

#include<iostream>
using namespace std;
#include<vector>

class MotorVehicle
{
    public:
        MotorVehicle(const int& whe,const double& size,const int& pas)
        :wheels(0),passengers(0),tax(0),engineSize(0)
        {
            setEnginSize(size);
        }
        virtual ~MotorVehicle() = default;

        /*setters*/
        virtual void setWheels(const int& whe) = 0;
        virtual void setPassengers(const int& passen) = 0;
        virtual void setTax() = 0;
        void setEnginSize(const double& sizeEngine)
        {
            if(sizeEngine<=0)
                engineSize = 1.6;
            else
                engineSize = sizeEngine;
        }
        /*getters*/
        const int& getWheels()const{return wheels;}
        const double& getEnginSize()const{return engineSize;}
        const int& getPassengers()const{return passengers;}
        const double& getTax()const{return tax;}
    protected:
        int wheels;
        double engineSize;
        int passengers;
        double tax;
};

#endif