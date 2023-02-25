#include <bits/stdc++.h>
using namespace std;
// Time complexity --> O(log7(n)) and Space --> O(log7(n))
class Solution {
public:
    string convertToBase7(int num) {
        string ans="";
        int neg=0;
        if(num<0) // If number if negative
        {
            neg=1;
            num=abs(num);
        }
        if(num==0)
        {
            return "0";
        }
        while(num!=0)
        {
            int quotient=num/7; // Calculating quotient
            int remainder=num%7; // Calculating remainder
            ans=ans+to_string(remainder); // Adding remainder to the string 
            num=quotient; 
        }
        if(neg==1)
        {
            ans=ans+"-";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// Cleaning the code [Just reducing extra variable]

class Solution {
public:
    string convertToBase7(int num) {
        string ans="";
        int neg=0;
        if(num<0) // If number if negative
        {
            neg=1;
            num=abs(num);
        }
        if(num==0){
            return "0";
        }
        while(num!=0)
        {
            ans=ans+to_string(num%7); 
            num=num/7; 
        }
        if(neg==1)
        {
            ans=ans+"-";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
}; 


// Question link -- https://leetcode.com/problems/base-7/

// My Solution link -- https://leetcode.com/problems/base-7/solutions/3229219/easiest-c-solution-optimized-approach-t-c-o-log7-n-s-c-o-log7-n/