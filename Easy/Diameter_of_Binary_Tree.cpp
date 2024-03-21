/*

543. Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].



Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
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

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(h)
// where h: height of binary tree and n: number of nodes in binary tree
class Solution {
private:
    int diameter=0;
    int height(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);

        diameter=max(diameter,lh+rh);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return diameter;
    }
};

// Optimized Approach
// Time complexity -> O(n) and Space -> O(h)
// where h: height of binary tree and n: number of nodes in binary tree
class Solution {
private:
    int height(TreeNode *root, int &diameter){
        if(root==nullptr){
            return 0;
        }
        int lh=height(root->left, diameter);
        int rh=height(root->right, diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};

/*
1. Question link -- https://leetcode.com/problems/diameter-of-binary-tree/description/

2. Solution link -- https://leetcode.com/problems/diameter-of-binary-tree/solutions/4905891/easy-c-solution-2-approach-brute-force-and-optimized-approach-with-explanation

3. Video link -- https://youtu.be/Rezetez59Nk
*/