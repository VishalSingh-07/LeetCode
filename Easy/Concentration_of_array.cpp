#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach 
// Time complexity --> O(n) and Space --> O(n)
// class Solution {
// public:
//     vector<int> getConcatenation(vector<int>& nums) {
//         vector<int> ans;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             ans.push_back(nums[i]);
//         }
//         for(int i=0;i<nums.size();i++)
//         {
//             ans.push_back(nums[i]);
//         }
//         return ans;
        
//     }
// };

// Optimized Approach 
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        
        return nums;
        
    }
};

// Question link -- https://leetcode.com/problems/concatenation-of-array/