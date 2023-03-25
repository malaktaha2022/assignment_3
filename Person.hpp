//
//  Person.hpp
//  assign3
//
//  Created by Malak Abdelhalim on 25/03/2023.
//

#ifndef Person_hpp
#define Person_hpp

#include <iostream>
using namespace std;

class Person
{
    // member variables of the person
private:
        string name;
        int id;
        int age;
    
public:
    // default constructor. parametized constructor not required here
    Person();
    // setters for the variables
    void set_name(string);
    void set_id(int);
    void set_age(int);
    // getters
    string get_name();
    int get_id();
    int get_age();
    // pure virtual funtion to make class person an abstract class
    virtual void print() = 0;
    // a struct of type appointment with members hours and minutes in 24 hour system
    struct Appointment
    {
        // initialized to -1 to indicate the availability of a person
        int hours = -1;
        int minutes = -1;
    };
};


#endif /* Person_hpp */
