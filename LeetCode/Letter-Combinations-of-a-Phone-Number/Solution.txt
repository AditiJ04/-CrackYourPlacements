1class Solution {
2public:
3    vector<string> ans;
4    unordered_map<char, string> mp;
5
6    void findMapping(string digits, int idx, string str) {
7        if (str.size() == digits.size()) {
8            ans.push_back(str);
9            return;
10        }
11
12        char c = digits[idx];
13
14        for (int i = 0; i < mp[c].size(); i++) {
15            str += mp[c][i];
16            findMapping(digits, idx + 1, str);
17            str.pop_back();
18        }
19    }
20    vector<string> letterCombinations(string digits) {
21        int n = digits.size();
22
23        mp['2'] = "abc";
24        mp['3'] = "def";
25        mp['4'] = "ghi";
26        mp['5'] = "jkl";
27        mp['6'] = "mno";
28        mp['7'] = "pqrs";
29        mp['8'] = "tuv";
30        mp['9'] = "wxyz";
31
32        findMapping(digits, 0, "");
33
34        return ans;
35    }
36};
37
38// 2 3 3 4