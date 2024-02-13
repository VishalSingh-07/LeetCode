/*
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

 

Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.


Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".


Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
 

Constraints:

- 1 <= words.length <= 100
- 1 <= words[i].length <= 100
- words[i] consists only of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n*m) and Space -> O(m)
// where n is the number of words and m is the length of the longest word.  
class Solution {
private:
    bool palindrome(string s)
    {
        string temp=s;
        reverse(temp.begin(),temp.end());
        return s==temp;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            if(palindrome(words[i])==true)
            {
                return words[i];
            }
        }
        return "";
    }
};

// OR
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            string reversed=words[i];
            reverse(reversed.begin(),reversed.end());
            if(words[i]==reversed)
            {
                return words[i];
            }
        }
        return "";
    }
};


// Optimized Approach
// Time complexity -> O(n*m) and Space -> O(1)
// where n is the number of words and m is the length of the longest word.  
class Solution {
private:
    bool palindrome(string s)
    {
        int start=0,end=s.size()-1;
        while(start<=end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            if(palindrome(words[i])==true)
            {
                return words[i];
            }
        }
        return "";
    }
};


/*
1. Question link -- https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13

2. Solution Link -- https://leetcode.com/problems/find-first-palindromic-string-in-the-array/solutions/4721606/easy-c-solution-2-approach-brute-force-and-optimized-approach-with-explanation
*/