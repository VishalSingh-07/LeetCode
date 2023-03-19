/*
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxArea=0;
//         for(int left=0;left<height.size();left++)
//         {
//             for(int right=left+1;right<height.size();right++)
//             {
//                 int width=right-left;
//                 maxArea=max(maxArea,min(height[left],height[right])*width);
//             }
//         }
//         return maxArea;
//     }
// };

// Above code give Time limit Exceeded due to high complexity O(n^2)

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxArea=0;
//         int left=0,right=height.size()-1;
//         for(int i=0;i<height.size();i++)
//         {
//             int width=right-left;
//             maxArea=max(maxArea,min(height[left],height[right])*width);
//             if(height[left]<=height[right])
//             {
//                 left++;
//             }
//             else
//             {
//                 right--;
//             }

//         }
//         return maxArea;
//     }
// };

// OR
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int left=0,right=height.size()-1;
        while(left<right)
        {
            int width=right-left;
            if(height[left]>height[right])
            {
                maxArea=max(maxArea,width*height[right]);
                right--;
            }
            else
            {
                maxArea=max(maxArea,width*height[left]);
                left++;
            }
            
        }
        return maxArea;
    }
};

/*
1. Question link -- https://leetcode.com/problems/container-with-most-water/

2. Solution link -- https://leetcode.com/problems/container-with-most-water/solutions/3315756/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link -- https://youtu.be/aO9eAw1wKvE
*/