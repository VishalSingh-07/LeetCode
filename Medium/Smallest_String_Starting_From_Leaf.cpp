/*
988. Smallest String Starting From Leaf

You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.

 
Example 1:

Input: root = [0,1,2,3,4,3,4]
Output: "dba"


Example 2:

Input: root = [25,1,3,1,3,0,2]
Output: "adz"

Example 3:

Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
 

Constraints:

- The number of nodes in the tree is in the range [1, 8500].
- 0 <= Node.val <= 25

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
class Solution {
    void getPath(TreeNode*root, string &store, string &path){
        if(root==nullptr){
            return;
        }
        path.push_back(root->val+'a');
        if(root->left==nullptr && root->right==nullptr){
            string temp=path;
            reverse(temp.begin(),temp.end());
            if(store.size()==0 || store>temp){
                store=temp;
            }
            path.pop_back();
            return;
        }
        getPath(root->left,store,path);
        getPath(root->right,store,path);
        path.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string store="";
        string path="";
        getPath(root,store,path);
        return store;
    }
};

/*
1. Question link -- https://leetcode.com/problems/smallest-string-starting-from-leaf/description/

2. Solution Link -- https://leetcode.com/problems/smallest-string-starting-from-leaf/solutions/5036989/optimized-approach-with-easy-explanation-best-c-solution
*/