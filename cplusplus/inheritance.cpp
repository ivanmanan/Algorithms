#include "globals.h"

using namespace std;

class Car {
protected:
    bool isSedan;
    string seats;

public:
    Car(bool isSedan, string seats) {
        this->isSedan = isSedan;
        this->seats = seats;
    }

    bool getIsSedan() {
        return this->isSedan;
    }

    string getSeats() {
        return this->seats;
    }

    virtual string getMileage() = 0;

    void printCar(string name) {
        cout << "A " << name << " is " << (this->getIsSedan() ? "" : "not ")
            <<"Sedan, is " << this->getSeats() << "-seater, and has a mileage of around "
            << getMileage() << ".\n";
    }
};
// Write your code here.

/**
*   WagonR class
**/

class WagonR : public Car {
    public:
        WagonR(int carMileage) : Car(getIsSedan(), getSeats()) {
            m_mileage = carMileage;
        }
        bool getIsSedan() {
            return false;
        }
        string getSeats() {
            return "4";
        }
        string getMileage() {
            return to_string(m_mileage) + " kmpl";
        }
    private:
        int m_mileage;
};

/**
*   HondaCity class
**/
class HondaCity : public Car {
    public:
        HondaCity(int carMileage) : Car(getIsSedan(), getSeats()) {
            m_mileage = carMileage;
        }
        bool getIsSedan() {
            return true;
        }
        string getSeats() {
            return "4";
        }
        string getMileage() {
            return to_string(m_mileage) + " kmpl";
        }
    private:
        int m_mileage;
};

/**
*   InnovaCrysta class
**/
class InnovaCrysta : public Car {
    public:
        InnovaCrysta(int carMileage) : Car(getIsSedan(), getSeats()) {
            m_mileage = carMileage;
        }
        bool getIsSedan() {
            return false;
        }
        string getSeats() {
            return "6";
        }
        string getMileage() {
            return to_string(m_mileage) + " kmpl";
        }
    private:
        int m_mileage;
};
