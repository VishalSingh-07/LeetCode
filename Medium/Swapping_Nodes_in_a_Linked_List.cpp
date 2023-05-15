/*
1721. Swapping Nodes in a Linked List
Medium

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]


Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
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
// Time complexity -> O(n) and Space -> O(n)
// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         vector<int> store;
//         while(head!=NULL)
//         {
//             store.push_back(head->val);
//             head=head->next;
//         }
//         int n=store.size();
//         swap(store[k-1],store[n-k]);

//         ListNode *ptr=new ListNode(store[0]);
//         ListNode* ptr1=ptr;
//         for(int i=1;i<n;i++){
//             ptr->next=new ListNode(store[i]);
//             ptr=ptr->next;
//         }
//         return ptr1;
//     }
// };


// Better Force Approach
// Time complexity -> O(2n) ~ O(n) and Space -> O(1)
// class Solution {
// private:
//     int count (ListNode* head)
//     {
//         ListNode *p=head;
//         int len=0;
//         while(p!=NULL)
//         {
//             len++;
//             p=p->next;
//         }
//         return len;
//     }
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         ListNode *first=head,*second=head;
//         int len=count(head);
//         int move=len-k;
//         k=k-1;
//         while(k--)
//         {
//             first=first->next;   
//         }
//         cout<<first->val;
//         while(move--)
//         {
//             second=second->next;
//         }
//         swap(first->val,second->val);
        
//         return head;
//     }
// };


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
/*
Iterate Left pointer while value of count is less than k
When value of counter is greater thsan k iterate right pointer
when curr pointer reaches end of the Linkedlist right pointer is at kth node from the end
because we started incrementing it after counter reaches value k
Then swap left and right node values.
*/
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left=head;
        ListNode *right=head;
        ListNode *curr=head;
        int counter=1;
        while(curr!=NULL)
        {
            if(counter<k)
            {
                left=left->next;
            }
            if(counter>k)
            {
                right=right->next;
            }
            curr=curr->next;
            counter++;
        }
        swap(left->val,right->val);
        return head;
    }
};

/*
1. Question link -- https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

2. Solution link -- https://leetcode.com/problems/swapping-nodes-in-a-linked-list/solutions/3525780/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/
*/