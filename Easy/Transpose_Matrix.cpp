#include <bits/stdc++.h>
using namespace std;

/*
Time complexity: O(m*n)

Space complexity: O(m*n)

where n = number of rows and m = number of columns

*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> transpose;
        int n=matrix.size(); // Number of rows
        int m=matrix[0].size(); // Number of columns

        for(int i=0;i<m;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(matrix[j][i]);
            
            }
            transpose.push_back(temp);
        }
        return transpose;
        
    }
};


// Question link -- https://leetcode.com/problems/transpose-matrix/

