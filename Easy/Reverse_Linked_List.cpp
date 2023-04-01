/*
206. Reverse Linked List
Easy

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]


Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
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


 // Brute Force Approach (Reversing Element [Swapping])
 // Time complexity -> O(n) and Space -> O(n)
// class Solution {
// private:
//     int lengthLinkedList(ListNode* head)
//     {
//         int count=0;
//         while(head!=NULL)
//         {
//             count++;
//             head=head->next;
//         }
//         return count;
//     }
// public:
//     ListNode* reverseList(ListNode* head) {
//         int *Arr,i=0;
//         ListNode* p=head;
//         Arr=(int*)malloc(sizeof(int)*lengthLinkedList(head));
//         while(p!=NULL)
//         {
//             Arr[i]=p->val;
//             p=p->next;
//             i++;
//         }
//         p=head;
//         i--;
//         while(p!=NULL)
//         {
//             p->val=Arr[i];
//             p=p->next;
//             i--;
//         }
//         free(Arr); // deallocating a array memory
//         return head;
//     }
// };

// Better Approach (Recursive Reverse)
// Time complexity -> O(n) and Space -> O(n)
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head==NULL || head->next==NULL)
//         {
//             return head;
//         }
//         ListNode* nexthead=reverseList(head->next);
//         head->next->next=head;
//         head->next=NULL;

//         return nexthead;
//     }
// };


// Optimized Approach (Reversing Links using Sliding Pointer)
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p=head;
        ListNode* q=NULL;
        ListNode* r=NULL;

        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return head;
    }
};



/*
1. Question link -- https://leetcode.com/problems/reverse-linked-list/

2. Solution link -- https://leetcode.com/problems/reverse-linked-list/solutions/3364713/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/
*/
