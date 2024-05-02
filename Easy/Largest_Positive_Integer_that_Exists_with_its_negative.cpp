/*
2441. Largest Positive Integer That Exists With Its Negative

Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

Return the positive integer k. If there is no such integer, return -1.

 

Example 1:

Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.



Example 2:

Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.



Example 3:

Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.
 

Constraints:
- 1 <= nums.length <= 1000
- -1000 <= nums[i] <= 1000
- nums[i] != 0
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i]==-nums[j]){
                    ans=max(ans,abs(nums[i]));
                }
            }
        }
        return ans;
    }
};


// Better Approach
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        for(auto x: nums){
            if(x<0){
                st.insert(x);
            }  
        }
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size();i++){
            if(st.find(-nums[i])!=st.end()){
                return nums[i];
            }
        }
        return -1;
    }
};


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        for(auto x: nums){
            if(x<0){
                st.insert(x);
            }
        }
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            if(st.find(-nums[i])!=st.end()){
                maxi=max(maxi,nums[i]);
            }
        }
        return maxi;
    }
};


// Optimized Approach [One Pass Hash Set]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        int ans=-1;
        for(int num:nums){
            int abs_num=abs(num);

            if(abs_num>ans && st.contains(-num)){
                ans=abs_num;
            }
            st.insert(num);
        }
        return ans;
    }
};


/*
1. Question link -- https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

2. Solution link -- https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/solutions/5100717/4-approach-easy-c-solutions-brute-force-better-optimized-approach-with-explanation
*/