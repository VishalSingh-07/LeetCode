#include <bits/stdc++.h>
using namespace std;

// Approach 1
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    int maxDepth(string s) {
        int counter=0;
        int maxCounter=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                counter++;
            }
            else if(s[i]==')'){
                counter--;
            }
            maxCounter=max(maxCounter,counter);
        }
        return maxCounter;
    }
};


// Approach 2
// Time complexity -> O(n) and Space -> O(1) because as it uses a constant amount of additional space (excluding the input space).
class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxCounter=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                maxCounter=max(maxCounter,(int)st.size());
                st.pop();
            }
        }
        return maxCounter;
    }
};

/*
1. Question link -- https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

2. Solution link -- https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/solutions/4973697/2-approach-best-c-approach-with-detailed-solution
*/

