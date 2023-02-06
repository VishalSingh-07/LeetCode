#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n) and Space --> O(n)
// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int> ans(2*n,0);
//         int j=0;
//         for(int i=0;i<nums.size();i+=2)
//         {
//             ans[i]=nums[j];
//             ans[i+1]=nums[j+n];
//             j++;
//         }
//         return ans;
//     }
// };

// Brute Force Approach [But Lightly different method]
// Time complexity --> O(n) and Space --> O(n) 
// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int> ans(2*n,0);
//         int x=0;
//         for(int i=0;i<n;i++)
//         {
//             ans[x]=nums[i];
//             x+=2;
           
//         }
//         x=1;
//         for(int i=n;i<nums.size();i++)
//         {
//             ans[x]=nums[i];
//             x+=2;
           
//         }
//         return ans;
//     }
// };

// Two pointer Approach
// Time complexity --> O(n) and Space --> O(n)
// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int> ans;
//         for(int i=0,j=n;i<nums.size(),j<nums.size();i++,j++)
//         {
//             ans.push_back(nums[i]);
//             ans.push_back(nums[j]);
//         }
//         return ans;
//     }
// };


// Optimized Approach
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int max=10000;
        for(int i=0;i<n;i++)
        {
            nums[i+n]+=nums[i]*max;
        }
        for(int i=0;i<n;i++)
        {
            nums[2*i]=nums[i+n]/max;
            nums[2*i+1]=nums[i+n]%max;
        }
        return nums;
    }
};

// max value can varies from greater than 1000, you also take 1001, it work perfectly.


// Question link -- https://leetcode.com/problems/shuffle-the-array/

// Video link -- https://youtu.be/XzU5nV98W40

// My Solution link -- https://leetcode.com/problems/shuffle-the-array/solutions/3150564/3-approach-to-solve-a-problem-easy-c-solution-brute-force-two-pointer-optimized/