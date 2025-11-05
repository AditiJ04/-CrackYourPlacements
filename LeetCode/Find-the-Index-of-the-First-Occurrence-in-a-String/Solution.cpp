class Solution {
public:
    void computeLPS(string needle,int m,int LPS[])
    {
        LPS[0]=0;
        int len=0;
        int i=1;

        while(i<m)
        {
            if(needle[len]==needle[i])
            {
                len++;
                LPS[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len=LPS[len-1];
                }
                else
                {
                    LPS[i]=0;
                    i++;
                }
            }
        }
    }
    int KMP(string haystack,string needle)
    {
        int n=haystack.size();
        int m=needle.size();

        int LPS[m];
        computeLPS(needle,m,LPS);

        int i=0,j=0;

        while(i<n)
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                return i-j;
            }
            else if(i<n && needle[j]!=haystack[i])
            {
                if(j!=0)
                {
                    j=LPS[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
            return KMP(haystack,needle);
    }
};