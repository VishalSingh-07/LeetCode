#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n*m) and Space --> O(n)
// where n=nums1.size() and m=nums2.size()
// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> v;
//         set<int> s;
//         for(int i=0;i<nums1.size();i++)
//         {
//             for(int j=0;j<nums2.size();j++)
//             {
//                 if(nums1[i]==nums2[j])
//                 {               
//                     s.insert(nums1[i]);               
//                 }
//             }
            
//         }
//         for(auto i: s)
//         {
//             v.push_back(i);
//         }
//         return v;

//     }
// };


// Brute force Approach [But Different method]
// Time complexity --> O(n*m) and Space --> O(n)
// where n=nums1.size() and m=nums2.size()
// class Solution {
// public:
//     bool PresentOrNot(vector<int> nums, int l, int x)
//     {
//         for(int i=0;i<l;i++)
//         {
//             if(nums[i]==x)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> v;
//         set<int> s;
//         for(int i=0;i<nums1.size();i++)
//         {
//             if(PresentOrNot(nums2,nums2.size(),nums1[i]))
//             {               
//                 s.insert(nums1[i]);               
//             }
//         }
//         for(auto i: s)
//         {
//             v.push_back(i);
//         }
//         return v;

//     }
// };

// Two Pointer Approach 
// Time complexity --> O((n+m)logn) and Space --> O(n)
// where n=nums1.size() and m=nums2.size()
// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> v;
//         unordered_set<int> s;
//         int i=0,j=0;
//         sort(nums1.begin(),nums1.end());
//         sort(nums2.begin(),nums2.end());
//         while(i<nums1.size() && j<nums2.size())
//         {
//             if(nums1[i]==nums2[j])
//             {
//                 s.insert(nums1[i]);
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
//         for(auto it: s)
//         {
//             v.push_back(it);
//         }
//         return v;

//     }
// };

// Optimized Approach [Using Set]
// Time complexity --> O(n+m) ~ O(n) and Space --> O(n)
// where n=nums1.size() and m=nums2.size()
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_set<int> s;
        for(auto it: nums1)
        {
            s.insert(it);
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(s.find(nums2[i])!=s.end())
            {
                v.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }
        return v;
    }
};


// Question link -- https://leetcode.com/problems/intersection-of-two-arrays/



