/*
24. Swap Nodes in Pairs
Medium

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]


Example 2:

Input: head = []
Output: []


Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
*/


#include <bits/stdc++.h>
using namespace std;
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Brute Force Approach
// Time complexity -> O(n) and O(n)
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         vector<int> store;
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }
//         while(head!=NULL)
//         {
//             store.push_back(head->val);
//             head=head->next;
//         }
//         int n=store.size();
//         for(int i=0;i<n-1;i+=2)
//         {
//             swap(store[i],store[i+1]);
//         }
//         ListNode *ptr=new ListNode(store[0]);
//         ListNode* ptr1=ptr;
//         for(int i=1;i<n;i++){
//             ptr->next=new ListNode(store[i]);
//             ptr=ptr->next;
//         }
//         return ptr1;
        
//     }
// };

// Optimized Approach
// Time complexity -> O(n) and O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *dummy=new ListNode();
        dummy->next=head;
        ListNode *prev=dummy;

        while(head!=NULL && head->next!=NULL)
        {
            prev->next=head->next;
            head->next=prev->next->next;
            prev->next->next=head;

            prev=head;
            head=head->next;
        }
        return dummy->next;
    }
};

/*
1. Question link -- https://leetcode.com/problems/swap-nodes-in-pairs/

2. Solution link -- https://leetcode.com/problems/swap-nodes-in-pairs/solutions/3530020/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/