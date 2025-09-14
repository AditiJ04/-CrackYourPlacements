class Solution {
public:
    bool isPalindrome(string s) {

        if(s.empty()) return false;

        int n=s.size();
        int l=0,h=n-1;

        while(l<=h)
        {
            while(l<h && !isalnum(s[l]))
            {
                l++;
            }
            while(h>l && !isalnum(s[h]))
            {
                h--;
            }

            if(tolower(s[l])==tolower(s[h])) 
            {
                l++;
                h--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};