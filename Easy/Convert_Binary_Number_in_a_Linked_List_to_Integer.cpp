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

