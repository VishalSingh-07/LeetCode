/*
1717. Maximum Score From Removing Substrings

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

- Remove substring "ab" and gain x points.
      - For example, when removing "ab" from "cabxbae" it becomes "cxbae".

- Remove substring "ba" and gain y points.
      - For example, when removing "ba" from "cabxbae" it becomes "cabxe".


Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.



Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:
- 1 <= s.length <= 105
- 1 <= x, y <= 104
- s consists of lowercase English letters.
*/


#include <bits/stdc++.h>
using namespace std;
// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int maximumPoints=0;
        stack<char> st;
        int n=s.length();
        if(x > y){
            // Process 'ab' pairs first
            for(int i=0;i<n;i++){
                if(!st.empty() && st.top()=='a' && s[i]=='b'){
                    st.pop();
                    maximumPoints+=x;
                }
                else{
                    st.push(s[i]);
                }
            }

            // Collect remaining characters back into s
            s.clear();
            while(!st.empty()){
                s+=st.top();
                st.pop();
            }
            reverse(s.begin(),s.end());
            
            // Process 'ba' pairs
            for(int i=0;i<s.length();i++){
                if(!st.empty() && st.top()=='b' && s[i]=='a'){
                    st.pop();
                    maximumPoints+=y;
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        else{
            // Process 'ba' pairs first
            for(int i=0;i<n;i++){
                if(!st.empty() && st.top()=='b' && s[i]=='a'){
                    st.pop();
                    maximumPoints+=y;
                }
                else{
                    st.push(s[i]);
                }
            }


            // Collect remaining characters back into s
            s.clear();
            while(!st.empty()){
                s+=st.top();
                st.pop();
            }
            reverse(s.begin(),s.end());
            
            // Process 'ab' pairs
            for(int i=0;i<s.length();i++){
                if(!st.empty() && st.top()=='a' && s[i]=='b'){
                    st.pop();
                    maximumPoints+=x;
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        return maximumPoints;
    }
};

/*
1. Question link -- https://leetcode.com/problems/maximum-score-from-removing-substrings/description/

2. Solution link -- https://leetcode.com/problems/maximum-score-from-removing-substrings/solutions/5466701/optimized-approach-greedy-with-stack-with-detailed-explanation-best-c-solutions
*/