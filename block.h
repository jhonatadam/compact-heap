#ifndef BITBLOCK_H
#define BITBLOCK_H

#include <string>

using namespace std;

class BitBlock
{
    uint8_t block = 0;
public:
    BitBlock();

    bool operator[](int index);
    void turnOn(int index);
    void turnOff(int index);

    int getBlockSize() const;

    string toString();
};

#endif // BITBLOCK_H
