class Solution {
public:
      bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> reverse_map;
        vector<vector<int>> res;

        // Build reverse map
        for (int i = 0; i < words.size(); ++i) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            reverse_map[rev] = i;
        }

        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];

            // Case 1: Exact reverse match
            if (reverse_map.count(word) && reverse_map[word] != i) {
                res.push_back({i, reverse_map[word]});
            }

            // Case 2: Empty string with palindromes
            if (!word.empty() && reverse_map.count("") && isPalindrome(word)) {
                res.push_back({i, reverse_map[""]});
                res.push_back({reverse_map[""], i});
            }

            // Case 3: Check all possible splits
            for (int j = 1; j < word.size(); ++j) {
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                if (isPalindrome(prefix) && reverse_map.count(suffix)) {
                    res.push_back({reverse_map[suffix], i});
                }
                if (isPalindrome(suffix) && reverse_map.count(prefix)) {
                    res.push_back({i, reverse_map[prefix]});
                }
            }
        }

        return res;
    }
};