//
//  Person.cpp
//  assign3
//
//  Created by Malak Abdelhalim on 25/03/2023.
//

#include "Person.hpp"
Person::Person()
{
    name = " ";
    id = 0;
    age = 0;
}
void Person::set_name(string n)
{
    name = n;
}
void Person::set_id(int i)
{
    id = i;
}
void Person::set_age(int a)
{
    age = a;
}
string Person::get_name()
{
    return name;
}
int Person::get_id()
{
    return id;
}
int Person::get_age()
{
    return age;
}

