#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach [Recursion]
// Time complexity -> O(2^(n+m)) and Space -> O(m+n)
// where m -> number of rows and n -> number of columns
// class Solution {
// private:
//     int countUniquePaths(int i, int j, int m, int n)
//     {
//         if(i==(n-1) && j==(m-1))
//         {
//             return 1;
//         }
//         if(i>=n || j>=m)
//         {
//             return 0;
//         }
//         return countUniquePaths(i+1,j,m,n)+countUniquePaths(i,j+1,m,n);
//     }
// public:
//     int uniquePaths(int m, int n) {
//        return countUniquePaths(0,0,m,n);
//     }
// };

// Above Code give timit limit exceeded due to exponential time complexity


// Better Approach [Dynamic Programming]
// Time complexity -> O(m*n) and Space -> O(m*n)
// where m -> number of rows and n -> number of columns
// class Solution {
// private:
//     int countUniquePaths(int i, int j, int m, int n,vector<vector<int>> &dp)
//     {
//         if(i==(n-1) && j==(m-1))
//         {
//             return 1;
//         }
//         if(i>=n || j>=m)
//         {
//             return 0;
//         }

//         if(dp[i][j]!=-1)
//         {
//             return dp[i][j];
//         }
//         return dp[i][j]= countUniquePaths(i+1,j,m,n,dp)+countUniquePaths(i,j+1,m,n,dp);
//     }
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         int num=countUniquePaths(0,0,m,n,dp);
//         if(m==1&&n==1)
//             return num;
//         return dp[0][0];
//     }
// };


// Optimized Approach [Maths (nCr -> Combination and arrangement)]
// Time complexity -> O(m-1) and Space -> O(1)
// where m -> number of rows. and n -> number of columns
class Solution {
public:
    int uniquePaths(int m, int n) {
       int N=m+n-2;
       int R=m-1;
       double res=1;
       for(int i=1;i<=R;i++)
       {
           res=res*(N-R+i)/i;
       }
       return (int)res;
    }
};

/*

1. Question link -- https://leetcode.com/problems/unique-paths/

2. Solution link -- https://leetcode.com/problems/unique-paths/solutions/3829439/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video link -- https://youtu.be/t_f0nwwdg5o

*/