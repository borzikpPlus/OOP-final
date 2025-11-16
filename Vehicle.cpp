#include "Vehicle.h"
#include "Base.h"

Vehicle::Vehicle(double petrol_amount, double tank_volume) {
    this->petrol_amount = petrol_amount;
    this->tank_volume = tank_volume;
}

Vehicle::~Vehicle() {
}

double Vehicle::getTankVolume() {
    return tank_volume;
}

double Vehicle::getPetrolAmount() {
    return petrol_amount;
}

void Vehicle::arrive() {
    // Машина приезжает на базу
    Base::vehicles_on_base++;
    Base::people_on_base++; // добавляем водителя
}

bool Vehicle::leave() {
    // Проверяем, есть ли водитель
    if (Base::people_on_base < 1) {
        return false;
    }

    // Сколько нужно бензина для полного бака
    double needed_petrol = tank_volume - petrol_amount;

    // Проверяем, достаточно ли бензина на базе
    if (Base::petrol_on_base < needed_petrol) {
        return false;
    }

    // Заправляем полный бак
    Base::petrol_on_base -= needed_petrol;
    petrol_amount = tank_volume;

    // Убираем машину и водителя с базы
    Base::vehicles_on_base--;
    Base::people_on_base--;

    return true;
}
