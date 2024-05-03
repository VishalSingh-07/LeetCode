/*
165. Compare Version Numbers

Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 

Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".


Example 2:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as "0".


Example 3:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.
 

Constraints:
- 1 <= version1.length, version2.length <= 500
- version1 and version2 only contain digits and '.'.
- version1 and version2 are valid version numbers.
- All the given revisions in version1 and version2 can be stored in a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n + max(m, n)) and Space -> O(max(m, n))
class Solution {
    vector<int> splitVersion(string version){
        vector<int> result;
        stringstream ss(version);
        string token="";
        while(getline(ss,token,'.')){
            result.push_back(stoi(token));
        }
        return result;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1=splitVersion(version1);
        vector<int> v2=splitVersion(version2);

        int n=v1.size(),m=v2.size();
        int i=0,j=0;
        while(i<n || j<m){
            int val1=i<n?v1[i]:0;
            int val2=j<m?v2[j]:0;
            if(val1<val2){
                return -1;
            }
            else if(val1>val2){
                return 1;
            }
            i++;
            j++;
        }
        return 0;
    }
};


// Optimized Approach
// Time complexity -> O(max(n,m))i and Space -> O(1)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size(),m=version2.size();
        int i=0,j=0;
        while(i<n || j<m){
            int v1=0,v2=0;
            while(i<n && version1[i]!='.'){
                v1=v1*10+(version1[i]-'0');
                i++;
            }
            while(j<m && version2[j]!='.'){
                v2=v2*10+(version2[j]-'0');
                j++;
            }
            if(v1>v2){
                return 1;
            }
            else if(v1<v2){
                return -1;
            }
            i++;
            j++;
        }
        return 0;
    }
};

/*
1. Question link -- https://leetcode.com/problems/compare-version-numbers/

2. Solution link -- https://leetcode.com/problems/compare-version-numbers/solutions/5107561/2-approach-best-c-solution-brute-force-and-optimzed-approach-with-explanation
*/