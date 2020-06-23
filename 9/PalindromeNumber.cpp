/*
 * =====================================================================================
 *
 *       Filename:  PalindromeNumber.cpp
 *
 *    Description: https://leetcode.com/problems/palindrome-number/ 
 *
 *        Version:  1.0
 *        Created:  06/23/20 17:10:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@epita.fr
 *        Company:  none
 *
 * =====================================================================================
 */
#include <limits>
#include <iostream>

bool isPalindrome(int x)
{
    if (x < 0 || (!(x % 10) && x)) return false;
    int reverse = 0;
    while (x > reverse)
    {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    return (x == reverse) || (x == reverse/10);
}

int main(void)
{
    std::cout << isPalindrome(121) << std::endl;
    std::cout << isPalindrome(-121) << std::endl;
    std::cout << isPalindrome(10) << std::endl;
    return 0;
}
