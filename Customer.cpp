//
//  Customer.cpp
//  assign3
//
//  Created by Malak Abdelhalim on 25/03/2023.
//

#include "Customer.hpp"

Customer::Customer()
{
    mechanicid = 0;
    appointment.hours = 0;
    appointment.minutes = 0;
}

Customer::Customer(string n, int a, int mechid, int h, int m)
{
    set_name(n);
    set_age(a);
    mechanicid = mechid;
    appointment.hours = h;
    appointment.minutes = m;
}

void Customer::set_mechanicid(int mechid)
{
    mechanicid = mechid;
};

int Customer::get_mechanicid()
{
    return mechanicid;
};

bool Customer::operator<(const Customer &app)
{
    if (appointment.hours < app.appointment.hours)
        return true;
    else if ((appointment.hours == app.appointment.hours) && (appointment.minutes < app.appointment.minutes))
        return true;
    else
        return false;
};

bool Customer::operator>(const Customer &app)
{
    if (appointment.hours > app.appointment.hours)
        return true;
    else if ((appointment.hours == app.appointment.hours) && (appointment.minutes > app.appointment.minutes))
        return true;
    else
        return false;
};

bool Customer::operator==(const Customer &app)
{
    if ((appointment.hours == app.appointment.hours) && (appointment.minutes == app.appointment.minutes))
        return true;
    else
        return false;
};

void Customer::set_appointment(int h, int m)
{
    if (((h >= 0) && (h < 24)) && (m == 0))
    {
        appointment.hours = h;
        appointment.minutes = m;
    }
    else
        cout << "the time you have entered is invalid. please try again." << endl;
};

void Customer::get_appointment(int &hr, int &min)
{
    if (appointment.hours == -1 && appointment.minutes == -1)
        cout << "no scheduled appointment. please schedule an appointment first." << endl;
    else
    {
        hr = appointment.hours;
        min = appointment.minutes;
    }
};

void Customer::print()
{
    cout << "name: " << get_name() << endl;
    cout << "age: " << get_age() << endl;
    cout << "mechanic id:" << mechanicid << endl;
    cout << "apointment time: " << appointment.hours << ":" << appointment.minutes << endl;
};


