class Solution {
public:
    string reverseWords(string s) {
        string ans;

        istringstream iss(s);
        string word;
        stack<string>st;

        while(iss>>word)
        {
            st.push(word);
        }

         while (st.size()>1) {
        ans+=st.top();
        ans+=" ";
        st.pop();
    }
    ans+=st.top();
    st.pop();
        return ans;
    }
};