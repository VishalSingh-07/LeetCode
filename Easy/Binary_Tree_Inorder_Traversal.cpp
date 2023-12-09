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

// Brute Force Approach [Recursive Approach]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
    private:
    void Inorder(TreeNode* root,vector<int> &ans)
    {
        if(root!=NULL)
        {
            Inorder(root->left,ans);
            ans.push_back(root->val);
            Inorder(root->right,ans);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        Inorder(root, ans);
        return ans;
    }
};


// Optimized Approach [Iterative Approach]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        stack <TreeNode* > st;
        
        while(root!=NULL || !st.empty())
        {
            if(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            else
            {
                root=st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};

/*
1. Question Link -- https://leetcode.com/problems/binary-tree-inorder-traversal/

2. Solution Link -- https://leetcode.com/problems/binary-tree-inorder-traversal/solutions/4381728/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/