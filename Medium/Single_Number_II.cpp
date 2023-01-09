#include <bits/stdc++.h>
using namespace std;

// Using Mapping
// Time complexity --> O(n) and space --> O(n)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         map<int,int>mp;
//         for(int i=0;i<nums.size();i++)
//         {
//             mp[nums[i]]++;
//         }
//         for(auto it: mp)
//         {
//             if(it.second==1)
//             {
//                 return it.first;
//             }
//         }
//         return -1;
        
//     }
// };

// Using Sorting Approach
// Time complexity --> O(nlogn)+O(n) == O(nlogn)  and space --> O(1)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         if(n==1)
//         {
//             return nums[0];
//         }
//         if(nums[0]!=nums[1]) // if single number is at first
//         {
//             return nums[0];
//         }
//         if(nums[n-1]!=nums[n-2]) // if single number is at last 
//         {
//             return nums[n-1];
//         }

//         for(int i=1;i<nums.size();i++)
//         {
//             if(nums[i]!=nums[i-1])
//             {
//                 return nums[i-1];
//             }
//             i=i+2;
//         }
//         return -1;

        
//     }
// };

// Using Counting Set bits
// Time complexity --> O(32*n) and Space --> O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int count,mask,ans=0;

        for(int i=0;i<32;i++)
        {
            count=0;
            mask=1<<i;
            for(auto n: nums)
            {
                if(n & mask)
                {
                    count++;
                }
            }
            if(count%3!=0)
            {
                ans=ans|mask;
            }
        }

        return ans;

        
    }
};

// OR --------------

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {

//         int count,mask,ans=0;

//         for(int i=0;i<32;i++)
//         {
//             count=0;
//             mask=1<<i;
//             for(int j=0;j<nums.size();j++)
//             {
//                 if(nums[j] & mask)
//                 {
//                     count++;
//                 }
//             }
//             if(count%3!=0)
//             {
//                 ans=ans|mask;
//             }
//         }

//         return ans;

        
//     }
// };


// XOR Bit Manipulation 
// Time Complexity : O(n) Space Complexity : O(1)

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) 
//     {       
//         int ones = 0;
//         int twos = 0;
        
//         for ( int i : nums ) {
//             ones = (ones ^ i) & (~twos);
//             twos = (twos ^ i) & (~ones);
//         }
        
//         return ones;
//     }
// };


// Question link -- https://leetcode.com/problems/single-number-ii/