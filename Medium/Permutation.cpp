#include <bits/stdc++.h>
using namespace std;


// Approach 1: Brute Force Approach [Recursion]
// Time complexity -> O(n!*n) and Space -> O(n + n) = O(2n) ~ O(n)
// class Solution {
// private:
//     // Helper function to generate permutations recursively
//     void recursionPermute(vector<vector<int>> &ans, vector<int> &nums, vector<int> &ds, vector<int> &freq)
//     {
//         if(ds.size() == nums.size()) // Base case: A valid permutation has been constructed
//         {
//             ans.push_back(ds); // Add the current permutation to the result vector
//             return;
//         }
//         for(int i = 0; i < nums.size(); i++)
//         {
//             if(!freq[i]) // Check if the element at index i has not been used in the current permutation
//             {
//                 ds.push_back(nums[i]); // Add the element to the temporary vector
//                 freq[i] = 1; // Mark the element as used
//                 recursionPermute(ans, nums, ds, freq); // Recursively generate the remaining permutations
//                 freq[i] = 0; // Reset the frequency of the element to backtrack
//                 ds.pop_back(); // Remove the element from the temporary vector
//             }
//         }
//     }
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans; // Vector to store the resulting permutations
//         vector<int> ds; // Temporary vector to store the current permutation being constructed
//         vector<int> freq(nums.size(), 0); // Frequency vector to keep track of used elements
//         recursionPermute(ans, nums, ds, freq); // Generate permutations using the helper function
//         return ans; // Return the resulting permutations
//     }
// };



// Approach 2: Optimized Force Approach [Recursion]
// Time complexity -> O(n!*n) and Space -> O(1)
class Solution {
private:
    // Helper function to generate permutations recursively
    void recursionPermute(int index, vector<int> &nums,vector<vector<int>> &ans)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            recursionPermute(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recursionPermute(0,nums,ans);
        return ans;
    }
};


/*

1. Question Link -- https://leetcode.com/problems/permutations/

2. Solution link -- https://leetcode.com/problems/permutations/solutions/3653480/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link --

      a) Part 1 -- https://youtu.be/YK78FU5Ffjw

      b) Part 2 -- https://youtu.be/f2ic2Rsc9pU

*/