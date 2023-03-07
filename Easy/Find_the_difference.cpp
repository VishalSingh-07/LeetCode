#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach [Sorting Approach]
// Time complexity -> O(nlogn) and Space -> O(1)
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         int n=s.length();
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]!=t[i])
//             {
//                 return t[i];
//             }
//         }
//         return t[n];
//     }
// };


// Hashmap Approach
// Time complexity -> O(n) and Space -> O(n)
// class Solution {
// public:
//     char findTheDifference(string s, string t) {

//         unordered_map<char,int> mp;
//         for(int i=0;i<s.size();i++)
//         {
//             mp[s[i]]++;
//         }
//         for(int i=0;i<t.size();i++)
//         {
//             mp[t[i]]--;
//         }
//         for(auto it: mp)
//         {
//             if(it.second!=0)
//             {
//                 return it.first;
//             }
//         }
//        return t[0]; 
//     }
// };


// Better Approach
// Time complexity -> O(n) and Space -> O(1)
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         vector<int> v(26,0);
//         for(auto cs: s)
//         {
//             v[cs-'a']++;
//         }
//         for(auto ct: t)
//         {
//             if(--v[ct-'a']<0)
//             {
//                 return ct;
//             }
//         }
//         return t[0];
//     }
// };

// Optimized Approach [Using Sum]
// Time complexity -> O(n) and Space -> O(1)
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         int sum=0;
//         for(auto ct: t)
//         {
//             sum+=ct;
//         }
//         for(auto cs: s)
//         {
//             sum-=cs;
//         }
//         return (char)sum;

//     }
// };

// Optimized Approach [Using Xor]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int xr=0;
        for(char cs: s)
        {
            xr^=cs;
        }
        for(char ct: t)
        {
            xr^=ct;
        }
        return xr;
    }
};


// Question link -- https://leetcode.com/problems/find-the-difference/

// Solution link -- https://leetcode.com/problems/find-the-difference/solutions/3268082/5-approach-easy-c-solution-brute-force-sorting-xor-hash-map-sum/