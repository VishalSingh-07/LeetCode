/*
739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]


Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]


Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(n) 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        int n=temperatures.size();
        for(int i=0;i<n;i++)
        {
            int x=0;
            for(int j=i+1;j<n;j++)
            {
                if(temperatures[j]>temperatures[i])
                {
                    x=j-i;
                    break;
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};

// Above code ❌ give timit limit Exceeded due to high time complexity O(n^2)


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n) 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(),0);

        for(int i=0;i<temperatures.size();i++)
        {
            while(!st.empty() && temperatures[i]>temperatures[st.top()])
            {
                int index=st.top();
                st.pop();
                ans[index]=i-index;
            }
            st.push(i);
        }
        return ans;
    }
};


/*
1. Question Link -- https://leetcode.com/problems/daily-temperatures/description/

2. Solution Link -- https://leetcode.com/problems/daily-temperatures/solutions/4655842/2-approach-easy-c-solution-brute-force-optimized-approach-with-explanation
*/