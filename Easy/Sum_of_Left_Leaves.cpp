/*
404. Sum of Left Leaves

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.


Example 2:

Input: root = [1]
Output: 0
 

Constraints:

- The number of nodes in the tree is in the range [1, 1000].
- -1000 <= Node.val <= 1000

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
// Time complexity -> O(n) and Space -> O(h)
// where n: number of nodes in the binary tree and h: height of the binary tree 
class Solution {
    int traversal(TreeNode *root, bool isLeft){
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            if(isLeft==true){
                return root->val;
            }else{
                return 0;
            }
        }
        int leftSum=traversal(root->left,true); // Pass true when traversing left child
        int rightSum=traversal(root->right,false); // Pass false when traversing right child

        return leftSum+rightSum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return traversal(root,false);
    }
};


// OR

class Solution {
    void traversal(TreeNode *root, int &sum){
        if(root==nullptr){
            return;
        }
        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr){
            sum+=root->left->val;
        }
        traversal(root->left,sum);
        traversal(root->right,sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        traversal(root,sum);
        return sum;
    }
};

/*
1. Question link -- https://leetcode.com/problems/sum-of-left-leaves/description/

2. Solution link -- https://leetcode.com/problems/sum-of-left-leaves/solutions/5021181/optimized-approach-with-explanation-best-c-solution-beats-100-00-of-users-with-c
*/