/*
506. Relative Ranks

You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

 

Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].


Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

 

Constraints:
- n == score.length
- 1 <= n <= 104
- 0 <= score[i] <= 106
- All the values in score are unique.
*/
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach [Using Sorting]
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        // The best practice is to not modify the input, 
        // so we create a copy of the score array in the below implementation. 
        // We sort the copy, leaving the original array unmodified.
        vector<int> scoreCopy(n);
        scoreCopy=score;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[scoreCopy[i]]=i;
        }
        vector<string> ans(n);
        sort(scoreCopy.begin(),scoreCopy.end(),greater<int>());
        for(int i=0;i<n;i++){
            int index=mpp[scoreCopy[i]];
            if(i==0){
                ans[index]="Gold Medal";
            }
            else if(i==1){
                ans[index]="Silver Medal";
            }
            else if(i==2){
                ans[index]="Bronze Medal";
            }
            else{
                ans[index]=to_string(i+1);
            }
        }
        return ans;
    }
};


// Better Approach [Usign Priority Queue]
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<pair<int,int>> heap;
        for(int i=0;i<n;i++){
            heap.push({score[i],i});
        }
        vector<string> ans(n);
        int place=1;
        while(!heap.empty()){
            int originalIndex=heap.top().second;
            heap.pop();
            if(place==1){
                ans[originalIndex]="Gold Medal";
            }
            else if(place==2){
                ans[originalIndex]="Silver Medal";
            }
            else if(place==3){
                ans[originalIndex]="Bronze Medal";
            }
            else{
                ans[originalIndex]=to_string(place);
            }
            place++;
        }
        return ans;
    }
};



// Optimized Approach [Hashing (Array as map)]
// Time complexity -> O(n+m) and Space -> O(m)
class Solution {
    int findMax(vector<int> &score){
        int maxScore=0;
        for(int i=0;i<score.size();i++){
            if(score[i]>maxScore){
                maxScore=score[i];
            }
        }
        return maxScore;
    }
    
    public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        int m=findMax(score);
        vector<int> scoreToIndex(m+1,0);
        for(int i=0;i<n;i++){
            scoreToIndex[score[i]]=i+1;
        }
        vector<string> ans(n);
        int place=1;
        for(int i=m;i>=0;i--){
            if(scoreToIndex[i]==0){
                continue;
            }
            int actualIndex=scoreToIndex[i]-1;
            if(place==1){
                ans[actualIndex]="Gold Medal";
            }
            else if(place==2){
                ans[actualIndex]="Silver Medal";
            }
            else if(place==3){
                ans[actualIndex]="Bronze Medal";
            }
            else{
                ans[actualIndex]=to_string(place);
            }
            place++;
        }
        return ans;
    }
};

/*
1. Question link -- https://leetcode.com/problems/relative-ranks/

2. Solution link -- https://leetcode.com/problems/relative-ranks/solutions/5129421/3-approach-best-c-solution-brute-force-better-optimized-approach-with-explanation
*/