/*
104. Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 3


Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:
- The number of nodes in the tree is in the range [0, 104].
- -100 <= Node.val <= 100

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
// where n: the number of nodes in the binary tree.
class Solution {
private:
    int countHeight(TreeNode* root)
    {
        int x=0,y=0;
        if(root!=nullptr)
        {
            x=countHeight(root->left);
            y=countHeight(root->right);
            if(x>y)
            {
                return x+1;
            }
            else
            {
                return y+1;
            }
        }
        return 0;
    }
public:
    int maxDepth(TreeNode* root) {
        return countHeight(root);
    }
};

// OR 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);

        return 1+max(lh,rh);
    }
};


/*
1. Question link -- https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

2. Solution Link -- https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/4838389/best-c-solution-optimized-approach-dry-run-detailed-explanation

3. Video Link -- https://youtu.be/eD3tmO66aBA
*/

