/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]


Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:
The number of nodes in the tree is in the range [0, 100].
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

// Optimized Approach
// Time Complexity: O(n) and Space Complexity: O(h)
// where h : the height of the binary tree and n : the number of nodes in the binary tree.
class Solution {
private:
    void rightView(TreeNode* root, int level, vector<int> &ans)
    {
        if(root==nullptr)
        {
            return;
        }
        if(ans.size()==level)
        {
            ans.push_back(root->val);
        }
        rightView(root->right,level+1,ans);
        rightView(root->left,level+1,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightView(root,0,ans);
        return ans;
    }
};

/*
1. Question link -- https://leetcode.com/problems/binary-tree-right-side-view/description/

2. Solution link -- https://leetcode.com/problems/binary-tree-right-side-view/solutions/4838732/best-c-solution-optimized-approach-left-right-view-of-binary-tree-with-explanation

3. Video link -- https://youtu.be/KV4mRzTjlAk
*/