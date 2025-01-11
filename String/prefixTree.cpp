struct TrieNode{
    char data; // Key is not necessary for basic trie as node present at specific index works as presence of that character. We can take key as count to keep track of how many words include this node.
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++) children[i]=nullptr;
        isTerminal=false;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode('\0');
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        for(char ch:word){
            int index=ch-'a';
            if(!curr->children[index]){
                TrieNode* child=new TrieNode(ch);
                curr->children[index]=child;
            }
            curr=curr->children[index];
        }
        curr->isTerminal=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char ch:word){
            int index=ch-'a';
            if(!curr->children[index]) return false;
            curr=curr->children[index];
        }
        return curr->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(char ch:word){
            int index=ch-'a';
            if(!curr->children[index]) return false;
            curr=curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */