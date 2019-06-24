#ifndef COMPACTARRAY_H
#define COMPACTARRAY_H

#include <bitarray.h>

#include <iostream>
#include <cmath>

using namespace std;

class CompactArray
{
    // values saved are at most 2^b -1
    const size_t b;
    // array size
    size_t size;
    // bit array
    BitArray bits;

public:
    CompactArray(size_t b);
    // build a random array
    CompactArray(size_t b, size_t size);

    // insert a new element at the end of array
    void insert(unsigned long value);

    // remove a element from the end of array
    void remove();

    unsigned long operator[](size_t index);

    // returns 1 if i is less than or equal to j;
    // 0, otherwise
    int isLessThanOrEqualTo(size_t i, size_t j);

    // swap
    void swap(const size_t i, const size_t j);

    size_t getSize();
    // returns an array bit string
    string toBitString();
    // return a string array
    string toString();
};

#endif // COMPACTARRAY_H
