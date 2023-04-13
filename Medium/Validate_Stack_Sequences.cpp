#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach [Stack]
// Time complexity -> O(n) and Space -> O(n)
// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int> st;
//         int j=0,n=pushed.size();
//         for(int i=0;i<n;i++)
//         {
//             st.push(pushed[i]);
//             while(st.size()>0 && j<n && st.top()==popped[j])
//             {
//                 st.pop();
//                 j++;
//             }
//         }
//         return j==n?true:false;

//     }
// };


// Optimized Approach [Two Pointer]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0; // Intialise one pointer pointing on pushed array
        int j=0; // Intialise one pointer pointing on popped array
        for(int x: pushed)
        {
            pushed[i]=x; // using pushed as the stack.
            i++;
            while(i>0 && pushed[i-1]==popped[j]) // pushed[i - 1] values equal to popped[j];
            {
                i--;
                j++;
            }
        }
        return i==0?true:false; // Since pushed is a permutation of popped so at the end we are supposed to be left with an empty stack
    }
};

/*
1. Question link -- https://leetcode.com/problems/validate-stack-sequences/

2. Solution link -- https://leetcode.com/problems/validate-stack-sequences/solutions/3413467/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link -- https://youtu.be/zafraJVHUGU
*/