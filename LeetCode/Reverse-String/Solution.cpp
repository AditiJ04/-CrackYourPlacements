class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();

        int l=0;
        int h=n-1;

        while(l<=h)
        {
            char tmp=s[l];
            s[l]=s[h];
            s[h]=tmp;

            l++;
            h--;
        }
    }
};