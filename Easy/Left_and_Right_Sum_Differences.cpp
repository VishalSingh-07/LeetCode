/*
2574. Left and Right Sum Differences

Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:

answer.length == nums.length.
answer[i] = |leftSum[i] - rightSum[i]|.
Where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return the array answer.

 

Example 1:

Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
Example 2:

Input: nums = [1]
Output: [0]
Explanation: The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
// class Solution {
// public:
//     vector<int> leftRigthDifference(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> leftSum(n),rightSum(n);
//         leftSum[0]=0;
//         for(int i=1;i<n;i++)
//         {
//             leftSum[i]=nums[i-1]+leftSum[i-1];
//         }
//         rightSum[n-1]=0;
//         for(int i=n-2;i>=0;i--)
//         {
//             rightSum[i]=nums[i+1]+rightSum[i+1];
//         }
//         for(int i=0;i<n;i++)
//         {
//             nums[i]=abs(leftSum[i]-rightSum[i]);
//         }
//         return nums;   
//     }
// };

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> ans;
        int leftSum=0,rightSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            rightSum+=nums[i];
        }
        cout<<rightSum<<" ";
        for(int i=0;i<n;i++)
        {
            rightSum-=nums[i];
            ans.push_back(abs(leftSum-rightSum));
            leftSum+=nums[i];

        } 
        return ans;
    }
};

/*
1. Question link -- https://leetcode.com/problems/left-and-right-sum-differences/

2. Solution link -- https://leetcode.com/problems/left-and-right-sum-differences/solutions/3287328/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/