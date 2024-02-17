/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]


Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 10
- -100 <= matrix[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;
// Optimized Approach
// Time complexity -> O(n*m) and Space -> O(n*m)
// where n: number of rows and m: number of columns
class Solution {
public:
      vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;
            int n=matrix.size(); // number of rows
            int m=matrix[0].size(); // number of columns

            int top=0,left=0,bottom=n-1,right=m-1;

            while(top<=bottom && left<=right)
            {
                // moving from left to right
                  for(int i=left;i<=right;i++)
                  {
                        ans.push_back(matrix[top][i]);
                  }
                  top++;

                  // moving from top to bottom
                  for(int i=top;i<=bottom;i++)
                  {
                        ans.push_back(matrix[i][right]);
                  }
                  right--;
                  // moving from right to left
                  if(top<=bottom)
                  {
                        for(int i=right;i>=left;i--)
                        {
                              ans.push_back(matrix[bottom][i]);
                        }
                        bottom--;
                  }

                  // moving from bottom to top
                  if(left<=right)
                  {
                        for(int i=bottom;i>=top;i--)
                        {
                              ans.push_back(matrix[i][left]);
                        }
                        left++;
                  }
            }
            return ans;
      }
};


/*
1. Question link -- https://leetcode.com/problems/spiral-matrix/description/

2. Solution Link -- https://leetcode.com/problems/spiral-matrix/solutions/4742084/optimized-approach-best-c-solution-detailed-solution-with-explanation

3. Video Link -- https://youtu.be/3Zv-s9UUrFM?si=4OtcFou7inZDEwo1
*/