#include <bits/stdc++.h>
using namespace std;

// Optimized Approach
// Time complexity --> O(n) and Space -> O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0, i=s.size()-1;
        while(i>=0 && s[i]==' ')
        {
            i--;
        }
        while(i>=0 && s[i]!=' ')
        {
            i--;
            ans++;
        }
        return ans;
        
    }
};

// Question link -- https://leetcode.com/problems/length-of-last-word/

// My solution link -- https://leetcode.com/problems/length-of-last-word/solutions/3214181/easiest-c-solution-optimized-approach/