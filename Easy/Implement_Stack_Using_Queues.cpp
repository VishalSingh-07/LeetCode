/*
225. Implement Stack Using Queues

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
 

Follow-up: Can you implement the stack using only one queue?
*/
#include <bits/stdc++.h>
using namespace std;


// Method 1: Using Two Queue
/*
Steps:

push(x)

Add x -> q2
q1 -> q2 (Element by Element)
Swap(q1,q2)


Pop()

Remove the top from q1 using q1.front()
*/
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q2,q1);
    }
    
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return (q1.empty() && q2.empty())?true:false;
    }
};


// Method 2: Using Single Queue
/*
Steps:
- Take a single queue.
- push(x): Push the element in the queue.
- Use a for loop of size()-1, remove element from queue and again push back to the queue, hence the most recent element becomes the most former element and vice versa.
- pop(): remove the element from the queue.
- top(): show the element at the top of the queue.
- size(): size of the current queue.
- Repeat step3 at every insertion of the element.
*/
class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        int size=q.size();
        q.push(x);
        for(int i=0;i<size;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty()?true:false;
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


/*
1. Question Link -- https://leetcode.com/problems/implement-stack-using-queues/description/

2. Solution Link -- https://leetcode.com/problems/implement-stack-using-queues/solutions/4644823/2-approach-easy-c-solution-using-two-queues-and-single-queue-with-explanation

3. Video Link -- https://youtu.be/jDZQKzEtbYQ
*/