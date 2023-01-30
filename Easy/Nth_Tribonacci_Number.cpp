#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(2^n) and Space --> O(n)
// class Solution {
// public:
//     int tribonacci(int n) {
//         if(n==0)
//         {
//             return 0;
//         }
//         else if(n==1 || n==2)
//         {
//             return 1;
//         }
//         return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
      
//     }
// };

// Above Code give Time limit Exceeded Due to high time complexity O(2^n)


// Tabulation Approach
// Time complexity --> O(n) and Space --> O(n)
/*
Approach for this Problem:
1. Initialize a vector "Tribonacci" with n+1 elements
2. Check if n is 0, if true return 0
3. Check if n is 1, if true return 1
4. Check if n is 2, if true return 1
5. Set Tribonacci[0] = 0, Tribonacci[1] = 1, Tribonacci[2] = 1
6. Iterate from i = 3 to n+1
7. Set Tribonacci[i] = Tribonacci[i-1] + Tribonacci[i-2] + Tribonacci[i-3]
8. Return Tribonacci[n]
*/
// class Solution {
// public:
//     int tribonacci(int n) {
//         if(n==0)
//         {
//             return 0;
//         }
//         else if(n==1 || n==2)
//         {
//             return 1;
//         }
//         vector<int> dp(n+1,0);
//         dp[0]=0;
//         dp[1]=1;
//         dp[2]=1;
//         for(int i=3;i<=n;i++)
//         {
//             dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
//         }
//         return dp[n];
      
//     }
// };


// Optimized Approach
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    int tribonacci(int n) {
        int a=0,b=1,c=1,d=0;
        if(n==0)
        {
            return a;
        }
        else if(n==1 || n==2)
        {
            return 1;
        }
        for(int i=3;i<=n;i++)
        {
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return c;
      
    }
};

// Question link -- https://leetcode.com/problems/n-th-tribonacci-number/