/*
744. Find Smallest Letter Greater Than Target

You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

 

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.


Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.



Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
 

Constraints:

2 <= letters.length <= 104
letters[i] is a lowercase English letter.
letters is sorted in non-decreasing order.
letters contains at least two different characters.
target is a lowercase English letter.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(1)
// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//         for(int i=0;i<letters.size();i++)
//         {
//             if(letters[i]>target)
//             {
//                 return letters[i];
//             }
//         }
//         return letters[0];
//     }
// };


// Optimized Approach [Binary Search]
// Time complexity -> O(logn) and Space -> O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left=0,right=letters.size()-1,mid;
        if(letters[right]<=target)
        {
            return letters[0];
        }
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(letters[mid]<=target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;;
            }
        }
        return letters[left];
    }
};

/*
In this question if target is not present in letters , we have to handle 2 cases
    if there exists a value greater than target return it
    if target is the largest value , return letters[0] .
*/


/*
1. Question link -- https://leetcode.com/problems/find-smallest-letter-greater-than-target/

2. Solution link -- https://leetcode.com/problems/find-smallest-letter-greater-than-target/solutions/3619081/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/