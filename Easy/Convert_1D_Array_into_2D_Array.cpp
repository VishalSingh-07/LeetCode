/*
2022. Convert 1D Array Into 2D Array

You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using all the elements from original.

The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.

Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

 

Example 1:


Input: original = [1,2,3,4], m = 2, n = 2
Output: [[1,2],[3,4]]
Explanation: The constructed 2D array should contain 2 rows and 2 columns.
The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.
Example 2:

Input: original = [1,2,3], m = 1, n = 3
Output: [[1,2,3]]
Explanation: The constructed 2D array should contain 1 row and 3 columns.
Put all three elements in original into the first row of the constructed 2D array.
Example 3:

Input: original = [1,2], m = 1, n = 1
Output: []
Explanation: There are 2 elements in original.
It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D array.
 

Constraints:

1 <= original.length <= 5 * 104
1 <= original[i] <= 105
1 <= m, n <= 4 * 104
*/


#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time complexity -> O(n*m) and Space -> O(m*n)
/*
Where 
    m= number of rows
    n= number of columns
*/
// class Solution {
// public:
//     vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
//         vector<vector<int>> ans(m,vector<int>(n));
//         int x=0;
//         if(m*n==original.size())
//         {
//             // cout<<"Possible"<<endl;
//             for(int i=0;i<m;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 {
//                     ans[i][j]=original[x];
//                     x++;
//                 }
//             }
//             return ans;
//         }
//         return {};        
//     }
// };

// Optimized Approach
// Time complexity -> O(n*m) and Space -> O(m*n)
/*
Where 
    m= number of rows
    n= number of columns
*/
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n));
        if(m*n==original.size())
        {
            for(int i=0;i<original.size();i++)
            {
                ans[i/n][i%n]=original[i];
            }
            return ans;
        }
        return {};        
    }
};

/*
The time complexity of the given code is O(m*n), where m and n are the dimensions of the 2D array to be constructed. This is because the code iterates over each element of the original vector once to assign its value to the corresponding element in the 2D array.

The space complexity of the code is O(m*n), as it creates a 2D vector of size m x n to store the constructed array. This space complexity is optimal since it is necessary to allocate space for m x n elements in the 2D array.

*/

/*
1. Question link -- https://leetcode.com/problems/convert-1d-array-into-2d-array/

2. My Solution link -- https://leetcode.com/problems/convert-1d-array-into-2d-array/solutions/3299871/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/