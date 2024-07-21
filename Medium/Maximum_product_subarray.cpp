/*
152. Maximum Product Subarray

Given an integer array nums, find a 
subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:
- 1 <= nums.length <= 2 * 104
- -10 <= nums[i] <= 10
- The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^3) and Space --> O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_product=INT_MIN;
        if(n==1)
        {
            return nums[0];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int product=1;
                for(int k=i;k<=j;k++)
                {
                    product*=nums[k];
                }
                if(product>max_product)
                {
                    max_product=product;
                }
            }
        }
        return max_product;
    }
};

// Above code give Time limit exceeded due to high complexity O(n^3)

// Better Approach
// Time complexity --> O(n^2) and Space --> O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_product=INT_MIN;
        if(n==1)
        {
            return nums[0];
        }
        for(int i=0;i<n;i++)
        {
            int product=1;
            for(int j=i;j<n;j++)
            {
                product*=nums[j];
                if(product>max_product)
                {
                    max_product=product;
                }
            }
        }
        return max_product;
    }
};
// Above code give Time limit exceeded due to high complexity O(n^2)

// Two traversals approach
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            product*=nums[i];
            maxi=max(maxi,product);
            if(product==0)
            {
                product=1;
            }
        }

        product=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            product*=nums[i];
            maxi=max(maxi,product);
            if(product==0)
            {
                product=1;
            }
        }
        return maxi;
    }
};


// Single traversal approach
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1,suffix=1;
        int maxProduct=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(prefix==1000000000 || suffix == 1000000000) {
                break;
            }

            if(prefix==0){
                prefix=1;
            }
            if(suffix==0){
                suffix=1;
            }
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1];
            maxProduct=max(maxProduct,max(prefix,suffix));
            
        }
        return maxProduct;
    }
};

// Optimized Approach [Kadane's Algorithm]
// Time complexity --> O(n) and Space --> O(1)
// The pick point for this problem is that we can get the maximum product from the product of two negative numbers too.

// Following are the steps for the approach:

// Traverse through the array.
// For each element, we will store prod1 and prod2.
// Prod1 is maximum of current element, product of current element and prod1 and product of current element and prod2
// Prod2 is minimum of current element, product of current element and prod1 and product of current element and prod2
// Return maximum of result and prod1

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int max_product=ans;
        int min_product=ans;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(max_product,min_product);
            }
            max_product=max(nums[i],max_product*nums[i]);
            min_product=min(nums[i],min_product*nums[i]);
            ans=max(max_product,ans);
        }
        return ans;
    }
};


/*
1. Question link -- https://leetcode.com/problems/maximum-product-subarray/

2. My Solution link -- https://leetcode.com/problems/maximum-product-subarray/solutions/3209734/5-approaches-easy-c-solution-brute-force-better-two-traversal-optimized-kadane-s

3. Video link --

    i)  https://youtu.be/hnswaLJvr6g?si=i6nPI9pYNWsNWBtw 

    ii) https://youtu.be/GbJh0MjUa5U

    iii) https://youtu.be/tHNsZHXnYd4
*/

