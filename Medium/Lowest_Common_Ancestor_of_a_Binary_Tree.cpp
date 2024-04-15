/*

236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.


Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

- The number of nodes in the tree is in the range [2, 105].
- -109 <= Node.val <= 109
- All Node.val are unique.
- p != q
- p and q will exist in the tree.
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

// Brute Force Appproach
// Time complexity -> O(2*n) and Space -> O(2*h)
// where n: number of nodes in a binary tree and h: height of the binary tree
class Solution {
private:
    // Helper function to find the path from root to a given node
    bool getPath(TreeNode *root, vector<TreeNode*> &path, TreeNode* target) {
        // Base case: if root is null, return false as we've reached the end
        if (root == nullptr) {
            return false;
        }
        
        // Add current node to the path
        path.push_back(root);

        // If the current node is the target, return true to indicate we've found the path
        if (root == target) {
            return true;
        }
        
        // Recursively search in left and right subtrees
        if (getPath(root->left, path, target) || getPath(root->right, path, target)) {
            return true; // Return true if target found in either subtree
        }
        
        // If target is not found in the subtree rooted at current node, backtrack
        path.pop_back();
        return false;
    }

public:
    // Main function to find lowest common ancestor of two nodes
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Paths to store the nodes from root to p and q
        vector<TreeNode*> pathToP, pathToQ;
        
        // Find paths from root to p and q
        getPath(root, pathToP, p);
        getPath(root, pathToQ, q);

        // Traverse both paths simultaneously to find the lowest common ancestor
        TreeNode *lca = nullptr;
        int i = 0, j = 0;
        while (i < pathToP.size() && j < pathToQ.size()) {
            if (pathToP[i] == pathToQ[j]) {
                lca = pathToP[i]; // Update lowest common ancestor
            } else {
                break; // Stop traversal if nodes diverge
            }
            i++;
            j++;
        }
        
        return lca;
    }
};



// Optimized Appproach
// Time complexity -> O(n) and Space -> O(h)
// where n: number of nodes in a binary tree and h: height of the binary tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q){
            return root;
        }

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left==nullptr){
            return right;
        }
        else if(right==nullptr){
            return left;
        }
        //both left and right are not null, we found our result
        else{
            return root;
        }
    }
};
/*
1. Question link -- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

2. Solution link -- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solutions/5028379/2-approach-best-c-solution-brute-force-optimized-approach-with-explanation

3. Video link -- https://youtu.be/_-QHfMDde90
*/