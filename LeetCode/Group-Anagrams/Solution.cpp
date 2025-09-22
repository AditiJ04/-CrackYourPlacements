class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();

        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;

        for(auto str:strs)
        {
            string s=str;
            sort(str.begin(),str.end());
            mp[str].push_back(s);
        }

        for(auto it:mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};