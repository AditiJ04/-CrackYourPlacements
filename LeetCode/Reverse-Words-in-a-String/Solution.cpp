class Solution {
public:
    string reverseWords(string s) {
        string res="";
        stack<string>st;

        istringstream iss(s);

        string word;
        while(iss>>word)
        {
            st.push(word);
        }

        while(st.size()>1)
        {
            res+=st.top();
            res+=' ';
            st.pop();
        }
        res+=st.top();
        return res;

    }
};