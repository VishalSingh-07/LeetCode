#include <bits/stdc++.h>
using namespace std;

// Brute force Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {

//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[i]==nums[j])
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// Above code give Time limit Exceeded due to O(n^2) time complexity

// Using Sorting Approach
// Time complexity --> O(nlogn) and Space --> O(1)
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {

//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         for(int i=0;i<n-1;i++)
//         {
//             if(nums[i]==nums[i+1])
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// Hash Map Approach
// Time complexity --> O(n) and Space --> O(n)
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {

//         int n=nums.size();
//         map<int,int> mp;
//         for(auto x: nums)
//         {
//             mp[x]++;
//         }
//         for(auto it: mp)
//         {
//             if(it.second>1)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// Optimized Approach [Using Set]
/*
Time complexity --> O(n)
Space complexity --> 
    1. Worst Case --> O(n)
    2. Best Case ---> O(1) 
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> s;
        for(auto i: nums)
        {
            s.insert(i);
        }
        if(nums.size()==s.size())
        {
            return false;
        }
        return true;
    }
};

// Question link -- https://leetcode.com/problems/contains-duplicate/