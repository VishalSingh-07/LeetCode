#include <bits/stdc++.h>
using namespace std;

/*
1544. Make the String Great

Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

 

Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".

Example 2:

Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""

Example 3:

Input: s = "s"
Output: "s"
 

Constraints:

1 <= s.length <= 100
s contains only lower and upper case English letters.
*/
// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
class Solution {
public:
    string makeGood(string s) {
        int flag=0;
        while(flag==0 && s.length()>0){
            flag=1;
            for(int i=0;i<s.length()-1;i++){
                if(abs(s[i]-s[i+1])==32){
                    s.erase(i,2);
                    flag=0;
                    break;
                }
            }
        }
        return s;
    }
};


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && abs(s[i]-st.top())==32){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string result="";
        while(!st.empty()){
            result=st.top()+result;
            st.pop();
        }
        return result;
    }
};

/*
1. Question link -- https://leetcode.com/problems/make-the-string-great/description/

2. Solution link -- https://leetcode.com/problems/make-the-string-great/solutions/4979268/2-approach-best-c-solution-brute-force-and-optimized-approach-with-explanation
*/