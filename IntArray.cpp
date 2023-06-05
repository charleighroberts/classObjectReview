//contents of IntArray.cpp
//implementation file for the IntArray class
#include <iostream>
#include <cstdlib> //for exit function
#include "IntArray.h"
using namespace std;

/*Constructor for the IntArray class. Sets the size of the array and allocates memory for it.*/
IntArray::IntArray(int s)
{
    arraysize = s;
    aptr = new int[s];
    for (int count = 0; count < arraysize; count++)
    {
        *(aptr + count) = 0;
    }
}

//copy constructor
IntArray::IntArray(const IntArray &obj)
{
    arraysize =obj.arraysize;
    aptr = new int[arraysize];
    for (int count = 0; count < arraysize; count++)
    {
        *(aptr + count) = *(obj.aptr + count);
    }
}

// deconstructor
IntArray::~IntArray()
{
    if (arraysize > 0)
        delete[] aptr;
}

//subscript error function
void IntArray::subscriptError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(0);
}

//overloaded [] operator. the argument is a subscript. this fuction returns a refernce to the element in the array indexed by the subscript
int& IntArray::operator[](const int& sub)
{
    if (sub < 0 || sub >= arraysize)
        subscriptError();
    return aptr[sub];
}