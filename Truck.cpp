#include "Truck.h"
#include "Base.h"

Truck::Truck(double load, double max_load, double petrol, double max_petrol)
    : Vehicle(petrol, max_petrol) {
    this->load = load;
    this->max_load = max_load;
}

double Truck::getCurrentLoad() {
    return load;
}

double Truck::getMaxLoad() {
    return max_load;
}

void Truck::arrive() {
    // Машина приезжает на базу
    Base::vehicles_on_base++;
    Base::people_on_base++; // добавляем водителя
    Base::goods_on_base += load; // добавляем груз

    // Выгружаем весь груз
    load = 0;
}

bool Truck::leave() {
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

    // Забираем как можно больше груза
    double goods_to_take = (Base::goods_on_base < max_load) ? Base::goods_on_base : max_load;

    load = goods_to_take;
    Base::goods_on_base -= goods_to_take;

    // Убираем машину и водителя с базы
    Base::vehicles_on_base--;
    Base::people_on_base--;

    return true;
}
