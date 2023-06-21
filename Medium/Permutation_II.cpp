#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n!*n) and space -> O(n!*n)
// class Solution {
// private:
//     void recPermuteUnique(int index, vector<int> &nums, set<vector<int>> &set, vector<int> temp)
//     {
//         if(index==nums.size())
//         {
//             set.insert(temp);
//             return;
//         }
//         for(int i=index;i<temp.size();i++)
//         {
//             swap(temp[index],temp[i]);
//             recPermuteUnique(index+1,nums,set,temp);
//         }
//     }
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//        vector<vector<int>> output;
//        vector<int> temp=nums;
//        sort(temp.begin(),temp.end());
//        set<vector<int>>set;
//        recPermuteUnique(0,nums,set,temp);
//        for(auto it: set)
//        {
//            output.push_back(it);
//        } 
//        return output;
//     }
// };


// Better Approach
// Time complexity -> O(n!*n) and Space -> O(n)
// class Solution {
// private:
//     void recPermuteUnique(int index, vector<int> &nums, vector<vector<int>> &ans)
//     {
//         if(index==nums.size())
//         {
//             ans.push_back(nums);
//             return;
//         }
//         unordered_set<int> st;
//         for(int i=index;i<nums.size();i++)
//         {
//             if(st.find(nums[i])!=st.end())
//             {
//                 continue;
//             }
//             st.insert(nums[i]);
//             swap(nums[index],nums[i]);
//             recPermuteUnique(index+1,nums,ans);
//             swap(nums[index],nums[i]);
//         }
//     }
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> ans;
//         recPermuteUnique(0,nums,ans);
//         return ans;
//     }
// };



// Optimized Approach
// Time complexity -> O(n!*n) and Space -> O(1)

/*
This method can be used to solve Permutation II problem of Leetcode, 
where duplicate elements could be present in the array. 

The only thing to take care in this case is that we are dependent on the sorted order of Array 
to check for and skip duplicates, so either don't pass the array as reference or restore 
the original array before exiting
*/

class Solution {
private:
    void recPermuteUnique(int index, vector<int> nums, vector<vector<int>> &ans) // not passing nums as by reference
    {
        // Base case: if all elements have been considered, add the permutation to ans
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        // Explore different possibilities by swapping elements
        for(int i=index;i<nums.size();i++)
        {
            // Explore different possibilities by swapping elements
            if(i==index || nums[i]!=nums[index])
            {
                // Swap elements at indices index and i
                swap(nums[index],nums[i]);

                // Recursive call to generate permutations
                recPermuteUnique(index+1,nums,ans); //As not passing by reference nums hence no backtrack
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        // Sort the input vector to handle duplicates
        sort(nums.begin(),nums.end());
        recPermuteUnique(0,nums,ans);
        return ans;
    }
};

/*
1. Question link -- https://leetcode.com/problems/permutations-ii/

2. Solution link -- https://leetcode.com/problems/permutations-ii/solutions/3665973/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video Link -- https://youtu.be/is_T6uzlTyg
*/