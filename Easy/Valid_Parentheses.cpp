#include <bits/stdc++.h>
using namespace std;
// Way 1: 
// Time complexity --> O(n) and Space --> O(n)
// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for(int i=0;i<s.length();i++)
//         {
//             if(st.empty())
//             {
//                 st.push(s[i]);
//             }
//             else if((st.top()=='(' && s[i]==')') 
//                     || (st.top()=='[' && s[i]==']') 
//                     || (st.top()=='{' && s[i]=='}'))
//             {
//                 cout<<s[i];
//                 st.pop();
//             }
//             else
//             {
//                 st.push(s[i]);
//             }
//         }
//         if(st.empty())
//         {
//             return true;
//         }
        
//         return false;
        
//     }
// };

// Way 2:
// Time complexity --> O(n) and Space --> O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                // if a closing bracket then we compare with the top of the stack 
                // while comparing with top of stack we have 2 cases 
                // the stack can be empty or the stack is not empty 

                if(st.empty())
                {
                    return false;
                }
                else
                {
                    if((st.top()=='(' && s[i]==')') 
                        || (st.top()=='[' && s[i]==']') 
                        || (st.top()=='{' && s[i]=='}'))
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }

                }

            }
        }
        if(st.empty())
        {
            return true;
        }
        
        return false;
        
    }
};

// Question link -- https://leetcode.com/problems/valid-parentheses/

// Video Link -- https://youtu.be/wkDfsKijrZ8