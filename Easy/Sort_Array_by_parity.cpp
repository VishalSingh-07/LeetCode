#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n) and Space -> O(n)
// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
        
//         int n=nums.size();
//         vector<int> ans;
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]%2==0)
//             {
//                 ans.push_back(nums[i]);
//             }
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]%2!=0)
//             {
//                 ans.push_back(nums[i]);
//             }
//         }
//         return ans;

//     }
// };


// Optimized Approach
// Time complexity --> O(n) and Space -> O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n=nums.size();
        int i=0,j=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return nums;

    }
};

/*

1. Question link -- https://leetcode.com/problems/sort-array-by-parity/

2. My Solution link -- https://leetcode.com/problems/sort-array-by-parity/solutions/3243578/easy-c-solution-2-approach-brute-force-and-optimized-approach/

3. Video link -- https://youtu.be/SNHeJl2h38I
*/