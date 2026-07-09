#ifndef UnsignedLargeNums_H
#define UnsignedLargeNums_H
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>


class UnsignedLargeNums
{
    public:
    unsigned long long digits8bit = 10;
    std::vector<unsigned char> TBitValue = std::vector<unsigned char>(10, 0);
    UnsignedLargeNums()
    {

    }
    UnsignedLargeNums(unsigned long long inDigsBinary)
    {
        TBitValue.resize(inDigsBinary, 0);
        digits8bit = inDigsBinary;
    }
    UnsignedLargeNums(std::vector<unsigned char> BaseVec)
    {
        TBitValue = BaseVec;
        digits8bit = BaseVec.size();
    }
    
    unsigned long long Size()
    {
        return digits8bit;
    }

    void resize(unsigned long long ResizeVal)
    {
        TBitValue.resize(ResizeVal);
        digits8bit = ResizeVal;
    }

    void PP()
    {
        for(int i = 0;i < digits8bit;i++)
        {
            if(TBitValue[i] == 255)
            {
                TBitValue[i] = 0;
                if(i + 1 == Size())
                {
                    resize(Size()+1);
                    TBitValue[Size()-1] += 1;
                    return;
                }
                continue;
            }
            TBitValue[i] += 1;
            return;
        }
    }
    void PP(int offset)
    {
        for(int i = offset;i < digits8bit;i++)
        {
            if(TBitValue[i] == 255)
            {
                TBitValue[i] = 0;
                continue;
            }
            TBitValue[i] += 1;
            return;
        }
    }

    void MM()
    {
        for(int i =0;i < digits8bit;i++)
        {
            if(TBitValue[i] != 0)
            {
                TBitValue[i]--;
                return;
            }
            else
            {
                TBitValue[i] = 255;
            }
        }
    }

    void print()
    {
        for (unsigned long long index = digits8bit-1;index > 0;index--)
        {
            std::cout << index << '(' << (int)TBitValue[index] << ")   ";
        }
        std::cout << "0(" << (int)TBitValue[0] << ")\n";
    }
};



inline UnsignedLargeNums AddUnsignedLargeNums(UnsignedLargeNums Value1, UnsignedLargeNums Value2)
{
    unsigned long long SmallestLength = (std::min(Value1.Size(), Value2.Size()));
    unsigned long long MaxLength = (std::max(Value1.Size(), Value2.Size()));

    bool carry = false;
    UnsignedLargeNums OutputNum(MaxLength);
    for(unsigned long long index = 0;index < SmallestLength;index++)
    {
        OutputNum.TBitValue[index] = (Value1.TBitValue[index] + Value2.TBitValue[index] + carry);
        if(Value1.TBitValue[index] + Value2.TBitValue[index] + carry >= 256)
            carry = true;
        else
            carry = false;
    }
    for (unsigned long long index = SmallestLength;index < MaxLength;index++)
    {
        if (Value1.Size() > SmallestLength)
        {
            OutputNum.TBitValue[index] = Value1.TBitValue[index];
        }
        else if(Value2.Size() > SmallestLength)
        {
            OutputNum.TBitValue[index] = Value2.TBitValue[index];
        }
    }
    bool Val1Larger = (Value1.Size() >= Value2.Size());
    OutputNum.resize(MaxLength);
    if (carry && Value1.Size() == Value2.Size())
    {
        OutputNum.resize(SmallestLength + 1);
        OutputNum.TBitValue[OutputNum.Size()-1] = 1;
    }
    else if (carry && Val1Larger)
    {
        for (int i = 0;i < Value1.Size();i++)
        {
            if (Value1.TBitValue[i] == 255)
                continue;
            OutputNum.resize(Value1.Size() + 1);
            OutputNum.PP();
        }
    }
    else if (carry && !Val1Larger)
    {
        for (int i = 0;i < Value2.Size();i++)
        {
            if (Value2.TBitValue[i] == 255)
                continue;
            OutputNum.resize(Value2.Size() + 1);
            OutputNum.PP();
            
        }
    }
    return OutputNum;
}



inline UnsignedLargeNums SubtractUnsignedLargeNums(UnsignedLargeNums Value1, UnsignedLargeNums Value2)
{
    //If Val1[i]<val2[i]
    //val1[i+1]--
    //returnval[i] = 256 - val2[i] + val1[i]
    unsigned long long SmallestLength = (std::min(Value1.Size(), Value2.Size()));
    unsigned long long MaxLength = (std::max(Value1.Size(), Value2.Size()));
    UnsignedLargeNums OutputNum(MaxLength);

    for(unsigned long long index = 0;index < SmallestLength;index++)
    {
        if (Value1.TBitValue[index] < Value2.TBitValue[index])
        {
            Value1.TBitValue[index+1]--;
            OutputNum.TBitValue[index] = 256 - Value2.TBitValue[index] + Value1.TBitValue[index];
            continue;
        }
        OutputNum.TBitValue[index] = Value1.TBitValue[index] - Value2.TBitValue[index];
        
    }
    for(unsigned long long index = SmallestLength;index < MaxLength;index++)
    {
        if(Value1.Size() > SmallestLength)
        {
            OutputNum.TBitValue[index] = Value1.TBitValue[index];
        }
        else if(Value2.Size() > SmallestLength)
        {
            std::cout << "Its backwards";
        }
    }
    OutputNum.resize(MaxLength);


    return OutputNum;
}

inline double RoughLogUnsignedNumbers(UnsignedLargeNums Value, double Base)
{
    int highest = Value.Size() - 1;

    while (highest > 0 && Value.TBitValue[highest] == 0)
        highest--;

    if (highest == 0 && Value.TBitValue[0] == 0)
        return -INFINITY;

    double mantissa = 0.0;

    for (int i = highest; i >= std::max(0, highest - 7); --i)
    {
        mantissa = mantissa * 256.0 + Value.TBitValue[i];
    }

    int bytesUsed = highest - std::max(0, highest - 7);

    double lnN =
        std::log(mantissa) + (highest - bytesUsed) * std::log(256.0);

    return lnN / std::log(Base);
}
#endif