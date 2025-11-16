#include "Bus.h"
#include "Base.h"

Bus::Bus(int people, int max_people, double petrol, double max_petrol)
    : Vehicle(petrol, max_petrol) {
    this->people = people;
    this->max_people = max_people;
}

int Bus::getPeopleCount() {
    return people;
}

int Bus::getMaxPeople() {
    return max_people;
}

void Bus::arrive() {
    // Машина приезжает на базу
    Base::vehicles_on_base++;
    Base::people_on_base++; // добавляем водителя
    Base::people_on_base += people; // добавляем пассажиров

    // Выгружаем всех пассажиров
    people = 0;
}

bool Bus::leave() {
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

    // Забираем как можно больше людей
    // Нужно оставить водителя, поэтому проверяем people_on_base - 1
    int available_people = Base::people_on_base - 1;
    int people_to_take = (available_people < max_people) ? available_people : max_people;

    people = people_to_take;
    Base::people_on_base -= people_to_take;

    // Убираем машину и водителя с базы
    Base::vehicles_on_base--;
    Base::people_on_base--;

    return true;
}
