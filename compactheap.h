#ifndef COMPACTHEAP_H
#define COMPACTHEAP_H

#include <compactarray.h>

class CompactHeap
{
    CompactArray compArray;

    size_t parent(size_t index);
    size_t left(size_t index);
    size_t right(size_t index);

    void heapify(size_t i);

public:
    CompactHeap(size_t b);
    CompactHeap(size_t b, size_t size);

    void insert(unsigned long value);
    void insert(string bits);

    unsigned long removeMin();

    string toString();

};

#endif // COMPACTHEAP_H
