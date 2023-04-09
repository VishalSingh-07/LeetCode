/*
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true


Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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
//     bool isPalindrome(ListNode* head) {
//         if(head==NULL ||head->next==NULL)
//         {
//             return true;
//         }
//         vector<int> store;
//         while(head!=NULL)
//         {
//             store.push_back(head->val);
//             head=head->next;
//         }
//         for(int i=0;i<store.size()/2;i++)
//         {
//             if(store[i]!=store[store.size()-i-1])
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };


// Better Approach
// Time complexity -> O(n) and Space -> O(n)
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         /*
//         Reverse the list and store it in r_head
//         and then compare head->val and r_head->val if equal move both the pointers otherwise if not equal
//         and return false
//         */
//         // When the loop will be executed fully retrun true
//          if(head == NULL || head->next == NULL){
//             return true;
//         }
//         ListNode *r_head = NULL;
//         ListNode *ptr = head;
//         while(ptr!=NULL){
//             ListNode *temp = new ListNode(ptr->val);
//             temp ->next = r_head;
//             r_head = temp;
//             ptr = ptr->next;
//         }
//         while(head && r_head){
//             if(head->val != r_head->val){
//                 return false;
//             }
//             head = head->next;
//             r_head = r_head->next;
//         }
//         return true;
//     }
// };

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *p=head;
        ListNode *q=NULL,*r=NULL;
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL ||head->next==NULL)
        {
            return true;
        }
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;

        while(slow!=NULL)
        {
            if(head->val!=slow->val)
            {
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};

/*

1. Question link -- https://leetcode.com/problems/palindrome-linked-list/

2. Solution link -- https://leetcode.com/problems/palindrome-linked-list/solutions/3398025/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video link -- https://youtu.be/-DtNInqFUXs
*/