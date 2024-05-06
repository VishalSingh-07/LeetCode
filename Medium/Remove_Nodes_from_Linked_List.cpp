/*
2487. Remove Nodes From Linked List

You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

 

Example 1:


Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.



Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 

Constraints:
- The number of the nodes in the given list is in the range [1, 105].
- 1 <= Node.val <= 105
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute Force Approach [Using Stack]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr=head;
        while(curr!=nullptr){
            st.push(curr);
            curr=curr->next;
        }
        ListNode* current=st.top();
        st.pop();
        int maximum=current->val;
        ListNode *resultList=new ListNode(maximum);

        while(!st.empty()){
            current=st.top();
            st.pop();
            if(current->val<maximum){
                continue;
            }else{
                ListNode *newNode =new ListNode(current->val);
                newNode->next=resultList;
                resultList=newNode;
                maximum=current->val;
            }
        }
        return resultList;
    }
};


// Optimized Approach [Reversing Twice]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
    ListNode* reverseList(ListNode* p){
        ListNode* q=nullptr,*r=nullptr;
        while(p!=nullptr){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *revhead=reverseList(head);
        ListNode *prev=revhead,*curr=revhead->next;
        while(prev!=nullptr){
            while(curr!=nullptr && curr->val<prev->val){
                curr=curr->next;
            }
            prev->next=curr;
            prev=curr;
            if(curr!=nullptr){
                curr=curr->next;
            }
        }
        return reverseList(revhead);
    }
};


/*
1. Question link -- https://leetcode.com/problems/remove-nodes-from-linked-list/description/

2. Solution link -- https://leetcode.com/problems/remove-nodes-from-linked-list/solutions/5120194/2-approach-best-c-solution-brute-force-and-optimized-approach-with-explanation
*/