#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^2) and Space -> O(1)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                if(sum%k==0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// Above code ❌ give Time limit Exceeded because of High time complexity O(n^2) 

// Optimized Approach
// Time complexity --> O(n) and Space -> O(n)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> rem_freq;
        int running_sum=0,count=0;
        rem_freq[0]=1; //initially sum will be zero so it will be divisible by k(thats obvious);
        for(int i=0;i<nums.size();i++)
        {
            running_sum+=nums[i];
            int rem=running_sum%k;
            if(rem<0)
            {
                rem+=k;
            }
            if(rem_freq[rem]!=0)
            {
                count+=rem_freq[rem];
            }
            rem_freq[rem]++;
        }
        return count;
    }
};


/*
1. Question link -- https://leetcode.com/problems/subarray-sums-divisible-by-k/

2. Solution link -- https://leetcode.com/problems/subarray-sums-divisible-by-k/solutions/3256035/2-approach-easy-c-solution-brute-force-optimized-approach-map-full-explanation/

3. Video link -- https://youtu.be/ufXxc8Vty9A
*/
