// Node structure for Trie
struct Node {
    int index;                  // Stores index of word if the word ends at this node
    bool end;                   // True if a word ends here
    Node* links[26];            // Pointers to next characters (a-z)
    vector<int> palinSuffix;    // Stores indices of words such that the remaining prefix is a palindrome

    Node() {
        index = -1;             // Default value (no word ends here initially)
        end = false;
        for (int i = 0; i < 26; i++) links[i] = nullptr; // Initialize children as null
    }
};

// Trie to store reversed words for efficient palindrome pair search
class Trie {
    Node* root;

    // Utility function to check if substring s[l...r] is a palindrome
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false; // mismatch found
            l++;
            r--;
        }
        return true; // valid palindrome
    }

public:
    Trie() { root = new Node(); }

    // Insert word into Trie (reversed), while keeping track of palindrome suffixes
    void insert(string &word, int idx) {
        Node* node = root;

        // Insert characters from last to first (reverse order)
        for (int i = word.size() - 1; i >= 0; i--) {
            // If prefix word[0...i] is palindrome, store index in palinSuffix
            // This means current node can form a palindrome pair later
            if (isPalindrome(word, 0, i)) {
                node->palinSuffix.push_back(idx);
            }

            // Create node for current character if not already present
            if (!node->links[word[i] - 'a'])
                node->links[word[i] - 'a'] = new Node();

            node = node->links[word[i] - 'a']; // move to next character
        }

        // Mark end of word
        node->end = true;
        node->index = idx;

        // Add index to palinSuffix, because empty suffix is also palindrome
        node->palinSuffix.push_back(idx);
    }

    // Search for palindrome pairs using given word
    void search(string &word, int idx, vector<vector<int>> &res) {
        Node* node = root;

        // Traverse word from first to last
        for (int i = 0; i < word.size(); i++) {
            // Case 1: If current Trie node is end of another word
            // and the remaining suffix of current word is palindrome
            if (node->end && node->index != idx && isPalindrome(word, i, word.size() - 1)) {
                res.push_back({idx, node->index});
            }

            // If next character not found in Trie → no match
            if (!node->links[word[i] - 'a']) return;

            node = node->links[word[i] - 'a'];
        }

        // Case 2: If we finished traversing word, check all palinSuffix indices
        // These are words that when appended will form a palindrome
        for (int j : node->palinSuffix) {
            if (idx != j) res.push_back({idx, j});
        }
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie t;

        // Step 1: Insert all words into Trie (in reversed form)
        for (int i = 0; i < words.size(); i++) {
            t.insert(words[i], i);
        }

        vector<vector<int>> res;

        // Step 2: For each word, search in Trie for palindrome pair possibilities
        for (int i = 0; i < words.size(); i++) {
            t.search(words[i], i, res);
        }

        // Step 3: Return all palindrome pairs
        return res;
    }
};
