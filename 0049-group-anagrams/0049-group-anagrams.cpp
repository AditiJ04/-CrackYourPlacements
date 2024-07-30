class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;

        unordered_map<string,vector<string>>mp;

        for(auto it:strs)
        {
            string word=it;

            sort(word.begin(),word.end());
            mp[word].push_back(it);
        }

        for(auto x:mp)
        {
            ans.push_back(x.second);
        }

        return ans;
    }
};