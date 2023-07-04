#include <bits/stdc++.h>
using namespace std;

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!= goal.size() || s.size()<=1)
        {
            return false;
        }
        if(s==goal)
        {
            // if we have 2 same characters in string 's'
            // we can swap them and still strings will remain equal
            vector<int> freq(26,0);
            for(auto& ch: s)
            {
                freq[ch-'a']+=1;
                if(freq[ch-'a']==2)
                {
                    return true;
                }
            }
            // otherwise, if we swap any two characters it will make strings unequal.
            return false;
        }
        int firstIndex=-1;
        int secondIndex=-1;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
            {
                if(firstIndex==-1)
                {
                    firstIndex=i;
                }
                else if(secondIndex==-1)
                {
                    secondIndex=i;
                }
                else
                {
                    // If we have atleast 3 indices with different characters,
                    // then, we can never make strings equal with only one swap
                    return false;
                }
            }
        }
        if(secondIndex==-1)
        {
            // we can't swap if character at only one index is different
            return false;
        }

        // All characters of both the string  are same except two indices.
        return s[firstIndex]==goal[secondIndex] && s[secondIndex]==goal[firstIndex];
    }
};

/*
1. Question link -- https://leetcode.com/problems/buddy-strings/

2. Solution link -- https://leetcode.com/problems/buddy-strings/solutions/3717176/optimized-approach-easy-c-solution-time-complexity-o-n-and-space-o-1/
*/