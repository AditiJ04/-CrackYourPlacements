class Solution {
public:
    int minimumSum(int n, int k) {
        int sum=0;
        int cnt=0;
        int s=1;

        unordered_map<int,int>mp;
        while(cnt!=n)
        {
            if(s>k || mp.find(k-s)==mp.end()) 
            {
                sum+=s;
                mp[s]++;
                cnt++;
            }
            s++;
            
        }
        return sum;
    }
};

//1,2,3