#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> (log(n)^2) and Space -> O(1)
// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if(n==1)
//         {
//             return true;
//         }
//         if(n<=0)
//         {
//             return false;
//         }
//         for(int i=0;i<=15;i++)
//         {
//             // If we find a power of four equal to 'n', return true
//             if(n==pow(4,i))
//             {
//                 return true;
//             }
//             // If the current power of four is greater than 'n', there's no need to continue
//             if(n<pow(4,i))
//             {
//                 return false;
//             }
//         }

//         // 'n' is not a power of four
//         return false;
//     }
// };


// Optimized Approach [Math]
// Time complexity -> O(1) and Space -> O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {

         // If 'n' is 1, it is a power of four
        if(n==1)
        {
            return true;
        }

        // If 'n' is non-positive, it cannot be a power of four
        if(n<=0)
        {
            return false;
        }

        // Calculate the logarithm of 'n' with base 4
        double logarithmBase4 = log(n) / log(4);

        // Check if the result of the logarithmic operation is an integer
        return (logarithmBase4 == (int)logarithmBase4);
    }
};

/*
1. Question Link -- https://leetcode.com/problems/power-of-four/

2. Solution Link --
      i) https://leetcode.com/problems/power-of-four/solutions/4197587/100-brute-force-two-math-solutions-explained-intuition/

      ii) https://leetcode.com/problems/power-of-four/solutions/4198881/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/