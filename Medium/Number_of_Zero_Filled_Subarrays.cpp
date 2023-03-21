/*
2348. Number of Zero-Filled Subarrays

Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
Example 2:

Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
Example 3:

Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
#include <bits/stdc++.h>
using namespace std;
// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0,zeros=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zeros++;
            }
            else
            {
                count+=(zeros+1)*zeros/2;
                zeros=0;
            }
        }
        count+=(zeros+1)*zeros/2;

        return count;
    }
};


/*
1. Question link -- https://leetcode.com/problems/number-of-zero-filled-subarrays/

2. Solution link --

      a) https://leetcode.com/problems/number-of-zero-filled-subarrays/solutions/3324103/easy-c-solution-optimized-approach-step-wise-explanation-t-c-o-n-s-c-o-1/

      b) https://leetcode.com/problems/number-of-zero-filled-subarrays/solutions/3322024/image-explanation-2-pointer-3-other-approaches-c-java-python/
*/