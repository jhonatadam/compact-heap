#ifndef COMPACTARRAY_H
#define COMPACTARRAY_H

#include <block.h>

#include <vector>

using namespace std;

class CompactArray
{
    // values saved are at most 2^b -1
    const size_t b;
    // blocks array size
    size_t size;
    // blocks array capacity
    size_t capacity;
    // block array
    vector<BitBlock> blocks;

    void resizeBlocks(size_t newCapacity);

public:
    CompactArray(size_t b);
    // build a random array
    CompactArray(size_t b, size_t size);

    // insert a new element at the end of array
    void insert(unsigned long value);
    // insert a new element in a given position (index)
    // of array
    void update(unsigned long value, size_t index);
    // remove a element from the end of array
    void remove();
    unsigned long operator[](size_t index);
    // swap
    void swap(const size_t i, const size_t j);
    size_t getSize() const;
    // returns an array bit string
    string toBitString();
    // return a string array
    string toString();
};

#endif // COMPACTARRAY_H
