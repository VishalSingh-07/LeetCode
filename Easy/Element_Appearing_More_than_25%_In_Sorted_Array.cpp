#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int range=arr.size()/4;
        unordered_map<int,int> mpp;
        for(auto it: arr)
        {
            mpp[it]++;
            if(mpp[it]>range)
            {
                return it;
            }
        }
        return -1;
    }
};

// Better Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int range=arr.size()/4;
        for(int i=0;i<arr.size()-range;i++)
        {
            if(arr[i]==arr[i+range])
            {
                return arr[i];
            }
        }
        return -1;
    }
};



// Optimized Approach
// Time complexity -> O(logn) and Space -> O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int range=n/4;
        vector<int> candidates{arr[n/4],arr[2*n/4],arr[3*n/4]};
        for(int candidate: candidates)
        {
            int left=lower_bound(arr.begin(),arr.end(),candidate)-arr.begin();
            int right=upper_bound(arr.begin(),arr.end(),candidate)-arr.begin()-1;
            if(right-left+1>range)
            {
                return candidate;
            }
        }
        return -1;
    }
};




/*
1. Question Link -- https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/

2. Solution Link -- https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/solutions/4390340/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/
*/