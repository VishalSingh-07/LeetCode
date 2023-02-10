#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach [Using Sorting]
// Time complexity --> O(nlogn+mlogm) and Space --> O(1)
/*
Where 
    n = length of string s 
    m = length of string t
*/
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size()!=t.size())
//         {
//             return false;
//         }
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());

//         return s==t?true:false;

//     }
// };

// Optimized Approach [Hash Table]
// Time complexity --> O(n+m) ~ O(n) and Space --> O(1)
/*
Where 
    n = length of string s 
    m = length of string t
*/
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int i,j;
//         int n=s.length();
//         int m=t.length();
//         if(n!=m)
//         {
//             return false;
//         }
//         int h[26]={0};
//         for(i=0;i<n;i++)
//         {
//             h[s[i]-97]++;
//         }
//         for(j=0;j<m;j++)
//         {
//             h[t[j]-97]--;
//             if(h[t[j]-97]<0)
//             {
//                 return false;
//             }
//         }
//         return t[j]=='\0'?true:false;
//     }
// };

// --OR--
// Time complexity --> O(n) and Space --> O(1)
/*
Where 
    n = length of string s 
    m = length of string t
*/
class Solution {
public:
    bool allZeroes(vector<int>& count)
    {
        for (int i = 0; i < 26; i++) {
            if(count[i] != 0)
                return false;
        }
        return true;
    }
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m)
        {
            return false;
        }  
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        if(allZeroes(count) == false)
        {
            return false;
        }
            
        return true;
    }
};

// Question link -- https://leetcode.com/problems/valid-anagram/