#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O((n*m)*(n+m)+(n+m)) ~ O(n^3) and Space -> O(1)

// class Solution {
// private:
//     void markRow(vector<vector<int>>& matrix, int i) // marking row element as -1
//     {
//         for(int j=0;j<matrix[0].size();j++)
//         {
//             if(matrix[i][j]!=0)
//             {
//                 matrix[i][j]=INT_MIN+1;
//             }
//         }
//     }
//     void markColumn(vector<vector<int>>& matrix, int j) // marking row element as -1
//     {
//         for(int i=0;i<matrix.size();i++)
//         {
//             if(matrix[i][j]!=0)
//             {
//                 matrix[i][j]=INT_MIN+1;
//             }
//         }
//     }

// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n=matrix.size(); // number of rows
//         int m=matrix[0].size(); // number of columns

//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]==0)
//                 {
//                     markRow(matrix,i);
//                     markColumn(matrix,j);
//                 }
//             }
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]==INT_MIN+1)
//                 {
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//     }
// };


// Better Approach
// Time complexity -> O(n*m) and Space -> O(n)+O(m) = O(n+m)
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
        
//         int n=matrix.size(); // number of rows
//         int m=matrix[0].size(); // number of columns

//         vector <int> row(n,0);
//         vector <int> col(m,0);
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]==0)
//                 {
//                     row[i]=1;
//                     col[j]=1;
//                 }
//             }
//         }

//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(row[i] || col[j])
//                 {
//                     matrix[i][j]=0;
//                 }
//             }
//         }

//     }
// };


// Optimized Approach
// Time complexity -> O(n*m) and Space -> O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size(); // number of rows
        int m=matrix[0].size(); // number of columns

        // int col[m]={0} ->> matrix[0][...]
        // int row[n]={0} ->> matrix[...][0];

        int col0=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    // mark the i-th row
                    matrix[i][0]=0; 
            
                    // mark the j-th col
                    if(j!=0)
                    {
                        matrix[0][j]=0;  
                    }
                    else
                    {
                        col0=0;
                    }
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]!=0)
                {
                    // check for col & row
                    if(matrix[i][0]== 0 || matrix[0][j]==0)
                    {
                        matrix[i][j]=0;
                    }
                }
            }
        }

        if(matrix[0][0]==0)
        {
            for(int j=0;j<m;j++)
            {
                matrix[0][j]=0;
            }
        }
        if(col0==0)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0]=0;
            }
        }

    }
};


/*

1. Question link -- https://leetcode.com/problems/set-matrix-zeroes/

2. Solution link -- https://leetcode.com/problems/set-matrix-zeroes/solutions/3648435/3-approach-easy-c-solution-brute-force-better-and-optimized-approach-with-notes/

3. Video Link -- https://youtu.be/N0MgLvceX7M

*/