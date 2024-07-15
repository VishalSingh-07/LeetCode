/*
2196. Create Binary Tree From Descriptions

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.

Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

 

Example 1:

Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.

Example 2:

Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
 

Constraints:
- 1 <= descriptions.length <= 10^4
- descriptions[i].length == 3
- 1 <= parenti, childi <= 10^5
- 0 <= isLefti <= 1
- The binary tree described by descriptions is valid.
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

// Optimized Approach [Using Hashmap]
// Time complexity -> O(n) and Space -> O(n)
class Solution
{
public:
      TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
      {
            unordered_map<int, TreeNode *> mpp;
            unordered_set<int> childNodes;
            for (int i = 0; i < descriptions.size(); i++)
            {
                  int parent = descriptions[i][0];
                  int child = descriptions[i][1];
                  int isLeft = descriptions[i][2];

                  childNodes.insert(child);

                  if (mpp.find(parent) == mpp.end())
                  {
                        mpp[parent] = new TreeNode(parent);
                  }

                  if (mpp.find(child) == mpp.end())
                  {
                        mpp[child] = new TreeNode(child);
                  }

                  if (isLeft == 1)
                  {
                        mpp[parent]->left = mpp[child];
                  }
                  else
                  {
                        mpp[parent]->right = mpp[child];
                  }
            }
            int root = -1;
            for (int i = 0; i < descriptions.size(); i++)
            {
                  int parent = descriptions[i][0];
                  if (childNodes.find(parent) == childNodes.end())
                  {
                        root = parent;
                        break;
                  }
            }
            return mpp[root];
      }
};

/*
1. Question link -- https://leetcode.com/problems/create-binary-tree-from-descriptions/

2. Solution link -- https://leetcode.com/problems/create-binary-tree-from-descriptions/solutions/5481712/begineer-friendly-c-solution-optimized-approach-with-detailed-explanation

3. Video Link -- https://youtu.be/d6rS24blgqQ?feature=shared
*/