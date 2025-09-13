class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        int mn=0;
        int prev=nums[0];
        for(int i=1;i<n;i++)
        {
            if(prev>=nums[i])
            {
                mn+=(prev+1)-nums[i];
                prev++;
            }
            else
            {
                prev=nums[i];
            }
        }

        return mn;
    }
};

//1 5 2 4 1
//1 5 6 
//4+