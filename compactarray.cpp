#include "compactarray.h"

CompactArray::CompactArray(size_t b):
    b(b), size(0), bits(b)
{
}

CompactArray::CompactArray(size_t b, size_t size):
    b(b), size(0), bits(b)
{
    srand(unsigned(time(nullptr)));

    for (size_t i = 0; i < size; i++)
    {
        unsigned long value =  unsigned(rand()) % unsigned(pow(2, b));
        this->insert(value);
    }
}

void CompactArray::insert(unsigned long value)
{
    if ((b * (size+1)) > bits.getSize())
        bits.resize(2 * b * size);

    for (size_t i = 0; i < b; ++i)
    {
        if ((value >> (b-i-1)) & 1)
            bits.turnOn((b * size) + i);
        else
            bits.turnOff((b * size) + i);
    }

    size++;
}

unsigned long CompactArray::operator[](size_t index)
{
    unsigned long value = 0;
    for (size_t i = 0; i < b; i++)
    {
        if (bits[b * index + i])
            value = value | (1<<(b - i - 1));
    }
    return value;
}

int CompactArray::isLessThanOrEqualTo(size_t i, size_t j)
{
    for (size_t a = 0; a < b; a++)
    {
        size_t bitI = b * i + a;
        size_t bitJ = b * j + a;

        if (!bits[bitI] && bits[bitJ])
            return true;
        else if (bits[bitI] && !bits[bitJ])
            return false;
    }
    return true;
}

void CompactArray::swap(const size_t i, const size_t j)
{
    for (size_t a = 0; a < b; a++)
    {
        size_t bitI = b * i + a;
        size_t bitJ = b * j + a;

        if (!bits[bitI] && bits[bitJ])
        {
            bits.turnOn(bitI);
            bits.turnOff(bitJ);
        }
        else if (bits[bitI] && !bits[bitJ])
        {
            bits.turnOff(bitI);
            bits.turnOn(bitJ);
        }
    }
}

size_t CompactArray::getSize()
{
    return size;
}

string CompactArray::toBitString()
{
    string strArray;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < b; j++)
        {
            if (bits[(i*b) + j])
                strArray.append("1");
            else
                strArray.append("0");
        }
        strArray.append(" ");
    }

    return strArray;
}

string CompactArray::toString()
{
    string str = "[";
    for (size_t i = 0; i < (size - 1); i++)
        str = str + to_string(this->operator[](i)) + ", ";
    str = str + to_string(this->operator[](size-1)) + "]\n";
    return str;
}
