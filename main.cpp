#include <iostream>
#include <compactheap.h>

using namespace std;

int main()
{
    BitBlock b;
    b.turnOn(7);
//    b.turnOff(7);

    cout << b.toString() << endl;
    return 0;
}
