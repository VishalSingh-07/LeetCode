#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n*m) and Space --> O(1)
// where n = number of rows and m= number of columns
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

// Above code give time limit exceeded because of high complexity O(n^2)


// Applying Binary Search on each row 
// Time complexity --> O(n*logm) and space --> O(1)
// where n = number of rows and m= number of columns
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n=matrix.size();// number of rows;
//         int m=matrix[0].size(); // number of columns
//         for(int i=0;i<matrix.size();i++)
//         {
//             int low=0;
//             int high=m-1;
//             while(low<=high)
//             {
//                 int mid=low+(high-low)/2; // finding mid of the row
//                 if(matrix[i][mid]==target)
//                 {
//                     return true; // if target matches then return true
//                 }
//                 else if(matrix[i][mid]<target)
//                 {
//                     low=mid+1;
//                 }
//                 else if(matrix[i][mid]>target)
//                 {
//                     high=mid-1;
//                 }
//             }
//         }
//         return false;
//     }
// };

// Optimized Approach
// Time complexity --> O(n+m) and Space --> O(1)
// where n = number of rows and m= number of columns
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();// number of rows;
        int m=matrix[0].size(); // number of columns
        int low=0;
        int high=m-1;
        while(low>=0 && low<n && high>=0 && high<m)
        {
            if(matrix[low][high]==target)
            {
                return true;
            }
            else if(matrix[low][high]>target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        return false;
    }
};


// Question link -- https://leetcode.com/problems/search-a-2d-matrix-ii/

// Video Link -- https://youtu.be/ZYpYur0znng

// My Detail Solution link -- https://leetcode.com/problems/search-a-2d-matrix-ii/solutions/3127608/three-approach-to-solve-a-problem-easy-c-solution-brute-force-binary-search-optimized/