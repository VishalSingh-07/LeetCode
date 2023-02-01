#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(m*n) and Space --> O(1)
// where m = number of columns and n= number of rows
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         for(int i=0;i<matrix.size();i++)
//         {
//             for(int j=0;j<matrix[i].size();j++)
//             {
//                 if(matrix[i][j]==target)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
        
//     }
// };


// Applying Binary Search on each row
// Time complexity --> O(n*logm) and Space --> O(1)
// where m = number of columns and n= number of rows
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();// number of rows;
        int m=matrix[0].size(); // number of columns
        for(int i=0;i<n;i++)
        {
            int low=0;
            int high=m-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2; // finding mid of the row
                if(matrix[i][mid]==target)
                {
                    return true; // if target matches then return true
                }
                else if(matrix[i][mid]<target)
                {
                    low=mid+1;
                }
                else if(matrix[i][mid]>target)
                {
                    high=mid-1;
                }
            }
        }
        return false;
        
    }
};

// Start from last index
// Time complexity --> O(m+n) and Space --> O(1)
// where m = number of columns and n= number of rows
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n=matrix.size(); // Number of rows
//         int m=matrix[0].size(); //Number of columns
//         int i=0;
//         int j=m-1;
//         while(i<n && j>=0)
//         {
//             if(matrix[i][j]<target)
//             {
//                 i++;
//             }
//             else if(matrix[i][j]>target)
//             {
//                 j--;
//             }
//             else if(matrix[i][j]==target)
//             {
//                 return true;
//             }
//         }
//         return false;
        
//     }
// };


// Optimized Approach
// Time complexity --> O(log(m*n)) and Space --> O(1)
// where m = number of columns and n= number of rows
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(); // Number of rows
        int m=matrix[0].size(); //Number of columns
        int low=0;
        int high=n*m-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(matrix[mid/m][mid%m]==target)
            {
                return true;
            }
            else if(matrix[mid/m][mid%m]>target)
            {
                high=mid-1;
            }
            if(matrix[mid/m][mid%m]<target)
            {
                low=mid+1;
            }
            
        }
        return false;
        
    }
};


// Question link -- https://leetcode.com/problems/search-a-2d-matrix/

// Video Link -- https://youtu.be/ZYpYur0znng

// My Detail Solution link -- https://leetcode.com/problems/search-a-2d-matrix/solutions/3122363/4-approach-to-solve-a-problem-easy-c-solution-brute-force-to-optimized-approach/