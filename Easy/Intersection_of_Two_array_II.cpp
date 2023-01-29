#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n*m) and Space --> O(1)
// where n = nums1.size() and m=nums2.size()
// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         for(int i=0;i<nums1.size();i++)
//         {
//             for(int j=0;j<nums2.size();j++)
//             {
//                 if(nums1[i]==nums2[j])
//                 {
//                     ans.push_back(nums2[j]);
//                     nums2.erase(find(nums2.begin(),nums2.end(),nums2[j]));
//                     break;
//                 }

//             }
            
//         }
//         return ans;
        
//     }
// };

// Two Pointer Approach [Using Sorting]
// Time complexity --> O(nlogn + mlogm) and Space --> O(1)
// where n = nums1.size() and m=nums2.size()
// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         sort(nums1.begin(),nums1.end());
//         sort(nums2.begin(),nums2.end());
//         vector<int> ans;
//         int i=0,j=0;
//         while(i<nums1.size() && j<nums2.size())
//         {
//             if(nums1[i]==nums2[j])
//             {
//                 ans.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//             else if(nums1[i]>nums2[j])
//             {
//                 j++;
//             }
//             else if(nums1[i]<nums2[j])
//             {
//                 i++;
//             }
//         }
//         return ans;

        
//     }
// };

// Using Multiset Approach
// Time complexity --> O(n+m) and Space --> O(n)
// where n = nums1.size() and m=nums2.size()
// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         multiset<int> ms;
//         for(auto x: nums1)
//         {
//             ms.insert(x);
//         }
//         for(int i=0;i<nums2.size();i++)
//         {
//             auto it=ms.find(nums2[i]);
//             if(it!=ms.end())
//             {
//                 ans.push_back(nums2[i]);
//                 ms.erase(it);
//             }
//         }
            
//         return ans;
        
//     }
// };

// Optimized Approach [Using Map]
// Time complexity --> O(n+m) and Space --> O(n)
// where n = nums1.size() and m=nums2.size()
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> mp;
        for(auto x: nums1)
        {
            mp[x]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            auto it=mp.find(nums2[i]);
            if(it!=mp.end() && it->second>0)
            {
                ans.push_back(nums2[i]);
                it->second--;
            }
        }
        return ans;
        
    }
};


// Question link -- https://leetcode.com/problems/intersection-of-two-arrays-ii/