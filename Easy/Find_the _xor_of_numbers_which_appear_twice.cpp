/*

3158. Find the XOR of Numbers Which Appear Twice

You are given an array nums, where each number in the array appears either once or twice.

Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.

 

Example 1:

Input: nums = [1,2,1,3]

Output: 1

Explanation:

The only number that appears twice in nums is 1.



Example 2:

Input: nums = [1,2,3]

Output: 0

Explanation:

No number appears twice in nums.



Example 3:

Input: nums = [1,2,2,1]

Output: 3

Explanation:

Numbers 1 and 2 appeared twice. 1 XOR 2 == 3.

 

Constraints:
- 1 <= nums.length <= 50
- 1 <= nums[i] <= 50
- Each number in nums appears either once or twice.
*/


#include <bits/stdc++.h>
using namespace std;


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto x: nums){
            mpp[x]++;
        }
        int Xor=0;
        for(auto it: mpp){
            if(it.second==2){
                Xor^=it.first;
            }
        }
        return Xor==0?0:Xor;
    }
};


// OR
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto x: nums){
            mpp[x]++;
        }
        int result=0;
        for(auto it: mpp){
            if(it.second==2){
                result^=it.first;
            }
        }
        return result;
    }
};
/*
1. Question link -- https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/

2. Solution link -- https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/solutions/5236601/optimized-approach-with-explanation-best-c-solution-unordered-map
*/