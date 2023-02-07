#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n*m) and Space --> O(1)
// where n = number of rows and m = number of columns
// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {

//         int count=0;
//         for(int i=0;i<grid.size();i++)
//         {
//             for(int j=0;j<grid[i].size();j++)
//             {
//                 if(grid[i][j]<0)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
        
//     }
// };

// Binary Search Approach [Applying Binary search on each row]
// Time complexity --> O(n*logm) and Space --> O(1)
// where n = number of rows and m = number of columns
// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {

//         int n=grid.size();
//         int m=grid[0].size();
//         int totalCount=0;
//         for(int i=0;i<n;i++)
//         {
//             int low=0;
//             int high=m-1;
//             int count=0;
//             while(low<=high)
//             {
//                 int mid=low+(high-low)/2;
//                 if(grid[i][mid]<0)
//                 {
//                     high=mid-1;
//                 }
//                 else
//                 {
//                     low=mid+1;
//                 }
//             }
//             // cout<<low<<" ";
//             count=m-low;
//             // cout<<count<<" ";
//             totalCount+=count;

//         }

//         return totalCount;
        
//     }
// };


// Optimized Approach
// Time complexity --> O(n+m) and Space --> O(1)
// where n = number of rows and m = number of columns
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int count=0;
        int n=grid.size(); // number of rows
        int m=grid[0].size(); // number of columns

        int row=n-1;
        int col=0;

        while(row>=0 && col<m)
        {
            if(grid[row][col]<0)
            {
                count+=m-col;
                row--;
            }
            else
            {
                col++;
            }
        }
        return count;

        
    }
};
/*
Time Complexity : O(N+M), because matrix is sorted in non-increasing order both row-wise & column-wise 
that's why this will form staircase structure like this.

Space Complexity : O(1), the algorithm itself takes constant space.

Using matrix + staircase logic becauase matrix is sorted in non-increasing order both row-wise and
column-wise. 

*/

// Question link -- https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

// My Solution link -- https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/solutions/3155516/3-approach-to-solve-a-problem-easy-c-solution-brute-force-binary-search-optimized/


