#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Two pointer approach
        if(nums.size()==0)
        {
            return 0;
        }
        int i=0;
        for(int j=1;j<nums.size();j++)
        {

            if(nums[j]!=nums[i])
            {
                i++;
                nums[i]=nums[j];
            }


        }
        return i+1;;
    }
};

/*
if a[i] == a[j] then j++
if a[i]!=a[j] then i++ and a[i]=a[j];
return i+1;

Time complexity--> O(n)
Space Complexity---> O(1)
*/


// Question Link-- https://leetcode.com/problems/remove-duplicates-from-sorted-array/