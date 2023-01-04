#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity --> O(n^2) and space Complexity --> O(n)
// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) {
//         vector<int> ans(nums.size());
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=0;j<=i;j++)
//             {
//                 ans[i]=ans[i]+nums[j];
//             }
//         }
//         return ans;
        
//     }
// };

// Optimize approach 

// Time complexity --> O(n) and space Complexity --> O(n)
// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) {
//         vector<int> ans(nums.size());
//         for(int i=0;i<nums.size();i++)
//         {
//             if(i==0)
//             {
//                 ans[i]=nums[i];
//             }
//             else
//             {
//                 ans[i]=ans[i-1]+nums[i];
//             }
//         }
//         return ans;
        
//     }
// };


// Reducing space complexity 

// Time complexity --> O(n) and space Complexity --> O(1)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        {
            nums[i]=nums[i]+nums[i-1];
        }
        return nums;
        
    }
};

// Question link -- https://leetcode.com/problems/running-sum-of-1d-array/
