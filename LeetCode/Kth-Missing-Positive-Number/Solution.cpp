class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();

        int l=0;
        int h=n-1;

        while(l<=h)
        {
            int mid=(l+h)/2;
            int missingele=arr[mid]-(mid+1);

            if(missingele<k)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }

        return l+k;
    }
};