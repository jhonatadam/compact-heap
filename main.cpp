#include <iostream>
#include <compactheap.h>

using namespace std;

int main()
{
    BitArray ba;
    ba.resize(18);
    ba.turnOn(7);
//    ba.turnOff(10);

    cout << ba[7] << endl;
    cout << ba.toString() << endl;
    return 0;
}
