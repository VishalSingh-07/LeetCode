/*
2073. Time Needed to Buy Tickets

There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person at position k (0-indexed) to finish buying tickets.

 

Example 1:

Input: tickets = [2,3,2], k = 2
Output: 6
Explanation: 
- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.


Example 2:

Input: tickets = [5,1,1,1], k = 0
Output: 8
Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.
 

Constraints:

n == tickets.length
1 <= n <= 100
1 <= tickets[i] <= 100
0 <= k < n

*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n*m) and Space -> O(n)
// where n: Length of the tickets array and m: maximum number of tickets at each index
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        queue<pair<int,int>>q;
        for(int i=0;i<tickets.size();i++){
            q.push({i, tickets[i]});
        }
        while(!q.empty()){
            auto [index,value] = q.front();
            q.pop();
            value--;
            time++;
            if(index==k && value==0){
                return time;
            }
            else if(value!=0){
                q.push({index,value});
            }
        }
        return time;
    }
};

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        queue<int>q;
        for(int i=0;i<tickets.size();i++){
            q.push(i);
        }
        while(!q.empty()){
            int front= q.front();
            q.pop();
            time++;
            tickets[front]--;
            if(front==k && tickets[front]==0){
                return time;
            }
            else if(tickets[front]!=0){
                q.push(front);
            }
        }
        return time;
    }
};


// Better Approach
// Time complexity -> O(n*m) and Space -> O(1)
// where n: Length of the tickets array and m: maximum number of tickets at each index
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int time=0;

        // If person k only needs one ticket, return the time to buy it
        if(tickets[k]==1){
            return k+1;
        }

        // Continue buying tickets until person k buys all their tickets
        while(tickets[k]>0){
            for(int i=0;i<n;i++){
                // Buy a ticket at index 'i' if available
                if(tickets[i]!=0){
                    tickets[i]--;
                    time++;
                }
                // If person k bought all their rickets, return the time
                if(tickets[k]==0){
                    return time;
                }
            }
        }
        return time;
        
    }
};



// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
// where n: Length of the tickets array
// The algorithm iterates through each person in the tickets array once using a for loop. 
// The body of the loop contains constant-time math operations. 
// Therefore, the time complexity is O(n).
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int time=0;
        for(int i=0;i<n;i++){
            // If the current person is before or at the desired person 'k'
            if(i<=k){
                // Buy the minimum of tickets available at person 'k' and the current person
                time+=min(tickets[k],tickets[i]);
            }else{
                // If the current person is after 'k', buy the minimum of 
                // (tickets available at person 'k' - 1) and the current person
                time+=min(tickets[k]-1,tickets[i]);
            }
        }
        return time;
    }
};

/*
1. Question link -- https://leetcode.com/problems/time-needed-to-buy-tickets/description/

2. Solution link -- https://leetcode.com/problems/time-needed-to-buy-tickets/solutions/4997610/4-approach-best-c-solution-brute-force-optimized-approach-with-detailed-explanation
*/