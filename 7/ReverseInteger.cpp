/*
 * =====================================================================================
 *
 *       Filename:  ReverseInteger.cpp
 *
 *    Description: https://leetcode.com/problems/reverse-integer/ 
 *
 *        Version:  1.0
 *        Created:  18/06/2020 12:39:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@edu.devinci.fr
 *        Company:  none
 *
 * =====================================================================================
 */
#include <iostream> 
#include <limits>

int reverse(int x)
{
    int sign = 1;
    int add = 0;
    if (x < 0)
    {
        if (x == std::numeric_limits<int>::min()) //pretending it would work
        {
            add = -1;
            x += 1;
        }
        sign = -1;
        x *= sign;
    }
    int res = 0;
    while (x)
    {
        if (res < 0)
        {
            if ((std::numeric_limits<int>::min() + x % 10) / 10 > res)
                return 0;
        }
        else
        {
            if (res > 0 && (std::numeric_limits<int>::max() - x % 10) / 10 < res)
                return 0;
        }
        res *= 10;
        res += (x % 10) * sign;
        x = x/10;
    }
    res += add;
    return res;
}

int main(void)
{
    std::cout << reverse(123) << std::endl;
    std::cout << reverse(-123) << std::endl;
    std::cout << reverse(120) << std::endl;
    std::cout << reverse(std::numeric_limits<int>::min()) << std::endl;
    std::cout << reverse(std::numeric_limits<int>::max()) << std::endl;
    std::cout << reverse(1463847412) << std::endl;
    std::cout << reverse(-1463847421) << std::endl;
    return 0;
}
