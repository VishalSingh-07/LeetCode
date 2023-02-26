#include <bits/stdc++.h>
using namespace std;


// Approach 1: Using Stack
// Time Complexity --> O(n) and Space -> O(n)
// where n=|S|

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res;
        for(int i=0;i<s.length();i++)
        {
            if(st.size()==0)
            {
                st.push(s[i]);
            }
            else if(s[i]==st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        while(st.size()!=0)
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


// Approach 2: Using String as a Stack
// Time Complexity --> O(n) and Space -> O(n)
// where n=|S|

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        ans.push_back(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(ans.back()==s[i])
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};


// Question link -- https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// My Solution link -- https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/solutions/3231931/easy-c-solution-optimized-approach-using-stack-and-using-string-as-a-stack/