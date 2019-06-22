#ifndef BITARRAY_H
#define BITARRAY_H

#include <block.h>

#include <vector>

using namespace std;

class BitArray
{
    // array containing all bits
    vector<BitBlock> bitBlocks;

    // index exeption
    string idxExeption = "BitArray: invalid index.\n";

public:
    BitArray();
    BitArray(size_t size);

    bool operator[](size_t index);
    void resize(size_t size);
    void turnOn(size_t index);
    void turnOff(size_t index);
    size_t getSize();
    string toString();
};

#endif // BITARRAY_H
