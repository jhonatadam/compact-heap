#ifndef BITBLOCK_H
#define BITBLOCK_H

#include <iostream>
#include <stdexcept>

using namespace std;

class BitBlock
{
    // block of bits
    unsigned long block = 0;

    void clean(unsigned long &value, size_t begin, size_t end);

public:
    // number of bits of the block
    const static size_t blockSize;

    // contructor
    BitBlock();

    // it sets block range between 'begin' and 'end'
    // with the same range in 'value'
    void update(unsigned long value, size_t begin, size_t end);
    unsigned long getValue(size_t begin, size_t end);
    // it return a string containing block bits
    string toString();
};

#endif // BITBLOCK_H
