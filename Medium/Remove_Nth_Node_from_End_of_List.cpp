/*
19. Remove Nth Node From End of List
Medium

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]


Example 2:

Input: head = [1], n = 1
Output: []


Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
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
// Time complexity -> O(2n) ~ O(n) and Space -> O(1)
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *del=new ListNode(); // Node to be deleted
//         ListNode *temp=head;
//         if(head->next==NULL && n==1)
//         {
//             return {};
//         }
//         int count=0;
//         while(temp!=NULL)
//         {
//             count++;
//             temp=temp->next;
//         }
//         if(count==n) // This condition will be true when they asked to delete head
//         {
//             del=head;
//             head=head->next;
//             delete del;
//             return head;
//         }
//         del=head; 
//         ListNode* prev=NULL;
//         int pos=count-n;
//         while(pos--)
//         {
//             prev=del;
//             del=del->next;
//         }
//         prev->next=del->next;
//         delete del;
//         return head;

//     }
// };

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*start=new ListNode();
        start->next=head;
        ListNode *slow=start,*fast=start,*del;
        while(n--)
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        del=slow->next;
        slow->next=slow->next->next;
        delete del;
        return start->next;
    }
};

/*
1. Question link -- https://leetcode.com/problems/remove-nth-node-from-end-of-list/

2. Solution link -- https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/3390761/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link --https://youtu.be/Lhu3MsXZy-Q
*/