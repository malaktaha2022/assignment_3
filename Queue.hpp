//
//  Queue.hpp
//  assign3
//
//  Created by Malak Abdelhalim on 25/03/2023.
//

#ifndef Queue_hpp
#define Queue_hpp
#include "Mechanic.hpp"
#include "Customer.hpp"

#include <iostream>
using namespace std;

// generic queue class template to work with any data type
template <class T>
class queue
{
private:
    // position variables to navigate queue
    int first;
    int last;
    int counter;
    // assume the maximum number of mechanics and customers is 5
    T arr[5];
public:
    // default contstructor implementing circular queue
    queue()
    {
        first = 0;
        last = -1;
        counter = 0;
    }
    // to enqueue an element into our queue
    void push(T value);
    // to dequeue an element from our queue
    T pop();
    int get_counter();
};

#endif /* Queue_hpp */
