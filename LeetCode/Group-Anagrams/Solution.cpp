class Solution {
public:
    string generate(string str)
    {
        int n=str.size();
        int arr[26]={0};

        for(char &ch:str)
        {
            arr[ch-'a']++;
        }

        string new_word="";

        for(int i=0;i<26;i++)
        {
            int freq=arr[i];

            if(freq>0)
            {
                new_word+=string(freq,i+'a');
            }
        }

        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();

        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;

        for(int i=0;i<n;i++)
        {
            string str=strs[i];
            string new_word=generate(str);
            mp[new_word].push_back(str);
        }

        for(auto it:mp)
        {
            ans.push_back(it.second);
        }

        return ans;
        
    }
};