/*
50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
-104 <= xn <= 104
*/


#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach 
// Time complexity -> O(n) and Space -> O(1)
// class Solution {
// public:
//     double myPow(double x, int n) {
//         long long num=n;
//         if(num<0)
//         {
//             num*=-1;
//             x=1/x;
//         }
//         double ans=1;
//         for(int i=0;i<num;i++)
//         {
//             ans*=x;
//         }
//         return ans;
//     }
// };
// Above Code ❌ time limit Exceeded


// Better Approach
// Time complexity -> O(n) and Space -> O(n)
// class Solution {
// private:
//     double power(double x, long n){
//         if(n==0)
//         {
//             return 1;
//         }
//         return x*pow(x,n-1);
//     }
// public:
//     double myPow(double x, int n) {
//         double ans=1;
//         long long num=n;
//         if(n>=0)
//         {
//             ans=power(x,n);
//         }
//         else
//         {
//             num*=-1;
//             ans=power(x,num);
//             ans=1/ans;
//         }
//         return ans;
//     }
// };





// Optimized Approach
// Time complexity -> O(logn) and Space -> O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long num=n;
        if(num<0)
        {
            num*=-1;
        }
        while(num>0)
        {
            if(num%2==0)
            {
                x=x*x;
                num=num/2;
            }
            if(num%2==1)
            {
                ans=ans*x;
                num=num-1;
            }
        }
        if(n<0)
        {
            ans=(double)(1.0)/(double)ans;
        }
        return ans;
    }
};



/*
1. Question Link -- https://leetcode.com/problems/powx-n/

2. Solution Link -- https://leetcode.com/problems/powx-n/solutions/3344673/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video Link -- https://youtu.be/l0YC3876qxg
*/