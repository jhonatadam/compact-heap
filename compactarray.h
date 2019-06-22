#ifndef COMPACTARRAY_H
#define COMPACTARRAY_H

#include <bitarray.h>

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

    // insert a new element at the end of array
    void insert(unsigned long value);
    void insert(string bits);

    // remove a element from the end of array
    void remove();

    // returns 1 if i is greater than j,
    // 0 if they are equal and -1 otherwise.
    int compare(size_t i, size_t j);

    // swap
    void swap(size_t i, size_t j);

};

#endif // COMPACTARRAY_H
