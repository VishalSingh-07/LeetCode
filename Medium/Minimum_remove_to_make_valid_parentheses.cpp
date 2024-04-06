/*
1249. Minimum Remove to make valid Parentheses

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

- It is the empty string, contains only lowercase characters, or
- It can be written as AB (A concatenated with B), where A and B are valid strings, or
- It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.


Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"


Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
 

Constraints:

1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.
*/
#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity -> O(2n) ~ O(n)and Space -> O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int counter=0;
        // Moving from left to right
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                counter++;
            }
            else if(s[i]==')'){
                if(counter>0){
                    counter--;
                }else{
                    s[i]='*';
                }
            }
        }

        counter=0;
        // Moving from right to left;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')'){
                counter++;
            }
            else if(s[i]=='('){
                if(counter>0){
                    counter--;
                }else{
                    s[i]='*';
                }
            }
        }

        string result="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                result+=s[i];
            }
        }
        return result;
    }
};



// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){

            // see we are not pushing or popping characters because 
            // they will not impact our string validity now we will 
            // check if the current element is ( then we will push it into stack
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){

                //so if stack is not empty and top of stack if ( , 
                // so if our current character ) goes in the stack they both 
                // will form closed brackets and are part of valid string 
                // so we will pop the top element that is (
                if(!st.empty() && s[st.top()]=='('){
                    st.pop();
                }else{
                    st.push(i);
                }
            }
        }

        // now by running above for loop we will get the extra parathesis 
        // that needs to be removed for making string valid . but we need their 
        // indexes to remove them . if we simply pop them out we don't know which 
        // index paranthesis will be removed
        while(!st.empty()) {

            //we will use erase function to remove that index paranthesis
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};

/*
1. Question link -- https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

2. Solution link -- https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/solutions/4983131/2-approach-best-c-solution-brute-force-and-optimized-approach-with-explanation
*/