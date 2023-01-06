#include <bits/stdc++.h>
using namespace std;

// Time complexity --> O(n^2) and space --> O(n) where n=rowIndex
// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {

//         vector<int> result(rowIndex+1,0);
//         result[0]=1;
//         for(int i=1;i<=rowIndex;i++)
//         {
//             for(int j=i;j>=1;j--)
//             {
//                 result[j]=result[j]+result[j-1];
//             }
//         }
//         return result;

        
//     }
// };

// Time complexity --> O(n^2) and space --> O(n) where n=rowIndex
class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> result(rowIndex+1,1);
        for(int i=1;i<rowIndex;i++)
        {
            for(int j=i;j>0;j--)
            {
                result[j]=result[j]+result[j-1];
            }
        }
        return result;

        
    }
};

// Question link -- https://leetcode.com/problems/pascals-triangle-ii/