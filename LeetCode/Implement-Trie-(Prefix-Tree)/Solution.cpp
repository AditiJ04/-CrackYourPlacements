class TrieNode{
      public:

      unordered_map<char,TrieNode*>mp;
      bool endOfWord=false;
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;

        for(auto c:word)
        {
            if(node->mp.find(c)==node->mp.end())
            {
                node->mp[c]=new TrieNode();
            }
            node=node->mp[c];
        }
        node->endOfWord=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;

        for(auto c:word)
        {
            if(node->mp.find(c)==node->mp.end())
            {
                return false;
            }
            node=node->mp[c];
        }
        if(node->endOfWord)
        {
        return true;
        }

        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;

        for(auto c:prefix)
        {
            if(node->mp.find(c)==node->mp.end())
            {
                return false;
            }
            node=node->mp[c];
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