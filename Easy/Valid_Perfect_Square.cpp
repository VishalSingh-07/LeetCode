#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n) and Space --> O(1)
// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//        for(long long i=1;i<=num;i++)
//        {
//            if(i*i==num)
//            {
//                return true;
//            }
//        }
//        return false;
//     }
// };

// Better Approach
// Time complexity --> O(sqrt(n)) and Space --> O(1)
// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         // 1 = 1
//         // 1 + 3 = 4
//         // 1 + 3 + 5 = 9
//         // 1 + 3 + 5 + 7 = 16
//         int a = 1 ; 
//         while (num > 0)
//         {
//             num -= a ;
//             a += 2 ; 
//         }
//         if (num == 0 )
//         {
//             return 1;
//         }
//         return 0 ;
//     }
// };

// Optimized Approach
// Time complexity --> O(logn) and Space --> O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
       int low=1,high=num;
       while(low<=high)
       {
           long long int mid=low+(high-low)/2;
           if(mid*mid==num)
           {
               return true;
           }
           else if(mid*mid<num)
           {
               low=mid+1;
           }
           else if(mid*mid>num)
           {
               high=mid-1;
           }
       }
       return false;
    }
};

// Question link -- https://leetcode.com/problems/valid-perfect-square/solutions/3176871/3-approach-to-solve-a-problem-easy-c-solution-brute-force-better-and-optimized/

// My Solution link -- https://leetcode.com/problems/valid-perfect-square/solutions/3176871/3-approach-to-solve-a-problem-easy-c-solution-brute-force-better-and-optimized/