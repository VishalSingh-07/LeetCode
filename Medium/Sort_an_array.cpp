/*
912. Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).


Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:
- 1 <= nums.length <= 5 * 104
- -5 * 104 <= nums[i] <= 5 * 104
*/

#include <bits/stdc++.h>
using namespace std;
// Optimized Approach [Merge Sort]
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution {
    void merge(vector<int> &nums, int low, int mid, int high){
        int i=low,j=mid+1;
        int temp[high+1];
        int k=low;
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=high){
            temp[k++]=nums[j++];
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i];
        }
    }
    void mergeSort(vector<int> &nums, int low, int high){
        if(low<high){
            int mid=low+(high-low)/2;
            mergeSort(nums,low,mid);
            mergeSort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};

/*
1. Question link -- https://leetcode.com/problems/sort-an-array/

2. Solution link -- https://leetcode.com/problems/sort-an-array/solutions/5188318/optimized-approach-with-explanation-merge-sort-best-c-solution
*/