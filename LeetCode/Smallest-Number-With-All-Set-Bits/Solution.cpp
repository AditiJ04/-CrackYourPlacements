class Solution {
public:
    int smallestNumber(int n) {
        int tmp=n;

        while(tmp!=0)
        {
            tmp>>=1;
            n |=tmp;
        }

        return n;
    }
};
// 101
//