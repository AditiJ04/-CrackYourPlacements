class Solution {
public:
    bool validPalindrome(string s) {
        int cnt=0;
        int cnt1=0;

        int l=0;
        int h=s.length()-1;

        while(l<h)
        {
            if(s[l]==s[h])
            {
                l++;
                h--;
            }

            else
            {
                cnt++;
                h--;
            }
            if(cnt>1)
            {
                break;
            }
        }
        l=0;
        h=s.length()-1;

        while(l<h)
        {
            if(s[l]==s[h])
            {
                l++;
                h--;
            }

            else
            {
                cnt1++;
                l++;
            }
            if(cnt1>1)
            {
                break;
            }
        }

        if(cnt==1 || cnt1==1)
        {
            return true;
        }
        if(cnt==0 || cnt1==0)
        {
            return true;
        }
        return  false;
    }
};