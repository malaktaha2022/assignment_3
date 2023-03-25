//
//  Customer.hpp
//  assign3
//
//  Created by Malak Abdelhalim on 25/03/2023.
//

#include "Person.hpp"
#ifndef Customer_hpp
#define Customer_hpp

#include <iostream>
using namespace std;

// class customer which inherits from class person
class Customer: public Person
{
    // the private variables of customer
private:
    int mechanicid;
    Appointment appointment;
public:
    // default constructor
    Customer();
    // parametized constructor to easily set all the variables of the customer
    Customer(string, int, int, int, int);
    // setters and getters for the mechanic appointed's id
    void set_mechanicid(int);
    int get_mechanicid();
    // overloading the <,>, & == operators to compare between customer's appointments
    bool operator<(const Customer &p);
    bool operator>(const Customer &p);
    bool operator==(const Customer &p);
    // sets an appointment for a customer assuming each appointment is an hour long
    void set_appointment (int, int);
    //returns the appointment time the customer requests
    void get_appointment (int &hr, int &min);
    
    void print(); // providing an implementation for the pure virtual function in the abstract class person. making this class 'customer' not abstract. 
};



#endif /* Customer_hpp */
