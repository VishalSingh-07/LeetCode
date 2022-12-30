#include <bits/stdc++.h>
using namespace std;
// Time complexity --> O(2^n) Using Recursion (without Dynamic Programming)
// class Solution {
// public:
//     int fib(int n) {
//         if(n==0)
//         {
//             return 0;
//         }
//         else if(n==1)
//         {
//             return 1;
//         }
//         return fib(n-1)+fib(n-2);      
//     }
// };

// Time complexity --> O(n) Using Iterative Approach
// class Solution {
// public:
//     int fib(int n) {
//         int a=0,b=1,c;
//         if(n<=1)
//         {
//             return n;
//         }
//         else
//         {
//             for(int i=2;i<=n;i++)
//             {
//                 c=a+b;
//                 a=b;
//                 b=c;
//             }

//             return c;

//         } 
//     }
// };


// Time complexity --> O(n) Using Dynamic Programming
// class Solution {
    
// public:
//     int fib(int n) {
//         int F[n+2];
//         int i;
//         F[0]=0;
//         F[1]=1;

//         for(int i=2;i<=n;i++)
//         {
//             F[i]=F[i-1]+F[i-2];
//         }
//         return F[n];
//     }
// };


// Time complexity --> O(logn) Using Golden Ratio
class Solution {
public:
    int fib(int n) {

        // Golden ratio
        double g=(1+sqrt(5))/2;

        return round(pow(g,n)/sqrt(5));
        
    }
};


// Question Link -- https://leetcode.com/problems/fibonacci-number/description/