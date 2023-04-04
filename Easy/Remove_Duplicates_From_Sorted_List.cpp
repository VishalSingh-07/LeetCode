/*
83. Remove Duplicates from Sorted List
Easy

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]


Example 2:

Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* p=head;
        ListNode* q=p->next; 
        while(q!=NULL)
        {
            if(p->val!=q->val)
            {
                p=q;
                q=q->next;
            }
            else
            {
                p->next=q->next;
                delete q;
                q=p->next;
            }
        }
        return head;
    }
};

/*
1. Question link -- https://leetcode.com/problems/remove-duplicates-from-sorted-list/

2. Solution link -- https://leetcode.com/problems/remove-duplicates-from-sorted-list/solutions/3379227/optimized-approach-easy-c-solution-t-c-o-n-and-s-c-o-1/
*/