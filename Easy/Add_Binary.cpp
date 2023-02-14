#include <bits/stdc++.h>
using namespace std;

// Approach 1: 
// Time complexity --> O(max(n,m)) and Space --> O(max(n,m))
// class Solution {
// public:
//     string addBinary(string a, string b) {
        
//         if(b.size()>a.size())
//         {
//             swap(a,b);
//         }
//         while(b.size()<a.size())
//         {
//             b="0"+b;
//         }
//         int carry=0;

//         string res="";
//         for(int i=b.size()-1;i>=0;i--)
//         {
//             if(b[i]=='1' && a[i]=='1')
//             {
//                 if(carry==0)
//                 {
//                     res="0"+res;
//                 }
//                 else if(carry==1)
//                 {
//                     res="1"+res;
//                 }
//                 carry=1;
//             }
//             else if(b[i]=='0' && a[i]=='0')
//             {
//                 if(carry==0)
//                 {
//                     res="0"+res;
//                 }
//                 else if(carry==1)
//                 {
//                     res="1"+res;
//                     carry=0;
//                 }
//             }
//             else if((b[i]=='0' && a[i]=='1')||(a[i]=='0' && b[i]=='1'))
//             {
//                 if(carry==0)
//                 {
//                     res="1"+res;
//                 }
//                 else if(carry==1)
//                 {
//                     res="0"+res;
//                 }
//             }
//         }
//         if(carry==1)
//         {
//             res="1"+res;
//         }

//         return res;
//     }
// };


// Approach 2:
// Time complexity --> O(max(n,m)) and Space --> O(max(n,m))

/*
take carry, value as 0 and an empty string
take a while loop in which iterate both the string and a condition in which carry is not equal to zero
take index A-i-1(A size of string a) of a and B-i-1(B size of string b) of b and add these values at these indexes with carry and mod the value
convert the values to string and add to ans string
increment i
after the loop return string ans
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0,i=0;
        int n=a.size(); // length of string a
        int m=b.size(); // length of string b
        string ans="";
        while(i<n || i<m || carry!=0)
        {
            int x=0;
            if(i<n && a[n-i-1]=='1')
            {
                x=1;
            }
            int y=0;
            if(i<m && b[m-i-1]=='1')
            {
                y=1;
            }
            ans=to_string((x+y+carry)%2)+ans;
            carry=(x+y+carry)/2;
            i++;
        }
        return ans;
    }
};

/*
Concept of Binary Addition.

**Rememeber,
1+1=0 with carry 1
1+0=1 with carry 0
0+1=1 with carry 0
0+0=0 with carry 0
Imp:1+1=1 with carry 1 if previous carry was 1.
The carry gets added in next step(scanning from right to left).
**
*/


// Question link -- https://leetcode.com/problems/add-binary/

// Video Link -- https://youtu.be/ju8iSHeQmx4

/*
Resource Link --

1. https://leetcode.com/problems/add-binary/solutions/3184758/easy-c-solution-2-approach-to-solve-a-problem-time-space-complexity-o-max-n-m/

2. https://leetcode.com/problems/add-binary/solutions/3182882/super-easy-solution-full-explanation-c-python3-java-commented/

*/