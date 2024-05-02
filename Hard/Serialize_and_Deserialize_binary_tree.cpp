/*
297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]


Example 2:
Input: root = []
Output: []
 

Constraints:
- The number of nodes in the tree is in the range [0, 104].
- -1000 <= Node.val <= 1000
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
Optimized Approach
Time Complexity: O(N)
- serialize function: O(N), where N is the number of nodes in the tree. This is because the function performs a level-order traversal of the tree, visiting each node once.

- deserialize function: O(N), where N is the number of nodes in the tree. Similar to the serialize function, it processes each node once while reconstructing the tree.

Space Complexity: O(N)
- serialize function: O(N), where N is the maximum number of nodes at any level in the tree. In the worst case, the queue can hold all nodes at the last level of the tree.

- deserialize function: O(N), where N is the maximum number of nodes at any level in the tree. The queue is used to store nodes during the reconstruction process, and in the worst case, it may hold all nodes at the last level.
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Check if the tree is empty
        if(root==nullptr){
            return "";
        }
        // Initialize an empty string to store the serialized data
        string s="";
        // Use a queue for level-order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal
        while(!q.empty()){
            // Get the front node in the queue
            TreeNode*  currNode=q.front();
            q.pop();
            // Check if the current node is null and append "#" to the string
            if(currNode==nullptr){
                s.append("#,");
            }else{
                // Append the value of the current node to the string
                s.append(to_string(currNode->val) + ",");
            }
            if(currNode!=nullptr){
                // Push the left and right children to the queue for further traversal
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Check if the serialized data is empty
        if(data.size()==0){
            return nullptr;
        }

        // Use a stringstream to tokenize the serialized data
        stringstream s(data);
        string str;

        // Read the root value from the serialized data
        getline(s, str, ',');
        TreeNode *root=new TreeNode(stoi(str));
        // Use a queue for level-order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal to reconstruct the tree
        while(!q.empty()){
            // Get the front node in the queue
            TreeNode *currNode=q.front();
            q.pop();

            // Read the value of the left child from the serialized data
            getline(s, str, ',');
            if(str == "#"){
                currNode->left=nullptr;
            }
            else{
                TreeNode *leftNode=new TreeNode(stoi(str));
                currNode->left=leftNode;
                q.push(leftNode);
            }

            // Read the value of the right child from the serialized data
            getline(s, str, ',');
            if(str=="#"){
                currNode->right=nullptr;
            }
            else{
                TreeNode *rightNode=new TreeNode(stoi(str));
                currNode->right=rightNode;
                q.push(rightNode);
            }
        }
        // Return the reconstructed root of the tree
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


/*
1. Question link -- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

2. Solution link -- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/solutions/5101078/optimized-approach-with-explanation-best-c-solution-striver-solutio

3. Video link -- https://youtu.be/-YbXySKJsX8
*/