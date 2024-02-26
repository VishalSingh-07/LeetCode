/*
102. Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]


Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
 

Constraints:

-  The number of nodes in the tree is in the range [0, 2000].
-  -1000 <= Node.val <= 1000
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
// Time Complexity -> O(n) and Space -> O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==nullptr)
        {
            return ans;
        }
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            vector<int> temp;
            for(int i=0;i<s;i++)
            {
                root=q.front();
                q.pop();
                if(root->left!=nullptr)
                {
                    q.push(root->left);
                }
                if(root->right!=nullptr)
                {
                    q.push(root->right);
                }
                temp.push_back(root->val);
            }
            ans.push_back(temp);   
        }
        return ans;
    }
};

/*
1. Question Link -- https://leetcode.com/problems/binary-tree-level-order-traversal/description/

2. Solution Link -- https://leetcode.com/problems/binary-tree-level-order-traversal/solutions/4786037/easy-c-solution-beats-100-00-of-users-with-c-optimized-approach-with-explanation

3. Video Link -- https://youtu.be/EoAsWbO7sqg?si=eSCa22aTieH5E3Cz
*/