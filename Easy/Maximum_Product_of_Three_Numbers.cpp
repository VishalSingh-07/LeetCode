#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(nlogn) and Space -> O(1)
// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
        
//         int n=nums.size();
//         if(n<3)
//         {
//             return -1;
//         }
//         sort(nums.begin(),nums.end());

//         int maxi=max(nums[n-3]*nums[n-2]*nums[n-1],nums[0]*nums[1]*nums[n-1]);

//         return maxi;
//     }
// };

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int first_max=INT_MIN;
        int second_max=first_max;
        int third_max=first_max;

        int first_min=INT_MAX;
        int second_min=first_min;

        for(int i=0;i<nums.size();i++)
        {
            // Calculating first_max, second_max, and third_max
            if(first_max<=nums[i])
            {
                third_max=second_max;
                second_max=first_max;
                first_max=nums[i];
            }
            else if(second_max<=nums[i])
            {
                third_max=second_max;
                second_max=nums[i];
            }
            else if(third_max<=nums[i])
            {
                third_max=nums[i];
            }

            // Calculating the first_min, second_min
            if(first_min>=nums[i])
            {
                second_min=first_min;
                first_min=nums[i];
            }
            else if(second_min>=nums[i])
            {
                second_min=nums[i];
            }
        }
        int maxi=max(first_max*second_max*third_max,first_min*second_min*first_max);

        return maxi;
    }
};

// Question link -- https://leetcode.com/problems/maximum-product-of-three-numbers/

// Solution link -- https://leetcode.com/problems/maximum-product-of-three-numbers/solutions/3279567/2-approach-easy-c-solution-brute-force-sorting-and-optimized-approach/
