/*
 * =====================================================================================
 *
 *       Filename:  ContainerWithMostWater.cpp
 *
 *    Description: https://leetcode.com/problems/container-with-most-water/ 
 *
 *        Version:  1.0
 *        Created:  06/24/20 10:41:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@epita.fr
 *        Company:  none
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int abs(int nb)
{
    return (nb < 0) ? nb * -1 : nb;
}

int max(int a , int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

//Brute Force
int maxArea_brute(std::vector<int>& height)
{
    int max_vol = 0;
    //std::vector<size_t> sorted_indexes = sort_indexes(height);

    for (long unsigned i = 0; i < height.size(); ++i)
    {
        if (max(height.size() -1 - i, i) * height[i] <= max_vol)
            continue;
        for (long unsigned j = i + 1; j < height.size(); ++j)
        {
            max_vol = max(max_vol, (j - i) * min(height[i] , height[j]));
        }
    }
    return max_vol;
}

int maxArea_pointers(std::vector<int>& height)
{
    int max_vol = 0;
    int right = height.size() - 1;
    int left = 0;
    while (left != right)
    {
        max_vol = max(max_vol, (right - left) * min(height[left], height[right]));
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_vol;
}

int main (void)
{
    std::vector<int> heights({1, 8, 6, 2, 5, 4, 8, 3, 7});
    std::cout << maxArea_pointers(heights) << std::endl;
    return 0;
}
