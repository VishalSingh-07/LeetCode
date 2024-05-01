/*

2000. Reverse Prefix of Word

Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

 

Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".



Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".



Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
 

Constraints:
- 1 <= word.length <= 250
- word consists of lowercase English letters.
- ch is a lowercase English letter.
*/

#include <bits/stdc++.h>
using namespace std;

// Optimized Approach 1
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=word.find(ch)+1;
        for(int i=0;i<index/2;i++){
            swap(word[i],word[index-i-1]);
        }
        return word;
    }
};


// Optimized Approach 2
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=word.find(ch);
        reverse(word.begin(),word.begin() + index + 1);
        return word;
    }
};



// Optimized Approach 3
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int left=0;
        for(int right=0;right<word.size();right++){
            if(word[right]==ch){
                while(left<=right){
                    swap(word[left],word[right]);
                    left++;
                    right--;
                }
                return word;
            }
        }
        return word;
    }
};


/*
1. Question link -- https://leetcode.com/problems/reverse-prefix-of-word/

2. Solution link -- https://leetcode.com/problems/reverse-prefix-of-word/solutions/5095396/3-approach-optimized-approach-with-explanation-best-c-solution
*/