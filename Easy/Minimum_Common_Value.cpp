/*
2540. Minimum Common Value

Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.


Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 109
Both nums1 and nums2 are sorted in non-decreasing order.
*/


#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> (n*m) and Space ->  O(1)
// where n: Size of nums1 and m: size of nums2
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    return nums1[i];
                }
            }
        }
        return -1;
    }
};
// Above code give Time Limit Exceeded due to High Complexity O(n^2)


// Better Approach [Using Hash Table]
// Time complexity -> (n+m) and Space ->  O(min(n,m))
// where n: Size of nums1 and m: size of nums2
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(),nums1.end());
        for(int i=0;i<nums2.size();i++)
        {
            if(s.count(nums2[i])>0)
            {
                return nums2[i];
            }
        }
        return -1;
    }
};

// Optimized Approach [Two Pointer]
// Time complexity -> O(n+m) and Space ->  O(1)
// where n: Size of nums1 and m: size of nums2
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int common=INT_MAX;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                common=nums1[i];
                break;
            }
            else if(nums1[i]>nums2[j] )
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return common!=INT_MAX?common:-1;
    }
};

/*
1. Question link -- https://leetcode.com/problems/minimum-common-value/description/

2. Solution link -- https://leetcode.com/problems/minimum-common-value/solutions/4847409/3-approach-easy-c-solution-brute-force-and-optimized-approach-with-explanation
*/