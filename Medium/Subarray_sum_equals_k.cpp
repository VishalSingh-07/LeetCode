#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^3) and Space --> O(1)
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
            
//             for(int j=i;j<n;j++)
//             {
//                 int sum=0;
//                 for(int x=i;x<=j;x++)
//                 {
//                     sum+=nums[x];

//                 }
//                 if(sum==k)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
        
//     }
// };

// Above code ❌ give time limit exceeded due to high complexity O(n^3)

// Better Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             int sum=0;
//             for(int j=i;j<n;j++)
//             {
//                 sum+=nums[j];
//                 if(sum==k)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
        
//     }
// };

// Above code ❌ also give time limit exceeded due to high complexity O(n^2)

// // Optimized Approach
// // Time complexity --> O(n) and Space --> O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;       
        int count=0,running_sum=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            running_sum+=nums[i];
            int find=running_sum-k;
            if(mp[find]!=0)
            {
                count+=mp[find];
            }
            mp[running_sum]++;
        }
        return count;
    }
};


/*
1. Question link -- https://leetcode.com/problems/subarray-sum-equals-k/

2. Solution link -- https://leetcode.com/problems/subarray-sum-equals-k/solutions/3275664/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video link -- https://youtu.be/ufXxc8Vty9A
*/
