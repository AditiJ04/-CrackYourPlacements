1class Solution {
2public:
3    set<vector<int>> unique_combinations;
4
5// Helper function to find combinations
6void FindCombo(vector<int>& v, vector<int>& ans, int k, int idx, int sum, int target) {
7    // Base case: if the combination size equals k and the sum matches the target
8    if (ans.size() == k) {
9        if (sum == target) {
10            unique_combinations.insert(ans); // Insert into set to ensure uniqueness
11        }
12        return;
13    }
14
15    // Iterate through the elements starting from index `idx`
16    for (int i = idx; i < v.size(); i++) {
17        ans.push_back(v[i]); // Include the current element
18        FindCombo(v, ans, k, i + 1, sum + v[i], target); // Recursive call with `i + 1` to avoid reuse
19        ans.pop_back(); // Backtrack to explore other combinations
20    }
21}
22
23// Function to find all unique combinations of `k` numbers that sum up to `n`
24vector<vector<int>> combinationSum3(int k, int n) {
25    vector<int> v;
26    for (int i = 1; i <= 9; i++) { // Numbers allowed are 1 through 9
27        v.push_back(i);
28    }
29
30    vector<int> ans;
31    unique_combinations.clear(); // Clear previous results if the function is reused
32    FindCombo(v, ans, k, 0, 0, n); // Start the recursion
33
34    // Convert set to result vector
35    vector<vector<int>> res(unique_combinations.begin(), unique_combinations.end());
36    return res;
37}
38};