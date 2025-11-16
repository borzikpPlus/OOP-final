#pragma once

class Vehicle {
protected:
    double petrol_amount;
    double tank_volume;

public:
    Vehicle(double petrol_amount, double tank_volume);
    virtual ~Vehicle();

    double getTankVolume();
    double getPetrolAmount();

    virtual void arrive();
    virtual bool leave();
};
