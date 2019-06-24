#include "compactheap.h"

size_t CompactHeap::parent(size_t index)
{
    return (index - 1)/2;
}

size_t CompactHeap::left(size_t index)
{
    return index * 2 + 1;
}

size_t CompactHeap::right(size_t index)
{
    return index * 2 + 2;
}

void CompactHeap::heapify(size_t item)
{
    size_t smaller = item;

    if (left(item) < compArray.getSize())
        if (!compArray.isLessThanOrEqualTo(smaller, left(item)))
            smaller = left(item);

    if (right(item) < compArray.getSize())
        if (!compArray.isLessThanOrEqualTo(smaller, right(item)))
            smaller = right(item);

    if (smaller != item)
    {
        compArray.swap(item, smaller);
        heapify(smaller);
    }
}

CompactHeap::CompactHeap(size_t b) : compArray(b)
{
}

CompactHeap::CompactHeap(size_t b, size_t size): compArray(b, size)
{
    size_t i = this->parent(compArray.getSize() -1);
    while (true)
    {
        heapify(i);
        if (i == 0)
            break;
        i--;
    }
}

void CompactHeap::insert(unsigned long value)
{
    compArray.insert(value);
    size_t newValIdx = compArray.getSize() - 1;

    while(newValIdx != 0)
    {
        size_t parentIdx = this->parent(newValIdx);
        if (compArray.isLessThanOrEqualTo(parentIdx, newValIdx))
            break;
        compArray.swap(parentIdx, newValIdx);
        newValIdx = parentIdx;
    }
}

string CompactHeap::toString()
{
    return compArray.toString();
}
