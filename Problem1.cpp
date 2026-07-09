#include <iostream>

int main()
{
    int sum;
    for (int i = 1;i*5 < 1000;i++)
    {
        sum += (i*5);
    }
    for (int i = 1;i*3 < 1000;i++)
    {
        if(i*3 % 5 != 0)
            sum += (i*3);
    }

    std::cout << sum << '\n';
}