class Solution {
public:
    bool checkDay(vector<int>& bloomDay, int m, int k, int day)
    {
       int n=bloomDay.size();
       int cnt=0;

       for(int i=0;i<n;i++)
       {
           if(bloomDay[i]<=day)
           {
               cnt++;
               if(cnt==k)
               {
                m--;
                cnt=0;
               }
           }
           else
           {
            cnt=0;
           }
       }

       return m<=0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = 1LL * m * k;
        if (need > bloomDay.size()) return -1; // not enough flowers

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (checkDay(bloomDay, m, k, mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
