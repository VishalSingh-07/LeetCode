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

// Optimized Approach
// Time complexity -> O(n) and Space -> O(h) 
class Solution {
private:

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)
        {
            return 0;
        }
        int val=(root->val>=low && root->val<=high)? root->val:0;
        int leftsum=rangeSumBST(root->left,low,high);
        int rightsum=rangeSumBST(root->right,low,high);

        return val+leftsum+rightsum;
    }
};

/*
1. Question link -- https://leetcode.com/problems/range-sum-of-bst/description/

2. Solution Link -- https://leetcode.com/problems/range-sum-of-bst/solutions/4527749/optimized-approach-easy-c-solution-begineer-friendly/
*/