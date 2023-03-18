/*
179. Largest Number

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;


// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution {
public:
    static bool custom_comparator(string &a, string &b)
    {
        if(a+b>b+a) // 3,30 ==> 330 or 303
        {
            return true;
        }
        return false;

    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string> v;
        for(int x: nums)
        {
            v.push_back(to_string(x));
        }
        sort(v.begin(),v.end(),custom_comparator);
        for(string x: v)
        {
            ans+=x;
        }
        int start=0;
        while(ans[start]=='0' && start<ans.size()-1)
        {
            start++;
        }
        return ans.substr(start);
    }
};

/*
1. Question link -- https://leetcode.com/problems/largest-number/

2. My Solution link -- https://leetcode.com/problems/largest-number/solutions/3311857/easy-c-solution-optimized-approach-t-c-o-nlogn-and-s-c-o-n/

3. Video Link -- https://youtu.be/2vcOnre_tMM
*/