/*
2300. Successful Pairs of Spells and Potions
Medium

You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

 

Example 1:

Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.


Example 2:

Input: spells = [3,1,2], potions = [8,5,8], success = 16
Output: [2,0,2]
Explanation:
- 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
- 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful. 
- 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful. 
Thus, [2,0,2] is returned.
 

Constraints:

n == spells.length
m == potions.length
1 <= n, m <= 105
1 <= spells[i], potions[i] <= 105
1 <= success <= 1010
*/
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n*m) and Space -> O(1)
// where n == spells.length and m == potions.length
// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         vector<int> ans;
//         for(int i=0;i<spells.size();i++)
//         {
//             int pairCount=0;
//             for(int j=0;j<potions.size();j++)
//             {
//                 long long check=(long long)(potions[j])*(long long)(spells[i]);
//                 if(check>=success)
//                 {
//                     pairCount++;
//                 }
//             }
//             ans.push_back(pairCount);
//         }
//         return ans;
//     }
// };

// Above code ❌ give time limit Exceeded due to high complexity O(n*m)

// Optimized Approach [Binary Search]
// Time complexity -> O((n+m)log(m)) and Space -> O(logm)
// where n == spells.length and m == potions.length
// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         int n=spells.size();
//         int m=potions.size();
//         sort(potions.begin(),potions.end());
//         vector<int> ans;
//         int maxPotionValue=potions[m-1];
//         for(int i=0;i<n;i++)
//         {
//             int spell=spells[i];
//             // minPotion*spell>=success
//             long long minPotion=ceil((1.0*success)/spell);
//             if(minPotion>maxPotionValue)
//             {
//                 ans.push_back(0);
//                 continue;
//             }
//             int index=lower_bound(potions.begin(),potions.end(),minPotion)-potions.begin();

//             int count=m-index;
//             ans.push_back(count);
//         }
//         return ans;
//     }
// };


class Solution {
private:
    int LowerBound(int l, int r,vector<int> &potions,int minPotion)
    {
        int possibleIndex=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(potions[mid]>=minPotion)
            {
                possibleIndex=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return possibleIndex;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end()); // O(mlogm)
        vector<int> ans;
        int maxPotionValue=potions[m-1];
        for(int i=0;i<n;i++) // O(n*logm)
        {
            int spell=spells[i];
            // minPotion*spell>=success
            long long minPotion=ceil((1.0*success)/spell);
            if(minPotion>maxPotionValue)
            {
                ans.push_back(0);
                continue;
            }
            int index=LowerBound(0,m-1,potions,minPotion);
            int count=m-index;
            ans.push_back(count);
        }
        return ans;
    }
};


/*

1. Question link -- https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

2. Video Link -- https://youtu.be/QZI4TCVckpA

3. Solution link -- https://leetcode.com/problems/successful-pairs-of-spells-and-potions/solutions/3371469/2-approach-easy-c-solution-brute-force-and-optimized-approach-binary-search/
*/