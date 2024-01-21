/*
49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]


Example 2:

Input: strs = [""]
Output: [[""]]


Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;

// Optimized Approach
// Time complexity -> O(n*klogk) and Space -> O(n)
// where n: length of string[strs]  and k: maximum length of individual string in strs

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        
        for(auto x: strs)
        {
            string temp=x;
            sort(x.begin(),x.end());
            mpp[x].push_back(temp);
        }
        for(auto x: mpp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};

/*
1. Question Link -- https://leetcode.com/problems/group-anagrams/description/

2. Solution Link -- https://leetcode.com/problems/group-anagrams/solutions/4604955/optimized-approach-easy-c-solution-with-explanation

3. Video Link -- https://youtu.be/zX9k1XvVUXI?si=_2Wz-JdYFUdejYYC
*/