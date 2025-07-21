#include<bits/stdc++.h>
using namespace std;

// Cache Miss or Page Fault is calculated as the number of times when the requested cache or page is not found in the cache.

class LRUCache {
    int cap;
    list<pair<int,int>> dll; // key-value pairs, LRU at the front (or left)
    unordered_map<int, list<pair<int,int>>::iterator> mp; // key-Address
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        auto it = mp[key];
        dll.splice(dll.end(), dll, it);
        return it->second;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            auto it = mp[key];
            it->second = value;
            dll.splice(dll.end(), dll, it);
        } 
        else {
            if (dll.size() == cap) {
                int oldKey = dll.front().first;
                dll.pop_front();
                mp.erase(oldKey);
            }
            dll.push_back({key, value});
            mp[key] = prev(dll.end());
        }
    }
};
