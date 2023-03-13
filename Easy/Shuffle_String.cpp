/*
1528. Shuffle String

You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

 

Example 1:


Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
 

Constraints:

s.length == indices.length == n
1 <= n <= 100
s consists of only lowercase English letters.
0 <= indices[i] < n
All values of indices are unique.

*/


#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(n)
// class Solution {
// public:
//     string restoreString(string s, vector<int>& indices) {
//         string ans="";
//         int index=0;
//         while(index<indices.size())
//         {
//             for(int i=0;i<indices.size();i++)
//             {
//                 if(indices[i]==index)
//                 {
//                     ans+=s[i];
//                     break;
//                 }
//             }
//             index++;
//         }
//         return ans;
//     }
// };

// Better Approach
// Time complexity -> O(nlogn) and Space -> O(n)
// class Solution {
// public:
//     string restoreString(string s, vector<int>& indices) {
//        vector<pair<int,char>>ans;
//        for(int i=0;i<s.size();i++)
//        {
//           ans.push_back(make_pair(indices[i],s[i]));
//        }
//        sort(ans.begin(),ans.end());
//        string res="";
//        for(int i=0;i<s.size();i++)
//        {
//           res.push_back(ans[i].second);
//        }
//        return res;
//     }
// };

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        string ans=s;
        for(int i=0;i<s.size();i++)
        {
            ans[indices[i]]=s[i];
        }
        return ans;
    }
};


/*
1. Question link -- https://leetcode.com/problems/shuffle-string/

2. Solution link -- https://leetcode.com/problems/shuffle-string/solutions/3291387/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/
*/