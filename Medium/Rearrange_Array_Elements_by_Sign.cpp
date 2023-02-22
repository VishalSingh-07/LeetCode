#include <bits/stdc++.h>
using namespace std;

// Approach 1 [Using vector]
// Time complexity -> O(n) and Space -> O(n)
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> positive, negative;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]>=0)
//             {
//                 positive.push_back(nums[i]);
//             }
//             else
//             {
//                 negative.push_back(nums[i]);
//             }
//         }
//         int i=0,j=0,k=0;
//         while(i<positive.size() && j<negative.size())
//         {
//             nums[k++]=positive[i++];
//             nums[k++]=negative[j++];
//         }
//         while(i<positive.size())
//         {
//             nums[k++]=positive[i++];
//         }
//         while(j<negative.size())
//         {
//             nums[k++]=negative[j++];
//         }
//         return nums;
//     }
// };


// Approach 1 [Using queue]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> positive, negative;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
            {
                positive.push(nums[i]);
            }
            else
            {
                negative.push(nums[i]);
            }
        }
        int i=0;
        while(i<n)
        {
            if(!positive.empty())
            {
                nums[i++]=positive.front();
                positive.pop();
            }
            if(!negative.empty())
            {
                nums[i++]=negative.front();
                negative.pop();
            }
        }
        return nums;
    }
};


// Question link -- https://leetcode.com/problems/rearrange-array-elements-by-sign/

// My solution link -- https://leetcode.com/problems/rearrange-array-elements-by-sign/solutions/3217799/2-approach-easy-c-solution-optimized-solution-t-c-o-n-and-s-c-o-n/