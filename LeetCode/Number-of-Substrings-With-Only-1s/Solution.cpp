class Solution {
public:

    int mod=1e9+7;
    int numSub(string s) {
        int n = s.size();
        int cnt = 0;

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i>0 && s[i - 1] == '0') {
                    j = i;
                }
                cnt=(cnt+i - j + 1)%mod;
            }
        }

        return cnt;
    }
};