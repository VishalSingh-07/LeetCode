/*
13. Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.


Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.


Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1. 1 <= s.length <= 15
2. s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
3. It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/


#include <bits/stdc++.h>
using namespace std;

// Optimized Approach
// Time complexity -> O(1) and Space -> O(1)

/*
Time Complexity : O(1), The maximum length of the string(s) can be 15 (as per the Constgraint), therefore, the worst case time complexity can be O(15) or O(1).

Space Complexity : O(1), We are using unordered_map(map) to store the Roman symbols and their corresponding integer values but there are only 7 symbols hence the worst case space complexity 
can be O(7) which is equivalent to O(1).

*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int ans=0;

        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]]<mp[s[i+1]])
            {
                ans-=mp[s[i]];
            }
            else
            {
                ans+=mp[s[i]];
            }
        }
        return ans;
    }
};

/*
1. Question link -- https://leetcode.com/problems/roman-to-integer/description/

2. My Solution link -- https://leetcode.com/problems/roman-to-integer/solutions/3307251/easy-c-solution-optimized-approach-t-c-o-1-and-s-c-o-1/

3. Video Link -- https://youtu.be/Ydho2JPTI3Y
*/