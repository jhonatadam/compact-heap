#include "block.h"

BitBlock::BitBlock()
{

}

bool BitBlock::operator[](int index)
{
    return ((block>>index) & 1);
}

void BitBlock::turnOn(int index)
{
    if (index >= 0 && index < getBlockSize())
        block = block | uint8_t(1<<index);
}

void BitBlock::turnOff(int index)
{
    if (index >= 0 && index < getBlockSize())
        if ((block>>index) & 1)
            block = block ^ uint8_t(1<<index);
}

int BitBlock::getBlockSize() const
{
    return sizeof(uint8_t) * 8;
}

string BitBlock::toString()
{
    string str_block(unsigned(getBlockSize()), '0');
    for (int i = 0; i < getBlockSize(); ++i)
    {
        if ((block>>i) & 1)
            str_block[unsigned(i)] = '1';
    }
    return str_block;
}
