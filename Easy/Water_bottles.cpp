/*
1518. Water Bottles

There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

 

Example 1:

Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.


Example 2:

Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
Number of water bottles you can drink: 15 + 3 + 1 = 19.
 

Constraints:
- 1 <= numBottles <= 100
- 2 <= numExchange <= 100
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res=numBottles;
        int currentEmpty=res;
        while(currentEmpty/numExchange!=0){
            int fullDrinked=currentEmpty/numExchange;
            res+=fullDrinked;
            int leftEmpty=currentEmpty-fullDrinked*numExchange;
            currentEmpty=leftEmpty+fullDrinked;
        }
        return res;
    }
};

// Optimized Approach
// Time complexity -> O(1) and Space -> O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles-1)/(numExchange-1);
    }
};

/*
1. Question link -- https://leetcode.com/problems/water-bottles/

2. Solution link -- https://leetcode.com/problems/water-bottles/solutions/5435901/2-approach-with-detailed-explanation-best-c-solution-brute-force-optimized-approach
*/