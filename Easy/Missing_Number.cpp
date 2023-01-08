#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity -> O(n) and space --> O(1)
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n=nums.size();
//         int nthsum=n*(n+1)/2;
//         int sum=0;
//         for(int i=0;i<n;i++)
//         {
//             sum+=nums[i];
//         }
//         int diff=nthsum-sum;
//         return diff;
        
//     }
// };


// 1 Line approach
// Time complexity -> O(n) and space --> O(1)
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n=nums.size();
//         return n*(n+1)*0.5-accumulate(nums.begin(),nums.end(),0);
        
//     }
// };




// Bit Manipulation Approach
// Time complexity -> O(n) and space --> O(1)
/*
Iterate over the size of the nums
if (i < size)
    // Perform XOR operation with variable to ^nums[i] ^ i
else
    //  Perform XOR operation with variable to ^ i
Return the answer
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int answer=0;
        for(int i=0;i<=nums.size();i++)
        {
            if(i<nums.size())
            {
                answer=answer^nums[i]^i;
            }
            else
            {
                answer=answer^i;
            }
        }
        return answer;
        
    }
};



/*
Property of XOR --
0 ^ 0 --> 0
0 ^ 1 --> 1
1 ^ 0 --> 1
1 ^ 1 --> 0
*/

// Question link -- https://leetcode.com/problems/missing-number/

