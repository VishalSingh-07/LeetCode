#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long int x;
        for(int i=0;i<=30;i++)
        {
            x=pow(2,i);
            if(x==n)
            {
                return true;
            }
        }

        return false;
        
    }
};

// Count Set Bits(Brian Kernighan’s Algorithm)
// Time complexity --> O(logn) and Space --> O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count=0;
        if(n<=0)
        {
            return false;
        }
        while(n)
        {
            count+=n&1;
            n>>=1;
        }
        if(count==1)
        {
            return true; // any number which is power of 2 have exactly one set bit
        }
        return false;
        
    }
};


// Count Set Bits(using STL c++ function)
// Time complexity --> O(logn) and Space --> O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)
        {
            return false;
        }
        int count= __builtin_popcount(n);
        if(count==1)
        {
            return true;
        }
        return false;
        
    }
};

// Bit Shift Approach
// Time complexity --> O(logn) and Space --> O(1)
// Keep Shifting bits till we find '1' at LSB.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
        {
            return false;
        }
        while(n>1 && (n&1)==0)
        {
            n>>=1;
        }
        return n==1?true:false;
    }
};

// Reminder-divident Approach
// Time complexity -> O(logn) and Space -> O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
        {
            return 0;
        }
        while(n%2==0)
        {
            n/=2;
        }
        if(n==1)
        {
            return true;
        }

        return false;
        
    }
};



// Bit Trick Approach
// Time complexity -> O(1) and Space -> O(1)

/*
There's a nice bit-trick that can be used to check if a number is power of 2 efficiently. 
As already seen above, n will only have 1 set bit if it is power of 2. 
Then, we can AND (&) n and n-1 and if the result is 0, it is power of 2. 
This works because if n is power of 2 with ith bit set, then in n-1, 
i will become unset and all bits to right of i will become set. Thus the result of AND will be 0.

If n is a power of 2:
n    = 8 (1000)
n-1  = 7 (0111)
----------------
&    = 0 (0000)         (no set bit will be common between n and n-1)

If n is not a power of 2:
n    = 10 (1010)
n-1  =  9 (1001)
-----------------
&    =  8 (1000)         (atleast 1 set bit will be common between n and n-1)

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        {
            return false;
        }
        return ((n&(n-1))==0)?true:false;
    
        
    }
};


// Using Floor and Ceil [Optimized Approach]
// Time complexity --> O(1) and Space --> O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
        {
            return false;
        }
        
        return floor(log2(n))==ceil(log2(n))?true:false;
    }
};

// Question link -- https://leetcode.com/problems/power-of-two/

// My solution link -- https://leetcode.com/problems/power-of-two/solutions/3147224/7-approach-to-solve-a-problem-brute-force-count-set-bits-bit-shift-bit-trick-optimized/

// Video link -- https://youtu.be/4cqHahxFTYw