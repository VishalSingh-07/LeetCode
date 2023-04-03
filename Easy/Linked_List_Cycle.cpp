/*
141. Linked List Cycle
Easy

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).


Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
  struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(head==NULL || head->next==NULL)
//         {
//             return false;
//         }
//         ListNode *slow,*fast;
//         slow=fast=head;
//         do
//         {
//             slow=slow->next;
//             fast=fast->next;
//             fast=fast!=NULL?fast->next:fast;
//         }while(slow!=NULL && fast!=NULL && slow!=fast);

//         return slow==fast?true:false;
//     }
// };

// OR
class Solution {
public:
    bool hasCycle(ListNode *head) {
	
		// if head is NULL then return false;
        if(head == NULL)
        {
            return false;
        }

		// making two pointers fast and slow and assignning them to head
        ListNode *fast = head;
        ListNode *slow = head;
        
		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
            {
                return true;
            }
        }
		// if traversal reaches to NULL this means no cycle.
        return false;
    }
};


/*
1. Question link -- https://leetcode.com/problems/linked-list-cycle/

2. Solution link -- https://leetcode.com/problems/linked-list-cycle/solutions/3375481/optimized-approach-easy-c-solution-t-c-o-n-and-s-c-o-1/
*/