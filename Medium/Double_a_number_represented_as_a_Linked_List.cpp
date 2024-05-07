/*
2816. Double a Number Represented as a Linked List

You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

 

Example 1:

Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.


Example 2:

Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
 

Constraints:
- The number of nodes in the list is in the range [1, 104]
- 0 <= Node.val <= 9
- The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.
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


// Brute Force Approach [Reversing the List]
// Time complexity -> O(n) and Space -> O(n)
class Solution {
     // Method to reverse the linked list
    ListNode* reverse(ListNode* p){
        ListNode *q=nullptr, *r=nullptr;
        while(p!=nullptr){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode *rev_head=reverse(head);
        int carry=0;
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        while(rev_head!=nullptr || carry!=0){
            int mul=0;
            if(rev_head!=nullptr){
                mul=rev_head->val*2;
                rev_head=rev_head->next;
            } 
            ListNode *newNode=new ListNode(mul%10+carry);
            temp->next=newNode;
            temp=temp->next; 
            carry=mul/10;
        }
        temp->next=nullptr;
        return reverse(dummy->next);
    }
};


// Better Approach [Reversing the List]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
     // Method to reverse the linked list
    ListNode* reverse(ListNode* p){
        ListNode *q=nullptr, *r=nullptr;
        while(p!=nullptr){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode *rev_head=reverse(head);
        // Initialize variables to track carry and previous node
        int carry=0;
        ListNode *curr=rev_head,*prev=nullptr;
        // Traverse the reversed linked list
        while(curr!=nullptr){
            // Calculate the new value for the current node
            int new_value=curr->val*2+carry;
            // Update carry for the next iteration
            curr->val=new_value%10;
            carry=new_value/10;
            // Move to the next node
            prev=curr;
            curr=curr->next;
        }
        // If there's a carry after the loop, add an extra node
        if(carry!=0){
            ListNode *extraNode=new ListNode(carry);
            prev->next=extraNode;
        }
        // Reverse the list again to get the original order
        ListNode *result=reverse(rev_head);
        return result;
    }
};


// Optimized Approach [Single Pointer]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {

        // If the value of the head node is greater than 4, insert a new node at the beginning
        if(head->val>4){
            head=new ListNode(0,head);
        }
        ListNode *node=head;
        // Traverse the linked list
        while(node!=nullptr){

            // Double the value of the current node and update it with the units digit
            node->val=(node->val*2)%10;

            // If the current node has a next node 
            // and the next node's value is greater than 4,
            // increment the current node's value to handle carry
            if(node->next!=nullptr && node->next->val>4){
                node->val++;
            }
            node=node->next;
        }
        return head;
    }
};

/*
1. Question link -- https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

2. Solution link -- https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/solutions/5125000/3-approach-best-c-solution-brute-force-better-optimized-approach-with-explanation
*/