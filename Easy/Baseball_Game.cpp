#include <bits/stdc++.h>
using namespace std;

// Approach 1: [Using Vector]
// Time complexity --> O(n) and Space --> O(1)
// class Solution {
// public:
//     int calPoints(vector<string>& operations) {

//         vector<int> ans;
//         for(int i=0;i<operations.size();i++)
//         {
            
//             if(operations[i]=="+")
//             {
//                 ans.push_back(ans[ans.size()-1]+ans[ans.size()-2]);
//             }
//             else if(operations[i]=="D")
//             {
//                 ans.push_back((ans[ans.size()-1])*2);
//             }
//             else if(operations[i]=="C")
//             {
//                 ans.pop_back();
//             }
//             else
//             {
//                 ans.push_back(stoi(operations[i]));
//             }
//         }
//         int sum=0;
//         for(auto it: ans)
//         {
//             sum+=it;
//         }
//         return sum;
        
//     }
// };

// Approach 2 [Using Stack]
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> s;
        for(int i=0;i<operations.size();i++)
        {
            
            if(operations[i]=="+")
            {
                int last=s.top();
                s.pop();
                int slast=s.top();
                s.push(last);
                s.push(last+slast);

            }
            else if(operations[i]=="D")
            {
                int top=s.top();
                s.push(top*2);
            }
            else if(operations[i]=="C")
            {
                s.pop();
            }
            else
            {
                int value=stoi(operations[i]);
                s.push(value);
            }
        }
        int sum=0;
        while(!s.empty())
        {
            sum+=s.top();
            s.pop();
        }
        return sum;
        
    }
};


// Quesition link -- https://leetcode.com/problems/baseball-game/