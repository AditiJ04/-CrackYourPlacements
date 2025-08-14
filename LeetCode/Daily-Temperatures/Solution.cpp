class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();

        stack<int>st;

        unordered_map<int,int>mp;
        vector<int>ans;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                mp[i]=-1;
            }
            else
            {
                mp[i]=st.top();
            }
            st.push(i);
        }

        for(int i=0;i<n;i++)
        {
            if(mp[i]==-1) ans.push_back(0);
            else
            {
                ans.push_back(mp[i]-i);
            }
        }

        return ans;
    }
};