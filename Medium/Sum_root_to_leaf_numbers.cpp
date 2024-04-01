/*
129. Sum Root to Leaf Numbers

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

 

Example 1:

Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.



Example 2:

Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.
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
// Where n: number of nodes in binary Tree
class Solution {
    void findAllPaths(TreeNode *root, string &path,int &totalSum){
        if(root==nullptr){
            return;
        }
        path+=to_string(root->val);
        if(root->left==nullptr && root->right==nullptr){
            totalSum+=stoi(path);
        }
        findAllPaths(root->left,path,totalSum);
        findAllPaths(root->right,path,totalSum);
        path.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        int totalSum=0;
        string path="";
        findAllPaths(root,path,totalSum);
        return totalSum;
    }
};

// OR

class Solution {
    void totalSum(TreeNode *root, int currSum,int &res){
        if(root->left==nullptr && root->right==nullptr){
            currSum=currSum*10+root->val;
            res+=currSum;
            return;
        }
        currSum=currSum*10+root->val;
        if(root->left!=nullptr){
            totalSum(root->left,currSum,res);
        }
        if(root->right!=nullptr){
            totalSum(root->right,currSum,res);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int res=0;
        totalSum(root,0,res);
        return res;
    }
};

/*
1. Question Link -- https://leetcode.com/problems/sum-root-to-leaf-numbers/

2. Solution Link -- https://leetcode.com/problems/sum-root-to-leaf-numbers/solutions/4958455/optimized-approach-with-explanation-best-c-solution-beats-100-00-of-users-with-c
*/