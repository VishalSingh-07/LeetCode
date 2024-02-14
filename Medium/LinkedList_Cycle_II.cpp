/*
142. Linked List Cycle II 

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *temp=head;
        unordered_map<ListNode*,int> mpp;
        while(temp!=nullptr)
        {
            if(mpp.find(temp)!=mpp.end())
            {
                return temp;
            }
            mpp[temp]=1;
            temp=temp->next;
        }
        return nullptr;
    }
};


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if (slow == fast) 
            {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            } 
        }
        return nullptr;
    }
};

/*
1. Question Link -- https://leetcode.com/problems/linked-list-cycle-ii/

2. Solution Link -- https://leetcode.com/problems/linked-list-cycle-ii/solutions/4727884/detailed-solution-best-c-solution-brute-force-and-optimized-approach-with-explanation

3. Video Link -- https://youtu.be/2Kd0KKmmHFc
*/