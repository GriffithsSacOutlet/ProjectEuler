#include <iostream>
#include <vector>

std::vector<unsigned long> PrimeList;
unsigned long largestPrime = 1;
bool isprime(unsigned long InPrime);
unsigned long goalint = 600851475143;
int main()
{
    for(unsigned long i = 2;i < 775146;i++)
    {
        if(i % 100000)
            std::cout << "count: " << i << "\n";
        isprime(i);
    }
    for(unsigned long i = 0;i < PrimeList.size();i++)
    {
        if(goalint % PrimeList[i] == 0)
        {
            largestPrime = PrimeList[i];
            std::cout << largestPrime << '\n';
        }
    }
    for(int i = 0;i < 10;i++)
    {
        std::cout << PrimeList[i] << '\n';
    }
}




bool isprime(unsigned long InPrime)
{
    for(unsigned long i = 0;i < PrimeList.size();i++)
    {
        if(InPrime % PrimeList[i] == 0)
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    PrimeList.push_back(InPrime);
    return true;
}