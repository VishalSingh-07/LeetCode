/*
1550. Three Consecutive Odds

Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.


Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.
 

Constraints:
- 1 <= arr.length <= 1000
- 1 <= arr[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach [Counting]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0){
                count++;
            }
            else{
                count=0;
            }

            if(count==3){
                return true;
            }
        }
        return false;
    }
};

// OR

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0){
                count++;
                if(count==3){
                    return true;
                }
            }
            else{
                count=0;
            }
        }
        return false;
    }
};


// Optimized Approach [Product of three Number]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            int product=arr[i]*arr[i+1]*arr[i+2];
            if(product%2==1){
                return true;
            }
        }
        return false;
    }
};


/*
1. Question link -- https://leetcode.com/problems/three-consecutive-odds/

2. Solution link -- https://leetcode.com/problems/three-consecutive-odds/solutions/5398052/2-approach-best-c-solution-brute-force-optimized-approach-with-explanation
*/