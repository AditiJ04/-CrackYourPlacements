1class Solution {
2public:
3    map<int, string> mp;
4vector<string> ans;
5
6void FindCombo(string digits, int idx, string str) {
7    if (idx == digits.size()) {
8        ans.push_back(str);
9        return;
10    }
11
12    int num = digits[idx] - '0';
13    string s = mp[num];
14
15    for (int j = 0; j < s.size(); j++) {
16        FindCombo(digits, idx + 1, str + s[j]);
17    }
18}
19
20vector<string> letterCombinations(string digits) {
21    if (digits.empty()) return {};  // Handle edge case for empty input
22    
23    // Initialize digit-to-letter mappings
24    mp[2] = "abc";
25    mp[3] = "def";
26    mp[4] = "ghi";
27    mp[5] = "jkl";
28    mp[6] = "mno";
29    mp[7] = "pqrs";
30    mp[8] = "tuv";
31    mp[9] = "wxyz";
32
33    ans.clear();
34    FindCombo(digits, 0, "");
35    
36    return ans;
37}
38};