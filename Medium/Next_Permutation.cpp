#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n!*n) and Space -> O((n!) * n)
// class Solution {
// private:
//     void recPermuteUnique(int index, vector<int> &nums, set<vector<int>> &set, vector<int> temp)
//     {
//         if(index==nums.size())
//         {
//             set.insert(temp);
//             return;
//         }
//         for(int i=index;i<temp.size();i++)
//         {
//             swap(temp[index],temp[i]);
//             recPermuteUnique(index+1,nums,set,temp);
//         }
//     } 
// public:
//     void nextPermutation(vector<int>& nums) {
//         vector<vector<int>> output;
//         int index=-1;
//         vector<int> temp=nums;
//         sort(temp.begin(),temp.end());
//         set<vector<int>>set;
//         recPermuteUnique(0,nums,set,temp);
//         for(auto it: set)
//         {
//            output.push_back(it);
//         } 
//         for(int i=0;i<output.size();i++)
//         {
//             if(output[i]==nums)
//             {
//                 index=i;
//                 break;
//             }
//         }
//         if(index==output.size()-1)
//         {
//             nums=output[0];
//         }
//         else
//         {
//             nums=output[index+1];
//         }
//     }
// };

// Above Code ❌ give Time Limit Exceeded due to high time complexity O((n!) * n)


// Better Approach
// Time complexity -> O(n) and Space -> O(1)
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(),nums.end());
//     }
// };





// Optimized Approach
// Time complexity -> O(3n) ~ O(n) and Space -> O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int i=n-1;i>index;i--)
            {
                if(nums[i]>nums[index])
                {
                    swap(nums[i],nums[index]);
                    break;
                }
            }
            reverse(nums.begin()+index+1,nums.end());
        }
    }
};


/*
1. Question link -- https://leetcode.com/problems/next-permutation/

2. Solution link -- https://leetcode.com/problems/next-permutation/solutions/3662540/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video Link -- https://youtu.be/JDOXKqF60RQ

*/

