/*
110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true


Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false


Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
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
// Time complexity -> O(n^2) and Space -> O(n)
class Solution {
private:
    int height(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        return 1+max(leftHeight,rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        if(abs(leftHeight-rightHeight)>1){
            return false;
        }

        bool leftBalanced=isBalanced(root->left);
        bool rightBalanced=isBalanced(root->right);

        return leftBalanced && rightBalanced;
    }
};



// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
private:
    int height(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        if(leftHeight==-1 || rightHeight==-1 || abs(leftHeight-rightHeight)>1){
            return -1;
        }
        return 1+max(leftHeight,rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1?true:false;
    }
};

/*
1. Question link -- https://leetcode.com/problems/balanced-binary-tree/description/

2. Solution link -- https://leetcode.com/problems/balanced-binary-tree/solutions/4880228/best-c-solutio-2-approach-brute-force-and-optimized-approach-with-explanation

3. Video Link -- https://youtu.be/Yt50Jfbd8Po
*/