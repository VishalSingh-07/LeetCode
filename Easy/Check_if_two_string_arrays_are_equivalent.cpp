#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(m+n) and Space -> O(m+n)
// where m -> the total number of characters in word1 and n -> the total number of characters in word2.
// class Solution {
// public:
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
//         string s1="";
//         string s2="";
//         for(int i=0;i<word1.size();i++)
//         {
//             s1+=word1[i];
//         }
//         for(int i=0;i<word2.size();i++)
//         {
//             s2+=word2[i];
//         }

//         return s1==s2;

//     }
// };

// Optimized Approach
// Time complexity -> O(m+n) and Space -> O(1)
// where m -> the total number of characters in word1 and n -> the total number of characters in word2.
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
         // Pointers to mark the current word in the given two lists.
        int word1Pointer=0, word2Pointer=0;

        // Pointers to mark the character in the string pointed by the above pointers.
        int string1Pointer=0,string2Pointer=0; 
        
        while(word1Pointer<word1.size() && word2Pointer<word2.size())
        {
            // If the characters at the two string are same, increment the string pointers
            // Otherwise return false.
            if(word1[word1Pointer][string1Pointer++]!=word2[word2Pointer][string2Pointer++])
            {
                return false;
            }

            // If the string pointer reaches the end of string in the list word1, 
            // Move to the next string in the list and, reset the string pointer to 0
            if(string1Pointer==word1[word1Pointer].size())
            {
                word1Pointer++;
                string1Pointer=0;
            }

            // If the string pointer reaches the end of string in the list word2, 
            // Move to the next string in the list and, reset the string pointer to 0.
            if(string2Pointer==word2[word2Pointer].size())
            {
                word2Pointer++;
                string2Pointer=0;
            }

        }
        return word1Pointer==word1.size() &&  word2Pointer==word2.size();
    }
};

/*
1. Question Link -- https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

2. Solution Link -- https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/solutions/4350988/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/