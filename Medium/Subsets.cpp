/*
78. Subsets

Given an integer array nums of unique elements, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:
- 1 <= nums.length <= 10
- -10 <= nums[i] <= 10
- All the numbers of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach [Recusion and BackTracking]
// Time complexity -> O(n*2^n) and Space -> O(n*2^n)
class Solution {
    void setOfSubsets(vector<int>& nums, vector<int> subset, vector<vector<int>> &result, int index){
        result.push_back(subset);
        for(int i=index;i<nums.size();i++){
            subset.push_back(nums[i]);
            setOfSubsets(nums,subset,result,i+1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        int index=0;
        setOfSubsets(nums,subset,result,index);
        return result;
    }
};


// Optimized Approach [Bit Manipulation]
// Time complexity -> O(n*2^n) and Space -> O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int> subset;
            for(int j=0;j<n;j++){
                if((i& (1<<j))!=0){
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};

/*
1. Question link -- https://leetcode.com/problems/subsets/description/

2. Solution link -- https://leetcode.com/problems/subsets/solutions/5188190/2-approach-best-c-solution-brute-force-and-optimized-approach-with-explanation
*/