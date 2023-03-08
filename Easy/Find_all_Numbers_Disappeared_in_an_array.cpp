#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// O(1) because excluding the space required for the output vector, we only use constant extra space. The output space is generally not included in the space complexity

// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         vector<int> ans;
//         for(int i=1;i<=nums.size();i++)
//         {
//             if(find(nums.begin(),nums.end(),i)==nums.end())
//             {
//                 ans.push_back(i);
//             }

//         }
//         return ans;
//     }
// };

// Above code ❌ give time limit exceeded due to high complexity

// Sorting Approach
// Time complexity -> O(nlogn) and Space -> O(1)
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         vector<int> ans;
//         sort(nums.begin(),nums.end());
//         for(int i=1;i<=nums.size();i++)
//         {
//             if(!binary_search(nums.begin(),nums.end(),i))
//             {
//                 ans.push_back(i);
//             }

//         }
//         return ans;
//     }
// };

// Hash Set Approach
// Time complexity -> O(n) and Space -> O(n)
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         vector<int> ans;
//         int n=nums.size();
//         set<int> st;
//         for(int i=0;i<nums.size();i++)
//         {
//             st.insert(nums[i]);
//         }
//         for(int i=1;i<=nums.size();i++)
//         {
//             if(st.find(i)==st.end())
//             {
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };


// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(auto x: nums)
        {
            int mark=abs(x)-1;
            if(nums[mark]>0)
            {
                nums[mark]*=-1;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};


/*
1. Question link -- https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

2. Solution link --

      i) https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/solutions/1583736/c-python-all-6-solutions-w-explanations-binary-search-hashset-2x-o-1-space-approach/

      ii) https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/solutions/3272165/4-approach-easy-c-solution-brute-force-sorting-hash-set-optimized-approach/
*/