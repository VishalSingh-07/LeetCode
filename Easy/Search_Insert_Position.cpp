#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n) and Space --> O(1)

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==target)
//             {
//                 return i;
//             }
//             else if(nums[i]>target)
//             {
//                 return i;
//             }
                
//         }

//         return nums.size();
//     }
// };

// Optimized Approach [Binary Search]
// Time complexity --> O(logn) and Space --> O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
        }
        return low;
    }
};


// Question link -- https://leetcode.com/problems/search-insert-position/

// Video link -- https://youtu.be/0A40XJH_VvE