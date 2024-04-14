/*
222. Count Complete Tree Nodes

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 6


Example 2:

Input: root = []
Output: 0


Example 3:

Input: root = [1]
Output: 1
 

Constraints:
- The number of nodes in the tree is in the range [0, 5 * 104].
- 0 <= Node.val <= 5 * 104
- The tree is guaranteed to be complete.
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
// Time complexity -> O(n) and Space -> O(h)
// where n: number of nodes in the binary tree and h: height of the tree
class Solution {
    int traversal(TreeNode* root, int &count){

        // Base case: If the current node is NULL, return
        if(root==nullptr){
            return 0;
        }
        // Increment count for the current node
        count++;

        // Recursively call inorder on the left subtree
        traversal(root->left,count);

        // Recursively call inorder on the right subtree
        traversal(root->right,count);
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int count=0;
        return traversal(root,count);
    }
};


// Optimized Approach
// Time complexity -> O((logn)^2) and Space -> O(logn)
// where n: number of nodes in the binary tree
class Solution {
    int findHeightLeft(TreeNode* root){
        int height=0;
        while(root!=nullptr){
            height++;
            root=root->left;
        }
        return height;
    }
    int findHeightRight(TreeNode* root){
        int height=0;
        while(root!=nullptr){
            height++;
            root=root->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {

        // Base case: If the root is NULL, there are no nodes
        if(root==nullptr){
            return 0;
        }
        // Find the left height of the tree
        int lh=findHeightLeft(root);
        // Find the right height of the tree
        int rh=findHeightRight(root);

        // Check if the last level is completely filled
        if(lh==rh){

            // If so, use the formula for total nodes in a perfect
            // binary tree ie. 2^h - 1
            return (1<<lh)-1;
            // OR
            // return pow(2,lh)-1;
        }

        // If the last level is not completely filled, recursively count 
        // nodes in left and right subtrees
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};


/*
1. Question link -- https://leetcode.com/problems/count-complete-tree-nodes/description/

2. Solution link -- https://leetcode.com/problems/count-complete-tree-nodes/solutions/5021572/2-approach-best-c-solution-brute-force-and-optimized-approach-with-explanation

3. Video Link -- https://youtu.be/u-yWemKGWO0
*/