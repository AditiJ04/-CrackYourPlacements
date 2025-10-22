class Solution {
public:
    bool isPerfectSquare(int num) {

        if(num==1) return true;
        int l=1;
        int h=num-1;

        while(l<=h)
        {
            long long mid=(l+h)/2;

            if(mid*mid==(long long)num)return true;

            else if(mid*mid>(long long)num)
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return false;
    }
};

// 1 13