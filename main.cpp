#include <iostream>
#include <bitarray.h>

using namespace std;

int main()
{
    BitArray ba(25);
    ba.turnOn(10);
    ba.turnOn(3);
    ba.turnOn(0);
    ba.turnOff(2);
    cout << ba.toString() << endl;
    ba.resize(1);
    cout << ba[1] << endl;
    return 0;
}
