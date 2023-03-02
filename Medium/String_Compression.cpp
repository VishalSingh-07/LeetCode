#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n) and Space -> O(n)
// class Solution {
// public:
//     int countCharacter(vector<char> &nums, int index)
//     {
//         int count=1;
//         for(int i=index+1;i<nums.size();i++)
//         {
//             if(nums[i]==nums[index])
//             {
//                 count++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         return count;
//     }
//     int compress(vector<char>& chars) {
//         vector<char> ans;
//         int n=chars.size();
//         for(int i=0;i<n;i++)
//         {
//             ans.push_back(chars[i]);

//             int count=countCharacter(chars,i);

//             if(count>1)
//             {
//                 i+=count-1;
//                 string s=to_string(count);
//                 for(char ch: s)
//                 {
//                     ans.push_back(ch);
//                 }
//             }
//         }
//         chars=ans;
//         return ans.size();
//     }
// };


// Optimized Approach
// Time complexity --> O(n) and Space -> O(1)

/*
Explanation--
- Here we are using two pointers, one for iterating through the original character array **i** and one for keeping track of the current position in the compressed array **ans**.

- Now also use a one more variable to keep track of the count of consecutive characters. and initialize the count as zero (count=0)

- Then iterate through the array until you find a different character or reach the end of the array.

- For each iteration, increment the count and the index i.

- When you find a different character or reach the end of the array, write the current letter to the compressed array and, if the count is greater than 1, write the count as a string to the compressed array.

- Then reset the count to 0 and set the current letter to the new letter.

- Finally, return the length of the compressed array, which is equal to the position of the last character in the compressed array plus one.
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n=chars.size();
        int ans=0;

        // iterate through input vector using i pointer
        for(int i=0;i<n;)
        {
            char letter=chars[i]; // current character being compressed
            int count=0; // count of consecutive occurrences of letter

            // count consecutive occurrences of letter in input vector
            while(i<n && chars[i]==letter)
            {
                count++;
                i++;
            }

            // write letter to compressed vector
            chars[ans++]=letter;

            // if count is greater than 1, write count as string to compressed vector
            if(count>1)
            {
                string cnt=to_string(count); // converting a count to string
                for(char ch: cnt) // Iterate over each character in string
                {
                    chars[ans++]=ch;
                }
            }
        }
        return ans;

    }
};

/*
1. Question link -- https://leetcode.com/problems/string-compression/

2. Solution link --

      i) https://leetcode.com/problems/string-compression/solutions/3248295/2-approach-easy-c-solution-brute-force-optimized-approach-two-pointer/

      ii) https://leetcode.com/problems/string-compression/solutions/3245804/clean-codes-full-explanation-two-pointers-c-java-python3/

      iii) https://leetcode.com/problems/string-compression/solutions/3245868/simple-diagram-explanation/

*/