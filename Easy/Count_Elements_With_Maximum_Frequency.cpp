/*
3005. Count Elements with Maximum Frequency

You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

 

Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.


Example 2:

Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(3n) ~ O(n) and Space -> O(n)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mpp;
        
        // Finding the frequency of each element
        for(auto x: nums)
        {
            mpp[x]++;
        }

        // Determine the maximum frequency
        int maxFreq=0;
        for(auto it: mpp)
        {
            maxFreq=max(maxFreq,it.second);
        }

        // Calculating the total Frequencies of element with the maximum Frequency
        int totalFreq=0;
        for(auto it: mpp)
        {
            if(maxFreq==it.second)
            {
                totalFreq+=it.second;
            }
        }
        return totalFreq;
    }
};

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq=0;
        int totalFreq=0;
        
        // Finding the frequency of each element
        // Determine the maximum frequency
        // Calculate the total Frequencies of element with the maximum frequency
        for(int x: nums)
        {
            freq[x]++;
            int frequency=freq[x];

            // If we discover a higher frequency element
            // Update maxFreq
            // Re-set totalfreq to the new max Frequency
            if(frequency>maxFreq)
            {
                maxFreq=frequency;
                totalFreq=frequency;
            }
            // if we find an element with the maxFreq, add it to the total
            else if(frequency==maxFreq)
            {
                totalFreq+=frequency;
            }
        }
        return totalFreq;
    }
};

/*
1. Question link -- https://leetcode.com/problems/count-elements-with-maximum-frequency/

2. Solution link -- https://leetcode.com/problems/count-elements-with-maximum-frequency/solutions/4842477/best-c-solution-2-approach-brute-force-and-optimized-approach-with-explanation
*/