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
        throw(idxExeption);

    size_t block = index/8;
    int blockIdx = (index%8);
    return bitBlocks[block][blockIdx];
}

void BitArray::resize(size_t size)
{
    BitBlock bb;
    size_t numBlocks = size/unsigned(bb.getBlockSize());
    numBlocks += (size % unsigned(bb.getBlockSize())) > 0;
    bitBlocks.resize(numBlocks);
}

void BitArray::turnOn(size_t index)
{
    if (index >= getSize())
        throw(idxExeption);

    size_t block = index/8;
    int blockIdx = (index%8);
    bitBlocks[block].turnOn(blockIdx);
}

void BitArray::turnOff(size_t index)
{
    if (index >= getSize())
        throw(idxExeption);

    size_t block = index/8;
    int blockIdx = (index%8);
    bitBlocks[block].turnOff(blockIdx);
}

size_t BitArray::getSize()
{
    if (!bitBlocks.empty())
        return bitBlocks.size() * size_t(bitBlocks.front().getBlockSize());
    return 0;
}

string BitArray::toString()
{
    string strBitBlocks = "";
    for (BitBlock& b: bitBlocks)
        strBitBlocks = strBitBlocks + b.toString() + " " ;
    return strBitBlocks;
}
