#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         int n=nums.size();
//         int count=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[i]==nums[j] && i<j)
//                 {
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };

//Optimized Approach [Using Hashmap]
// Time complexity --> O(n) and Space --> O(1)

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        map<int,int> mp;
        for(auto i: nums)
        {
            mp[i]++;
        }
        for(auto it: mp)
        {
            if(it.second>1)
            {
                count+=it.second*(it.second-1)/2;
            }
        }
        return count;
    }
};

/*
Create an map and store no. of time all elements occur in nums.
If count>1, use the combination formula nC2, which gives n*(n-1)/2;
*/

// Question link -- https://leetcode.com/problems/number-of-good-pairs/