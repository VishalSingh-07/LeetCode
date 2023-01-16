#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++)
//         {
//             int leftsum=0;
//             int rightsum=0;
//             for(int j=0;j<i;j++)
//             {
//                 leftsum=leftsum+nums[j];
//             }
//             for(int k=i+1;k<nums.size();k++)
//             {
//                 rightsum=rightsum+nums[k];
//             }

//             if(leftsum==rightsum)
//             {
//                 return i;
//             }
//         }
//         return -1;
        
//     }
// };

// Optimized Approach

// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    
        int sum=0,leftsum=0,rightsum=0;
        for(auto i: nums)
        {
            sum+=i;
        }
        rightsum=sum;
        for(int i=0;i<nums.size();i++)
        {
            leftsum+=nums[i];
            if(leftsum==rightsum)
            {
                return i;
            }
            rightsum-=nums[i];
        }
            

        return -1;
        
    }
};

// Question link -- https://leetcode.com/problems/find-pivot-index/

// My Fully Explained Solution -- https://leetcode.com/problems/find-pivot-index/solutions/3058088/two-approach-to-solve-a-problem-easy-solution-brute-force-optimized-approach-dry-run/