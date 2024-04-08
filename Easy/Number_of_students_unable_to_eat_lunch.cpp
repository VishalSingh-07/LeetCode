/*
1700. Number of Students Unable to Eat Lunch

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

 

Example 1:

Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0 
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.


Example 2:

Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3
 

Constraints:

1 <= students.length, sandwiches.length <= 100
students.length == sandwiches.length
sandwiches[i] is 0 or 1.
students[i] is 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(auto x: students){
            q.push(x);
        }
        int i=0,count=0;
        while(q.size()>0 and count<q.size()){
            if(q.front()==sandwiches[i]){
                count=0;
                q.pop();
                i++;
            }else{
                int x=q.front();
                q.pop();
                q.push(x);
                count++;
            }
        }
        return q.size();
    }
};



// Optimized Approach
// Time complexity -> O(n+m) and Space -> O(1)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circleStudentCount=0,squareStudentCount=0;
        for(int i=0;i<students.size();i++){
            if(students[i]==0){
                circleStudentCount++;
            }else{
                squareStudentCount++;
            }
        }
        for(int i=0;i<sandwiches.size();i++){
            // No student wants the circle sandwich on top of the stack
            if(sandwiches[i]==0 && circleStudentCount==0){
                return squareStudentCount;
            }
            // No student wants the square sandwich on top of the stack
            if(sandwiches[i]==1 && squareStudentCount==0){
                return circleStudentCount;
            }
            if(sandwiches[i]==0){
                circleStudentCount--;
            }else{
                squareStudentCount--;
            }
        }

        // Every student received a sandwich
        return 0;
    }
};


/*
1. Question link -- https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/

2. Solution link -- https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/solutions/4991986/2-approach-best-c-solution-brute-force-and-optimized-approach-with-explanation
*/