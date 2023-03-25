//
//  Mechanic.hpp
//  assign3
//
//  Created by Malak Abdelhalim on 25/03/2023.
//

#ifndef Mechanic_hpp
#define Mechanic_hpp
#include "Person.hpp"
#include <iostream>

// class mechanic that inherits from class person
class Mechanic: public Person
{
    // private member variables
private:
    // number of appointments a mechanic has that day
    int counter;
    // there are 24 possible appointment times during a mechanic's day
    Appointment appointment[24];
public:
    // default constructor
    Mechanic();
    // parametized constructor to enter mechanic's details more easily in the main
    Mechanic(string, int, int);
    // checks the 24 slots of the mechanic's day using the hours & minutes and returns whether the mechanic is available in a specific slot
    bool is_available(int, int);
    // sets up appointment for a customer at the given hour and minute
    void setappointment(int, int);
    // gets the appointment slot and inputs it in the array
    void getappointments(Appointment arr[]);
    
    void print(); // providing an implementation for the pure virtual function in the abstract class person. making this class 'mechanic' not abstract.
};

#endif /* Mechanic_hpp */
