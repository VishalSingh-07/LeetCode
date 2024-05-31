/*
3159. Find Occurrences of an Element in an Array

You are given an integer array nums, an integer array queries, and an integer x.

For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.

Return an integer array answer containing the answers to all queries.

 

Example 1:

Input: nums = [1,3,1,7], queries = [1,3,2,4], x = 1

Output: [0,-1,2,-1]

Explanation:

For the 1st query, the first occurrence of 1 is at index 0.
For the 2nd query, there are only two occurrences of 1 in nums, so the answer is -1.
For the 3rd query, the second occurrence of 1 is at index 2.
For the 4th query, there are only two occurrences of 1 in nums, so the answer is -1.



Example 2:

Input: nums = [1,2,3], queries = [10], x = 5

Output: [-1]

Explanation:

For the 1st query, 5 doesn't exist in nums, so the answer is -1.
 

Constraints:
- 1 <= nums.length, queries.length <= 105
- 1 <= queries[i] <= 105
- 1 <= nums[i], x <= 104
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n*m) and Space -> O(n+m)
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans;
        // index,values
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[i]=nums[i];
        }
        for(int i=0;i<queries.size();i++){
            int occurrence=queries[i];
            int count=0;
            for(auto it: mpp){
                if(it.second==x) count++;
                if(count==occurrence){
                    ans.push_back(it.first);
                    break;
                }
            }
            if(count<occurrence){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

// Above code giving time limit exceeded due to high time complexity O(n^2)


// Optimized Approach
// Time complexity -> O(n+m) and Space -> O(n+m)
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans;
        vector<int> indices;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                indices.push_back(i);
            }
        }
        for(int i=0;i<queries.size();i++){
            int occurrence=queries[i];
            if(occurrence<=indices.size()){
                ans.push_back(indices[occurrence-1]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
        
    }
};


/*
1. Question link -- https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/description/

2. Solution link -- https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/solutions/5236684/2-approach-best-c-solution-brute-force-and-optimized-approach
*/