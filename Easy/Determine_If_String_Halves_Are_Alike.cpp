/*
1704.  Determine If String Halvres are Alike

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
 

Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.

*/

#include <bits/stdc++.h>
using namespace std;

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int countLeftVowel=0,countRightVowel=0;
        for(int i=0;i<n/2;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'||
                s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
               countLeftVowel++;
            }
            if(s[i+n/2]=='a' || s[i+n/2]=='e' || s[i+n/2]=='i' || s[i+n/2]=='o' || s[i+n/2]=='u' || 
                s[i+n/2]=='A' || s[i+n/2]=='E' || s[i+n/2]=='I' || s[i+n/2]=='O' || s[i+n/2]=='U')
            {
               countRightVowel++;
            }

        }
        return countLeftVowel==countRightVowel?true:false;
    }
};

/*
1. Question Link -- https://leetcode.com/problems/determine-if-string-halves-are-alike/description/

2. Solution Link -- https://leetcode.com/problems/determine-if-string-halves-are-alike/solutions/4551481/optimized-approach-easy-c-solution-beats-100-of-users-with-c-0-ms
*/