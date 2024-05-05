/*
105. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]


Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:
- 1 <= preorder.length <= 3000
- inorder.length == preorder.length
- -3000 <= preorder[i], inorder[i] <= 3000
- preorder and inorder consist of unique values.
- Each value of inorder also appears in preorder.
- preorder is guaranteed to be the preorder traversal of the tree.
- inorder is guaranteed to be the inorder traversal of the tree.
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

/*
Optimized Approach
Time complexity -> O(n) and Space -> O(n)
where:
- n: number of nodes in a binary tree
- inStart: inorderStart
- inEnd: inorderEnd
- preStart: postorderStart
- preEnd: postorderEnd
*/
class Solution {
    TreeNode* constructBinaryTree(vector<int> &inorder, int inStart,int inEnd,vector<int> &preorder, int preStart, int preEnd, map<int,int> &mpp){
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }
        TreeNode *root=new TreeNode(preorder[preStart]);
        int inRoot=mpp[preorder[preStart]];
        int numsLeft=inRoot-inStart;
        root->left=constructBinaryTree(inorder,inStart,inRoot-1,preorder,preStart+1,preStart+numsLeft,mpp);
        root->right=constructBinaryTree(inorder,inRoot+1,inEnd,preorder,preStart+numsLeft+1,preEnd,mpp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()!=preorder.size()){
            return nullptr;
        }
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return constructBinaryTree(inorder,0,inorder.size()-1, preorder,0,preorder.size()-1,mpp);
    }
};

/*
1. Question link -- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

2. Solution link -- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/5116112/optimized-approach-with-detailed-explanation-best-c-solution-striver-solution

3. Video link -- https://youtu.be/aZNaLrVebKQ
*/