#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n) and Space --> O(1)
// class Solution {
// public:
//     int countOdds(int low, int high) {
//         int count=0;
//         while(low<=high)
//         {
//             if(low%2!=0)
//             {
//                 count++;
//             }
//             low++;
//         }
//         return count;
//     }
// };

// Optimized Approach
// Time complexity --> O(1) and Space --> O(1)
/*
Example
low = 4, high = 10 
Odd numbers - (5,7,9) -> (10-4)/2 = 3

low = 4, high = 11 
Odd numbers - (5,7,9,11) -> (11-4)/2 = 3, as high is odd, 3+1 = 4

low = 3, high = 10 
Odd numbers - (3,5,7,9) -> (10-3)/2 = 3, as low is odd, 3+1 = 4

low = 3, high = 11 
Odd numbers - (3,5,7,9,11) -> (11-3)/2 = 4, as low and high both are odd, 4+1 = 5
*/
class Solution {
public:
    int countOdds(int low, int high) {
        // Initialize odd with the number of even numbers between low and high.
        int odd = (high - low)/2;

        // If either low or high is odd, increment odd by 1.
        if((low % 2)!=0 || (high % 2)!=0)
        {
            odd++;
        }
           

        // Return the number of odd numbers between low and high.
        return odd;
    }
};

// Question link -- https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

// My Solution  Link --  https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/solutions/3180024/easy-beginner-friendly-c-solution-2-approach-brute-force-and-optimized-approach/