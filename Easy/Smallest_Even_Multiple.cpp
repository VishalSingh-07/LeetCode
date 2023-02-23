#include <bits/stdc++.h>
using namespace std;

// Approach 1
// Time Complexity --> O(1) and Space -> O(1)
class Solution {
public:
    int smallestEvenMultiple(int n) {

        if(n%2==0) // When n is even number
        {
            return n;
        }
        return 2*n;  
    }
};


// Approach 2: [One line approach]
// Kind of similar to above approach
// Time Complexity --> O(1) and Space -> O(1)
class Solution {
public:
    int smallestEvenMultiple(int n) {
       return (n%2==0)?n:2*n; 
    }
};


// Question link -- https://leetcode.com/problems/smallest-even-multiple/

// My Solution link --https://leetcode.com/problems/smallest-even-multiple/solutions/3222173/easiest-c-solution-one-line-approach-optimized-approach-t-c-o-1-s-c-o-1/