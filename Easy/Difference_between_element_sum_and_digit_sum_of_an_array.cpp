// Time complexity --> O(n) and Space --> O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {

        int sum=0;
        int digitsum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(nums[i]>9)
            {
                int x=nums[i];
                while(x!=0)
                {
                    int rem=x%10;
                    digitsum=digitsum+rem;
                    x=x/10;
                }

            }
            else
            {
                digitsum=digitsum+nums[i];
            }
        }
        return abs(sum-digitsum);
    }
};

// Question link -- https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/