#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {

//         int n=nums.size();

//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[i]==nums[j])
//                 {
//                     return nums[i];
//                 }
//             }
//         }
//         return -1;
        
//     }
// };

// Above Code is not working due to time limit exceeded. 
// This is because above code has time complexity --> O(n^2)

// Using Sorting technique -- [Naive Approach]
// Time complexity --> O(nlogn) and Space --> O(1)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==nums[i+1])
//             {
//                 return nums[i];
//             }
//         }

//         return -1;
        
//     }
// };


// Using Hashing Approach 
// Time complexity --> O(n) and Space --> O(n)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         map<int,int> mp;
//         for(auto it: nums)
//         {
//             mp[it]++;
//         }

//         for(auto i: mp)
//         {
//             if(i.second>1)
//             {
//                 return i.first;
//             }
//         }

//         return -1;

        
//     }
// };

// Optimized Approach [Linked List Cyclic Method]
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];

        do{
            slow=nums[slow]; // slow move one step 
            fast=nums[nums[fast]]; // fast move two step
        }while(slow!=fast);

        fast=nums[0];

        while(slow!=fast)
        {
            // Now slow and fast both move one step 
            slow=nums[slow]; 
            fast=nums[fast];
        }

        return slow;
        
    }
};

// Question link -- https://leetcode.com/problems/find-the-duplicate-number/

// Resource Link -- https://leetcode.com/problems/find-the-duplicate-number/solutions/3081802/four-approach-to-solve-a-problem-c-solution-brute-sorting-hashing-optimized-approach/

// Video link -- https://youtu.be/32Ll35mhWg0