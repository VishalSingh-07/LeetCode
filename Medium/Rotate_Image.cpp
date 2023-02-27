#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(n^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n=matrix.size();
        cout<<n;
        vector<vector<int>> rotate(n, vector <int> (n, 0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                rotate[j][n-i-1]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=rotate[i][j];
            }
        }
        

    }
};


// Optimized Approach
// Time complexity --> O(n^2) and Space --> O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n=matrix.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        

    }
};

/*
1. Question link -- https://leetcode.com/problems/rotate-image/

2. My Solution link --

      a) GFG: https://discuss.geeksforgeeks.org/comment/5077066bd04c4aa22b7a14c7b35d49e1

      b) Leetcode: https://leetcode.com/problems/rotate-image/solutions/3236044/2-approach-easy-c-solution-brute-force-optimized-approach-dry-run-of-a-program/

3. Video Link -- https://youtu.be/Y72QeX0Efxw

*/