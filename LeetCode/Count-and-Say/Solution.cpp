class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        if (n == 1)
            return str;

        n--;

        while (n != 0) {
            stack<char> st;

            string ans = "";
            for (int i = 0; i < str.size(); i++) {
                if (st.empty() || st.top() == str[i]) {
                    st.push(str[i]);
                } else if (st.top() != str[i]) {
                    ans += to_string(st.size());
                    ans += st.top();

                    while (!st.empty())
                        st.pop();

                    st.push(str[i]);
                }
            }
            if (!st.empty()) {
                ans += to_string(st.size());
                ans += st.top();
            }

            str = ans;
            n--;
        }

        return str;
    }
};

// n=5

// 1->11
// 2 ->21
// 3->1211