/*
547. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2


Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:
- 1 <= n <= 200
- n == isConnected.length
- n == isConnected[i].length
- isConnected[i][j] is 1 or 0.
- isConnected[i][i] == 1
- isConnected[i][j] == isConnected[j][i]
*/

#include <bits/stdc++.h>
using namespace std;


// Optimzed Approach [Using Adjacency List]
// Time complexity -> O(n) + O(V+2E) and Space -> O(n)
// Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 
class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int> &visited){
        visited[node]=1;
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it, adj,visited);
            }
        }
    } 
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];

        // Creating Adjacency List
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n,0);
        int province=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                province++;
                dfs(i,adj,visited);
            }
        }
        return province;
    }
};


// Optimzed Approach [Using Adjacency Matrix]
// Time complexity -> O(n) + O(V+2E) and Space -> O(n)
// Where O(n) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 
class Solution {
private:
    void dfs(int node, vector<vector<int>> &isConnected, int v, vector<int> &visited){
        visited[node]=1;
        for(int i=0;i<v;i++){
            if(!visited[i] && isConnected[node][i]){
                dfs(i,isConnected,v,visited);
            }
        }
    } 
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int> visited(v,0);
        int province=0;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                province++;
                dfs(i,isConnected,v,visited);
            }
        }
        return province;
    }
};


/*
1. Question link -- https://leetcode.com/problems/number-of-provinces/description/

2. Solution link -- https://leetcode.com/problems/number-of-provinces/solutions/5486845/optimized-approach-with-explanation-easy-c-solution-striver-solution

3. Video link -- https://youtu.be/ACzkVtewUYA?si=MWzGtvBP8Zq6Ggq_
*/