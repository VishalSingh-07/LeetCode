/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity - O(n^4) and Space - O(2 * no. of the quadruplets) 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    for(int l=k+1;l<n;l++)
                    {
                        long long sum=nums[i]+nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum==target)
                        {
                            vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

// Above code time limit exceeded due to high complexity O(n^4)


// Better Approach
// Time Complexity - O(n^3*log(m)) and Space - O(2 * no. of the quadruplets)+O(n)
// where n = size of the array, m = no. of elements in the set. 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                set<long long> hashset;
                for(int k=j+1;k<n;k++)
                {
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourth=target-(sum);
                    if(hashset.find(fourth)!=hashset.end())
                    {
                        vector<int> temp={nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

// Optimized Approach
// Time Complexity - O(n^3) and Space - O(no. of quadruplets)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j=i+1;j<n;j++)
            {
                if(j!=(i+1) && nums[j]==nums[j-1])
                {
                    continue;
                }
                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target)
                    {
                        vector<int> temp = {nums[i],nums[j],nums[l],nums[k]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) // for skipping the duplicate element
                        {
                            k++;
                        }
                        while(k<l && nums[l]==nums[l+1]) // for skipping the duplicate element
                        {
                            l--;
                        }
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }   
                }
            } 
        }
        return ans;
    }
};


/*
1. Question Link -- https://leetcode.com/problems/4sum/description/

2. Solution Link -- https://leetcode.com/problems/4sum/solutions/4672889/best-c-solution-3-approach-brute-force-better-and-optimized-approach

3. Video Link -- https://youtu.be/eD95WRfh81c
*/