/*
59. Spiral Matrix II

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]


Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
*/

#include <bits/stdc++.h>
using namespace std;


// Optimized Approach
// Time complexity-> O(n*n) and Space -> (1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        // n: number of rows and number of columns
        int top=0,left=0,bottom=n-1,right=n-1;
        int num=0;
        while(top<=bottom && left<=right)
        {
            // moving from left to right
            for(int i=left;i<=right;i++)
            {
                matrix[top][i]=num+1;
                num++;
            }
            top++;
            
            // moving from top to bottom
            for(int i=top;i<=bottom;i++)
            {
                matrix[i][right]=num+1;
                num++;
            }
            right--;
            // moving from right to left
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    matrix[bottom][i]=num+1;
                    num++;
                }
                bottom--;
            }
            
            // moving from bottom to top
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    matrix[i][left]=num+1;
                    num++;
                }
                left++;
            }
        }
        return matrix;
    }
};


/*
1. Question link -- https://leetcode.com/problems/spiral-matrix-ii/description/

2. Solution Link -- https://leetcode.com/problems/spiral-matrix-ii/solutions/4742234/best-c-solution-optimized-approach-time-complexity-o-n-n-and-space-o-1

3. Reference Solution Link -- https://leetcode.com/problems/spiral-matrix/solutions/4742084/optimized-approach-best-c-solution-detailed-solution-with-explanation
*/