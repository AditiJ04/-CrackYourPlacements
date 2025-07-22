class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - i;

            int odd_cnt=(left*right)/2;

            if((left*right)%2!=0)
            {
                odd_cnt+=1;
            }

            sum+=odd_cnt*arr[i];
        }

        return sum;
    }
};
