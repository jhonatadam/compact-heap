#include "bitarray.h"

BitArray::BitArray()
{
    size = 0;
}

BitArray::BitArray(size_t size)
{
    resize(size);
}

bool BitArray::operator[](size_t index)
{
    if (index >= size)
        throw out_of_range("BitArray::operator[](): invalid index.");

    size_t arrayIdx = index/bitBlocks.front().getBlockSize();
    size_t blockIdx = (index%bitBlocks.front().getBlockSize());
    return bitBlocks[arrayIdx][blockIdx];
}

void BitArray::turnOn(size_t index)
{
    if (index >= size)
        throw out_of_range("BitArray::turnOn(): invalid index.");

    size_t arrayIdx = index/bitBlocks.front().getBlockSize();
    size_t blockIdx = (index%bitBlocks.front().getBlockSize());
    bitBlocks[arrayIdx].turnOn(blockIdx);
}

void BitArray::turnOff(size_t index)
{
    if (index >= size)
        throw out_of_range("BitArray::turnOff(): invalid index.");

    size_t arrayIdx = index/bitBlocks.front().getBlockSize();
    size_t blockIdx = (index%bitBlocks.front().getBlockSize());
    bitBlocks[arrayIdx].turnOff(blockIdx);
}

size_t BitArray::getSize()
{
    return size;
}

void BitArray::resize(size_t size)
{
    BitBlock bb;
    size_t numBlocks = size/bb.getBlockSize();
    numBlocks += (size % bb.getBlockSize()) > 0;
    bitBlocks.resize(numBlocks);
    this->size = size;
}

string BitArray::toString()
{
    string strBitBlocks = "";
    for (size_t i = 0; i < size; i++)
    {
        size_t arrayIdx = i/bitBlocks.front().getBlockSize();
        size_t blockIdx = (i%bitBlocks.front().getBlockSize());
        if (bitBlocks[arrayIdx][blockIdx])
            strBitBlocks.append("1");
        else
            strBitBlocks.append("0");
    }

    return strBitBlocks;
}
