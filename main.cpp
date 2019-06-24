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
    CompactHeap ch(10, 16);
    cout << ch.toString() << endl;

    while (ch.getSize() > 0)
    {
        cout << ch.removeMin() << " " << endl;
        cout << ch.toString() << endl;
    }

    ch.insert(10);
    ch.insert(10);
    ch.insert(15);
    ch.insert(5);
    ch.insert(1);
    ch.insert(15);
    ch.insert(1);
    ch.changePriority(0, 2);
    cout << ch.toString() << endl;
}

int main()
{
//    testBitArray();
//    testCompactArray();
    testCompactHeap();

    return 0;
}
