/*
You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.

 

Example 1:


Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.


Example 2:


Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.
 

Constraints:

3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104
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

// Brute Force Approach
// Time complexity -> O(n+m) and Space -> O(n+m)
// where n: Length of list1 and m: Length of list2
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        vector<int> mergeArr;
        ListNode *current1=list1;
        int index=0;

        // Add list1 node values before `a` to the array.
        while(index<a){
            mergeArr.push_back(current1->val);
            current1=current1->next;
            index++;
        }

        ListNode *current2=list2;

        // Add list2 node values to the array
        while(current2!=nullptr){
            mergeArr.push_back(current2->val);
            current2=current2->next;
        }

        // Find node b + 1
        while(index<b+1){
            current1=current1->next;
            index++;
        }

        // Add list1 node values after `b` to the array.
        while(current1!=nullptr){
            mergeArr.push_back(current1->val);
            current1=current1->next;
        }
        // Build a linked list with the result by iterating over the array
        // in reverse order and inserting new nodes to the front of the list
        ListNode* resultList = nullptr;
        for (int i = mergeArr.size() - 1; i >= 0; i--) { 
            ListNode* newNode = new ListNode(mergeArr[i], resultList);
            resultList = newNode;
        }

        return resultList;
    }
};



// Optimized Approach
// Time complexity -> O(n+m) and Space -> O(1)
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list1;

        // Move temp1 to the node before 'a'
        while(a>1){
            temp1=temp1->next;
            a--;
        }

        // Move temp2 to the node after 'b'
        while(b>=0){
            temp2=temp2->next;
            b--;
        }

        // Connect temp1 to list2
        temp1->next=list2;

        // Link the last node of list2 to temp2
        ListNode* temp = list2;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=temp2;
        
        return list1;
    }
};


// OR
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start=nullptr;
        ListNode* end=list1;

        // Putting start node at (a-1)th node and end node at (b+1)th node
        for(int index=0;index<=b;index++){
            if(index==a-1){
                start=end;
            }
            end=end->next;
        }

        // Connect the start node to list2
        start->next = list2;

        // Find the tail of list2
        ListNode* tail = list2;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        // Set the tail of list2 to end
        tail->next = end;

        return list1;

    }
};

/*
1. Question Link -- https://leetcode.com/problems/merge-in-between-linked-lists/

2. Solution link -- https://leetcode.com/problems/merge-in-between-linked-lists/solutions/4903401/2-approach-easy-c-solution-brute-force-and-optimized-approach-with-explanation
*/