#include <bits/stdc++.h>
using namespace std;

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1;i>=0;i--)
        {
            if((num[i]-'0')%2!=0)
            {
                // If an odd digit is found, return the substring up to that point
                return num.substr(0,i+1);  
            }
        }
        
        // If no odd digits are found, return an empty string
        return "";
    }
};
/*
1. Question Link -- https://leetcode.com/problems/largest-odd-number-in-string/description/

2. Solution Link -- https://leetcode.com/problems/largest-odd-number-in-string/solutions/4374034/optimized-approach-easy-c-solution-simple-approach-easy-to-understand/
*/