class Solution {
public:
    int totalMoney(int n) {
        int m=1;
        int day=1;
        
        int sum=1;
        for(int i=2;i<=n;i++)
        {
            if((i-1)%7==0)
            {
                m++;
                day=m;
                sum+=day;
                continue;
            }
            day+=1;
            sum+=day;
        }

        return sum;
    }
};

//

//day=2
//sum=1+2+3+4+5+6+7+(2)
//m=2