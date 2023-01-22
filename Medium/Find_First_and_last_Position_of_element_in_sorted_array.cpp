#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity --> O(n) and Space --> O(n)
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> v={-1,-1};
//         int n=nums.size();
//         // if (nums.empty())
//         // {
//         //     return {-1,-1};
//         // } 
//         // if((nums.size()==1) && (nums[0]==target))
//         // {
//         //     return {0,0};
//         // }   
//         // else if((nums.size()==1) && (nums[0]!=target))
//         // {
//         //     return {-1,-1};
//         // }
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]==target)
//             {
//                 v[0]=i;
//                 break;
//             }
//         }
//         for(int i=n-1;i>=0;i--)
//         {
//             if(nums[i]==target)
//             {
//                 v[1]=i;
//                 break;
//             }
//         }
//         return v;
        
//     }
// };

// Brute Force Approach 
// Time complexity --> O(n) and space --> O(1)
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n=nums.size();
//         int first=-1;
//         int second=-1;
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]==target)
//             {
//                 first=i;
//                 break;
//             }
//         }
//         for(int i=n-1;i>=0;i--)
//         {
//             if(nums[i]==target)
//             {
//                 second=i;
//                 break;
//             }
//         }
//         if(first==-1 && second==-1)
//         {
//             return {-1,-1};
//         }
//         return {first,second};
        
//     }
// };

// Optimized Approach [Binary Search]
// Time complexity --> O(logn) and Space --> O(1)

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n=nums.size();
//         int index1=-1;
//         int index2=-1;
//         int low=0;
//         int high=n-1;

//         while(low<=high) // for searching an element on the left side of an array
//         {
//             int mid=low+(high-low)/2;
//             if(nums[mid]==target)
//             {
//                 index1=mid;
//                 high=mid-1;
//             }
//             else if(nums[mid]>target) // move to left
//             {
//                 high=mid-1;
//             }
//             else // move to right
//             {
//                 low=mid+1;
//             }
//         }
        
//         low=0;
//         high=n-1;

//         while(low<=high) // for searching an element on the right side of an array
//         {
//             int mid=low+(high-low)/2;
//             if(nums[mid]==target)
//             {
//                 index2=mid;
//                 low=mid+1;
//             }
//             else if(nums[mid]>target)
//             {
//                 high=mid-1;
//             }
//             else
//             {
//                 low=mid+1;
//             }
//         }

//         if(index1==-1 && index2==-1)
//         {
//             return {-1,-1};
//         }

//         return {index1, index2};

//     }
// };

// Optimized Approach [Binary Search]
// Time complexity --> O(logn) and Space --> O(1)
class Solution {
public:
    int firstposition(vector<int> &nums, int target,int n) // search an element on left side of an array
    {
        int index1=-1;
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                index1=mid;
                high=mid-1;
            }
            else if(nums[mid]>target) // move to left
            {
                high=mid-1;
            }
            else // move to right
            {
                low=mid+1;
            }
        }
        return index1;

    }
    int secondposition(vector<int> &nums, int target, int n) // search an element on right side of an array
    {
        int index2=-1;
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                index2=mid;
                low=mid+1;
            }
            else if(nums[mid]>target) // move to left
            {
                high=mid-1;
            }
            else // move to right
            {
                low=mid+1;
            }
        }

        return index2;

    }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int first=firstposition(nums,target,n);
        int second=secondposition(nums,target,n);

        if(first==-1 && second==-1)
        {
            return {-1,-1};
        }

        return {first, second};

    }
};

// Question link -- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Resource link -- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/solutions/3085909/four-way-to-solve-a-problem-c-solution-brute-force-and-optimized-approach/