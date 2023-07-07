#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(nlogn) + O(2n) and Space -> O(n)
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> ans;
//         sort(intervals.begin(),intervals.end());

//         for(int i=0;i<intervals.size();i++)
//         {
//             int start=intervals[i][0];
//             int end=intervals[i][1];

//             if(!ans.empty() && end<=ans.back()[1])
//             {
//                 continue;
//             }
//             for(int j=i+1;j<intervals.size();j++)
//             {
//                 if(intervals[j][0]<=end)
//                 {
//                     end=max(end,intervals[j][1]);
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             ans.push_back({start,end});
//         }

//         return ans;

//     }
// };

// Optimized Approach
// Time complexity -> O(nlogn) + O(n) and Space -> O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        for(int i=0;i<intervals.size();i++)
        {
            if(ans.empty() || ans.back()[1] < intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};




/*
1. Question link -- https://leetcode.com/problems/merge-intervals/

2. Solution link -- https://leetcode.com/problems/merge-intervals/solutions/3730445/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link -- https://youtu.be/IexN60k62jo
*/