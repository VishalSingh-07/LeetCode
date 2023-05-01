#include <bits/stdc++.h>
using namespace std;

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size(),totalSalary=0;
        int maxSalary=INT_MIN,minSalary=INT_MAX;
        double averageSalary=0;
        for(int i=0;i<salary.size();i++)
        {
            totalSalary+=salary[i]; // Calculating total Salary
            minSalary=min(minSalary,salary[i]); // Finding MinSalary
            maxSalary=max(maxSalary,salary[i]); // Finding MaxSalary
        }
        averageSalary=(double)(totalSalary-minSalary-maxSalary);
        return averageSalary/(n-2);
    }
};

/*
1. Question link -- https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

2. Solution link -- https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/solutions/3473165/optimized-approach-easy-c-solution-t-c-o-n-and-s-c-o-1/
*/