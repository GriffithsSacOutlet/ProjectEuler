#include <iostream>
#include "Fibbonachi.h"

int sum;
int main()
{

    int i = 0;
    sum = 0;
    while(Fibbonachi(i) < 4000000)
    {
        if((Fibbonachi(i) % 2) == 0)
        {
            sum += Fibbonachi(i);
        }
        i++;
    }
    std::cout << sum << '\n';


}


