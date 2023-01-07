#include <bits/stdc++.h>
using namespace std;
// Using Maps (Not using constant space)
// Time complexity --> O(n) and space --> O(n)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for(auto it : nums)
//         {
//             mp[it]++;
//         }
//         for(auto x: mp)
//         {
//             if(x.second==1)
//             {
//                 return x.first;
//             }
//         }
//         return -1;
//     }
// };

// Using Sorting (Use Constant Space)
// Time complexity --> O(nlogn)+ O(n) --> O(nlogn) and Space --> O(1)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {

//         if(nums.size()<1)
//         {
//             return 0;
//         }
//         else if(nums.size()>1)
//         {
//             sort(nums.begin(),nums.end());
//             for(int i=0;i<nums.size();i++)
//             {
//                 if(nums[i]!=nums[i+1])
//                 {
//                     return nums[i];
//                 }
//                 i++;
//             }

//         }
        
//         return nums[0];

//     }
// };

// Optimize Approach using Bit Manipulation 
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            x=x^nums[i];
        }
        return x;
    }
};

/*
Property of XOR --
0 ^ 0 --> 0
0 ^ 1 --> 1
1 ^ 0 --> 1
1 ^ 1 --> 0

Example --

So, our array is arr[]: [5, 1, 3, 1, 3, 4, 5, 7, 4] 

[5, 1, 3, 1, 3, 4, 5, 7, 4]
 ↑  ↑
 5 ^ 1 = 4
 
[5, 1, 3, 1, 3, 4, 5, 7, 4]
       ↑                       
	   4 ^ 3 = 7 (prev answer xor current index)
	   
[5, 1, 3, 1, 3, 4, 5, 7, 4]
	      ↑
		  7 ^ 1 = 6 (prev answer xor current index)
		  
[5, 1, 3, 1, 3, 4, 5, 7, 4]
             ↑
			 6 ^ 3 = 5 (prev answer xor current index)

[5, 1, 3, 1, 3, 4, 5, 7, 4]
                ↑
				5 ^ 4 = 1  (prev answer xor current index)
				
[5, 1, 3, 1, 3, 4, 5, 7, 4]
                   ↑
				   1 ^ 5 = 4 (prev answer xor current index)
				   
[5, 1, 3, 1, 3, 4, 5, 7, 4]
                      ↑
					  4 ^ 7 = 3 (prev answer xor current index)
					  
[5, 1, 3, 1, 3, 4, 5, 7, 4]
                         ↑
						 3 ^ 4 = 7 (prev answer xor current index)
						 
So, the element which we got as left should be our answer, so the answer is '7'
*/

// Question link --> https://leetcode.com/problems/single-number/