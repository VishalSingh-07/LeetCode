#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time Complexity --> O(1) and Space -> O(n)
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        double kelvin=celsius+273.15;
        double fahrenheit=celsius*1.80 + 32.00;

        ans.push_back(kelvin);
        ans.push_back(fahrenheit);

        return ans;
        
    }
};

// Optimized Approach

// Time Complexity --> O(1) and Space -> O(1)
// class Solution {
// public:
//     vector<double> convertTemperature(double celsius) {
//         return{celsius+273.15,celsius*1.80+32.00};
//     }
// };

// Question link -- https://leetcode.com/problems/convert-the-temperature/