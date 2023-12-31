
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pcb.hpp"


//podemos utilizar una semilla para neviarle los datos en timepo real
/* const unsigned int SEED = 0; */
// Random Time Slice
int RandomTimeSlice()
{
    srand(time(NULL));
    return rand() % 100 + 1;
}

// Create PCB Array

void CreatePCBArray(PCB *array, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        array[i] = PCB();
    }
}

#endif