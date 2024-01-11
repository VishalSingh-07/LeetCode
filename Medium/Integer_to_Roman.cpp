#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(logn) and Space -> O(1)
class Solution {
public:
    string intToRoman(int num) {
        int number[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string symbol[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

        int i=12;
        string ans="";
        while(num>0)
        {
            int div=num/number[i];
            num=num%number[i];
            while(div>0)
            {
                ans+=symbol[i];
                div--;
            }
            i--;
        }
        return ans;
        
    }
};


// Optimized Approach
// Time complexity -> O(1) and Space -> O(1)
class Solution {
public:
    string intToRoman(int num) {
        string thousands[]={"","M","MM","MMM"};
        string hundreds []={"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string tens [] ={"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ones []={"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        string ans="";
        ans+=thousands[num/1000];
        ans+=hundreds[(num%1000)/100];
        ans+=tens[(num%100)/10];
        ans+=ones[num%10];

        return ans;
    }
};

/*
1. Question Link -- https://leetcode.com/problems/integer-to-roman/description/

2. Solution Link -- https://leetcode.com/problems/integer-to-roman/solutions/4547454/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/