class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        string str=words[0];
        unordered_map<char,int>mp;

        vector<string>ans;
        for(char c:str)
        {
            mp[c]++;
        }

        for(int i=1;i<n;i++)
        {
            unordered_map<char,int>tmp;
            for(char c:words[i])
            {
                tmp[c]++;
            }

            for(auto &p:mp)
            {
                if(tmp.find(p.first)!=tmp.end())
                {
                    p.second=min(tmp[p.first],p.second);
                }
                else
                {
                    p.second=0;
                }
            }
        }

        vector<char>keysToRemove;

        for (auto& p : mp) {
            if (p.second == 0) {
                keysToRemove.push_back(p.first);
            }
        }
        for (char key : keysToRemove) {
            mp.erase(key);
        }

        for(auto c:mp)
        {
            for(int i=0;i<c.second;i++)
            {
            ans.push_back(string(1,c.first));
            }
        }

        return ans;
    }
};