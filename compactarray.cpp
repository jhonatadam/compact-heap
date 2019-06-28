#include "compactarray.h"

void CompactArray::resizeBlocks(size_t newCapacity)
{
    size_t numBits = newCapacity * b;

    size_t numBlocks = numBits/BitBlock::blockSize;
    numBlocks += (numBits % BitBlock::blockSize) > 0;
    if (numBlocks != blocks.size())
        blocks.resize(numBlocks);

    capacity = newCapacity;
}

CompactArray::CompactArray(size_t b):
    b(b), size(0)
{
    resizeBlocks(1);
}

CompactArray::CompactArray(size_t b, size_t size):
    b(b), size(0)
{
    resizeBlocks(1);

    srand(unsigned(time(nullptr)));
    for (size_t i = 0; i < size; i++)
    {
        unsigned long max = 0;
        max = ~max;
        max = (max << (BitBlock::blockSize - b)) >> (BitBlock::blockSize - b);
        unsigned long value = unsigned(rand()) % max;
        this->insert(value);
    }
}

void CompactArray::insert(unsigned long value)
{
    if (size >= capacity)
        resizeBlocks(capacity * 2);
    size++;
    update(value, size-1);
}

void CompactArray::update(unsigned long value, size_t index)
{
    if (index >= size)
        throw out_of_range("CompactArray::update(): invalid index.");

    size_t initialBit = b * index;
    size_t block = initialBit / BitBlock::blockSize;
    size_t blockBit = initialBit % BitBlock::blockSize;

    // if 'value' fits in the block
    if ((blockBit + b) <= BitBlock::blockSize)
    {
        value  = value << (BitBlock::blockSize - blockBit - b);
        blocks[block].update(value, blockBit, blockBit + b - 1);
    }
    else
    {
        size_t first = BitBlock::blockSize - blockBit;
        size_t second = b - first;
        blocks[block].update(value>>second, blockBit, BitBlock::blockSize - 1);
        blocks[block + 1].update(value<<(BitBlock::blockSize - second), 0, second - 1);
    }
}

void CompactArray::remove()
{
    if (size > 0)
    {
        size--;
        if (size < (capacity / 4))
            resizeBlocks(capacity/2);
    }
}

unsigned long CompactArray::operator[](size_t index)
{
    if (index >= size)
        throw out_of_range("CompactArray::update(): invalid index.");

    size_t initialBit = b * index;
    size_t block = initialBit / BitBlock::blockSize;
    size_t blockBit = initialBit % BitBlock::blockSize;

    unsigned long value = 0;

    // if 'value' fits in the block
    if ((blockBit + b) <= BitBlock::blockSize)
        value = blocks[block].getValue(blockBit, blockBit + b - 1);
    else
    {
        size_t first = BitBlock::blockSize - blockBit;
        size_t second = b - first;
        value = blocks[block].getValue(blockBit, BitBlock::blockSize - 1) << second;
        value = value | blocks[block + 1].getValue(0, second - 1);
    }

    return value;
}

void CompactArray::swap(const size_t i, const size_t j)
{
    unsigned long a = this->operator[](i);
    unsigned long b = this->operator[](j);

    this->update(b, i);
    this->update(a, j);
}

size_t CompactArray::getSize() const
{
    return size;
}

string CompactArray::toBitString()
{
    string strArray;
    for (size_t i = 0; i < size; i++)
        strArray += blocks[i].toString();
    return strArray;
}

string CompactArray::toString()
{
    if (size == 0)
        return "[]";

    string str = "[";
    for (size_t i = 0; i < (size - 1); i++)
        str = str + to_string(this->operator[](i)) + ", ";
    str = str + to_string(this->operator[](size-1)) + "]\n";
    return str;
}
