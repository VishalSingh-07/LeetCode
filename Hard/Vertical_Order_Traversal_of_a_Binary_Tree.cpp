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
// Time complexity -> O(nlogn) and Space -> O(n)
// where n: number of nodes in a binary tree
/*
Remember :
1. For left child -> {vertical-1,level+1}
2. For right child -> {vertical+1,level+1}

// where vertical: columns and level: rows


    This int is for storing verticals
     ^
     |
map<int,map<int,multiset<int>>> mpp:

    
        This int is for level 
         ^
         |
    map<int,multiset<int>>
                |
                This multiset is used for multinode on same level as well as same vertical
   
*/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>> ans;
            if(root==nullptr){
                return ans;
            }
            map<int,map<int,multiset<int>>> mpp;
            queue<pair<TreeNode*,pair<int,int>>> q;
            q.push({root,{0,0}}); // q.push({root,{verticals,levels}})
            while(!q.empty()){
                  auto it=q.front();
                  q.pop();
                  TreeNode* node=it.first;
                  int vertical=it.second.first,level=it.second.second;
                  mpp[vertical][level].insert(node->val);
                  if(node->left!=nullptr){
                        q.push({node->left,{vertical-1,level+1}});
                  }
                  if(node->right!=nullptr){
                        q.push({node->right,{vertical+1,level+1}});
                  }
            }
            // where p.first=int and p.second=map<int,multiset<int>>
            for(auto p: mpp){
                  vector<int> col;
                  for(auto q: p.second){
                        // q.first -> int and q.second -> multiset<int>
                        col.insert(col.end(),q.second.begin(),q.second.end());
                  }
                  ans.push_back(col);
            }
            return ans; 
      }
};

/*
1. Question link -- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

2. Solution Link -- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/solutions/4876004/beats-100-00-of-users-with-c-easy-c-solution-optimized-approach-with-explanation

3. Video Link -- https://youtu.be/q_a6lpbKJdw
*/