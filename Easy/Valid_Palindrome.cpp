/*
Valid Palindrome 

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.


Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.


Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        int n=s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        for(int i=0;i<n;i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            {
                str+=s[i];
            }
        }
        string temp="";
        for(int i=str.size()-1;i>=0;i--)
        {
            temp+=str[i];
        }
        return temp==str;
    }
};


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int start=0,end=s.size()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        while(start<=end)
        {
            if(!isalnum(s[start]))
            {
                start++;
            }
            else if(!isalnum(s[end]))
            {
                end--;
            }
            else if(s[start]!=s[end])
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        return true;

    }
};

/*
1. Question Link -- https://leetcode.com/problems/valid-palindrome/description/

2. Solution Link -- https://leetcode.com/problems/valid-palindrome/solutions/4605182/two-approach-easy-c-solution-brute-force-and-optimized-approach
*/