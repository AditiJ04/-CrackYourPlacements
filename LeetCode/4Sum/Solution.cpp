class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {

            if(i>0 && nums[i]==nums[i-1]) continue;
            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, k = n - 1;

                long long t = (long long)target - nums[i] - nums[j];
                while (l < k) {
                    long long sum = nums[l] + nums[k];

                    if (sum < t) {
                        l++;
                    } else if (sum > t)
                        k--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[k]});

                        while (l < k && nums[l] == nums[l + 1])
                            l++;
                        while (k > l && nums[k] == nums[k - 1])
                            k--;

                        l++;
                        k--;
                    }
                }
            }
        }

        return ans;
    }
};

// -2 -1 0 0 1 2