#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n/2) and Space --> O(1)
// class Solution {
// public:
//     bool checkPerfectNumber(int num) {

//         int temp=num;
//         int sum=0;
//         if(num<=0)
//         {
//             return false;
//         }
//         for(int i=1;i<=num/2;i++)
//         {
//             if(num%i==0)
//             {
//                 sum+=i;
//             }
//         }
//         return (temp==sum)?true:false;
        
//     }
// };

// Optimized Approach
// Time complexity --> O(sqrt(num)) and Space --> O(1)
class Solution {
public:
    bool checkPerfectNumber(int num) {

        int temp=num;
        int sum=1;
        if(num==1)
        {
            return false;
        }
        for(int i=2;i<=sqrt(num);i++)
        {
            if(num%i==0)
            {
                sum+=i+num/i;
            }
        }
        return (temp==sum)?true:false;
        
    }
};

// Question link -- https://leetcode.com/problems/perfect-number/