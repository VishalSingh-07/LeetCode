/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]



Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
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
// where n: number of nodes in Binary Tree
class Solution {
    void findAllPaths(TreeNode* root, vector<string> &ans, string path){
        if(root==nullptr){
            return;
        }
        path+=to_string(root->val);
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(path);
        }
        findAllPaths(root->left,ans,path + "->");
        findAllPaths(root->right,ans,path + "->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==nullptr){
            return ans;
        }
        findAllPaths(root,ans,"");
        return ans;
    }
};

/*
1. Question link -- https://leetcode.com/problems/binary-tree-paths/description/

2. Solution Link -- https://leetcode.com/problems/binary-tree-paths/solutions/4958320/optimized-approach-with-explanation-best-c-solution-beats-100-00-of-users-with-c
*/