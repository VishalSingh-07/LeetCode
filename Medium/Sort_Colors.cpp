#include <bits/stdc++.h>
using namespace std;

/*
Color Representation in integer
red: 0
white: 1
blue: 2
*/

// Using Sorting Function
// Time complexity --> O(nlogn) and Space --> O(1)
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {

//         sort(nums.begin(),nums.end());
        
//     }
// };

/*
Logically using the above code is not good because according to the question, It is clearly written to solve a problem without using the library's sort function.
*/

// Using Counting Approach
// Time complexity --> O(n) + O(n) ~ O(2n) and Space --> O(1)
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int i,countzero=0, countone=0,counttwo=0; 
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             // switch(nums[i])
//             // {
//             //     case 0: 
//             //         countzero++;
//             //         break;
//             //     case 1: 
//             //         countone++;
//             //         break;
//             //     case 2: 
//             //         counttwo++;
//             //         break;
//             // }

//             // -------OR ------- 

//             if(nums[i]==0)
//             {
//                 countzero++;
               
//             }
//             else if(nums[i]==1)
//             {
//                 countone++;
                
//             }
//             else if(nums[i]==2)
//             {
//                 counttwo++;
        
//             }
//         }
//         i=0;
//         while(countzero>0)
//         {
//             nums[i]=0;
//             countzero--;
//             i++;
//         }
//         while(countone>0)
//         {
//             nums[i]=1;
//             countone--;
//             i++;
//         }
//         while(counttwo>0)
//         {
//             nums[i]=2;
//             counttwo--;
//             i++;
//         }
        
//     }
// };


// Using Pointer Approach (Dutch National Flag Algorithm)
// Time complexity --> O(n) and Space -->O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mid=0;

        while(mid<=h)
        {
            if(nums[mid]==0)
            {
                swap(nums[l],nums[mid]);
                l++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;

            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[h]);
                h--;
            }
        }
        
    }
};



// Question link -- https://leetcode.com/problems/sort-colors/description/

// Resource link -- https://leetcode.com/problems/sort-colors/solutions/3034975/easy-solution-three-approach-to-solve-a-problem-dry-run-sorting-counting-dnf-algorithm/

// Video link -- https://youtu.be/oaVa-9wmpns