#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key, val, cnt;
};

class LFUCache {
    int cap, minf;
    unordered_map<int, list<Node>::iterator> mp; // key -> iterator of Node
    unordered_map<int, list<Node>> freq;         // freq -> list of Nodes

    void insertNode(int key, int val, int cnt) {
        freq[cnt].push_back({key, val, cnt});
        mp[key] = --freq[cnt].end();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minf = 0;
    }

    int get(int key) {
        if(!mp.count(key)) return -1;

        auto it = mp[key];
        int cnt=it->cnt, val=it->val;
        freq[cnt].erase(it);

        if (freq[cnt].empty()) {
            freq.erase(cnt);
            if (minf==cnt) minf++;
        }
        insertNode(key, val, cnt+1);

        return val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key]->val = value;
            get(key);
            return;
        }

        if (mp.size()==cap) {
            auto& listRef = freq[minf];
            auto nodeToDelete = listRef.front();
            mp.erase(nodeToDelete.key);
            listRef.pop_front();
            if (listRef.empty()) freq.erase(minf);
        }

        minf = 1;
        insertNode(key, value, 1);
    }
};