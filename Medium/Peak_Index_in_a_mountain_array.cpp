#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach 
// Time complexity --> O(n) and space --> O(1)
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int max=arr[0];
//         int index=0;
//         for(int i=0;i<arr.size();i++)
//         {
//             if(arr[i]>max)
//             {
//                 max=arr[i];
//                 index=i;
//             }
//         }

//         return index;
        
//     }
// };


// Using STL max_element approach

// Time complexity --> O(n) and Space --> O(1)
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int ans=(max_element(arr.begin(),arr.end())-arr.begin());
//         return ans;        
//     }
// };



// Using Binary Search Approach
// Time complexity --> O(logn) and space --> O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]<arr[mid+1])
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }
        return start;
    }
};

/*
if you use this formula mid = (s+e)/2 than 
you doing a mistake when you put the value of 
int-max and int-min than your mid term exceed the 
limit of integer range that's why we use mid = s + (e-s)/2
*/


// Question link -- https://leetcode.com/problems/peak-index-in-a-mountain-array/

// Video link -- https://youtu.be/xGIF8avlj64

