/*
114. Flatten Binary Tree to Linked List

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]


Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [0]
Output: [0]
 

Constraints:
- The number of nodes in the tree is in the range [0, 2000].
- -100 <= Node.val <= 100
 
Follow up: Can you flatten the tree in-place (with O(1) extra space)?
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

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
    void preorder(TreeNode* root, vector<int> &arr) {
        if (root != nullptr) {
            arr.push_back(root->val);
            preorder(root->left, arr);
            preorder(root->right, arr);
        }
    }
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        vector<int> arr;
        preorder(root, arr);
        
        TreeNode* current = root;
        for (int i = 1; i < arr.size(); ++i) {
            current->left = nullptr;
            current->right = new TreeNode(arr[i]);
            current = current->right;
        }
    }
};


// Recursive Approach [Recursion]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    TreeNode* prev=nullptr;
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        flatten(root->right);
        flatten(root->left);

        root->right=prev;
        root->left=nullptr;
        prev=root;
    }
};


//  Iterative Approach [using Stack]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    TreeNode* prev=nullptr;
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *curr=st.top();
            st.pop();
            if(curr->right!=nullptr){
                st.push(curr->right);
            }
            if(curr->left!=nullptr){
                st.push(curr->left);
            }
            if(!st.empty()){
                curr->right=st.top();
            }
            curr->left=nullptr;
        }
    }
};



// Optimized Approach [Morris Preorder Traversal]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        TreeNode *curr=root;
        while(curr!=nullptr){
            if(curr->left!=nullptr){
                TreeNode *prev=curr->left;
                while(prev->right!=nullptr){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }
    }
};

/*
1. Question link -- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

2. Solution Link -- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/solutions/5180333/4-approach-best-c-solution-brute-force-recursion-iterative-optimized-approach

3. Video link -- https://youtu.be/sWf7k1x9XR4?si=ghp8OzBBGlbZN7w3
*/