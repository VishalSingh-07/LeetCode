/*
100. Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true


Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false


Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:
- The number of nodes in both trees is in the range [0, 100].
- -104 <= Node.val <= 104

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
// Time Complexity -> O(n) and Space -> O(h)
// Where n: number of nodes in the tree and h: height of the tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base Case
        if(!p && !q)
        {
            return true;
        }
        if(p!=nullptr && q!=nullptr && p->val==q->val)
        {
            return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        }
        return false;
    }
};

/*
1. Question Link -- https://leetcode.com/problems/same-tree/description/

2. Solution Link -- https://leetcode.com/problems/same-tree/solutions/4783870/best-c-solution-optimized-approach-beats-100-00-of-users-with-c-with-explanation
*/