class Solution {
public:
    int mod=1e9+7;
    using ll=long long;

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();

        vector<int>L(n,-1);
        vector<int>R(n,n);

        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                L[i]=st.top();
            }
            st.push(i);
        }

        st=stack<int>();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                R[i]=st.top();
            }
            st.push(i);
        }

        ll sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=static_cast<ll>(i-L[i])*(R[i]-i)*arr[i]%mod;
            sum%=mod;
        }

        return sum;
    }
};