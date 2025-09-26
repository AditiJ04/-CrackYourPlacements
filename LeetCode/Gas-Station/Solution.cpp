class Solution {
public:
    
    bool check(int targetidx,int idx,vector<int>&gas,vector<int>&cost)
    {

        int n=gas.size();
        int i=(idx+1)%n;
        int samt=gas[idx];

        while(true)
        {
            if(samt<cost[idx]) return false;
            if(i==targetidx) return true;
            samt-=cost[idx];
            samt+=gas[i];
            idx=i;
            i=(idx+1)%n;
        }

        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();

        if(n==1 && gas[0]>=cost[0]) return 0;

        int idx=0;

        for(int i=0;i<n;i++)
        {
            if(gas[i]>cost[i])
            {
                idx=i;

                if(check(idx,idx,gas,cost)) return idx;
            }
        }

        return -1;
    }
};