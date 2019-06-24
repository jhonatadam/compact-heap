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

void CompactHeap::climb(size_t index)
{
    size_t newValIdx = index;
    while(newValIdx != 0)
    {
        size_t parentIdx = this->parent(newValIdx);
        if (compArray.isLessThanOrEqualTo(parentIdx, newValIdx))
            break;
        compArray.swap(parentIdx, newValIdx);
        newValIdx = parentIdx;
    }
}

void CompactHeap::heapify(size_t index)
{
    size_t smaller = index;

    if (left(index) < compArray.getSize())
        if (!compArray.isLessThanOrEqualTo(smaller, left(index)))
            smaller = left(index);

    if (right(index) < compArray.getSize())
        if (!compArray.isLessThanOrEqualTo(smaller, right(index)))
            smaller = right(index);

    if (smaller != index)
    {
        compArray.swap(index, smaller);
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
    climb(compArray.getSize() - 1);
}

unsigned long CompactHeap::removeMin()
{
    if (compArray.getSize() == 0)
        throw std::length_error("CompactHeap::removeMin(): heap is empty.");

    unsigned long min = compArray[0];

    compArray.swap(0, compArray.getSize() - 1);
    compArray.remove();
    heapify(0);

    return min;
}

void CompactHeap::changePriority(unsigned long value, size_t index)
{
    if (compArray[index] > value)
    {
        compArray.insert(value, index);
        climb(index);
    }
    else
    {
        compArray.insert(value, index);
        heapify(index);
    }
}

size_t CompactHeap::getSize()
{
    return compArray.getSize();
}

string CompactHeap::toString()
{
    return compArray.toString();
}
