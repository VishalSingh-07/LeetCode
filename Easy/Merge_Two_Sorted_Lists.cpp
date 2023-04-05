/*
21. Merge Two Sorted Lists
Easy

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]


Example 2:

Input: list1 = [], list2 = []
Output: []


Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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
// Time complexity -> O(n+m) and Space -> O(1)
// where n=number of nodes in list1 and m=number of nodes in list2 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        ListNode *third,*last; 
        if(list1->val<list2->val)
        {
            third=last=list1;
            list1=list1->next;
            last->next=NULL;
        }
        else // list1->val>list2->val
        {
            third=last=list2;
            list2=list2->next;
            last->next=NULL;
        }
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<list2->val)
            {
                last->next=list1;
                last=list1;
                list1=list1->next;
                last->next=NULL;
            }
            else
            {
                last->next=list2;
                last=list2;
                list2=list2->next;
                last->next=NULL;
            }
        }
        if(list1!=NULL)
        {
            last->next=list1;
        }
        else
        {
            last->next=list2;
        }
        return third;
    }
};

/*
1. Question link -- https://leetcode.com/problems/merge-two-sorted-lists/

2. Solution link -- https://leetcode.com/problems/merge-two-sorted-lists/solutions/3381613/optimized-approach-easy-c-solution-t-c-o-n-and-s-c-o-1/

*/