#include <bits/stdc++.h>
using namespace std;
/*
Approach 1: Copy elements of second array into first and sort the merged array (Time complexity --> O(klogk) and space :-- O(1))
where k = m + n;

Approach 2: Two Pointer Approach 
Time complexity -->  O(k) and space: -- O(1)
where k=m+n
**/

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

//         vector<int> merge;

//         for(int i=0;i<m;i++)
//         {
//             merge.push_back(nums1[i]);
//         }
//         for(int i=0;i<n;i++)
//         {
//             merge.push_back(nums2[i]);
//         }

//         sort(merge.begin(),merge.end());

//         nums1.clear();

//         for(auto it: merge)
//         {
//             nums1.push_back(it);
//         }

        
        
//     }
// };



// Approach 2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1; // for first array (pointer)
        int p2=n-1; // for second array (pointer)
        int i=m+n-1; // Point to the last element of the array 1

        while(p2>=0)
        {
            if(p1>=0 && nums1[p1]>nums2[p2])
            {
                nums1[i]=nums1[p1];
                i--;
                p1--;
            }
            else
            {
                nums1[i]=nums2[p2];
                i--;
                p2--;
            }
        }
        
    }
};

// Question link -- https://leetcode.com/problems/merge-sorted-array/description/

// Youtube Video Link -- https://youtu.be/C4oBXLr3zos