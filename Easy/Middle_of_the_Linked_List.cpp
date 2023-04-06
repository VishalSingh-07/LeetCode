/*
876. Middle of the Linked List
Easy

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.


Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
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
//     ListNode* middleNode(ListNode* head) {
//         int count=0;
//         ListNode* p=head;
//         while(p!=NULL)
//         {
//             count++;
//             p=p->next;
//         }
//         count=count/2;
//         while(count--)
//         {
//             head=head->next;
//         }
//         return head;
//     }
// };


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

/*
1. Question link -- https://leetcode.com/problems/middle-of-the-linked-list/

2. Solution link -- https://leetcode.com/problems/middle-of-the-linked-list/solutions/3386996/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link -- https://youtu.be/5blSG0JZNbg
*/
