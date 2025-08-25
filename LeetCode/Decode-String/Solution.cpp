class Solution {
public:
    string decodeString(string s) {
          int n = s.size();
    stack<pair<int, string>> st; // Pair of count and string

    string currStr;
    int currNum = 0;

    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            currNum = currNum * 10 + (s[i] - '0');
        } else if (isalpha(s[i])) {
            currStr.push_back(s[i]);
        } else if (s[i] == '[') {
            st.push({currNum, currStr});
            currNum = 0;
            currStr.clear();
        } else if (s[i] == ']') {
            int repeat = st.top().first;
            string prevStr = st.top().second;
            st.pop();
            for (int j = 0; j < repeat; ++j) {
                prevStr += currStr;
            }
            currStr = prevStr;
        }
    }
    return currStr;
    }
};