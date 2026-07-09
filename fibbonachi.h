#ifndef FIBBY
#define FIBBY
#include "ULargeNumbersLibrary.h"


std::vector<unsigned char> one {1};
UnsignedLargeNums BigOne(one);

inline UnsignedLargeNums Fibbonachi(unsigned long long index)
{
    if(index == 1 || index == 2)
        return BigOne;
    else
        return AddUnsignedLargeNums(Fibbonachi(index-1), Fibbonachi(index-2));
}

inline unsigned long long Fibbonachi(int index)
{
    unsigned long long num1 = 0;
    unsigned long long num2 = 1;
    unsigned long long num3 = 0;
    for (int i = 0;i < index;i++)
    {
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
    }
    return num3;
}

#endif