// 3045. Count Prefix and Suffix Pairs II
// https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/

struct TrieNode{
    long long cnt; // For counting how many words contain this node
    map<pair<char,char>,TrieNode*> children; // Constructing prefix and suffix trie in one by taking nodes as pair of first and corresponding last character
    TrieNode(){
        cnt=0;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode();
    }
    void insert(string word) {
        TrieNode* curr=root;
        int n=word.size();
        int i=0, j=n-1;
        while(i<n){
            pair<char,char> p={word[i],word[j]};
            if(!curr->children[p]){
                curr->children[p]=new TrieNode();
            }
            curr=curr->children[p];
            curr->cnt++;
            i++; j--;
        }
    }
    long long count(string word) {
        TrieNode* curr=root;
        int n=word.size();
        int i=0, j=n-1;
        while(i<n){
            pair<char,char> p={word[i],word[j]};
            if(!curr->children[p]) return 0;
            curr=curr->children[p];
            i++; j--;
        }
        return curr->cnt;
    }
};
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long res=0;
        Trie *root=new Trie();
        for(int i=words.size()-1;i>=0;i--){
            res+=root->count(words[i]);
            root->insert(words[i]); // Inserting after counting otherwise it will also include itself
            // We can also combine insert and count function
        } 
        return res;
    }
};