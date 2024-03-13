/*
2485. Find the Pivot Integer

Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

 

Example 1:

Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.


Example 2:

Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.


Example 3:

Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
 

Constraints:

1 <= n <= 1000
*/
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
class Solution {
public:
    int pivotInteger(int n) {
        for(int i=1;i<=n;i++)
        {
            int sumLeft=0,sumRight=0;
            for(int j=1;j<=i;j++)
            {
                sumLeft+=j;
            }
            for(int k=i;k<=n;k++)
            {
                sumRight+=k;
            }
            if(sumLeft==sumRight)
            {
                return i;
            }
        }
        return -1;
    }
};


// Better Approach [Two Pointer]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    int pivotInteger(int n) {
        int leftValue=1,rightValue=n;
        int sumLeft=leftValue,sumRight=rightValue;

        if(n==1)
        {
            return n;
        }
        // Iterate until the pointer meet
        while(leftValue<rightValue)
        {
            // Adjust sums and pointer based on comparison
            if(sumLeft<sumRight){
                leftValue++;
                sumLeft+= leftValue;
            }
            else{
                rightValue--;
                sumRight+=rightValue;
            }

            // Check for pivot condition
            if(sumLeft==sumRight && leftValue+1==rightValue-1)
            {
                // return leftValue+1;
                return rightValue-1;
            }
        }
        return -1;
    }
};


// Optimized Approach
// Time complexity -> O(1) and Space -> O(1)
class Solution {
public:
    int pivotInteger(int n) {
        int sum=n*(n+1)/2;
        int pivot=sqrt(sum);
        
        // if pivot*pivot is equal to sum (pivot found) return pivot,else return -1
        return pivot*pivot==sum?pivot:-1;
    }
};

/*
1. Question link -- https://leetcode.com/problems/find-the-pivot-integer/description/

2. Solution link -- https://leetcode.com/problems/find-the-pivot-integer/solutions/4870522/3-approach-best-c-solution-brute-force-better-and-optimized-approach-with-explanation/
*/