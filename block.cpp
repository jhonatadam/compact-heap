#include "block.h"

const size_t BitBlock::blockSize = sizeof(unsigned long) * 8;

void BitBlock::clean(unsigned long &value, size_t begin, size_t end)
{
    unsigned long left = 0;
    unsigned long right = 0;

    if (begin > 0)
        left =  (value >> (blockSize-begin)) << (blockSize-begin);
    if (end < blockSize-1)
        right = (value << (end+1)) >> (end+1);

    value = left | right;
}

BitBlock::BitBlock()
{

}

void BitBlock::update(unsigned long value, size_t begin, size_t end)
{
    if ((end >= blockSize) || (end < begin))
        throw std::out_of_range("BitBlock::operator[](): invalid interval.");

    unsigned long valueCopy = value;
    clean(valueCopy, begin, end);
    clean(block, begin, end);
    block = block | (value ^ valueCopy);
}

unsigned long BitBlock::getValue(size_t begin, size_t end)
{
    unsigned long blockCopy = block;
    clean(blockCopy, begin, end);
    return (block ^ blockCopy) >> (BitBlock::blockSize - end - 1);
}

string BitBlock::toString()
{
    string str_block(blockSize, '0');
    for (size_t i = 0; i < blockSize; ++i)
    {
        if ((block>>(blockSize-i-1)) & 1)
            str_block[unsigned(i)] = '1';
    }
    return str_block;
}
