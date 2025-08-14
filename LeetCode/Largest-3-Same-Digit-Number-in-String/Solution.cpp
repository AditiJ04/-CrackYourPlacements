class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        string ans="";

        for(int i=2;i<n;i++)
        {
            if(num[i]==num[i-1] && num[i]==num[i-2])
            {
                string curr=num.substr(i-2,3);
                if(ans=="")
                {
                   ans=curr;
                }
                else
                {
                    int digit1=stoi(ans);
                    int digit2=stoi(curr);

                    if(digit2>digit1)
                    {
                        ans=curr;
                    }
                }
            }
        }

        return ans;
    }
};