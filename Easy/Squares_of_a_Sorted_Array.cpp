#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity --> O(n)+O(nlogn) ~~O(nlogn) and space --> O(1)
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
        
//         for(int i=0;i<nums.size();i++)
//         {
//             nums[i]=nums[i]*nums[i];
//         }
//         sort(nums.begin(),nums.end());

//         return nums;
//     }
// };

// Time complexity --> O(n) and space --> O(n)
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {

//         vector<int> output(nums.size());
//         int left=0;
//         int right=nums.size()-1;
        
//         for(int i=nums.size()-1; i>=0;i--)
//         {
//             if(abs(nums[left])>abs(nums[right]))
//             {
//                 output[i]=nums[left]*nums[left];
//                 left++;
//             }
//             else
//             {
//                 output[i]=nums[right]*nums[right];
//                 right--;
//             }
//         }
//         return output;

        
//     }
// };

// OR

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int left=0;
        int right=nums.size()-1;
        vector<int> output(nums.size());
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[left]*nums[left]>nums[right]*nums[right])
            {
                output[i]=nums[left]*nums[left];
                left++;
            }
            else
            {
                output[i]=nums[right]*nums[right];
                right--;

            }
        }

        return output;
    }
};

// Question link -- https://leetcode.com/problems/squares-of-a-sorted-array/description/

// Video Link -- https://youtu.be/XgRIr8CCCVk