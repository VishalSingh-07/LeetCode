/*
662. Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).



Example 2:

Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).


Example 3:

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 

Constraints:
- The number of nodes in the tree is in the range [1, 3000].
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
// Time complexity -> O(n) and Space -> O(n)
// where n: number of nodes in a binary tree
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            int mmin=q.front().second;
            int first,last;
            for(int i=0;i<sz;i++){
                int currentId=q.front().second - mmin;
                TreeNode *node=q.front().first;
                q.pop();
                if(i==0){
                    first=currentId;
                }
                if(i==sz-1){
                    last=currentId;
                }
                if(node->left!=nullptr){
                    q.push({node->left,(long long)currentId*2+1});
                }
                if(node->right!=nullptr){
                    q.push({node->right,(long long)currentId*2+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};

/*
1. Question link -- https://leetcode.com/problems/maximum-width-of-binary-tree/description/

2. Solution link -- https://leetcode.com/problems/maximum-width-of-binary-tree/solutions/5183861/optimized-approach-with-explanation-best-c-solution-striver-solution

3. Video link -- https://youtu.be/ZbybYvcVLks?si=OglytVsdnCT_QTwg
*/