#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// class Solution {
// public:
//     int diagonalSum(vector<vector<int>>& mat) {
//         int principalDiagonal=0,secondaryDiagonal=0;
//         for(int i=0;i<mat.size();i++)
//         {
//             for(int j=0;j<mat[i].size();j++)
//             {
//                 if(i==j)
//                 {
//                     principalDiagonal+=mat[i][j];
//                 }
//                 else if((i+j)==mat.size()-1)
//                 {
//                     secondaryDiagonal+=mat[i][j];
//                 }
//             }
//         }
//         return principalDiagonal+secondaryDiagonal;
//     }
// };

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size(),ans=0;
        for(int i=0;i<mat.size();i++)
        {
            ans+=mat[i][i]; // Adding element from primary Diagonal
            ans+=mat[n-1-i][i]; // Adding element from secondary Diagonal
        }
        if(n%2!=0)
        {
            ans-=mat[n/2][n/2];
        }
        return ans;
    }
};


/*
Quesiton link -- https://leetcode.com/problems/matrix-diagonal-sum/

Solution link -- https://leetcode.com/problems/matrix-diagonal-sum/solutions/3501122/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/