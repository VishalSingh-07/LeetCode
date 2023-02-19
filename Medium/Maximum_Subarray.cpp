#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^3) and Space --> O(1)
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         int max_sum=INT_MIN;
//         if(n==1)
//         {
//             return nums[0];
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i;j<n;j++)
//             {
//                 int sum=0;
//                 for(int k=i;k<=j;k++)
//                 {
//                     sum=sum+nums[k];
//                 }
//                 if(sum>max_sum)
//                 {
//                     max_sum=sum;
//                 }
//             }
//         }
//         return max_sum;
        
//     }
// };

// Above code ❌ give Time limit exceeded due to high time complexity O(n^3) 

// Better Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         int max_sum=INT_MIN;
//         if(n==1)
//         {
//             return nums[0];
//         }
//         for(int i=0;i<n;i++)
//         {
//             int sum=0;
//             for(int j=i;j<n;j++)
//             {
//                 sum+=nums[j];
//                 if(sum>max_sum)
//                 {
//                     max_sum=sum;
//                 }
//             }
//         }
//         return max_sum;
        
//     }
// };

// Above code ❌ give Time limit exceeded due to high time complexity O(n^2) 

// Optimized Approach [Kadane's Algorithm]
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=nums[0];
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
        
    }
};

/*
1. Question link -- https://leetcode.com/problems/maximum-subarray/

2. My Solution link -- https://leetcode.com/problems/maximum-subarray/solutions/3206363/3-approach-to-solve-a-problem-easy-c-solution-dry-run-of-optimized-solution/

3. Video link --

      i) https://youtu.be/w_KEocd__20

      ii) https://youtu.be/w4W6yya1PIc
*/