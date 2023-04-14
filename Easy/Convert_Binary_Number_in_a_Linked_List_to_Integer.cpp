/*
1290. Convert Binary Number in a Linked List to Integer
Easy
3.6K
147
Companies
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10


Example 2:

Input: head = [0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
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
// private:
//     ListNode* reverseList(ListNode* head)
//     {
//         ListNode *p=head,*q=NULL,*r=NULL;
//         while(p!=NULL)
//         {
//             r=q;
//             q=p;
//             p=p->next;
//             q->next=r;
//         }
//         return q;
//     }
// public:
//     int getDecimalValue(ListNode* head) {
//         if(head==NULL)
//         {
//             return 0;
//         }
//         ListNode *p;
//         head=reverseList(head);
//         int num=0,i=0;
//         while(head!=NULL)
//         {
//             num+=head->val*pow(2,i);
//             head=head->next;
//             i++;
//         }
//         return num;
//     }
// };

// Better Approach [Binary Representation]
// Time complexity -> O(n) and Space -> O(1)
// Formula used : num = num*2 + x
// class Solution {
// public:
//     int getDecimalValue(ListNode* head) {
//         if(head==NULL)
//         {
//             return 0;
//         }
//         int num=0;
//         while(head!=NULL)
//         {
//             num=num*2+head->val;
//             head=head->next;
//         }
//         return num;
//     }
// };


// Optimized Approach [Bit Manipulation]
// Time complexity -> O(n) and Space -> O(1)
// Formula used : num = (num<<1)| x
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(head==NULL)
        {
            return 0;
        }
        int num=0;
        while(head!=NULL)
        {
            num=(num<<1)|head->val;
            head=head->next;
        }
        return num;
    }
};

/*
1. Question Link -- https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

2. Solution link -- https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/solutions/3416515/3-approach-easy-c-brute-force-better-and-optimized-approach/

3. Video link --https://youtu.be/rPbzUW7usJE
*/

