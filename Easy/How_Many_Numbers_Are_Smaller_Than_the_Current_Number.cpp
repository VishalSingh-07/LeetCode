/*
1365. How Many Numbers Are Smaller Than the Current Number

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).


Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]


Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]
 

Constraints:

2 <= nums.length <= 500
0 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(n)
// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         vector<int> ans;
//         for(int i=0;i<nums.size();i++)
//         {
//             int count=0;
//             for(int j=0;j<nums.size();j++)
//             {
//                 if(nums[i]>nums[j] && i!=j)
//                 {
//                     count++;
//                 }
//             }
//             ans.push_back(count);
//         }
//         return ans;

//     }
// };

// Better Approach
// Time complexity -> O(nlogn) and Space -> O(n)
// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         vector<int> ans;
//         vector<int> temp = nums;
//         sort(temp.begin(),temp.end());
//         for(int i = 0; i < nums.size(); i++)
//         {
//             int low = 0;
//             int high = temp.size()-1;
//             while(low<=high)
//             {
//                 int mid = low+(high-low)/2;
//                 if(temp[mid] == nums[i])
//                 {
//                     high=mid-1;
//                 }
//                 else if(temp[mid] > nums[i])
//                 {
//                     high=mid-1;
//                 }
//                 else
//                 {
//                     low=mid+1;
//                 }
//             }
//             ans.push_back(low);
//         }
//         return ans;
//     }
// };

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> temp(101);
        for(int i=0;i<nums.size();i++) 
        {
            temp[nums[i]]++;  // Storing the frequency
        }
        for(int i=1;i<101;i++)
        {
            temp[i]=temp[i]+temp[i-1];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                ans[i]=0;
            }
            else
            {
                ans[i]=temp[nums[i]-1];
            }
        }
        return ans;

    }
};


/*
1. Question link -- https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

2. Solution link -- https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/solutions/3303330/3-approach-easy-c-solution-brute-force-better-sorting-optimized-approach/

3. Video Link -- https://youtu.be/ftnhmygR7k4
*/