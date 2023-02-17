#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^2) and Space -> O(1)
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++)
//         {
//             int count=0;
//             for(int j=0;j<nums.size();j++)
//             {
//                 if(nums[i]==nums[j])
//                 {
//                     count++;
//                 }
//             }
//             if(count==1)
//             {
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };

// Above code give Time limit Exceeded due to high complexity O(n^2)

// Using Map [Hash Table]
// Time complexity --> O(n) and Space -> O(n)
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         map<int,int> mp;
//         for(auto x: nums)
//         {
//             mp[x]++;
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


// Using XOR Approach
// Time complexity --> O(n) and Space -> O(1)
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int Xor=0;
//         for(auto x: nums)
//         {
//             Xor^=x;
//         }
//         return Xor;
//     }
// };

// Optimized Approach
// Time complexity --> O(logn) and Space -> O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        // Checking boundary condition
        if(high==0)
        {
            return nums[0]; 
        }
        else if(nums[0]!=nums[1])
        {
            return nums[0];
        }
        else if(nums[high]!=nums[high-1])
        {
            return nums[high];
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
            {
                return nums[mid];
            }
            else if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1]))
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            
        }
        return -1;
    }
};

/*
1. Question link: https://leetcode.com/problems/single-element-in-a-sorted-array/

2. My Solution link: https://leetcode.com/problems/single-element-in-a-sorted-array/solutions/3198028/4-approach-to-solve-a-problem-easy-c-problem-brute-force-map-xor-and-optimized/

3. Video Link: https://youtu.be/nMGL2vlyJk0
*/