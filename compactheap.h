#ifndef COMPACTHEAP_H
#define COMPACTHEAP_H

#include <compactarray.h>

class CompactHeap
{
    CompactArray compArray;

public:
    CompactHeap();

    void insert(unsigned long value);
    void insert(string bits);

    unsigned long removeMin();

};

#endif // COMPACTHEAP_H
