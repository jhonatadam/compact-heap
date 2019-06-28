#include <iostream>
#include <compactheap.h>

using namespace std;

void testBitBlock()
{
    BitBlock bb;
    unsigned long value = 0;
    bb.update(~value, 0, 19);
    bb.update(~value, 21, 41);
    bb.update(~value, 43, 63);
    cout << bb.toString() << endl;
}

void testCompactArray()
{
    CompactArray ca(8, 2);
    ca.insert(1);
    ca.insert(5);
    ca.insert(8);
    ca.insert(20);
    cout << ca.toString();

    ca.update(0, 0);
    ca.update(15, 2);
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
    cout << ch.toString() << endl;
    ch.changePriority(0, 2);
    cout << ch.toString() << endl;
    ch.changePriority(20, 2);
    cout << ch.toString() << endl;
}

int main()
{
//    testBitBlock();
//    testCompactArray();
    testCompactHeap();

    return 0;
}
