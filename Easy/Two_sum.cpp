#include <bits/stdc++.h>
using namespace std;

// Brute for approach
// Time complexity -> O(n^2) and Space -> O(1)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[i]+nums[j]==target)
//                 {
//                     return {i,j};
//                 }
//             }
//         }
//         return {-1,-1};
//     }
// };


// Hash table approach
// Time complexity -> O(n) and Space -> O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            if(mpp.find(target-nums[i])!=mpp.end())
            {
                return {mpp[target-nums[i]],i};
            }
            mpp[nums[i]]=i;

        }
        return {-1,-1};
        
        
    }
};

/*

1. Question link -- https://leetcode.com/problems/two-sum/

2. Video Link -- https://youtu.be/UXDSeD9mN-k

3. Solution link -- https://leetcode.com/problems/two-sum/solutions/3843569/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/