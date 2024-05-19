/*
2385. Amount of Time for Binary Tree to Be Infected

You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

 

Example 1:

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.


Example 2:

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
 

Constraints:
- The number of nodes in the tree is in the range [1, 105].
- 1 <= Node.val <= 105
- Each node has a unique value.
- A node with a value of start exists in the tree.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
    int findMaxDistance(map<TreeNode*,TreeNode*> &mpp, TreeNode *target){
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, int> visited;
        visited[target]=1;
        int maxi=0;
        while(!q.empty()){
            int sz=q.size();
            int fl=0;
            for(int i=0;i<sz;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=nullptr && !visited[node->left]){
                    fl=1;
                    visited[node->left]=1;
                    q.push(node->left);
                }
                if(node->right!=nullptr && !visited[node->right]){
                    fl=1;
                    visited[node->right]=1;
                    q.push(node->right);
                }
                if(mpp[node] && !visited[mpp[node]]){
                    fl=1;
                    visited[mpp[node]]=1;
                    q.push(mpp[node]);
                }
            }
            if(fl==1){
                maxi++;
            }
        }
        return maxi;
    }
    TreeNode* markParents(TreeNode* root, map<TreeNode*,TreeNode*> &mpp, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *res;
        while(!q.empty()){
            TreeNode *node=q.front();
            if(node->val==start){
                res=node;
            }
            q.pop();
            if(node->left!=nullptr){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right!=nullptr){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mpp;
        TreeNode* target=markParents(root,mpp,start);
        int maxi=findMaxDistance(mpp,target);
        return maxi;
    }
};

/*
1. Question link -- https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

2. Solution link -- https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/solutions/5180113/optimized-approach-with-explanation-best-c-solution-striver-solution

3. Video link -- https://youtu.be/2r5wLmQfD6g?si=W6cVfCVZJT0j3cmS

*/