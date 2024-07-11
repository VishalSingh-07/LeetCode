/*
1190. Reverse Substrings Between Each Pair of Parentheses

You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

Example 1:

Input: s = "(abcd)"
Output: "dcba"


Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.


Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 

Constraints:
- 1 <= s.length <= 2000
- s only contains lower case English characters and parentheses.
- It is guaranteed that all parentheses are balanced.
*/

#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int start=st.top()+1;
                int end=i-1;
                st.pop();
                reverse(s.begin() + start, s.begin() + end + 1);
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                ans+=s[i];
            }
        }
        return ans;
    }
};


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<int> st;
        vector<int> pairs(n);

        // First pass: Pair up parentheses
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int j=st.top();
                st.pop();
                pairs[i]=j;
                pairs[j]=i;
            }
        }

        // Second pass: Build the result string
        string ans="";
        for(int index=0,direction=1;index<n;index+=direction){
            if(s[index]=='(' || s[index]==')'){
                index=pairs[index];
                direction=-direction;
            }
            else{
                ans+=s[index];
            }
        }
        return ans;

    }
};

/*
1. Question link -- https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/

2. Solution link -- https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/solutions/5461936/2-approach-with-explanation-beats-100-00-of-users-with-c-best-c-solution
*/