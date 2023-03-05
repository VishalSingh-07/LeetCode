#include <bits/stdc++.h>
using namespace std;

// Optimized Approach 
// Time complexity -> O(log10(x)) and Space -> O(1)
class Solution {
public:
    int reverse(int x) {
        int temp=x;
		long rev=0;
		while(temp!=0)
		{
		    rev=rev*10+temp%10;
		    temp=temp/10;
		    
		}
        if(rev>INT_MAX || rev<INT_MIN) // For Handling the value whoch go outside the signed 32-bit integer range [-2^31, 2^31-1]
        {
            return 0;
        }
		return (int)rev;
        
    }
};

/*
1. Question link -- https://leetcode.com/problems/reverse-integer/

2. Solution link -- https://leetcode.com/problems/reverse-integer/solutions/3259503/easy-c-solution-optimized-approach-time-complexity-o-log10-x-space-o-1/

3. Video link -- https://youtu.be/0fwrMYPcGQ0
*/