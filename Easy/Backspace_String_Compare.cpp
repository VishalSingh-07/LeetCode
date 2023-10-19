#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity -> O(n+m) and Space -> O(n+m)
// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         stack<char> st1;
//         stack<char> st2;

//         for(int i=0;i<s.length();i++)
//         {
//             if(s[i]=='#')
//             {
//                 if(!st1.empty())
//                 {
//                     st1.pop();
//                 }
//             }
//             else
//             {
//                 st1.push(s[i]);
//             }
//         }
//         for(int i=0;i<t.length();i++)
//         {
//             if(t[i]=='#')
//             {
//                 if(!st2.empty())
//                 {
//                     st2.pop();
//                 }
//             }
//             else
//             {
//                 st2.push(t[i]);
//             }
//         }

//         while(!st1.empty() && !st2.empty())
//         {
//             if(st1.top()!=st2.top())
//             {
//                 return false;
//             }
//             st1.pop();
//             st2.pop();
//         }
//         return st1.empty() && st2.empty();
//     }
// };


// Better Approach
// Time complexity -> O(n+m) and Space -> O(n+m)
// class Solution {
// public:
//     string build(string s)
//     {
//         stack<char> st;
//         for(char c: s)
//         {
//             if(c!='#')
//             {
//                 st.push(c);
//             }
//             else if(!st.empty())
//             {
//                 st.pop();
//             }
//         }
//         string ans;
//         while(!st.empty())
//         {
//             ans+=st.top();
//             st.pop();
//         }
//         return ans;
//     }
//     bool backspaceCompare(string s, string t) {
//         return build(s)==build(t);
//     }
// };


// Optimized Approach [Two pointer]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.length()-1;
        int j=t.length()-1;

        int hashCount1=0, hashCount2=0;
        while(i>=0 || j>=0)
        {
            // Find position of next possible char in build(S)
            while(i>=0)
            {
                if(s[i]=='#')
                {
                    hashCount1++;
                    i--;
                }
                else if(hashCount1>0)
                {
                    hashCount1--;
                    i--;
                }
                else
                {
                    break;
                }
            }
            // Find position of next possible char in build(T)
            while(j>=0)
            {
                if(t[j]=='#')
                {
                    hashCount2++;
                    j--;
                }
                else if(hashCount2>0)
                {
                    hashCount2--;
                    j--;
                }
                else
                {
                    break;
                }
            }

            // If two actual characters are different
            if(i>=0 && j>=0 && s[i]!=t[j])
            {
                return false;
            }
            // If expecting to compare char vs nothing
            if((i>=0) !=(j>=0))
            {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};
/*
1. Question link -- https://leetcode.com/problems/backspace-string-compare/

2. Solution link -- https://leetcode.com/problems/backspace-string-compare/solutions/4186823/three-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video link -- https://youtu.be/MGOjHoeMlsM?si=12uKk1UbUpwfKhKe
*/
