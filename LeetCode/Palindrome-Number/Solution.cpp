class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        string s=to_string(x);

        int l=0;
        int h=s.size()-1;

        while(l<=h)
        {
            if(s[l]==s[h])
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