#include "bitarray.h"

BitArray::BitArray()
{

}

BitArray::BitArray(size_t size)
{
    resize(size);
}

bool BitArray::operator[](size_t index)
{
    if (index >= getSize())
        throw out_of_range("BitArray::operator[](): invalid index.");

    size_t arrayIdx = index/bitBlocks.front().getBlockSize();
    size_t blockIdx = (index%bitBlocks.front().getBlockSize());
    return bitBlocks[arrayIdx][blockIdx];
}

void BitArray::turnOn(size_t index)
{
    if (index >= getSize())
        throw out_of_range("BitArray::turnOn(): invalid index.");

    size_t arrayIdx = index/bitBlocks.front().getBlockSize();
    size_t blockIdx = (index%bitBlocks.front().getBlockSize());
    bitBlocks[arrayIdx].turnOn(blockIdx);
}

void BitArray::turnOff(size_t index)
{
    if (index >= getSize())
        throw out_of_range("BitArray::turnOff(): invalid index.");

    size_t arrayIdx = index/bitBlocks.front().getBlockSize();
    size_t blockIdx = (index%bitBlocks.front().getBlockSize());
    bitBlocks[arrayIdx].turnOff(blockIdx);
}

size_t BitArray::getSize()
{
    if (!bitBlocks.empty())
        return bitBlocks.size() * bitBlocks.front().getBlockSize();
    return 0;
}

void BitArray::resize(size_t size)
{
    BitBlock bb;
    size_t numBlocks = size/bb.getBlockSize();
    numBlocks += (size % bb.getBlockSize()) > 0;
    bitBlocks.resize(numBlocks);
}

string BitArray::toString()
{
    string strBitBlocks = "";
    for (BitBlock& b: bitBlocks)
        strBitBlocks = strBitBlocks + b.toString() + " " ;
    return strBitBlocks;
}
