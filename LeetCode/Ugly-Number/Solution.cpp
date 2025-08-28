class Solution {
public:
    bool isUgly(int n) {

        if(n==0) return false;
        if(n==1) return true;
        unordered_map<int,int>mp;
        mp[2]++;
        mp[3]++;
        mp[5]++;

        for(auto it:mp)
        {
            while(n%it.first==0)
            {
                n/=it.first;
            }
        }

        return n==1;
    }
};