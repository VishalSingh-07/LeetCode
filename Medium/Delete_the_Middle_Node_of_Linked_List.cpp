/*
2095. Delete the Middle Node of a Linked List
Medium
2.9K
50
Companies
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 



Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.



Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
1 <= Node.val <= 105
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
// Time complexity -> O(2n) ~ O(n)  and Space -> O(1)
// class Solution {
// private:
//     int Length(ListNode *p)
//     {
//         int len=0;
//         while(p!=NULL)
//         {
//             len++;
//             p=p->next;
//         }
//         return len;
//     }
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if(head->next==NULL)
//         {
//             return NULL;
//         }
//         int len=Length(head);
//         ListNode *p=head;
//         int middleIndex=len/2;
//         for(int i=0;i<middleIndex-1;i++)
//         {
//             p=p->next;
//         }
//         p->next=p->next->next;
//         return head;
//     }
// };


// Optimized Approach [Two Pointer]
// Time complexity -> O(n/2) ~ O(n) and Space -> O(1)
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if(head->next==NULL)
//         {
//             return NULL;
//         }
//         ListNode *slow=head,*fast=head->next->next;
//         while(fast!=NULL && fast->next!=NULL)
//         {
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         slow->next=slow->next->next;
//         return head;

//     }
// };

// OR
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
        {
            return NULL;
        }
        ListNode *slow=head,*fast=head;
        ListNode *slow_prev;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow_prev=slow;
            slow=slow->next;
            
        }
        slow_prev->next=slow_prev->next->next;
        return head;

    }
};

/*
1. Question link -- https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

2. Solution link -- https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/solutions/3453366/2-approach-easy-c-solution-with-explanation-brute-force-and-optimized-approach/
*/