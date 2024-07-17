class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int l=0;
        int h=n-1;

        int m=(l+h)/2;

        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=abs(nums[m]-nums[i]);
        }

        return sum;

    }//1 2 9 10

};