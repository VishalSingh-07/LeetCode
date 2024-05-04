/*
106. Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]


Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:
- 1 <= inorder.length <= 3000
- postorder.length == inorder.length
- -3000 <= inorder[i], postorder[i] <= 3000
- inorder and postorder consist of unique values.
- Each value of postorder also appears in inorder.
- inorder is guaranteed to be the inorder traversal of the tree.
- postorder is guaranteed to be the postorder traversal of the tree.
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
- is: inorderStart
- ie: inorderEnd
- ps: postorderStart
- pe: postorderEnd
*/
class Solution {
    TreeNode* constructBinaryTree(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int,int> &mpp){
        if(ps>pe || is>ie){
            return nullptr;
        }
        TreeNode* root=new TreeNode(postorder[pe]);
        int inRoot=mpp[postorder[pe]];
        int numsLeft=inRoot-is;

        root->left=constructBinaryTree(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,mpp);
        root->right=constructBinaryTree(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return nullptr;
        }
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        
        return constructBinaryTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }
};


/*
1. Question link -- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

2. Solution Link -- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solutions/5112274/optimized-approach-with-detailed-explanation-best-c-solution-striver-solution

3. Video Link -- https://youtu.be/LgLRTaEMRVc?si=sLowSLnvSjB2WAm2
*/