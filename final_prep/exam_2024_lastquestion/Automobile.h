#ifndef AUTO_H
#define AUTO_H

#include"MotorHehicle.h"

class Automobile:public MotorVehicle
{
    public:
        Automobile(const int& whe,const double& size,const int& pas,const int& spe,const string& col):
            MotorVehicle(whe,size,pas)
        {
            setWheels(whe);       // Call overridden setWheels
            setPassengers(pas);   // Call overridden setPassengers
            set_speed(spe);  // Initialize max speed
            setColor(col);      // Initialize color
            setTax();;
        }
        ~Automobile()=default;
        virtual void setWheels(const int& whe)
        {
            if(whe!=4)
                wheels = 4;
            else wheels = whe;
        }
        virtual void setPassengers(const int& passen)
        {
            if(passen>=7 || passen<=1)
                passengers = 3;
            else passengers = passen;
        }
        virtual void setTax()
        {
            tax = max_speed*engineSize;
        }
        void setColor(const string& col)
        {
            if(col.empty())
                color = "white";
            else
                color = col;
        }
        const string& getColor()const{return color;}
        void set_speed(const int& spe)
        {
            if(spe <= 0)
                max_speed = 250;
            else
                max_speed = spe;
        }
        const int& get_speed()const{return max_speed;}
    private:
        int max_speed;
        string color;
};

#endif