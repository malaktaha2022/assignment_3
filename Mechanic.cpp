//
//  Mechanic.cpp
//  assign3
//
//  Created by Malak Abdelhalim on 25/03/2023.
//

#include "Mechanic.hpp"

Mechanic::Mechanic()
{
    counter = 0;
}

Mechanic::Mechanic(string n, int a, int mechid)
{
    set_name(n);
    set_age(a);
    set_id(mechid);
}

bool Mechanic:: is_available(int hr, int min)
{
    int slot = hr%24;
    if (appointment[slot].hours == -1)
        return true;
    else
        return false;
}

void Mechanic::setappointment(int hr, int min)
{
    if (((hr >= 0) && (hr < 24)) && min == 0)
    {
        if (is_available(hr, min))
        {
            int slot = hr%24;
            counter++;
            appointment[slot].hours = hr;
            appointment[slot].minutes = min;
        }
    }
    else
        cout << "the time you entered is invalid. please enter a valid appointment time." << endl;
}

void Mechanic::getappointments(Appointment arr[])
{
    arr = appointment;
}

void Mechanic::print()
{
    cout << "name: " << get_name() << endl;
    cout << "age: " << get_age() << endl;
    cout << "id: " << get_id() << endl;
};
