/*

Binary Tree Preorder Traversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]


Example 2:

Input: root = []
Output: []


Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include <bits/stdc++.h>
using namespace std;

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Brute Fore Approach [Recursive Approach]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
private:
    void preorder(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};



// Better Approach [Iterative Approach]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty())
        {
            if(root!=NULL)
            {
                ans.push_back(root->val);
                st.push(root);
                root=root->left;
            }
            else
            {
                root=st.top();
                st.pop();
                root=root->right;
            }
        }
        return ans;
    }
};


// Optimized Approach 
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode *curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode *prev=curr->left;
                while(prev->right!=nullptr && prev->right !=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};

/*
1. Question Link -- https://leetcode.com/problems/binary-tree-preorder-traversal/description/

2. Solution Link -- https://leetcode.com/problems/binary-tree-preorder-traversal/solutions/4609371/2-approach-easy-c-solution-brute-force-and-optimized-approach

3. Reference Solution Link -- https://leetcode.com/problems/binary-tree-inorder-traversal/solutions/4381728/3-approach-best-c-solution-brute-force-better-and-optimized-approach
*/