#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int max=0;
//         int product=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[i]*nums[j]>max)
//                 {
//                     max=nums[i]*nums[j];
//                     product=(nums[i]-1)*(nums[j]-1);
//                 }
//             }
//         }
//         return product;
//     }
// };

// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int ans=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 ans=max(ans,(nums[i]-1)*(nums[j]-1));
//             }
//         }
//         return ans;

//     }
// };


// Time complexity --> O(nlogn) and Space --> O(1)
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         sort(nums.begin(),nums.end(),greater<int>());
//         return (nums[0]-1)*(nums[1]-1);

//     }
// };


// Optimized Solution
// Time complexity--> O(n) and Space--> O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first=0,second=0;
        for(auto num: nums)
        {
            if(num>first)
            {
                second=first;
                first=num;
            }
            else if(num>second)
            {
                second=num;
            }
        }
        return (first-1)*(second-1);

    }
};

// Question link -- https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/