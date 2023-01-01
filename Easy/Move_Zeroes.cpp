// Time complexity --> O(n) and space --> O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        for(;j<nums.size();j++)
        {
            nums[j]=0;
        }
        
    }
};

// Question link -- https://leetcode.com/problems/move-zeroes/description/