#include <bits/stdc++.h>
using namespace std;

// Time complexity --> O(n^2) and O(1)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int maxcount=0;
//         int index=-1;
//         int n=nums.size();

//         for(int i=0;i<n;i++)
//         {
//             int count=0;
//             for(int j=0;j<n;j++)
//             {
//                 if(nums[i]==nums[j])
//                 {
//                     count++;
//                 }
//             }

//             // update maxcount if count of current element is greater

//             if(count>maxcount)
//             {
//                 maxcount=count;
//                 index=i;
//             }
//         }

//         if(maxcount>n/2)
//         {
//             return nums[index];
//         }
        
//         return -1;
//     }
// };

// Time complexity --> O(nlogn)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         return nums[n/2];
//     }
// };

//Time complexity ---> O(n) and space ---> O(n/2)~ O(n)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         int n=nums.size();
//         map<int, int> mp;
//         for(auto it: nums)
//         {
//             mp[it]++;
//             if(mp[it]>n/2)
//             {
//                 return it;
//             }
//         }
//         return -1;
//     }
// };


// Optimizate the code for the above to reduce the space complexity, we use moore's voting algorithm

// Using Moore's Voting Algorithm (Time complexity --> O(n) and space --> O(1))
/*
if the majority elemeny was x, and it by any chance appears on the 
left prefix, then it count at max can be (lenOfLeftPrefix/2). So since
it has to appear more than N/2 times, it is bound to appear as a majority
in the last suffix. Dry run multiple examples to get this clear! if it does not appears on left as majority, then it is quite clear that it will
be the majority at right.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;

        for(int num:nums)
        {
            if(count==0)
            {
                candidate=num;
            }
            if(num==candidate)
            {
                count+=1;
            }
            else
            {
                count-=1;
            }
        }

        return candidate;

    }
};


// Question link --> https://leetcode.com/problems/majority-element/description/

// Video Link --> https://youtu.be/AoX3BPWNnoE

// Helpful Resource --> https://www.geeksforgeeks.org/majority-element/
