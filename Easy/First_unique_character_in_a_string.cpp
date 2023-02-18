#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         if(s.length()==1)
//         {
//             return 0;
//         }
//         for(int i=0;i<s.length();i++)
//         {
//             bool found=true;
//             for(int j=0;j<s.length();j++)
//             {
//                 if(i!=j && s[i]==s[j])
//                 {
//                     found=false;
//                     break;
//                 }
//             }
//             if(found==true)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };


// Hashmap Map Approach [Using Unordered Map] 
// Time complexity --> O(n) and Space --> O(n)
// class Solution {
// public:
//     int firstUniqChar(string s) {
//        unordered_map<char,int> mp;
//        for(int i=0;i<s.length();i++)
//        {
//            mp[s[i]]++;
//        }
//        for(int i=0;i<s.length();i++)
//        {
//            if(mp[s[i]]==1)
//            {
//                return i;
//            }
//        }
       
//        return -1;
//     }
// };

// Optimized Approach
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    int firstUniqChar(string s) {
       vector<int> ans(26,0);
       for(int i=0;i<s.length();i++)
       {
           ans[s[i]-'a']++;
       }
       for(int i=0;i<s.length();i++)
       {
           if(ans[s[i]-'a']==1)
           {
               return i;
           }
       }
       
       return -1;
    }
};


/*
Question link -- https://leetcode.com/problems/first-unique-character-in-a-string/

My Solution link -- https://leetcode.com/problems/first-unique-character-in-a-string/solutions/3200951/3-approach-to-solve-a-problem-easy-c-solution-brute-force-hashmap-optimized/
*/