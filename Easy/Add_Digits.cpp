/*
258. Add Digits
Easy

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.


Example 2:

Input: num = 0
Output: 0
 

Constraints:

0 <= num <= 231 - 1
 

Follow up: Could you do it without any loop/recursion in O(1) runtime?
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Apporach
// Time complexity -> O(logn) and Space -> O(1)
// class Solution {
// public:
//     int addDigits(int num) {

//         if(num==0)
//         {
//             return 0;
//         }
//         while(num>9)
//         {
//             int sum=0,digit=num;
//             while(digit!=0)
//             {
//                 sum+=digit%10;
//                 digit=digit/10;

//             }
//             num=sum;
//         }
//         return num;
//     }
// };

// OR

// class Solution {
// public:
//     int addDigits(int num) {
//         int digitRoot=0;
//         while(num>0)
//         {
//             digitRoot+=num%10;
//             num=num/10;
//             if(num==0 && digitRoot>9)
//             {
//                 num=digitRoot;
//                 digitRoot=0;
//             }
//         }
//         return digitRoot;
//     }
// };

// Optimized Approach
// Time complexity -> O(1) and Space -> O(1)
class Solution {
public:
    int addDigits(int num) {
        if(num==0)
        {
            return 0;
        }
        if(num%9==0)
        {
            return 9;
        }
        return num%9;
    }
};

/*
1. Question link -- https://leetcode.com/problems/add-digits/

2. Solution link -- https://leetcode.com/problems/add-digits/solutions/3456750/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/