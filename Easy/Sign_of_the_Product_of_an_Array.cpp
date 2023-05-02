/*
1822. Sign of the Product of an Array
Easy

There is a function signFunc(x) that returns:

1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).

 

Example 1:

Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1


Example 2:

Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0


Example 3:

Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1
 

Constraints:

1 <= nums.length <= 1000
-100 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;
// Approach 1: Counting Negative Number 
// Time complexity -> O(n) and Space -> O(1)
// class Solution {
// public:
//     int arraySign(vector<int>& nums) {
//         int countNegativeNumbers=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==0)
//             {
//                 return 0;
//             }
//             if(nums[i]<0)
//             {
//                 countNegativeNumbers++;
//             }
//         }
//         return countNegativeNumbers%2==0?1:-1;
//     }
// };

// Approach 2: Tracking the Sign of the Product
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                return 0;
            }
            if(nums[i]<0)
            {
                sign=-1*sign;
            }
        }
        return sign;
    }
};

/*
1. Question link -- https://leetcode.com/problems/sign-of-the-product-of-an-array/

2. Solution link -- https://leetcode.com/problems/sign-of-the-product-of-an-array/solutions/3476959/2-approach-easy-c-solution-with-explanation-optimized-approach/
*/