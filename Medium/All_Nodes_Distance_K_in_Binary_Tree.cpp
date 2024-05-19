/*
863. All Nodes Distance K in Binary Tree

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.



Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:
- The number of nodes in the tree is in the range [1, 500].
- 0 <= Node.val <= 500
- All the values Node.val are unique.
- target is the value of one of the nodes in the tree.
- 0 <= k <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
    vector<int> findDistance(TreeNode *target, unordered_map<TreeNode*, TreeNode*> &parentTrack, int k){
        unordered_map<TreeNode*,int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=1;
        int distance=0;
        while(!q.empty()){
            int sz=q.size();
            if(distance==k){
                break;
            }
            distance++;
            for(int i=0;i<sz;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=nullptr && !visited[node->left]){
                    visited[node->left]=1;
                    q.push(node->left);
                }
                if(node->right!=nullptr && !visited[node->right]){
                    visited[node->right]=1;
                    q.push(node->right);
                }
                if(parentTrack[node] && !visited[parentTrack[node]]){
                    visited[parentTrack[node]]=1;
                    q.push(parentTrack[node]);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }
    void markParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parentTrack){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node->left!=nullptr){
                parentTrack[node->left]=node;
                q.push(node->left);
            }
            if(node->right!=nullptr){
                parentTrack[node->right]=node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        markParents(root,parentTrack);
        return findDistance(target,parentTrack,k);
    }
};
/*
1. Question link -- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

2. Solution link -- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/solutions/5179862/optimized-approach-with-explanation-best-c-solution-beats-100-00-of-users-with-c

3. Video link -- https://youtu.be/i9ORlEy6EsI?si=K_optysQriHMKIMD
*/