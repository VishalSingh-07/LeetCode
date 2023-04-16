/*
706. Design HashMap
Easy

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
 

Constraints:

0 <= key, value <= 106
At most 104 calls will be made to put, get, and remove.
*/


#include <bits/stdc++.h>
using namespace std;
// Approach 1 [Using Vector]
// Time complexity -> O(1) and Space -> O(n)
// class MyHashMap {
// public:
//     vector<int> m;
//     int size;
//     MyHashMap() {
//         size=1e6+1;
//         m.resize(size,-1);
//     }
//     void put(int key, int value) {
//         m[key]=value;   
//     }
    
//     int get(int key) {
//         if(m[key]!=-1)
//         {
//             return m[key];
//         }
//         return -1;
//     }
    
//     void remove(int key) {
//         m[key]=-1;
//     }
// };


// Approach 2 [Using Hashing]
// Time complexity -> O(1) and Space -> O(n)
class MyHashMap {
public:
    vector<list<pair<int,int>>> m;
    int size;
    MyHashMap() {
        size=100;
        m.resize(size);
    }
    int hash(int key)
    {
        return key%size;
    }
    list<pair<int,int>>:: iterator search(int key)
    {
        int i=hash(key);
        list<pair<int,int>> :: iterator it=m[i].begin();
        while(it!=m[i].end())
        {
            if(it->first==key)
            {
                return it;
            }
            it++;
        }
        return it;
    }
    void put(int key, int value) {
        int i=hash(key);
        remove(key);
        m[i].push_back({key,value});
    }
    
    int get(int key) {
        int i=hash(key);
        list<pair<int,int>>:: iterator it=search(key);
        if(it==m[i].end())
        {
            return -1;
        }
        return it->second;
    }
    
    void remove(int key) {
        int i=hash(key);
        list<pair<int,int>>:: iterator it=search(key);
        if(it!=m[i].end())
        {
            m[i].erase(it);
        }
    }
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */


/*
1. Question link -- https://leetcode.com/problems/design-hashmap/

2. Solution link -- https://leetcode.com/problems/design-hashmap/solutions/3423030/2-approach-easy-c-solution-solve-using-vector-and-hashing-method/

3. Video link -- https://youtu.be/xVEGczCJCHs

*/