/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.


Example 2:

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000

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
// Time complexity -> O(n) and Space -> O(n)
// where n: number of nodes in a binary tree
class Solution {

    // Function to find the maximum sum of a path starting from the current node downwards.
    // It updates the 'maxi' variable with the maximum path sum found so far.
    int maxPathDown(TreeNode* node, int &maxi){

        // Base case: If the current node is null, return 0.
        if(node==nullptr){
            return 0;
        }
        // Calculate the maximum sum of paths starting from the left and right child nodes.

        // Maximum sum of the path starting from the left child
        int leftSum=max(0,maxPathDown(node->left,maxi)); 

        // Maximum sum of the path starting from the right child
        int rightSum=max(0,maxPathDown(node->right,maxi)); 

        // Update 'maxi' with the maximum of the following:
        // 1. Current maximum value.
        // 2. Sum of the path through the current node, left child, and right child.
        maxi=max(maxi,leftSum+rightSum+node->val);

        // Return the maximum sum starting from the current node going downwards.
        // This will be the maximum of:
        // 1. The value of the current node.
        // 2. The sum of the path starting from either left or right child, whichever is greater.
        return (node->val)+max(leftSum,rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPathDown(root,maxi); 
        return maxi;
    }
};

/*
1. Question link -- https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

2. Solution link -- https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/4910129/best-c-solution-optimized-approach-with-explanation-striver-solution

3. Video Link -- https://youtu.be/WszrfSwMz58
*/