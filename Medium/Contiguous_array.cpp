/*
525. Contiguous Array


Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.


Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.


Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int n=nums.size();
        for (int i = 0; i < n; i++) 
        {
            int countZero = 0, countOne = 0;
            for (int j = i; j < n; j++) 
            {
                if (nums[j] == 0){
                    countZero++;
                }
                else{
                    countOne++;
                }  
                if (countZero == countOne){
                    maxLength = max(maxLength, j - i + 1);
                }  
            }
        }
        return maxLength;
    }
};

// Above code give Time limit Exceeded due to high time complexity O(n^2)

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int sum=0,maxLen=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]==0?-1:1;
            if(sum==0){
                maxLen=i+1;
            }
            else if(mpp.find(sum)!=mpp.end()){
                maxLen=max(maxLen,i-mpp[sum]);
            }else{
                mpp[sum]=i;
            }
        }
        return maxLen;
    }
};

/*
1. Question link -- https://leetcode.com/problems/contiguous-array/description/

2. Solution link -- https://leetcode.com/problems/contiguous-array/solutions/4884512/best-c-solution-2-approach-brute-force-and-optimized-approach-with-explanation
*/