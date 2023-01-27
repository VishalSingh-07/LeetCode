#include <bits/stdc++.h>
using namespace std;
//Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[i]==nums[j] && abs(i-j)<=k)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
    
//     }
// };

// Above Code gave time limit exceeded due to O(n^2) time complexity

// Optimized Approach [using Map]
// Time complexity --> O(n) and Space --> O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            
            if(mp.find(nums[i])!=mp.end()) // checking whether nums[i] is already present in a map or not
            {
                // If I have already seen this number, then check for condition abs(i-j)<=k
                if(i-mp[nums[i]]<=k)
                {
                    return true;
                }
            }
            // just insert in value, or update the value of index.
            mp[nums[i]]=i;
        }

        return false;
    
    }
};

// Question link -- https://leetcode.com/problems/contains-duplicate-ii/
