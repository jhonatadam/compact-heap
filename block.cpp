#include "block.h"

BitBlock::BitBlock()
{

}

bool BitBlock::operator[](size_t index) const
{

    if (index >= blockSize)
        throw std::out_of_range("BitBlock::operator[](): invalid index.");

    return ((block>>index) & 1);
}

void BitBlock::turnOn(size_t index)
{
    if (index >= blockSize)
        throw std::out_of_range("BitBlock::turnOn(): invalid index.");

    block = block | uint8_t(1<<index);
}

void BitBlock::turnOff(size_t index)
{
    if (index >= blockSize)
        throw std::out_of_range("BitBlock::turnOff(): invalid index.");

    if ((block>>index) & 1)
        block = block ^ uint8_t(1<<index);
}

size_t BitBlock::getBlockSize() const
{
    return blockSize;
}

string BitBlock::toString()
{
    string str_block(blockSize, '0');
    for (size_t i = 0; i < blockSize; ++i)
    {
        if ((block>>i) & 1)
            str_block[unsigned(i)] = '1';
    }
    return str_block;
}
