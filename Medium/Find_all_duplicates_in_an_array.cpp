#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> v;
//         for(int i=0;i<n;i++)
//         {
//             int ele=nums[i];
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[j]==ele)
//                 {
//                     v.push_back(nums[i]);
//                 }
//             }
//         }
//         return v;
        
//     }
// };

// Above approach give time limit exceeded due to O(n^2) time complexity



// Sorting Approach 
// Time complexity --> O(nlogn) and Space --> O(1)
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         int n=nums.size();
//         int count=1;
//         sort(nums.begin(), nums.end());
//         vector<int> v;
//         for(int i=0;i<n-1;i++)
//         {
//             if(nums[i]==nums[i+1])
//             {
//                 count++;
//                 if(count==2)
//                 {
//                     v.push_back(nums[i]);
//                     count=1;
//                 }

//             }
//             else
//             {
//                 count=1;
//             }
//         }
//         // sort(v.begin(),v.end());

//         return v;
        
//     }
// };

// Hashing Approach 
// Time complexity --> O(n) and Space --> O(n)
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         map<int,int> mp;
//         vector<int> v;
//         for(auto i: nums)
//         {
//             mp[i]++;
//         }
//         for(auto it: mp)
//         {
//             if(it.second==2)
//             {
//                 v.push_back(it.first);
//             }
//         }
//         return v;
        
//     }
// };

// Xor Approach 
// Time complexity --> O(nlogn) and Space --> O(1)
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(), nums.end());
//         vector<int> v;
//         for(int i=0;i<n-1;i++)
//         {
//             int val=nums[i]^nums[i+1];
//             if(val==0)
//             {
//                 v.push_back(nums[i]);
//                 i++;
//             }
//         }

//         return v;
        
//     }
// };


// Optimized Approach
// Time complexity --> O(n) and Space --> O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for(auto it: nums)
        {
            int x=abs(it);
            if(nums[x-1]>0)
            {
                nums[x-1]*=-1;
            }
            else
            {
                result.push_back(x);
            }

        }
        return result;
    }
};


// Question link -- https://leetcode.com/problems/find-all-duplicates-in-an-array/

// My Solution -- https://leetcode.com/problems/find-all-duplicates-in-an-array/solutions/3089765/five-approach-to-solve-a-problem-c-solution-brute-force-sorting-hashing-xor-optimized/