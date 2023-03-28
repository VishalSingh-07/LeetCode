/*
415. Add Strings
Easy
4.3K
643
Companies
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"


Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/
#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach 
// Time complexity -> O(n) and Space -> O(1)
// class Solution {
// public:
//     string addStrings(string num1, string num2) {
        
//         int x=stoi(num1);
//         int y=stoi(num2);

//         return to_string(x+y);

//     }
// };
/*
Above code is not allowed according to the question because 
You must solve the problem without using any built-in library 
for handling large integers (such as BigInteger). 
You must also not convert the inputs to integers directly.
*/

// Optimized Approach
// Time complexity -> O(max(n,m)) and Space -> O(1)
// Where n =  length of string num1 and m = length of string num2
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1,j=num2.size()-1;
        int sum=0,carry=0;
        string ans="";
        while(i>=0 && j>=0)
        {
            sum=num1[i]-'0'+num2[j]-'0';
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
            i--;
            j--;
        }
        while(i>=0)
        {
            sum=num1[i]-'0';
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
            i--;
        }
        while(j>=0)
        {
            sum=num2[j]-'0';
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
            j--;
        }
        if(carry!=0)
        {
            ans+=to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        

    }
};

/*
The stoi() is a standard library function that turns a string into an integer. 
C++ programmers utilize the function, which stands for “string to integer,”
to obtain integers from strings. Additionally, the stoi() function can remove 
other components, such as trailing letters from the string.
*/

/*
1. Question Link -- https://leetcode.com/problems/add-strings/

2. Solution Link -- https://leetcode.com/problems/add-strings/solutions/3352044/easy-c-solution-optimized-approach-begineer-friendly/
*/