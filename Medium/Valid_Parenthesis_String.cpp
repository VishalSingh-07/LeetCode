/*

678. Valid Parenthesis String

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true


Example 2:

Input: s = "(*)"
Output: true

Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.
*/
#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        stack<char> star;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty() && star.empty()){
                    return false;
                }
                else if(!st.empty()){
                    st.pop();
                }
                else{
                    star.pop();
                }
            }
            else if(s[i]=='*'){
                star.push(i);
            }
        }
        while(!st.empty()){
            if(star.empty()){
                return false;
            }
            if(st.top()>star.top()){
                return false;
            }
            st.pop();
            star.pop();
        }
        return true;
    }
};



// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int open=0; //For keeping count in Left to right travers
        int close=0; //For keeping count in Right to left travers
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='*'){
                open++;
            }else{
                open--;
            }
            if(open<0){
                return false;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]==')' || s[i]=='*'){
                close++;
            }else{
                close--;
            }
            if(close<0){
                return false;
            }
        }
        return true;
    }
};




/*
1. Question link -- https://leetcode.com/problems/valid-parenthesis-string/

2. Solution link -- https://leetcode.com/problems/valid-parenthesis-string/solutions/4987173/2-approach-best-c-solution-brute-force-and-optimized-approach-with-explanation
*/