#include <iostream>
#include <string>
#include <vector>
#include<stdexcept>
#include<algorithm>

using namespace std;

class AvailableCars:public exception
{
    public:
        const char* what() const noexcept override
        {
            return "All cars are rented\n";
        }
};

class CarAlreadyRentedException:public exception
{
    public:
        const char* what() const noexcept override
        {
            return "Car already rented\n";
        }
};

class CarNotRentedException:public exception
{
    public:
        const char* what() const noexcept override
        {
            return "Car already returned\n";
        }
};

class CarRental
{
    public:
        CarRental(){available_cars = {"Totota Corolla","Honda Civic","BMW X5","Mercedes E200"};}
        void listAvailableCars()
        {
            if(available_cars.empty())
                throw AvailableCars();
            else
            {
                for(auto cars : available_cars)
                    cout << cars << endl;
            }
        }

        void rentCar(const string& wanted_car)
        {
            if(find(rented_cars.begin(),rented_cars.end(),wanted_car) != rented_cars.end())
            {
                throw CarAlreadyRentedException();
            }
            auto tmp = find(available_cars.begin(),available_cars.end(),wanted_car);
            if(tmp != available_cars.end())
            {
                rented_cars.push_back(wanted_car);
                available_cars.erase(tmp);
            }
            else
                cout << "We do not have a car with that name\n";
        }

        void returnCar(const string& retrun_car_name)
        {
            auto tmp = find(rented_cars.begin(),rented_cars.end(),retrun_car_name);
            if(tmp != rented_cars.end())
            {
                available_cars.push_back(retrun_car_name);
                rented_cars.erase(tmp);
            }
            else
                throw CarNotRentedException();

        }
    private:
        vector<string>available_cars;
        vector<string>rented_cars;
};

int main() {
    CarRental carRental;
    try {
        // Araç kiralama sistemi nesnesi


        // Mevcut araçlarý listele
        std::cout << "Mevcut araçlar:" << std::endl;
        carRental.listAvailableCars();

        // Araç kiralama iþlemi
        std::cout << "\nToyota Corolla'yý kiralýyorum..." << std::endl;
        carRental.rentCar("Toyota Corolla");

        // Mevcut araçlarý tekrar listele
        std::cout << "\nKiralamadan sonra mevcut araçlar:" << std::endl;
        carRental.listAvailableCars();

        // Ayný aracý tekrar kiralamayý dene (istisna atýlmalý)
        std::cout << "\nToyota Corolla'yý tekrar kiralamayý deniyorum..." << std::endl;
        carRental.rentCar("Toyota Corolla");

    } catch (const CarAlreadyRentedException& e) {
        std::cerr << "Hata: " << e.what() << std::endl;
    } catch (const CarNotRentedException& e) {
        std::cerr << "Hata: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Beklenmeyen hata: " << e.what() << std::endl;
    }

    try {
        // Araç iade iþlemi
        std::cout << "\nToyota Corolla'yý iade ediyorum..." << std::endl;
        carRental.returnCar("Toyota Corolla");

        // Mevcut araçlarý tekrar listele
        std::cout << "\nÝadeden sonra mevcut araçlar:" << std::endl;
        carRental.listAvailableCars();

        // Kiralanmamýþ bir aracý iade etmeyi dene (istisna atýlmalý)
        std::cout << "\nBMW X5'i iade etmeyi deniyorum (kiralanmamýþ)..." << std::endl;
        carRental.returnCar("BMW X5");

    } catch (const CarAlreadyRentedException& e) {
        std::cerr << "Hata: " << e.what() << std::endl;
    } catch (const CarNotRentedException& e) {
        std::cerr << "Hata: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Beklenmeyen hata: " << e.what() << std::endl;
    }

    return 0;
}
