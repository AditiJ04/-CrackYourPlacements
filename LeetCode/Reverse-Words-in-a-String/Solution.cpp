class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        string res = "";

        int j = n - 1, i = n - 1;

        while(s[j]==' ') j--;
        int si=0;

        while(s[si]==' ') si++;
        while (j >=si) {

            if(j+1<n && s[j]==' ' && s[j+1]==' ')
            {
                j--;
                continue;
            }
           
           if(j+1<n && s[j]!=' ' && s[j+1]==' ')
            {
                i=j;
                j--;
                continue;
            }

            if (s[j] == ' ') {
                string str = s.substr(j + 1, i - j);
                res += str;
                res += " ";
                i = j;
            }

            j--;
        }
        string str = s.substr(j + 1, i - j);
        if(str==" ") return res;
        res += str;

        return res;
    }
};