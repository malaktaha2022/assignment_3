//
//  Queue.cpp
//  assign3
//
//  Created by Malak Abdelhalim on 25/03/2023.
//

#include "Queue.hpp"

template <class T>
void queue<T>::push(T value)
{
    if (counter >= 5)
    {
        cout << "the queue is already at capacity." << endl;
    }
    else
    {
        last = (last + 1) %5;
        arr[last] = value;
        counter++;
    }
}

template <class T>
T queue<T>::pop()
{
    if (counter <= 0)
    {
        cout << "the queue is empty." << endl;
        exit(1);
    }
    else
    {
        T temp;
        temp = arr[first];
        first = (first + 1) %5;
        counter--;
        return temp;
    }
}

template <class T>
int queue<T>::get_counter()
{
    return counter;
}
