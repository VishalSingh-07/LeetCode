/*
153. Find Minimum in Rotated Sorted Array

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.


Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.


Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(1)
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int min=INT_MAX;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]<min)
//             {
//                 min=nums[i];
//             }
//         }
//         return min;
//     }
// };

// Optimized Approach
// Time complexity -> O(logn) and Space -> O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {

        if(nums.size()==1) // If the  array has just one element then return that element
        { 
            return nums[0];
        }
        int start=0,end=nums.size()-1;
        if(nums[end]>nums[0]) // If the last element is greater than the first element then it means thers is no rotation
        {
            return nums[0];
        }
        int index=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2; // Finding the mid element
            /*
            If the mid element is greater than its next element then mid+1 element is the smallest
            This point would be the point of change [Inflection Point]. 
            */
            if(nums[mid]>nums[mid+1]) 
            {
                return nums[mid+1];
            }
            /*
            If the mid element is lesser than its previous element then mid element is the smallest
            This point would be the point of change [Inflection Point]. 
            */
            if(nums[mid]<nums[mid-1])
            {
                return nums[mid];
            }
            /*
            If the mid element is greater than 0th element this means the least value is still somewhere
            to the right as we are still dealing with elements greater thn nums[0]. [Right Search]
            */
            if(nums[mid]>nums[0])
            {
                start=mid+1;
            }
            /*
            If nums[0] is greater than the mid value then this means the smallest value is somewhere to 
            the left [Left Search] 
            */
            else
            {
                end=mid-1;
            }
        }
        return -1;
    }
};

/*
1. Question link -- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

2. Solution Link -- 

      a) https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solutions/3340231/2-approach-easy-c-solution-brute-force-optimized-approach-fully-explained/

      b) https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/editorial/

*/