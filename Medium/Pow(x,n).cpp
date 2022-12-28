#include <math.h>
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
        {
            return 1;
        }
        else
        {
            return pow(x,double(n)-1)*x;
        }
    }
};

// Question Link -- https://leetcode.com/problems/powx-n/description/