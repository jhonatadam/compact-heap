#include <iostream>
#include <compactheap.h>

using namespace std;

void testBitArray()
{
    BitArray ba(15);

    ba.turnOn(10);
    ba.turnOn(5);
    ba.turnOn(4);

    ba.turnOff(4);

    cout << ba.toString() << endl;
}

void testCompactArray()
{
    CompactArray ca(6, 8);

    ca.insert(8);
    ca.insert(8);
    cout << ca.toBitString() << endl;
    cout << ca.toString() << endl;

    ca.swap(1, 0);
    cout << ca.toBitString() << endl;
    cout << ca.toString() << endl;
}

void testCompactHeap()
{
    CompactHeap ch;
}

int main()
{
//    testBitArray();
//    testCompactArray();
    testCompactHeap();

    return 0;
}
