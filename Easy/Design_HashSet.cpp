/*
705. Design HashSet
Easy
2.7K
238
Companies
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
 

Constraints:

0 <= key <= 106
At most 104 calls will be made to add, remove, and contains.
*/
#include <bits/stdc++.h>
using namespace std;
// Approach 1 [Using Vector]
// Time complexity -> O(1) and Space -> O(n)
// class MyHashSet {
// public:
//     vector<int> v;
//     int size;
//     MyHashSet() {
//         size=1e6+1;
//         v.resize(size);
//     }
    
//     void add(int key) {
//         v[key]=1;
//     }
    
//     void remove(int key) {
//         v[key]=0;
//     }
    
//     bool contains(int key) {
//         return v[key];
//     }
// };


// Approach 2 [Using Hashing]
// Time complexity -> O(1) and Space -> O(n)
class MyHashSet {
public:
    vector<list<int>> m;
    int size;
    MyHashSet() {
        size=100;
        m.resize(size);
    }
    int hash(int key)
    {
        return key%size;
    }
    list<int> :: iterator search(int key)
    {
        int i=hash(key);
        return find(m[i].begin(),m[i].end(),key);
    }
    void add(int key) {
        if(contains(key))
        {
            return;
        }
        int i=hash(key);
        m[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key))
        {
            return;
        }
        int i=hash(key);
        m[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
        if(search(key)!=m[i].end())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


/*
1. Question link -- https://leetcode.com/problems/design-hashset/

2. Solution link -- https://leetcode.com/problems/design-hashset/solutions/3420304/2-approach-easy-c-solution-solve-using-vector-and-hashing-approach/

3. Video link --  https://youtu.be/IjxkD8L2cOM
*/