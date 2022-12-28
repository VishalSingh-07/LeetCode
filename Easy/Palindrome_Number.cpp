class Solution {
public:
    bool isPalindrome(int x) {
        // special cases:
        /*
        As discussed above, when x<0, x is not a palindrome.
        Also if the last digit of the number is 0, in order to be a palindrome, then
        the first digit of the number also needs to be 0.
        Only 0 satisfy this property
        */
        long long temp=x;
        if(x==0)
        {
            return true;
        }
        if(x<0 || x%10==0)
        {
            return false;
        }
        long long rev=0;
        while(temp>0)
        {
            
            rev= rev*10 + temp%10;
            temp=temp/10;

        }
        if(x==rev)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        

    }
};

// Question Link-- https://leetcode.com/problems/palindrome-number/