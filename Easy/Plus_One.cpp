#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         vector<int> ans;
//         long long n=digits[0];
//         for(int i=1;i<digits.size();i++)
//         {
//             n=n*10+digits[i];
            
//         }
//         n=n+1;
//         while(n!=0)
//         {
//             ans.push_back(n%10);
//             n/=10;
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
        
//     }
// };

// Above code ❌ is not working for below test case
// digits = [7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6]

// This is because value of n hold the value in the range of  
// -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

// Due to high digits value above code give runtime error.

// Optimized Approach
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]<9)
            {
                digits[i]++;

                return digits;
            }
            else if(digits[i]==9)
            {
                digits[i]=0;
            }
        }
        digits.push_back(0);
        digits[0]=1;
        return digits;
        
    }
};


// Question link -- https://leetcode.com/problems/plus-one/

//  My Solution link -- https://leetcode.com/problems/plus-one/solutions/3189991/easy-c-solution-optimized-approach-time-complexity-o-n-and-space-complexity-o-1/

// Video Link -- https://youtu.be/Tcxob-LyBTo