class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        if (n == 1)
            return str;

        n--;

        while (n != 0) {

            string ans = "";
            int si = 0;
            for (int i = 1; i < str.size(); i++) {
                if (str[i - 1] != str[i]) {
                    ans += to_string(i - si);
                    ans += str[i - 1] ;
                    si = i;
                }
            }
            ans += to_string(str.size()-si);
            ans += str.back();
            str = ans;
            n--;
        }

        return str;
    }
};

// n=5

// 1->11
// 2 ->21
// 3->1211