/*
167. Two Sum II - Input Array Is Sorted

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

Constraints:

1. 2 <= numbers.length <= 3 * 104

2. -1000 <= numbers[i] <= 1000

3. numbers is sorted in non-decreasing order.

4. -1000 <= target <= 1000

5. The tests are generated such that there is exactly one solution.
*/


#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int n=numbers.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(numbers[i]+numbers[j]==target)
//                 {
//                     return {i+1,j+1};
//                 }
//             }
//         }
//         return {-1,-1};
//     }
// };

// Above Code ❌ give time limit Exceeded due to high complexity O(n^2) 

// Better Approach [Binary Search]
// Time complexity -> O(nlogn) and Space -> O(1)
// class Solution {
// public:
//     int FindNum(vector<int> &numbers, int target,int low, int high)
//     {
//         while(low<=high)
//         {
//             int mid=low+(high-low)/2;
//             if(numbers[mid]==target)
//             {
//                 return mid;
//             }
//             else if(numbers[mid]>target)
//             {
//                 high=mid-1;
//             }
//             else
//             {
//                 low=mid+1;
//             }
//         }
//         return -1;
//     }
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int low=0,high=numbers.size()-1;
//         for(int i=0;i<numbers.size();i++)
//         {
//             int find=target-numbers[i];
//             low=i+1;
//             int index=FindNum(numbers,find,low,high);
//             if(index!=-1)
//             {
//                 return {i+1,index+1};
//             }
//         }
//         return {-1,-1};
//     }
// };



// HashMap Approach
// Time complexity -> O(n) and Space -> O(n)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         unordered_map<int,int> mpp;
//         vector<int> ans;
//         int n=numbers.size();
//         for(int i=0;i<n;i++)
//         {
//             if(mpp.find(target-numbers[i])!=mpp.end())
//             {
//                 ans.push_back(mpp[target-numbers[i]]+1);
//                 ans.push_back(i+1);
//                 return ans;
//             }
//             mpp[numbers[i]]=i;
//         }
//         return ans;
//     }
// };


// Optimized Approach [Two Pointer]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int p1=0,p2=n-1;
        while(p1<p2)
        {
            int sum=numbers[p1]+numbers[p2];
            if(sum==target)
            {
                return {p1+1,p2+1};
            }
            else if(sum>target)
            {
                p2--;
            }
            else
            {
                p1++;
            }
        }
        return {-1,-1};
    }
};

/*
1. Question link -- https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

2. Solution link -- https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/solutions/3284501/4-approach-easy-c-solution-brute-force-better-hashmap-optimized-approach/
*/