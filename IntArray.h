//specification for the IntArray class
#ifndef INTARRAY_H
#degin INTARRAY_H

class IntArray
{
private:
    int *aptr; //pointer to the array
    int arraysize; //holds array size
    void subscriptError(); //handles invalid subscripts
public:
    IntArray(int); //constructor
    IntArray(const IntArray&); //handles invalid sbscripts
    ~IntArray(); //destructor

    int size() const   //returns array size
    {
        return arraysize;
    }

    int& operator[](const int&); //overloaded [] operator
};
#endif