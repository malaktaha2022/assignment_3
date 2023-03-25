/*
 Malak Abdelhalim
 900222407
 Assignment 3
 Sat 25 March
 */
#include "Person.hpp"
#include "Customer.hpp"
#include "Mechanic.hpp"
#include "Queue.hpp"
#include "Queue.cpp"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // i have always at most 5 mechanics and 5 customers
    Mechanic m1, m2, m3;
    string n1, n2, n3;
    // gathering the mechanic's names from the user
    cout << "what are the names of the available mechanics today?" << endl;
    cin >> n1 >> n2 >> n3;
    m1.set_name(n1);
    m2.set_name(n2);
    m3.set_name(n3);
    m1.set_id(34);
    m2.set_id(35);
    m3.set_id(36);
    
    // initializing five customers with their appointments
    Customer c1;
    c1.set_name("Ahmed");
    c1.set_appointment(1,00);
    Customer c2;
    c2.set_name("Sara");
    c2.set_appointment(4,00);
    Customer c3;
    c3.set_name("Kareem");
    c3.set_appointment(3,00);
    Customer c4;
    c4.set_name("Mohammed");
    c4.set_appointment(1,00);
    Customer c5;
    c5.set_name("Malak");
    c5.set_appointment(1,00);

    // creating an array of my five customers
    Customer c_arr[5];
    Customer temp;
    
    // two queues for the mechanics and customers
    queue <Customer> q1;
    queue <Mechanic> q2;
    
    // input my customers into their array
    c_arr[0] = c1;
    c_arr[1] = c2;
    c_arr[2] = c3;
    c_arr[3] = c4;
    c_arr[4] = c5;
    
    // push the mechanics into the queue
    q2.push(m1);
    q2.push(m2);
    q2.push(m3);
    
    // bubble sort using the overloaded operators to sort with the earliest appointment
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (c_arr[i] > c_arr[j])
            {
                temp = c_arr[j];
                c_arr[j] = c_arr[i];
                c_arr[i] = temp;
            }
        }
    }
    
    // push ordered customers into their queue
    q1.push(c_arr[0]);
    q1.push(c_arr[1]);
    q1.push(c_arr[2]);
    q1.push(c_arr[3]);
    q1.push(c_arr[4]);
    
    Customer carr[5];
    Mechanic marr[5];
    
    int x = 0, y = 0;
    // x is the customers y is the mechanics
    while (q1.get_counter() >= 0) //loops on all customers
    {
        if (!q1.get_counter())
        {
            break;
        }
        
        Mechanic mtemp = q2.pop();
        Customer ctemp = q1.pop();
        
        carr[x] = ctemp;
        marr[y] = mtemp;
        
        int hrs;
        int mins;
        
        ctemp.get_appointment(hrs, mins);
        // if a mechanic is unavailable check other mechanics at that time slot
        while (q2.get_counter() > 0 && !(mtemp.is_available(hrs,mins)))
        {
            y++;
            mtemp = q2.pop();
            marr[y] = mtemp;
        }
        if (q2.get_counter() <= 0)
            // if no mechanic is available at that time at all then the appointment cant be placed
        {
            cout << "no availability with our mechanics at that time. apologies mr/mrs." << carr[x].get_name() << endl;
        }
        else
        {
            // a mechanic is available
            marr[y].setappointment(hrs, mins); // takes a specific slot from the chosen mechanic's time
            carr[x].set_mechanicid(marr[y].get_id());
            //takes the mechanic's id and assigns it to customer mechanic id in the customer class
            
            // printing the appointment details in order of time slots with mechanics
            cout << "appointment scheduled for customer " << carr[x].get_name() << " at: " << hrs << ":" << mins << "0" << " with mechanic " << marr[y].get_name() << " with ID: " << carr[x].get_mechanicid() << endl;
            
        }
        
        while (y >= 0)
        {
            // returns mechanic to queue for next customer
            q2.push(marr[y]);
            y--;
        }
        
        if (y == -1)
        {
            y = 0;
        }
        x++;
        
    }
}
