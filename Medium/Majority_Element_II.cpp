#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         vector<int> ans;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             if(ans.size()==0 || ans[0]!=nums[i])
//             {
//                 int count=0;
//                 for(int j=0;j<n;j++)
//                 {
//                     if(nums[i]==nums[j])
//                     {
//                         count++;
//                     }
//                 }
//                 if(count>n/3)
//                 {
//                     ans.push_back(nums[i]);
//                 }
//             }
//             if(ans.size()==2)
//             {
//                 break;
//             }
            
//         }
//         return ans;
//     }
// };

// Better Approach
// Time complexity -> O(2n) and Space -> O(n)
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         vector<int> ans;
//         for(auto it: nums)
//         {
//             mp[it]++;
//         }
//         for(auto x:mp)
//         {
//             if(x.second>nums.size()/3)
//             {
//                 ans.push_back(x.first);
//             }
//         }
//         return ans;
//     }
// };

// OR 

// Time complexity -> O(n) and Space -> O(n)
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         vector<int> ans;
//         int mm=(int)(nums.size()/3)+1;
//         for(int i=0;i<nums.size();i++)
//         {
//             mp[nums[i]]++;
//             if(mp[nums[i]]==mm)
//             {
//                 ans.push_back(nums[i]);
//             }
//             if(ans.size()==2)
//             {
//                 break;
//             }
//         }
//         return ans;
//     }
// };



// Optimized Approach
// Time complexity -> O(2n) and Space -> O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int ele1,ele2;
        int count1=0,count2=0;
        // Step 1: Find the potential element for majority elements
        for(int i=0;i<nums.size();i++)
        {
            if(count1==0 && nums[i]!=ele2)
            {
                ele1=nums[i];
                count1=1;
            }
            else if(count2==0 && nums[i]!=ele1)
            {
                ele2=nums[i];
                count2=1;
            }
            else if(nums[i]==ele1)
            {
                count1++;
            }
            else if(nums[i]==ele2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        // Step 2: Verify the element to find the majority elements
        count1=0,count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele1)
            {
                count1++;
            }
            if(nums[i]==ele2)
            {
                count2++;
            }
        }

        if(count1>nums.size()/3)
        {
            ans.push_back(ele1);
        }
        if(count2>nums.size()/3)
        {
            ans.push_back(ele2);
        }
        return ans;
    }
};

/*
1. Question link -- https://leetcode.com/problems/majority-element-ii/

2. Video Link -- https://youtu.be/vwZj1K0e9U8

3. Solution link -- https://leetcode.com/problems/majority-element-ii/solutions/3815568/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/
*/