// Brute Force Approach
// Time complexity: O(logn) and Space -> O(1)
class Solution {
public:
    int numberOfMatches(int n) {
        int ans=0;
        while(n>1)
        {
            if(n%2==0)
            {
                ans+=n/2;
                n=n/2;
            }
            else
            {
                ans+=(n-1)/2;
                n=(n-1)/2+1;
            }
        }
        return ans;
    }
};

// Optimized Approach
// Time complexity: O(1) and Space -> O(1)
class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};
/*
1. Question Link -- https://leetcode.com/problems/count-of-matches-in-tournament/

2. Solution Link -- https://leetcode.com/problems/count-of-matches-in-tournament/solutions/4366138/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/