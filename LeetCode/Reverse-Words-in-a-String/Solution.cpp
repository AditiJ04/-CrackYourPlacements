class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        int n = s.size();

        int i = n - 1, j = n - 1;
        while (s[j] == ' ')
            j--;
        i = j;

        while (j >= 0) {
            if (s[j] == ' ') {
                string str = s.substr(j + 1, i - j);
                if (!ans.empty())
                    ans += " ";
                ans += str;

                while (j >= 0 && s[j] == ' ')
                    j--;
                i = j;
            }
                j--;
            }

            if (i >= 0) {
                if (!ans.empty())
                    ans += " ";
                ans += s.substr(0, i + 1);
            }
            return ans;
        }
    };