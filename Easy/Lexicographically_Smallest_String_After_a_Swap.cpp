/*
3216. Lexicographically Smallest String After a Swap

Given a string s containing only digits, return the lexicographically smallest string

that can be obtained after swapping adjacent digits in s with the same parity at most once.

Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.

 

Example 1:

Input: s = "45320"

Output: "43520"

Explanation:

s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.

Example 2:

Input: s = "001"

Output: "001"

Explanation:

There is no need to perform a swap because s is already the lexicographically smallest.

 

Constraints:
- 2 <= s.length <= 100
- s consists only of digits.
*/

#include <bits/stdc++.h>
using namespace std;

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    string getSmallestString(string s) {
        for(int i=0;i<s.length()-1;i++){
            if((s[i]%2!=0 && s[i+1]%2!=0) || (s[i]%2==0 && s[i+1]%2==0)){
                if(s[i]>s[i+1]){
                    swap(s[i],s[i+1]);
                    break;
                }
            }
        }
        return s;
    }
};
/*
1. Question link -- https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/description/

2. Solution link -- https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/solutions/5474378/optimized-approach-with-explanation-best-c-solution-beats-100-00-of-users-with-c
*/