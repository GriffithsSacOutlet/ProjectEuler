#include <iostream>

int main()
{
  int sum = 0;
  for (int i = 0;i < 888000;i += 2)
    {
      sum += (i*i);
    }

  std::cout << sum;
  
}
