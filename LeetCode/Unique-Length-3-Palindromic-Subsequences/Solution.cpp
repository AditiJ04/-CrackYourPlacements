class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();

        unordered_set<char>letters;

        for(int i=0;i<n;i++)
        {
            letters.insert(s[i]);
        }

        int res=0;

        for(char l:letters)
        {
            int f_idx=-1;
            int l_idx=-1;

            for(int i=0;i<n;i++)
            {
                if(s[i]==l)
                {
                    if(f_idx==-1)
                    {
                        f_idx=i;
                    }
                    else
                    {
                        l_idx=i;
                    }
                }
            }

            unordered_set<char>st;
            for(int j=f_idx+1;j<=l_idx-1;j++)
            {
                st.insert(s[j]);
            }

            res+=st.size();
        }

        return res;
    }
};