#include <bits/stdc++.h>
using namespace std;

// Time complexity --> O(n^2) and Space --> O(n^2)
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {

//         vector<vector<int>> ans(numRows);

//         // i--> rows and j--> column
//         for(int i=0;i<numRows;i++)
//         {
//             ans[i].resize(i+1); // increasing the size of row
//             ans[i][0]=ans[i][i]=1; // first and last element is same

//             for(int j=1;j<i;j++)
//             {
//                 ans[i][j]=ans[i-1][j-1]+ans[i-1][j]; // Add element
//             }

//         }
        
//         return ans;
//     }
// };

// Time complexity --> O(n^2) and Space --> O(n^2)

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {

//         vector<vector<int>> ans;

//         // i--> rows and j--> column
    
//         for(int i=0;i<numRows;i++)
//         {
//             vector<int> v(i+1,1); // initialize vector element as 1 and increasing the size of vector in each rows

//             for(int j=1;j<i;j++) 
//             {
//                 v[j]=ans[i-1][j]+ans[i-1][j-1]; // sum the above two elements
//             }

//             ans.push_back(v);
//         }

//         return ans;
//     }

// };

// Time complexity --> O(n^2) and Space --> O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> triangle;

        // i--> rows and j--> column
        for(int i=0;i<numRows;i++)
        {
            vector<int> row;

            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(triangle[i-1][j-1]+triangle[i-1][j]);
                }
            }

            triangle.push_back(row);
        }
        

        return triangle;
    }

};


// Question link --> https://leetcode.com/problems/pascals-triangle/

/*
Video Link --
1) https://youtu.be/6FLvhQjZqvM

2) https://youtu.be/Q1lj9B33Euc
*/