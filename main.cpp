#include <iostream>
#include <string>
#include "Base.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Truck.h"

void printBaseStatus() {
    std::string separator = "=====";
    std::cout << separator << std::endl;
    std::cout << "People on base: " << Base::people_on_base << std::endl;
    std::cout << "Vehicles on base: " << Base::vehicles_on_base << std::endl;
    std::cout << "Petrol on base: " << Base::petrol_on_base << " L" << std::endl;
    std::cout << "Goods on base: " << Base::goods_on_base << " tons" << std::endl;
    std::cout << separator << std::endl << std::endl;
}

int main() {
    std::string msg;

    msg = "Initial base state:";
    std::cout << msg << std::endl;
    printBaseStatus();

    // Create a regular vehicle
    Vehicle* car = new Vehicle(30.0, 50.0);
    msg = "Regular vehicle arrived at base";
    std::cout << msg << std::endl;
    car->arrive();
    printBaseStatus();

    // Create a bus with 20 passengers
    Bus* bus = new Bus(20, 30, 40.0, 80.0);
    msg = "Bus arrived at base (20 passengers)";
    std::cout << msg << std::endl;
    bus->arrive();
    printBaseStatus();

    // Create a truck with 15 tons of cargo
    Truck* truck = new Truck(15.0, 20.0, 50.0, 100.0);
    msg = "Truck arrived at base (15 tons of cargo)";
    std::cout << msg << std::endl;
    truck->arrive();
    printBaseStatus();

    // Try to send regular vehicle
    msg = "Regular vehicle trying to leave...";
    std::cout << msg << std::endl;
    if (car->leave()) {
        std::cout << "Vehicle left successfully" << std::endl;
        std::cout << "Petrol in tank: " << car->getPetrolAmount() << " L" << std::endl;
    } else {
        std::cout << "Vehicle could not leave" << std::endl;
    }
    printBaseStatus();

    // Try to send bus
    msg = "Bus trying to leave...";
    std::cout << msg << std::endl;
    if (bus->leave()) {
        std::cout << "Bus left successfully" << std::endl;
        std::cout << "Petrol in tank: " << bus->getPetrolAmount() << " L" << std::endl;
        std::cout << "Passengers in bus: " << bus->getPeopleCount() << std::endl;
    } else {
        std::cout << "Bus could not leave" << std::endl;
    }
    printBaseStatus();

    // Try to send truck
    msg = "Truck trying to leave...";
    std::cout << msg << std::endl;
    if (truck->leave()) {
        std::cout << "Truck left successfully" << std::endl;
        std::cout << "Petrol in tank: " << truck->getPetrolAmount() << " L" << std::endl;
        std::cout << "Cargo in truck: " << truck->getCurrentLoad() << " tons" << std::endl;
    } else {
        std::cout << "Truck could not leave" << std::endl;
    }
    printBaseStatus();

    // Another bus tries to take remaining people
    Bus* bus2 = new Bus(0, 50, 60.0, 100.0);
    msg = "Second bus arrived at base (empty)";
    std::cout << msg << std::endl;
    bus2->arrive();
    printBaseStatus();

    msg = "Second bus trying to leave...";
    std::cout << msg << std::endl;
    if (bus2->leave()) {
        std::cout << "Second bus left successfully" << std::endl;
        std::cout << "Passengers in second bus: " << bus2->getPeopleCount() << std::endl;
    } else {
        std::cout << "Second bus could not leave" << std::endl;
    }
    printBaseStatus();

    delete car;
    delete bus;
    delete truck;
    delete bus2;

    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}
