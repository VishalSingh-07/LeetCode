#include <bits/stdc++.h>
using namespace std;
// Approach 1: Brute Force Approach [Using Hash Table]
// Time complexity -> O(logn) and Space -> O(logn)
// Where n is the number
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        if(n==1)
        {
            return true;
        }
        while(n!=1)
        {
            int newNumber=0;
            while(n!=0)
            {
                int digit=n%10;
                newNumber+=digit*digit;
                n/=10;
            }
            if(newNumber==1)
            {
                return true;
            }
            else if(st.find(newNumber)!=st.end())
            {
                return false;
            }
            st.insert(newNumber);
            n=newNumber;
        }
        return false;
    }
};

// Approach 2: Optimized Approach [Floyd's Cycle-Finding Algorithm.]
// Time complexity -> O(logn) and Space -> O(1)
// Where n is the number
class Solution {
public:
    int NextNumber(int n)
    {
        int newNumber=0;
        while(n!=0)
        {
            int digit=n%10;
            newNumber+=digit*digit;
            n/=10;
        }
        return newNumber;
    }
    bool isHappy(int n) {
        int slow=n,fast=n;
        do
        {
            slow=NextNumber(slow); // It move one step at a time
            fast=NextNumber(NextNumber(fast)); // It move two step at a time
        }while(slow!=fast);
        
        return slow==1?true:false;
    }
};


/*
1. Question link -- https://leetcode.com/problems/happy-number/

2. My Solution link -- https://leetcode.com/problems/happy-number/solutions/3263618/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link --

      i) https://youtu.be/Egw03gI-Tf0

      ii) https://youtu.be/ocDwEjRVDAk
*/