class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        }
    };
    vector<int> findXSum(vector<int>& nums, int k, int x) {

        int n = nums.size();

        vector<int> ans;
        for (int i = 0; i < n - k + 1; i++) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
            unordered_map<int, int> mp;
            int sum = 0;

            for (int j = i; j <i + k; j++) {
                mp[nums[j]]++;
            }
            for (auto it : mp) {
                pq.push({it.second, it.first});
            }

            int cnt = x; // number of top elements to take
            while (!pq.empty() && cnt--) {
                for (int t = 0; t < pq.top().first; t++) {
                    sum += pq.top().second;
                }
                pq.pop();
            }

            ans.push_back(sum);
        }

        return ans;
    }
};