/*
 * =====================================================================================
 *
 *       Filename:  SearchinRotatedSortedArray.cpp
 *
 *    Description: https://leetcode.com/problems/search-in-rotated-sorted-array 
 *
 *        Version:  1.0
 *        Created:  09/16/22 18:57:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), misterjonathansands@gmail.com
 *        Company:  none
 *
 * =====================================================================================
 */

int search(vector<int>& nums, int target) {
    return search_rec(nums, target, 0, nums.size() - 1);
}

int search_rec(vector<int>& nums, int target, int left, int right)
{
    if (right >= left)
    {
    
        int consider = (left + right) / 2;
        
        if (nums[consider] == target)
            return consider;
        if (nums[left] == target)
            return left;
        if (nums[right] == target)
            return right;

        if (nums[consider] > target)
        {
            if (nums[left] <= target | nums[left] >= nums[consider])
                return search_rec(nums, target, left, consider-1);
            else 
                return search_rec(nums, target, consider + 1, right);
        }
        else
        {
            if (nums[right] >= target | nums[right] <= nums[consider])
                return search_rec(nums, target, consider+1, right);
            else
                return search_rec(nums, target, left, consider-1);
        }
    }
    return  -1;
}



// A good upvoted solution
int search(int A[], int n, int target) {
    int lo=0,hi=n-1;
    // find the index of the smallest value using binary search.
    // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
    // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(A[mid]>A[hi]) lo=mid+1;
        else hi=mid;
    }
    // lo==hi is the index of the smallest value and also the number of places rotated.
    int rot=lo;
    lo=0;hi=n-1;
    // The usual binary search and accounting for rotation.
    while(lo<=hi){
        int mid=(lo+hi)/2;
        int realmid=(mid+rot)%n;
        if(A[realmid]==target)return realmid;
        if(A[realmid]<target)lo=mid+1;
        else hi=mid-1;
    }
    return -1;
}
