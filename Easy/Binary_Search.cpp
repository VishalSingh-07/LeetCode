#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity --> O(n) and Space --> O(1)
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {

//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==target)
//             {
//                 return i;
//             }
//         }
//         return -1;
        
//     }
// };

// Optimized Approach
// Time complexity --> O(logn) and Space --> O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target) // The target element is on left side
            {
                h=mid-1;
            }
            else if(nums[mid]<target)  // The target element is on right side
            { 
                l=mid+1;
            }
        }

        return -1;
        
    }
};

// Question link -- https://leetcode.com/problems/binary-search/