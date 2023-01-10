#include <bits/stdc++.h>
using namespace std;

// Bit manipulation (Xor and &) Approach
// Time complexity --> O(max(number of bits in a, number of bits in b)) and space --> O(1)
// class Solution {
// public:
//     int getSum(int a, int b) {
//         int carry;
//         while(b!=0)
//         {
//             int carry=a&b;
//             a=a^b;
//             b=(unsigned int)carry<<1;

//         }
//         return a;
//     }
// };

// OR


// Bit manipulation (Xor and &) Approach
// Time complexity --> O(max(number of bits in a, number of bits in b)) and space --> O(1)
class Solution {
public:
    int getSum(int a, int b) {
        int carry,sum=a;
        while(b!=0)
        {
            sum=a^b;
            carry=a&b;
            a=sum;
            b=(unsigned int)carry<<1;

        }
        return sum;
    }
};

// Question link -- https://leetcode.com/problems/sum-of-two-integers/