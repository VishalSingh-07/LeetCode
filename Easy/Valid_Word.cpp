/*
3136. Valid Word

A word is considered valid if:

It contains a minimum of 3 characters.
It consists of the digits 0-9, and the uppercase and lowercase English letters. (Not necessary to have all of them.)
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
 

Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.

 

Constraints:
- 1 <= word.length <= 20
- word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.
*/

#include <bits/stdc++.h>
using namespace std;

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3){
            return false;
        }
        int num=0,vowel=0,consonant=0;
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(isdigit(ch)){
                num++;
            }
            if(isalpha(ch)){
                cout<<ch<<endl;
                if(ch=='a' || ch=='e' || ch=='i' ||ch=='o' || ch=='u' || 
                    ch=='A' || ch=='E' || ch=='I' ||ch=='O' || ch=='U'){
                    vowel++;
                }
                else{
                    consonant++;
                }
            }
        }
        if(num+vowel+consonant==n && vowel>0 && consonant>0){
            return true;
        }
        return false;
    }
};

/*
1. Question link -- https://leetcode.com/problems/valid-word/description/

2. Solution link -- https://leetcode.com/problems/valid-word/solutions/5116792/beats-100-00-of-users-with-c-optimized-approach-best-c-solution
*/