/*
 * =====================================================================================
 *
 *       Filename:  NextPermutation.cpp
 *
 *    Description: https://leetcode.com/problems/next-permutation/ 
 *
 *        Version:  1.0
 *        Created:  09/16/22 16:10:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), misterjonathansands@gmail.com
 *        Company:  none
 *
 * =====================================================================================
 */

void nextPermutation(vector<int>& nums) {
    int tmp;
    int old_i = nums[nums.size() - 1];
    for (int i = nums.size() - 2; (i >= 0); --i)
    {
        if (nums[i] < old_i)
        {
            int swap_i = i+1;
            for(; swap_i < nums.size() && nums[swap_i] <= nums[i]; ++swap_i);
            tmp = nums[i];
            nums[i] = nums[swap_i];
            nums[swap_i] = tmp;
            return;
        }
        old_i = nums[i];
        for (int k = i; k < nums.size() - 1 && nums[k] > nums[k+1]; ++k) // We can avoid bubble sort
        {
            tmp = nums[k];
            nums[k] = nums[k+1];
            nums[k+1] = tmp;
        }
    }
}

// Online Solution
public void nextPermutation(int[] nums) {
    int i = nums.length - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        i--;
    }
    if (i >= 0) {
        int j = nums.length - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }
    reverse(nums, i + 1);
}

private void reverse(int[] nums, int start) {
    int i = start, j = nums.length - 1;
    while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
    }
}

private void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

