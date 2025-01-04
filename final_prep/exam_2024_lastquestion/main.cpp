#include <iostream>
#include <vector>
#include "MotorHehicle.h"
#include "Automobile.h"
#include "Boat.h"
#include "Truck.h"

int total_pas(const vector<MotorVehicle*>& motors);
double total_load(const vector<MotorVehicle*> motors);

int main() {
    // Create a vector of MotorVehicle pointers
    std::vector<MotorVehicle*> vehicles;

    // Create an Automobile object
    Automobile* car = new Automobile(4, 2.0, 5, 200, "Red");
    std::cout << "Automobile created: " << std::endl;
    std::cout << "  Wheels: " << car->getWheels() << std::endl;
    std::cout << "  Engine Size: " << car->getEnginSize() << std::endl;
    std::cout << "  Passengers: " << car->getPassengers() << std::endl;
    std::cout << "  Max Speed: " << car->get_speed() << std::endl;
    std::cout << "  Color: " << car->getColor() << std::endl;
    std::cout << "  Tax: " << car->getTax() << std::endl;
    vehicles.push_back(car);

    // Create a Boat object
    Boat* boat = new Boat(0, 3.5, 10, 500);
    std::cout << "\nBoat created: " << std::endl;
    std::cout << "  Wheels: " << boat->getWheels() << std::endl;
    std::cout << "  Engine Size: " << boat->getEnginSize() << std::endl;
    std::cout << "  Passengers: " << boat->getPassengers() << std::endl;
    std::cout << "  Weight: " << boat->getWeight() << std::endl;
    std::cout << "  Tax: " << boat->getTax() << std::endl;
    vehicles.push_back(boat);

    // Create a Truck object
    Truck* truck = new Truck(6, 5.0, 2, 1000);
    std::cout << "\nTruck created: " << std::endl;
    std::cout << "  Wheels: " << truck->getWheels() << std::endl;
    std::cout << "  Engine Size: " << truck->getEnginSize() << std::endl;
    std::cout << "  Passengers: " << truck->getPassengers() << std::endl;
    std::cout << "  Load Capacity: " << truck->getCapacity() << std::endl;
    std::cout << "  Tax: " << truck->getTax() << std::endl;
    vehicles.push_back(truck);

    // Test the global function for total passengers
    std::cout << "\nTotal passengers in all vehicles: " << total_pas(vehicles) << std::endl;

    // Test the global function for total load capacity
    std::cout << "Total load capacity of all trucks: " << total_load(vehicles) << std::endl;

    // Clean up memory
    for (auto vehicle : vehicles) {
        delete vehicle;
    }
    vehicles.clear();

    return 0;
}

int total_pas(const vector<MotorVehicle*>& motors)
{
    int total_passenger = 0;
    for(auto x : motors)
        total_passenger += x->getPassengers();
    return total_passenger;
}
double total_load(const vector<MotorVehicle*> motors)
{
    double total_load_capacity = 0;
    for(auto x : motors)
    {
        if(typeid(*x) == typeid(Truck))
        {
            Truck*a = dynamic_cast<Truck*>(x);
            if(a!= nullptr)
                total_load_capacity += a->getCapacity();
        }
    }
    return total_load_capacity;
}