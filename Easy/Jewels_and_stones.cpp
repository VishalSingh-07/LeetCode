/*
771. Jewels and Stones

You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3


Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0
 

Constraints:

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n+m) and Space -> O(1)
// Where n = length of string jewels and m = length of string stones
// class Solution {
// public:
//     int numJewelsInStones(string jewels, string stones) {
//         int count=0;
//         for(int i=0;i<jewels.size();i++)
//         {
//             for(int j=0;j<stones.size();j++)
//             {
//                 if(jewels[i]==stones[j])
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

// Optimized Approach [Hash Set or Hash map]
// Time complexity -> O(n+m) and Space -> O(n+m)
// Where n = length of string jewels and m = length of string stones 
// class Solution {
// public:
//     int numJewelsInStones(string jewels, string stones) {
//         int count=0;
//         set<char> st;
//         for(auto x: jewels)
//         {
//             st.insert(x);
//         }
//         for(int i=0;i<stones.size();i++)
//         {
//             if(st.find(stones[i])!=st.end())
//             {
//                 count++;
//             }
//         }
//         return count;
//     }
// };


// OR
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        unordered_map<char,int> mp;
        for(auto x: jewels)
        {
            mp[x]++;
        }
        for(int i=0;i<stones.size();i++)
        {
            if(mp[stones[i]]>0)
            {
                count++;
            }
        }
        return count;
    }
};

/*
1. Question link -- https://leetcode.com/problems/jewels-and-stones/

2. Solution link -- https://leetcode.com/problems/jewels-and-stones/solutions/3360041/2-approach-easy-c-solution-brute-and-optimized-approach/
*/