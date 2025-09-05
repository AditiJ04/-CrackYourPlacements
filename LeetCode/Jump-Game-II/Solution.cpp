class Solution {
public:
    int jump(vector<int>& nums) {
        int jmps=0,farthest=0,currend=0;

        for(int i=0;i<nums.size()-1;i++)
        {
            farthest=max(farthest,i+nums[i]);

            if(i==currend)
            {
                jmps++;
                currend=farthest;
            }
        }

        return jmps;
    }
};

// 2 3 1 1 4
// 0 1 2 3 4

//curr=2, 