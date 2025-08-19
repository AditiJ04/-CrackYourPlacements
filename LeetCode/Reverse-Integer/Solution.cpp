class Solution {
public:
    int reverse(int x) {
        int flg=0;
        if(x<0) flg=1;

        long long num=0;

        long long y=x;
        y=abs(y);
        while(y!=0)
        {
            int r=y%10;
            num=num*10+r;
            y/=10;
        }
        return (num>=INT_MIN && num<=INT_MAX)?(flg?(-1)*num:num):0;
    }
};