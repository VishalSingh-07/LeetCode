/*

232. Implement Queue using Stacks

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
 

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach 1
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    int front; 
    MyQueue() {
        front=0;
    }
    void push(int x) {
        if(st1.empty())
        {
            front=x;
        }
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int x=st1.top();
        st1.pop();
        if(!st1.empty())
        {
            front=st1.top();
        }
        return x;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return st1.empty()?true:false;
    }
};


// Approach 2
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    int front; 
    MyQueue() {
        front=0;
    }
    void push(int x) {
        if(st1.empty())
        {
            front=x;
        }
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int x=st2.top();
        st2.pop();
        return x;
    }
    
    int peek() {
        if(!st2.empty())
        {
            return st2.top();
        }
        return front;
    }
    
    bool empty() {
        return (st1.empty() && st2.empty())?true:false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/*
1. Question Link -- https://leetcode.com/problems/implement-queue-using-stacks/description/

2. Solution Link -- https://leetcode.com/problems/implement-queue-using-stacks/solutions/4644968/2-approach-easy-c-solution-with-explanation-beats-100-00-of-users-with-c
*/