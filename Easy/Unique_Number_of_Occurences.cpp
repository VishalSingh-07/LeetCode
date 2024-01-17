#include <bits/stdc++.h>
using namespace std;


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(auto it: arr)
        {
            mpp[it]++;
        }
        unordered_set<int> s;
        for(auto x: mpp)
        {
            s.insert(x.second);
        }
        return s.size()==mpp.size()?true:false;
    }
};

/*
1. Question link -- https://leetcode.com/problems/unique-number-of-occurrences/description/

2. Solution link -- https://leetcode.com/problems/unique-number-of-occurrences/solutions/4580622/optimized-approach-easy-c-solution-with-explanation
*/