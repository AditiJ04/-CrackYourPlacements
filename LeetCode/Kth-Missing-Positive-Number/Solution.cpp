class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>mp;

        int n=arr.size();
        int mx=*max_element(arr.begin(),arr.end());

        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }

        for(int i=1;i<=mx;i++)
        {
            if(mp.find(i)==mp.end())
            {
                k--;
                if(k==0) return i;
            }
        }
        return mx+k;
    }
};