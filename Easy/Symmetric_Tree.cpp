/*
101. Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true


Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
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

// Optimized Approach [Recursive Approach]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
    bool isSymmetricHelper(TreeNode* leftTree, TreeNode* rightTree){
        if(leftTree==nullptr || rightTree==nullptr){
            return leftTree==rightTree;
        }
        if(leftTree->val!=rightTree->val){
            return false;
        }
        return isSymmetricHelper(leftTree->left,rightTree->right)
            &&  isSymmetricHelper(leftTree->right,rightTree->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return root==nullptr || isSymmetricHelper(root->left,root->right);
    }
};


// Optimized Approach [Iterative Approach]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode *leftNode=q.front();
            q.pop();
            TreeNode *rightNode=q.front();
            q.pop();

            if(leftNode==nullptr && rightNode==nullptr){
                continue;
            }
            if(leftNode==nullptr || rightNode==nullptr){
                return false;
            }
            if(leftNode->val!=rightNode->val){
                return false;
            }
            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        return true;
    }
};


/*
1. Question link -- https://leetcode.com/problems/symmetric-tree/description/

2. Solution Link -- https://leetcode.com/problems/symmetric-tree/solutions/4884765/easy-c-solution-optimized-approach-iterative-and-recursive-with-explanation

3. Video Link -- https://youtu.be/nKggNAiEpBE
*/