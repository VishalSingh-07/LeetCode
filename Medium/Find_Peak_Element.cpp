#include <bits/stdc++.h>
using namespace std;

// Brute ForceApproach
// Time complexity --> O(n) and Space --> O(1)
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {

//         int n=nums.size();
//         if(n==1 || nums[0]>nums[1])
//         {
//             return 0;
//         }
//         if(nums[n-1]>nums[n-2])
//         {
//             return n-1;
//         }
//         for(int i=1;i<n-1;i++)
//         {
//             if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
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
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        if(nums.size()==1)
        {
            return 0;
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mid==0)
            {
                if(nums[mid]>nums[mid+1])
                {
                    return mid;
                }
                else
                {
                    low=mid+1;
                }
            }
            else if(mid==nums.size()-1)
            {
                if(nums[mid]>nums[mid-1])
                {
                    return mid;
                }
                else
                {
                    high=mid-1;
                }
            }
            else
            {
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                {
                    return mid;
                }
                else
                {
                    if(nums[mid]<nums[mid-1]) // move in left
                    {
                        high=mid-1;
                    }
                    else if(nums[mid]<nums[mid+1]) // move in right
                    {
                        low=mid+1;
                    }
                }
            }
        }
        return -1;
        
    }
};

/*
1. Question link -- https://leetcode.com/problems/find-peak-element/

2. My Solutio link -- https://leetcode.com/problems/find-peak-element/solutions/3192847/two-approach-to-solve-a-problem-easy-c-solution-brute-force-and-optimized-approach/

3. Video Link -- https://youtu.be/qQKbr4WtGjc
*/