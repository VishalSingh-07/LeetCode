#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n*m) and Space -> O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int m=haystack.length(); //Length of haystack string
        int n=needle.length(); //Length of needle string

        if(n==0)
        {
            return -1;
        }
        if(m<n)
        {
            return -1;
        }
        for(int i=0;i<=m-n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(needle[j]==haystack[j+i])
                {
                    count++;
                }
            }
            if(count==n)
            {
                return i;
            }
        }
        return -1;
    }
};

//-----------------

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int m=haystack.length(); //Length of haystack string
        int n=needle.length(); //Length of needle string

        if(n==0)
        {
            return -1;
        }
        if(m<n)
        {
            return -1;
        }
        for(int i=0;i<=m-n;i++)
        {
            bool isCheck=true;
            for(int j=0;j<n;j++)
            {
                if(needle[j]!=haystack[j+i])
                {
                    isCheck=false;
                    break;
                }
            }
            if(isCheck)
            {
                return i;
            }
        }
        return -1;
    }
};

// Optimized Approach [Inbuilt Approach]
// Time complexity -> O(m+n) and Space -> O(1)
// m = Length of the haystack string
// n = Length of the needle string
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        size_t found=haystack.find(needle);
        if(found!=string::npos)
        {
            return found;
        }
        return -1;
    }
};


/*
1. Question link -- https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

2. Solution link --

      i) https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/3252629/2-approach-easy-c-solution-brute-force-and-optimized-approach/

      ii) https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/3249831/day-62-o-m-n-time-o-m-space-kmp-algo-easiest-beginner-friendly-sol/

3. Video link -- https://youtu.be/_ZWnkyae2gA
*/