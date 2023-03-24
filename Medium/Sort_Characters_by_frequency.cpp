/*
451. Sort Characters By Frequency

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.


Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.


Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/


#include <bits/stdc++.h>
using namespace std;

// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(n)
// class Solution {
// private:
//     static bool comparator(pair<char,int>&a, pair<char,int>&b)
//     {
//         return a.second>b.second;
//     }
// public:
//     string frequencySort(string s) {
//         string ans;
//         unordered_map<char,int> mp;
//         for(auto x: s)
//         {
//             mp[x]++;
//         }
//         vector<pair<char,int>> v;
//         for(auto it: mp)
//         {
//             v.push_back({it.first,it.second});
//         }
//         sort(v.begin(),v.end(),comparator);

//         for(auto i: v)
//         {
//             while(i.second)
//             {
//                 ans+=i.first;
//                 i.second--;
//             }
//         }
//         return ans;
//     }
// };

// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mp;
        for(auto x: s)
        {
            mp[x]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it: mp)
        {
            pq.push({it.second,it.first});
        }
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            while(p.first--) 
            {
                ans += p.second;
            }
        }
        return ans;
        
    }
};

/*
1. Question link -- https://leetcode.com/problems/sort-characters-by-frequency/

2. Solution link -- https://leetcode.com/problems/sort-characters-by-frequency/solutions/3336201/2-approach-easy-c-solution-optimized-approach/
*/