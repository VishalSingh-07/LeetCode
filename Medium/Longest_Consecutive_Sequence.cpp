/*
128. Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/


#include <bits/stdc++.h>
using namespace std;



// Brute Force Approach
// Time complexity -> O(n^3) and Space -> O(1)
// class Solution {
// private:
//     bool arrayContains(vector<int> &nums, int x)
//     {
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==x)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int longestStreak=0;

//         for(int i=0;i<nums.size();i++)
//         {
//             int currentNum=nums[i];
//             int currentStreak=1;

//             while(arrayContains(nums,currentNum+1))
//             {
//                 currentNum++;
//                 currentStreak++;
//             }
//             longestStreak=max(longestStreak,currentStreak);
//         }
//         return longestStreak;
//     }
// };

// Above code ❌ give time limit Exceeded due to high complexity O(n^3)

// Better Approach [Using Sorting Approach]
// Time complexity -> O(nlogn) and Space -> O(1)
// class Solution {
// public:

//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size()==0)
//         {
//             return 0;
//         }
//         sort(nums.begin(),nums.end());
//         int longestStreak=1,currentStreak=1;
//         for(int i=1;i<nums.size();i++)
//         {
//             if(nums[i]!=nums[i-1])
//             {
//                 if(nums[i]==nums[i-1]+1)
//                 {
//                     currentStreak++;
//                 }
//                 else
//                 {
//                     longestStreak=max(longestStreak,currentStreak);
//                     currentStreak=1;
//                 }
//             }
//         }
//         return max(longestStreak,currentStreak);
//     }
// };

// Optimized Approach [Using Unordered_Map]
// Time complexity -> O(n) and Space -> O(n)
/*
Algorithm:

1.  Create an empty hash.
2.  Insert all array elements to hash.
3.  Do following for every element arr[i].
4.  Check if this element is the starting point of a subsequence. To check this, simply look for
    arr[i]-1 in the hash, if not found, then this is the first element a subsequence.
5.  If this element is the first element, then count the number of element in the consecutive starting
    with this element iterate from arr[i]+1 till the last element that can be found.
6.  If the count is more than the previous longest subsequence found, then update this.
*/
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(auto it: nums)
//         {
//             mp[it]++;
//         }
//         int longestStreak=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             int currentElement=nums[i];
//             int previousElement=currentElement-1;
//             int currentStreak=0;
//             if(mp.find(previousElement)==mp.end())
//             {
//                 while(mp.find(currentElement)!=mp.end())
//                 {
//                     currentElement++;
//                     currentStreak++;
//                 }
//             }
//             longestStreak=max(longestStreak,currentStreak);
//         }
//         return longestStreak;

//     }
// };

// Optimized Approach [Using Unordered Set]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto it: nums)
        {
            s.insert(it);
        }
        int longestStreak=0;
        for(int i=0;i<nums.size();i++)
        {
            int currentElement=nums[i];
            int previousElement=currentElement-1;
            int currentStreak=0;
            if(s.find(previousElement)==s.end())
            {
                while(s.find(currentElement)!=s.end())
                {
                    currentElement++;
                    currentStreak++;
                }
            }
            longestStreak=max(longestStreak,currentStreak);
        }
        return longestStreak;

    }
};


/*
1. Question link -- https://leetcode.com/problems/longest-consecutive-sequence/

2. My Solution link -- https://leetcode.com/problems/longest-consecutive-sequence/solutions/3332851/4-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video Link --

      a) https://youtu.be/pLzOp2_Y9Vk

      b) https://youtu.be/qgizvmgeyUM

*/