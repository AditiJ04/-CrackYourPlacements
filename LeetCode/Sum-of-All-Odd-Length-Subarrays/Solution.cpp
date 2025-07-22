class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int sum=0;

        for(int i=0;i<n;i++)
        {
            int l=i+1;
            int r=n-i;

            int totalodd=(l*r+1)/2;
            sum+=totalodd*arr[i];
        }

        return sum;
    }
};