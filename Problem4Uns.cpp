#include <iostream>
#include <string>

int largestPalindrome = 0;
bool ispalindrome(int Testindrome);

int main()
{
    for(int i = 100;i < 999;i++)
    {
        for(int j = i;j < 999;j++)
        {
            if (ispalindrome(i*j))
                if (i*j > largestPalindrome)
                    largestPalindrome = i*j;

        }
    }
    std::cout << largestPalindrome;
}


bool ispalindrome(int Testindrome)
{
    std::string TestindromeString = std::to_string(Testindrome);
    std::cout << "\n\n\n\n" << Testindrome << '\n';
    std::cout << TestindromeString.size() << '\n';
    for(int i = 0;i < TestindromeString.size()/2;i++)
    {
        std::cout << TestindromeString[i] << "    " << (TestindromeString[TestindromeString.size() - i]) << '\n';
        if(TestindromeString[i] == TestindromeString[TestindromeString.size() - i])
        {
            std::cout << "A true val" << '\n';
            continue;
        }
        else
        {
            return false;
        }
    }
    std::cout << "A true case" << '\n';
    return true;
}