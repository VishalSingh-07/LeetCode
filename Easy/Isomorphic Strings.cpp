/*
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true


Example 2:

Input: s = "foo", t = "bar"
Output: false


Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

#include <bits/stdc++.h>
using namespace std;

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
// where n: length of string s or string t
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;

        int sDistinct=0,tDistinct=0;

        for(int i=0;i<s.length();i++){
            if(smap.find(s[i])==smap.end()){
                sDistinct++;
                smap[s[i]]=sDistinct;
            }
            if(tmap.find(t[i])==tmap.end()){
                tDistinct++;
                tmap[t[i]]=tDistinct;
            }

            if(smap[s[i]]!=tmap[t[i]]){
                return false;
            }
        }
        return true;
    }
};


// OR
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;

        int sDistinct=0,tDistinct=0;
        string s1="",t1="";

        for(int i=0;i<s.length();i++){
            if(smap.find(s[i])==smap.end()){
                sDistinct++;
                smap[s[i]]=sDistinct;
            }
            s1+=to_string(smap[s[i]]);
            if(tmap.find(t[i])==tmap.end()){
                tDistinct++;
                tmap[t[i]]=tDistinct;
            }
            t1+=to_string(tmap[t[i]]);
        }
        return s1==t1;
    }
};



/*
1. Question link -- https://leetcode.com/problems/isomorphic-strings/description/

2. Solution link -- https://leetcode.com/problems/isomorphic-strings/solutions/4961673/2-approach-best-c-solution-optimized-approach-with-explanation
*/