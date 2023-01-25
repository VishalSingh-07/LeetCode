#include <bits/stdc++.h>
using namespace std;

// Time complexity --> O(m*n) and Space --> O(1)
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth=0;
        for(int i=0;i<accounts.size();i++)
        {
            int sum=0;
            for(int j=0;j<accounts[i].size();j++)
            {
                sum+=accounts[i][j];
            }
            if(sum>maxWealth)
            {
                maxWealth=sum;
            }
        }
        return maxWealth;
    }
};

// Question link -- https://leetcode.com/problems/richest-customer-wealth/