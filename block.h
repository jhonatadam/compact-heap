#ifndef BITBLOCK_H
#define BITBLOCK_H

#include <string>
#include <stdexcept>

using namespace std;

class BitBlock
{
    // block of bits
    uint8_t block = 0;
    // number of bits of the block
    size_t blockSize = sizeof(uint8_t) * 8;

public:
    // contructor
    BitBlock();

    // get bit at the 'index' position
    bool operator[](size_t index) const;
    // turn into 1 a bit at 'index'
    void turnOn(size_t index);
    // turn into 0 a bit at 'index'
    void turnOff(size_t index);
    // return the number of bits of the block
    size_t getBlockSize() const;
    // return a string containing the bits of the block
    string toString();

};

#endif // BITBLOCK_H
