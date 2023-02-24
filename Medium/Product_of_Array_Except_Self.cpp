#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> ans;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             int product=1;
//             for(int j=0;j<n;j++)
//             {
//                 if(i!=j)
//                 {
//                     product*=nums[j];
//                 }
//             }
//             ans.push_back(product);
//         }
//         return ans;
//     }

// };

// Above code give Time limit Exceeded due to high complexity O(n^2)

// Better Approach
// Time complexity --> O(n) and Space --> O(1)
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();
//         int product=1;
//         int countZero=0;
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]==0)
//             {
//                 countZero++;
//             }
//             else
//             {
//                 product*=nums[i];
//             }
            
//         }
//         if(countZero==0)
//         {
//             for(int i=0;i<n;i++)
//             {
//                 nums[i]=product/nums[i];
//             }
//         }
//         else if(countZero==1)
//         {
//             for(int i=0;i<n;i++)
//             {
//                 if(nums[i]==0)
//                 {
//                     nums[i]=product;
//                 }
//                 else
//                 {
//                     nums[i]=0;
//                 }
//             }
//         }
//         else
//         {
//             for(int i=0;i<n;i++)
//             {
//                 nums[i]=0;
//             }
//         }
//         return nums;
//     }
// };



// Prefix and Suffix Product Approach
// Time complexity -> O(n) and Space --> O(n)
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>ans(n);
//         vector<int> left(n);
//         vector<int> right(n);
//         left[0]=1;
//         for(int i=1;i<n;i++)
//         {
//             left[i]=left[i-1]*nums[i-1];
//         }
//         right[n-1]=1;
//         for(int i=n-2;i>=0;i--)
//         {
//             right[i]=right[i+1]*nums[i+1];
//         }
//         for(int i=0;i<n;i++)
//         {
//             ans[i]=left[i]*right[i];
//         }
//         return ans;

//     }

// };



// Optimized Approach
// Time complexity -> O(n) and Space --> O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        if(n<1)
        {
            return ans;
        }

        int product=1;
        for(int i=0;i<n;i++)
        {
            product*=nums[i];
            ans.push_back(product);
        }

        // Traverse from right and update output array
        product=1;
        for(int i=n-1;i>0;i--)
        {
            ans[i]=ans[i-1]*product;
            product*=nums[i];
        }
        ans[0]=product;
        return ans;
    }

};


/*
1. Question link -- https://leetcode.com/problems/product-of-array-except-self/

2. My Solution link -- 

            i)  https://leetcode.com/problems/product-of-array-except-self/solutions/3225593/4-approach-easy-c-solution-brute-force-optimized-prefix-suffix-product-approach/

            ii) https://leetcode.com/problems/product-of-array-except-self/solutions/3186745/best-c-3-solution-dp-space-optimization-brute-force-optimize-one-stop-solution/

3. Video Link -- https://youtu.be/gREVHiZjXeQ
*/
