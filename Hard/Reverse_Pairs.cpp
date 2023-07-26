#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int count=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 long a=nums[i];
//                 long b=nums[j];
//                 if(a>2*b)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
        
//     }
// };

// Above Code ❌ give limit limit Exceeded due to high complexity O(n^2)


// Optimized Approach
// Time complexity -> O(2n*logn) and Space -> O(n)
class Solution {
private:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;  // temporary array
        int left=low;  // starting index of left half of arr
        int right=mid+1; // starting index of right half of arr
        
        //storing elements in the temporary array in a sorted manner//
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

         // if elements on the left half are still left //
        while(left<=mid)
        {
            temp.push_back(nums[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while(right<=high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
    }
    int countReversePairs(vector<int> &nums, int low,int mid, int high)
    {
        int count=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(right<=high && nums[i]>2*(long)nums[right])
            {
                right++;
            }
            count+=right-(mid+1);
        }
        return count;
    }
    int mergeSort(vector<int> &nums, int low, int high)
    {
        int count=0;
        if(low>=high)
        {
            return count;
        }
        int mid=low+(high-low)/2;
        count+=mergeSort(nums,low,mid); // left half
        count+=mergeSort(nums,mid+1,high); // right half
        count+=countReversePairs(nums,low,mid,high); // Modification
        merge(nums,low,mid,high); // merging sorted halves
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};

/*
1. Question link -- https://leetcode.com/problems/reverse-pairs/

2. Solution link -- https://leetcode.com/problems/reverse-pairs/solutions/3819575/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link -- https://youtu.be/0e4bZaP3MDI
*/