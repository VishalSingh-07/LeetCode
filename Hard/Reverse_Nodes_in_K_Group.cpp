/*
25. Reverse Nodes in K Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]


Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?
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

// Optimized Approach
// Time complexity -> O(2n) ~ O(n) and Space -> O(1)
class Solution {
private:
    // Helper function to reverse a linked list
    ListNode* reverseLinkedList(ListNode *head) 
    {
        ListNode *currNode = head, *prevNode = nullptr, *nextNode;
        while (currNode != nullptr) 
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

    // Helper function to get the kth node from the current position
    ListNode* getKthNode(ListNode *temp, int k) 
    {
        k -= 1;
        while (temp != nullptr && k > 0) 
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

public:
    // Function to reverse nodes in k-group in a linked list
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *temp = head, *prevNode = nullptr, *nextNode = nullptr;
        // Iterate through the linked list
        while (temp != nullptr) 
        { 
            // Get the kth node from the current position
            ListNode *kthNode = getKthNode(temp, k);

            // If kth node is not found, connect the remaining nodes to the previous group
            if (kthNode == nullptr) 
            {
                if (prevNode != nullptr) 
                {
                    prevNode->next = temp;
                }
                break;
            }

            // Save the next node after kth node
            nextNode = kthNode->next;

            // Disconnect the kth node from the rest of the list
            kthNode->next = nullptr;

            // Reverse the current k-group and update head if necessary
            reverseLinkedList(temp);
            if (temp == head) 
            {
                head = kthNode;
            } else 
            {
                prevNode->next = kthNode;
            }

            // Update pointers for the next iteration
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};

/*
1. Question link -- https://leetcode.com/problems/reverse-nodes-in-k-group/

2. Solution link -- https://leetcode.com/problems/reverse-nodes-in-k-group/solutions/4844525/best-c-solution-optimized-approach-with-explanation-striver-solution

3. Video Link -- https://youtu.be/lIar1skcQYI
*/