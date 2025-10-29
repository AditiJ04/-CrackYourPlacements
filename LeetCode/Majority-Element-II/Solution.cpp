class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int thr = n / 3;

        int cnt = 0;
        int candidate = 0;

        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                candidate = nums[i];
                cnt = 1;
            } else if (nums[i] == candidate) {
                cnt++;
            } else {
                if (cnt > thr)
                    ans.push_back(candidate);
                candidate = nums[i];
                cnt = 1;
            }
        }

        if (cnt > thr)
            ans.push_back(candidate);

        return ans;
    }
};